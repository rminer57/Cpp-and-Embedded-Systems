/*!
 *    @file             UartTiva.cpp
 *    @brief            Implementation for UartTiva Class.
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.1 $
 *
 *    @date             $Date: 2015/05/07 13:41:16EDT $
 *
 *    @par Description 
 *                      <more in-depth description>
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

#include <UartTiva.h>
#include <HAL_Assert.h>
#include <inc/hw_memmap.h>
#include <driverLib/uart.h>
#include <driverLib/interrupt.h>
#include <stddef.h>


H_DEFINE_THIS_MODULE("UartTiva.cpp")

namespace HAL
{

// Interrupt flags we are using
#define UART_ERROR_FLAGS    (UART_INT_OE | UART_INT_BE | UART_INT_PE | UART_INT_FE)
#define UART_RX_FLAGS       (UART_INT_RX | UART_INT_RT)
#define UART_TX_FLAGS       UART_INT_TX

//////////////// Interrupt Handlers ////////////////////////////////
extern "C" void Interrupt_UART0(void);
extern "C" void Interrupt_UART1(void);
extern "C" void Interrupt_UART2(void);
extern "C" void Interrupt_UART3(void);
extern "C" void Interrupt_UART4(void);
extern "C" void Interrupt_UART5(void);
extern "C" void Interrupt_UART6(void);
extern "C" void Interrupt_UART7(void);


UartTiva*    UartTiva::me[UART_TIVA_PORT_MAX];



UartTiva::UartTiva(uint32_t baseAddress, uint32_t uartClk, uint32_t baud, uint32_t config) :
        baseAddress(baseAddress),
        uartClk(uartClk),
        baud(baud),
        config(config),
        pClient(NULL),
        portNum(UART_TIVA_PORT_MAX)
{


}

UartTiva::~UartTiva()
{

}

int UartTiva::Init()
{
    // Make sure port is closed
    Close();

    // Clear any flags
    UARTIntClear(baseAddress, 0xFFFFFFFF);

    /// Set our port number and me pointer
    switch(baseAddress)
    {
    case UART0_BASE:
        portNum = 0;
        me[portNum] = this;
        break;
    case UART1_BASE:
        portNum = 1;
        me[portNum] = this;
        break;
    case UART2_BASE:
        portNum = 2;
        me[portNum] = this;
        break;
    case UART3_BASE:
        portNum = 3;
        me[portNum] = this;
        break;
    case UART4_BASE:
        portNum = 4;
        me[portNum] = this;
        break;
    case UART5_BASE:
        portNum = 5;
        me[portNum] = this;
        break;
    case UART6_BASE:
        portNum = 6;
        me[portNum] = this;
        break;
    case UART7_BASE:
        portNum = 7;
        me[portNum] = this;
        break;
    default:
        H_ASSERT(0); //Bad uart address
        break;
    }

    return 0;
}

void UartTiva::Open()
{
    //
    // Set the UART to interrupt whenever the TX FIFO is almost empty or
    // when any character is received.
    //
    UARTFIFOLevelSet(baseAddress, UART_FIFO_TX1_8, UART_FIFO_RX1_8);

    /// Enable Rx interrupt sources, and error indications (Tx flags done later)
    UARTIntEnable(baseAddress, UART_RX_FLAGS | UART_ERROR_FLAGS);

    /// Wire in the interrupt handler for this port
    switch(portNum)
    {
    case 0:
        UARTIntRegister(baseAddress, Interrupt_UART0);
        break;
    case 1:
        UARTIntRegister(baseAddress, Interrupt_UART1);
        break;
    case 2:
        UARTIntRegister(baseAddress, Interrupt_UART2);
        break;
    case 3:
        UARTIntRegister(baseAddress, Interrupt_UART3);
        break;
    case 4:
        UARTIntRegister(baseAddress, Interrupt_UART4);
        break;
    case 5:
        UARTIntRegister(baseAddress, Interrupt_UART5);
        break;
    case 6:
        UARTIntRegister(baseAddress, Interrupt_UART6);
        break;
    case 7:
        UARTIntRegister(baseAddress, Interrupt_UART7);
        break;
    default:
        H_ASSERT(0); // bad port, did you call Init first?
        break;
    }

    // Configure according to construction, this also enables the UART
    UARTConfigSetExpClk(baseAddress, uartClk, baud, config);
}

void UartTiva::Close()
{
    // Disable interrupts and uart
    UARTIntDisable(baseAddress, 0xFFFFFFFF);
    UARTDisable(baseAddress);
}

void UartTiva::Register(IUartClient* client)
{
    // So sorry, already have a client
    H_ASSERT(pClient == NULL);
    pClient = client;
}

void UartTiva::Unregister(IUartClient* client)
{
    // No client
    H_ASSERT(pClient != NULL);
    // Wrong client
    H_ASSERT(pClient == client);
    pClient = NULL;
}

bool UartTiva::TxFifoSpaceAvailable()
{
    return UARTSpaceAvail(baseAddress);
}

bool UartTiva::LoadTxFifo(uint8_t txByte)
{
    bool hasRoom = UARTCharPutNonBlocking(baseAddress, txByte);

    // Turn on interrupt to send it out
    UARTIntEnable(baseAddress, UART_TX_FLAGS);

    return hasRoom;
}

void UartTiva::SendTxFifo()
{
    // I'm not sure if we need this, was here in case LoadTxFifo disabled interrupts so this routine would reenable them
    H_ASSERT(false);
}

bool UartTiva::RxFifoDataAvailable()
{
    return UARTCharsAvail(baseAddress);
}

bool UartTiva::ReadRxFifo(uint8_t* pRxByte)
{
    int32_t charCode = UARTCharGetNonBlocking(baseAddress);

    // Set RxByte
    *pRxByte = static_cast<uint8_t>(charCode & 0xFF);

    // charCode will be -1 if there is nothing in the rx fifo
    return (charCode >= 0);
}

void UartTiva::OnInterrupt()
{
    //
    // Get and clear the current interrupt source(s)
    //
    uint32_t interruptStatus = UARTIntStatus(baseAddress, true);
    UARTIntClear(baseAddress, interruptStatus);

    // Check for errors
    if(interruptStatus & UART_ERROR_FLAGS)
    {
        if(pClient != NULL)
        {
            // Notify client of error
            pClient->OnUartError(interruptStatus & UART_ERROR_FLAGS);
        }
    }

    // Check for transmit space available
    if(interruptStatus & UART_TX_FLAGS)
    {
        if(pClient != NULL)
        {
            // Notify client of available space in txFifo
            pClient->OnTxFifoSpaceAvailable();
        }
    }

    // Check for receive data arrived
    if(interruptStatus & UART_RX_FLAGS)
    {
        if(pClient != NULL)
        {
            // Notify client of available data in rxFifo
            pClient->OnRxFifoDataAvailable();
        }
    }

}

/// Static Methods //////////////
void UartTiva::IntHandler(uint32_t portNumber)
{
    me[portNumber]->OnInterrupt();
}

//////////////// Interrupt Handlers ////////////////////////////////
extern "C"
{

void Interrupt_UART0(void)
{
    UartTiva::IntHandler(0);
}
void Interrupt_UART1(void)
{
    UartTiva::IntHandler(1);
}
void Interrupt_UART2(void)
{
    UartTiva::IntHandler(2);
}
void Interrupt_UART3(void)
{
    UartTiva::IntHandler(3);
}
void Interrupt_UART4(void)
{
    UartTiva::IntHandler(4);
}
void Interrupt_UART5(void)
{
    UartTiva::IntHandler(5);
}
void Interrupt_UART6(void)
{
    UartTiva::IntHandler(6);
}
void Interrupt_UART7(void)
{
    UartTiva::IntHandler(7);
}

} // extern "C"

} /* namespace HAL */
