/*!
 *    @file             ISerialPort.h
 *    @brief            Header for SerialPort Class.
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.1 $
 *
 *    @date             $Date: 2015/05/07 14:10:02EDT $
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

#ifndef ISERIALPORT_H_
#define ISERIALPORT_H_
#include <stddef.h>
#include <stdint.h>

namespace Driver
{

// Forward Declares
class ISerialPortClient;

class ISerialPort
{
public:
    enum Error
    {
        ERROR_UART,                 // Error from underlying Uart, parity, framing, etc..
        ERROR_RX_BUFFER_OVERRUN     // Read was not called often enough or buffer not big enough
    };


    virtual ~ISerialPort(){};

    /// Opens a serial port for communications
    virtual void Open() = 0;

    /// Closes the port
    virtual void Close() = 0;

    /// Call this method to have OnSerialDataReceived event only happen when a terminal character arrives
    /// @param terminator Byte used to trigger OnSerialDataReceived() event
    virtual void SetDataTerminator(uint8_t terminator) = 0;

    /// Registers a serial port client to receive messages
    /// @param client Pointer to a class implementing the client interface
    virtual void Register(ISerialPortClient* client) = 0;

    /// Removes a client from the port
    /// @param client Pointer of client to remove
    virtual void Unregister(ISerialPortClient* client) = 0;

    /// Writes data out of the serial port
    /// @param data Pointer to data bytes
    /// @param dataSize number of bytes to send
    /// @return number of bytes actually written
    virtual size_t Write(uint8_t const * const data, size_t dataSize) = 0;


    /// Reads data from serial port
    /// @param data Pointer to receive data from port
    /// @param dataSize maximum bytes to read
    /// @return number of bytes actually transferred into data
    virtual size_t Read(uint8_t* data, size_t dataSize) = 0;
};

class ISerialPortClient
{
public:
    virtual ~ISerialPortClient(){};

    /// Event that indicates all data writes have been satisfied
    virtual void OnSerialDataSent() = 0;

    /// Event that is fired when serial port is no longer empty or when a data terminator character is received
    virtual void OnSerialDataReceived() = 0;

    /// An error has occurred
    virtual void OnSerialError(ISerialPort::Error error) = 0;

};

} // namespace Driver


#endif /* ISERIALPORT_H_ */
