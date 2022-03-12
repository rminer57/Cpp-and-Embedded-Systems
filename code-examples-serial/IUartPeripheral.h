/*!
 *    @file             IUartPeripheral.h
 *    @brief            Base Interface for Uart HAL components
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.1 $
 *
 *    @date             $Date: 2015/05/07 14:18:16EDT $
 *
 *    @par Description 
 *                      Interface for UARTs from the HAL
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

#ifndef IUART_PERIPHERAL_H_
#define IUART_PERIPHERAL_H_
#include <IUart2.h>
#include <IPeripheral.h>

namespace HAL
{

/**
 * @brief Uart Peripheral
 */
class IUartPeripheral: public IUart2, public IPeripheral
{
};

}//namespace HAL



#endif /* IUART_PERIPHERAL_H_ */
