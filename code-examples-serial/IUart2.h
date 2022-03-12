/*!
 *    @file             $Source: IUart2.h $
 *    @brief            Header for IUart Class.
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.1 $
 *
 *    @date             $Date: 2015/05/07 13:13:27EDT $
 *
 *    @par Description
 *                      Defines base interface for driving a Uart
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
#ifndef IUART2_H_
#define IUART2_H_
#include <stdint.h>

namespace HAL
{

// Forward declares
class IUartClient;

class IUart2
{
public:
    virtual ~IUart2(){};

    /// Opens a UART
    virtual void Open() = 0;

    /// Closes a UART
    virtual void Close() = 0;

    /// Registers a Uart Client
    /// @param client Client to register
    virtual void Register(IUartClient* client) = 0;

    /// Unregisters a Uart Client
    /// @param client Client to unregister
    virtual void Unregister(IUartClient* client) = 0;


    /// Method that indicates space is available on the TX FIFO
    virtual bool TxFifoSpaceAvailable() = 0;

    /// Loads a byte into the transmit FIFO
    /// @param byte data to load for SendTxFifo()
    /// @return @c true if byte was loaded into TxFifo
    virtual bool LoadTxFifo(uint8_t txByte) = 0;

    /// Begins transmission of txFifo loaded with LoadTxFifo()
    virtual void SendTxFifo() = 0;

    /// Indicates that one or more bytes are availbie in the RxFifo
    virtual bool RxFifoDataAvailable() = 0;

    /// Reads a byte from the receive FIFO
    /// @param pRxByte pointer to return byte
    /// @return @c true if byte was returned in pRxByte
    virtual bool ReadRxFifo(uint8_t* pRxByte) = 0;
};

class IUartClient
{
public:
   virtual ~IUartClient(){};


   /// Event that happens when space is available in the UART transmit FIFO
   virtual void OnTxFifoSpaceAvailable() = 0;

   /// Event that happens when data is available to read from the UART receive FIFO
   virtual void OnRxFifoDataAvailable() = 0;

   /// Event that indicates an error
   /// @param errorCode Cause of error (implementation specific but most likely framing errors)
   virtual void OnUartError(uint32_t errorCode) = 0;

};

}// namespace HAL

#endif /* IUART2_H_ */
