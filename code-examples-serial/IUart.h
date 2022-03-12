/*!
 *    @file             $Source: IUart.h $
 *    @brief            Header for IUart Class.
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.1 $
 *
 *    @date             $Date: 2015/05/07 13:41:07EDT $
 *
 *    @par Description
 *                      Defines base interface for driving UI Uart
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
#ifndef IUART_H_
#define IUART_H_

#include <IPeripheral.h>
#include "qp_port.h"

namespace HAL
{

class IUart : public IPeripheral
{
public:
    virtual ~IUart(){};
    virtual int Init() = 0;
    virtual int WriteBytes(const uint8_t *pcBuf, uint32_t ui32Len) = 0;

    /// Registers a client to receive uart messages
    virtual void Register(QP::QActive* client) = 0;

    /// Unregisters a client from receiving uart messages
    virtual void Unregister(QP::QActive* client) = 0;
};

}// namespace HAL

#endif /* IUART_H_ */
