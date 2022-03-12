/*!
 *    @file             SerialPortDriver.h
 *    @brief            Header for SerialPortDriver Class.
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.1 $
 *
 *    @date             $Date: 2015/05/07 13:10:25EDT $
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

#ifndef SERIALPORTDRIVER_H_
#define SERIALPORTDRIVER_H_

#include <ISerialPortDriver.h>
#include <IUart2.h>
#include <Fifo.h>

namespace Driver
{

class SerialPortDriver: public Driver::ISerialPortDriver, public HAL::IUartClient
{
public:

    /// Constructor
    SerialPortDriver(HAL::IUart2&   uart,
                     uint8_t*       rxBuffer,
                     size_t         rxBufferSize,
                     uint8_t*       txBuffer,
                     size_t         txBufferSize);

    virtual ~SerialPortDriver();

    /// Called to initialize a driver
    void Init();

    /// Called to start a driver
    void Start();

    /// Called to stop a driver
    void Stop();

    /// Opens a serial port for communcations
    void Open();

    /// Closes the port
    void Close();

    /// Call this method to have OnSerialDataReceived event only happen when a terminal character arrives
    /// @param terminator Byte used to trigger OnSerialDataReceived() event
    void SetDataTerminator(uint8_t terminator);

    /// Registers a serial port client to receive messages
    /// @param client Pointer to a class implementing the client interface
    void Register(ISerialPortClient* client);

    /// Removes a client from the port
    /// @param client Pointer of client to remove
     void Unregister(ISerialPortClient* client);

    /// Writes data out of the serial port
    /// @param data Pointer to data bytes
    /// @param dataSize number of bytes to send
    /// @return number of bytes actually written
    size_t Write(uint8_t const * const data, size_t dataSize);

    /// Reads data from serial port
    /// @param data Pointer to receive data from port
    /// @param dataSize maximum bytes to read
    /// @return number of bytes actually transferred into data
    size_t Read(uint8_t* data, size_t dataSize);


    /// Event that happens when space is available in the UART transmit FIFO
    void OnTxFifoSpaceAvailable();

    /// Event that happens when data is available to read from the UART receive FIFO
    void OnRxFifoDataAvailable();

    /// Event that indicates an error
    /// @param errorCode Cause of error (implementation specific but most likely framing errors)
    void OnUartError(uint32_t errorCode);

private:
    void LoadUartTransmit();

    HAL::IUart2&                uart;
    ISerialPortClient*          pClient;
    Utility::Fifo<uint8_t>      rxFifo;
    Utility::Fifo<uint8_t>      txFifo;
    uint8_t                     terminatorValue;
    bool                        terminatorIsSet;
};

} /* namespace Driver */
#endif /* SERIALPORTDRIVER_H_ */
