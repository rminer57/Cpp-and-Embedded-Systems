/*!
 *    @file             $Source: UartMinGW.cpp $
 *    @brief            Implementation for UartMinGW Class.
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.1 $
 *
 *    @date             $Date: 2015/05/07 13:09:34EDT $
 *
 *    @par Description 
 *                      Implementation for UartMinGW Class.
 *
 *    @par Copyright
 *                      COPYRIGHT (C) 2014, Jabil
 *
 *    This source code and any compilation or derivative thereof is the sole 
 *    property of Jabil Circuit and is provided pursuant to a Software License 
 *    Agreement. This code is the proprietary information of Jabil Circuit and 
 *    is confidential in nature. Its use and dissemination by any party other 
 *    than Jabil Circuit is strictly limited by the confidential information 
 *    provisions of the Software License Agreement referenced above.
 */

#include <stdio.h>
#include <stddef.h>

#include <UartMinGW.h>
#include <HAL_Assert.h>

H_DEFINE_THIS_MODULE("UartMinGW.cpp")

// use the same values for flags as TivaWare does
#define UART_INT_OE             0x400       // Break Error Interrupt Mask

namespace HAL
{

// forward declaration
DWORD WINAPI ReadThreadFunction(LPVOID lpParameter);
DWORD WINAPI WriteThreadFunction(LPVOID lpParameter);

UartMinGW::UartMinGW(char* commPortPtr) :
        commPortNamePtr(commPortPtr),
        commPortHandle(reinterpret_cast<HANDLE>(-1)),
        initCompleteEvent(NULL),
        txDataReady(NULL),
        terminateEvent(NULL),
        receiveThreadHandle(NULL),
        sendThreadHandle(NULL),
        pClient(NULL),
        rxFifo(rxBuffer, RX_BUFFER_SIZE),
        txFifo(txBuffer, TX_BUFFER_SIZE)
{
    memset(&readOverlapped, 0, sizeof(readOverlapped));
    memset(&writeOverlapped, 0, sizeof(writeOverlapped));

    InitializeCriticalSection(&txCriticalSection);

    // create a self-resetting event for read operations
    readOverlapped.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    H_ASSERT(readOverlapped.hEvent != NULL);

    // create a self-resetting event for write operations
    writeOverlapped.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    H_ASSERT(writeOverlapped.hEvent != NULL);

    // create a manual-reset event for initialization complete indication
    initCompleteEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    H_ASSERT(initCompleteEvent != NULL);

    // create a manual-reset event for Tx data ready
    txDataReady = CreateEvent(NULL, TRUE, FALSE, NULL);
    H_ASSERT(txDataReady != NULL);

    // create a manual-reset event for termination indication
    terminateEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    H_ASSERT(terminateEvent != NULL);
}

UartMinGW::~UartMinGW()
{
    CloseHandle(terminateEvent);
    CloseHandle(txDataReady);
    CloseHandle(initCompleteEvent);
    CloseHandle(writeOverlapped.hEvent);
    CloseHandle(readOverlapped.hEvent);

    DeleteCriticalSection(&txCriticalSection);
}

int UartMinGW::Init()
{
    // Make sure port is closed
    if (commPortHandle != reinterpret_cast<HANDLE>(-1))
    {
        Close();
    }

    return 0;
}

void UartMinGW::Open()
{
    // no communication timeouts
    COMMTIMEOUTS ct = { 0, 0, 0, 0, 0 };
    DCB dcb;

    commPortHandle = CreateFile(commPortNamePtr, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
    H_ASSERT(commPortHandle != reinterpret_cast<HANDLE>(-1));

    dcb.DCBlength = sizeof(dcb);
    H_ASSERT(GetCommState(commPortHandle, &dcb) != 0);

    dcb.BaudRate = CBR_115200;
    dcb.fParity = FALSE;
    dcb.fOutxCtsFlow = FALSE;
    dcb.fOutxDsrFlow = FALSE;
    dcb.fDtrControl = DTR_CONTROL_DISABLE;
    dcb.fDsrSensitivity = FALSE;
    dcb.fTXContinueOnXoff = TRUE;
    dcb.fOutX = FALSE;
    dcb.fInX = FALSE;
    dcb.fNull = FALSE;
    dcb.fRtsControl = RTS_CONTROL_DISABLE;
    dcb.fAbortOnError = FALSE;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;

    H_ASSERT(SetCommState(commPortHandle, &dcb) != 0);

    H_ASSERT(SetCommTimeouts(commPortHandle, &ct) != 0);

    receiveThreadHandle = CreateThread(NULL, 0, ReadThreadFunction, this, 0, NULL);
    H_ASSERT(receiveThreadHandle != NULL);

    sendThreadHandle = CreateThread(NULL, 0, WriteThreadFunction, this, 0, NULL);
    H_ASSERT(sendThreadHandle != NULL);

    // ready for action
    SetEvent(initCompleteEvent);
}

void UartMinGW::Close()
{
    // first signal that the read thread can terminate
    SetEvent(terminateEvent);

    // wait for the receive thread to terminate (give it a second)
    if (WaitForSingleObject(receiveThreadHandle, 1000) == WAIT_TIMEOUT)
    {
        printf("Read thread did not terminate within 1000 ms.\n");
    }

    // wait for the send thread to terminate (give it a second)
    if (WaitForSingleObject(sendThreadHandle, 1000) == WAIT_TIMEOUT)
    {
        printf("Read thread did not terminate within 1000 ms.\n");
    }

    // close all handles
    CloseHandle(receiveThreadHandle);
    CloseHandle(sendThreadHandle);
    CloseHandle(commPortHandle);

    commPortHandle = reinterpret_cast<HANDLE>(-1);
}

void UartMinGW::Register(IUartClient* client)
{
    // So sorry, already have a client
    H_ASSERT(pClient == NULL);
    pClient = client;
}

void UartMinGW::Unregister(IUartClient* client)
{
    // No client
    H_ASSERT(pClient != NULL);
    // Wrong client
    H_ASSERT(pClient == client);
    pClient = NULL;
}

bool UartMinGW::TxFifoSpaceAvailable()
{
    bool haveRoom;

    EnterCriticalSection(&txCriticalSection);
    haveRoom = txFifo.HasRoom();
    LeaveCriticalSection(&txCriticalSection);

    return haveRoom;
}

bool UartMinGW::LoadTxFifo(uint8_t txByte)
{
    bool haveRoom;

    EnterCriticalSection(&txCriticalSection);
    haveRoom = txFifo.HasRoom();
    if (haveRoom)
    {
        txFifo.Put(txByte);
    }
    LeaveCriticalSection(&txCriticalSection);

    SetEvent(txDataReady);

    return haveRoom;
}

void UartMinGW::SendTxFifo()
{
    // I'm not sure if we need this, was here in case LoadTxFifo disabled interrupts so this routine would reenable them
    H_ASSERT(false);
}

bool UartMinGW::RxFifoDataAvailable()
{
    return !rxFifo.IsEmpty();
}

bool UartMinGW::ReadRxFifo(uint8_t* pRxByte)
{
    return rxFifo.Get(pRxByte);
}

void UartMinGW::OnInterrupt()
{
}

DWORD UartMinGW::Receive()
{
    uint8_t byte;
    DWORD bytesRead;
    bool readOk;
    bool readPending;

    while (1)
    {
        readOk = true;
        readPending = false;

        if (ReadFile(commPortHandle, &byte, 1, &bytesRead, &readOverlapped) == FALSE)
        {
            DWORD lastError = GetLastError();
            if (lastError == ERROR_IO_PENDING)
            {
                readPending = true;
            }
            else
            {
                printf("Receive/ReadFile failed: %lu\n", lastError);
                readOk = false;
            }
        }

        if (readOk)
        {
            // do the wait if necessary
            if (readPending)
            {
                HANDLE handles[2];
                DWORD waitResult;

                handles[0] = terminateEvent;
                handles[1] = readOverlapped.hEvent;

                waitResult = WaitForMultipleObjects(2, handles, FALSE, INFINITE);
                if (waitResult == WAIT_OBJECT_0)
                {
                    // terminate requested. Cancel the I/O
                    if (CancelIo(commPortHandle) == 0)
                    {
                        printf("Receive/CancelIo failed: %lu\n", GetLastError());
                    }

                    break;
                }

                // overlapped I/O completed. see what happened
                if (GetOverlappedResult(commPortHandle, &readOverlapped, &bytesRead, FALSE) == FALSE)
                {
                    printf("Receive/GetOverlappedResult failed: %lu\n", GetLastError());
                    readOk = false;
                }
            }

            if (readOk)
            {
                if (bytesRead > 0)
                {
                    if (!rxFifo.Put(byte))
                    {
                        // overrun
                        pClient->OnUartError(UART_INT_OE);
                        printf("RxOF\n");
                    }
                    else
                    {
                        if(pClient != NULL)
                        {
                            // Notify client of available data in rxFifo
                            pClient->OnRxFifoDataAvailable();
                        }
                    }
                }
            }
        }
        else
        {
            // make sure the terminate event isn't signaled
            if (WaitForSingleObject(terminateEvent, 0) == WAIT_OBJECT_0)
            {
                break;
            }
        }
    }

    return 0;
}

DWORD UartMinGW::Send()
{
    HANDLE handles[3];
    DWORD waitResult;
    bool keepGoing = true;

    handles[0] = terminateEvent;
    handles[1] = writeOverlapped.hEvent;
    handles[2] = txDataReady;

    while (keepGoing)
    {
        waitResult = WaitForMultipleObjects(3, handles, FALSE, INFINITE);

        // terminate?
        if (waitResult == WAIT_OBJECT_0)
        {
            break;
        }

        // got data to send?
        if (waitResult == (WAIT_OBJECT_0 + 2))
        {
            bool haveData;
            uint8_t byte;
            DWORD bytesWritten;
            bool writePending = false;

            while (1)
            {
                EnterCriticalSection(&txCriticalSection);
                haveData = txFifo.Get(&byte);
                LeaveCriticalSection(&txCriticalSection);

                if (!haveData)
                {
                    break;
                }

                if (WriteFile(commPortHandle, &byte, 1, &bytesWritten, &writeOverlapped) == FALSE)
                {
                    DWORD lastError = GetLastError();
                    if (lastError == ERROR_IO_PENDING)
                    {
                        writePending = true;
                    }
                    else
                    {
                        printf("Send/WriteFile failed: %lu\n", lastError);
                    }
                }

                // if a write is pending, do the wait
                if (writePending)
                {
                    waitResult = WaitForMultipleObjects(2, handles, FALSE, INFINITE);
                    if (waitResult == WAIT_OBJECT_0)
                    {
                        // terminate requested. Cancel the I/O
                        if (CancelIo(commPortHandle) == 0)
                        {
                            printf("Send/CancelIo failed: %lu\n", GetLastError());
                        }

                        keepGoing = false;
                        break;
                    }
                }

            }

            ResetEvent(txDataReady);

            // burned all the data in the buffer. Let them know we can take more
            if(pClient != NULL)
            {
                // Notify client of available space in txFifo
                pClient->OnTxFifoSpaceAvailable();
            }
        }
    }

    return 0;
}

/// Static Methods //////////////
void UartMinGW::IntHandler(uint32_t portNumber)
{
}

DWORD WINAPI ReadThreadFunction(LPVOID lpParameter)
{
    H_ASSERT(lpParameter != NULL);

    UartMinGW* objectPtr = static_cast<UartMinGW*>(lpParameter);

    return objectPtr->Receive();
}

DWORD WINAPI WriteThreadFunction(LPVOID lpParameter)
{
    H_ASSERT(lpParameter != NULL);

    UartMinGW* objectPtr = static_cast<UartMinGW*>(lpParameter);

    return objectPtr->Send();
}

} /* namespace HAL */
