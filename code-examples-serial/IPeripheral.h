/*!
 *    @file             $Source: IPeripheral.h $
 *    @brief            Base Interface for HAL components
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.1 $
 *
 *    @date             $Date: 2015/05/07 13:10:41EDT $
 *
 *    @par Description 
 *                      Since the HAL abstracts controller peripherals, all HAL pieces should implement this interface
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

#ifndef IPERIPHERAL_H_
#define IPERIPHERAL_H_

namespace HAL
{

/**
 * @brief Base Peripheral interface
 * This interface must be implemented by every HAL component in the system.
 */
class IPeripheral
{
public:
    virtual ~IPeripheral(){};


    /// Called to initialize a peripheral
    virtual int Init() = 0;
};

}//namespace Driver



#endif /* IPERIPHERAL_H_ */
