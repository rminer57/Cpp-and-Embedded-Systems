/*!
 *    @file             SerialPortDriver.cpp
 *    @brief            Implementation for SerialPortDriver Class.
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.2 $
 *
 *    @date             $Date: 2015/06/03 09:34:48EDT $
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
#include <stddef.h>
#include <SerialPortDriver.h>
#include <DriverAssert.h>

D_DEFINE_THIS_MODULE("SerialPortDriver.cpp")

namespace Driver
{

SerialPortDriver::SerialPortDriver( HAL::IUart2&  uart,
                                    uint8_t* rxBuffer,
                                    size_t   rxBufferSize,
                                    uint8_t* txBuffer,
                                    size_t   txBufferSize) :
        uart(uart),
        pClient(NULL),
        rxFifo(rxBuffer, rxBufferSize),
        txFifo(txBuffer, txBufferSize),
        terminatorValue(0),
        terminatorIsSet(false)
{

}

SerialPortDriver::~SerialPortDriver()
{
}

void SerialPortDriver::Init()
{
}

void SerialPortDriver::Start()
{
}

void SerialPortDriver::Stop()
{
    Close();
}

void SerialPortDriver::Open()
{
    // Attach to UART
    uart.Register(this);

    // Open underlying uart
    uart.Open();
}

void SerialPortDriver::Close()
{
    // Close underlying uart
    uart.Close();

    // Detach from UART
    uart.Unregister(this);
    rxFifo.Flush();
    txFifo.Flush();
}

void SerialPortDriver::SetDataTerminator(uint8_t terminator)
{
    terminatorValue = terminator;
    terminatorIsSet = true;
}

void SerialPortDriver::Register(ISerialPortClient* client)
{
    // Only one currently
    D_ASSERT(pClient == NULL);
    pClient = client;
}

void SerialPortDriver::Unregister(ISerialPortClient* client)
{
   // Only one currently
   D_ASSERT(pClient != NULL);
   D_ASSERT(pClient == client);

   // Clear client
   pClient = NULL;
}

size_t SerialPortDriver::Write(const uint8_t* const data, size_t dataSize)
{
    size_t writeCount = 0;

    // Put as many bytes as possible into txFifo
    while(dataSize--)
    {
        if(txFifo.Put(data[writeCount]))
        {
            writeCount++;
        }
    }

    // Start the UART send
    if(writeCount > 0)
    {
        LoadUartTransmit();
    }

    return writeCount;
}

size_t SerialPortDriver::Read(uint8_t* data, size_t dataSize)
{
    size_t readCount = 0;
    bool terminatorFound = false;

    // Put as many bytes as possible into data or until a terminator is found
    while((dataSize--) && !terminatorFound)
    {
        if(rxFifo.Get(&data[readCount]))
        {
            // If the terminator is set, just read until terminator
            if(terminatorIsSet && (data[readCount] == terminatorValue))
            {
                terminatorFound = true;
            }
            readCount++;
        }
    }

    return readCount;
}

void SerialPortDriver::OnTxFifoSpaceAvailable()
{
    // Just try to put more bytes in TxFifo
    LoadUartTransmit();
}


void SerialPortDriver::OnRxFifoDataAvailable()
{
    bool fifoHasSpace       = true;
    bool sendDataReceived = false;

    // Remember if we were empty at the start
    bool wasEmpty = rxFifo.IsEmpty();

    // Get available characters from the uart
    while(uart.RxFifoDataAvailable() && fifoHasSpace)
    {
        uint8_t rxByte;
        D_ASSERT(uart.ReadRxFifo(&rxByte));  // assert that RxFifoDataAvailable() is not lying

        fifoHasSpace = rxFifo.Put(rxByte);

        // Check if we got a data terminator or new data
        if( terminatorIsSet && (rxByte == terminatorValue) )
        {
            sendDataReceived = true;
        }
        else if( !terminatorIsSet && wasEmpty)
        {
            sendDataReceived = true;
        }
    }

    // Tell client if our rxFifo overflows
    if(!fifoHasSpace && (pClient != NULL))
    {
        pClient->OnSerialError(ERROR_RX_BUFFER_OVERRUN);
    }

    // Tell client we received data
    if(sendDataReceived && (pClient != NULL))
    {
        pClient->OnSerialDataReceived();
    }

}

void SerialPortDriver::OnUartError(uint32_t errorCode)
{
    // Pass on this error to the client as a UART ERROR
    if(pClient != NULL)
    {
        pClient->OnSerialError(ERROR_UART);
    }
}

void SerialPortDriver::LoadUartTransmit()
{
    while( (uart.TxFifoSpaceAvailable() == true) && (txFifo.IsEmpty() == false) )
    {
        uint8_t txByte;
        txFifo.Get(&txByte);
        uart.LoadTxFifo(txByte);
    }

    // If we emptied out the TxFifo, tell the client
    if(txFifo.IsEmpty() &&  (pClient != NULL))
    {
        pClient->OnSerialDataSent();
    }
}

} /* namespace Driver */
