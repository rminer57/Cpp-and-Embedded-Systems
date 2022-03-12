/*!
 *    @file             $Source: IDriver.h $
 *    @brief            Header for driver interface.
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.1 $
 *
 *    @date             $Date: 2015/05/07 13:14:25EDT $
 *
 *    @par Description 
 *                      This is the common interface to all drivers in the system.
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

#ifndef IDRIVER_H_
#define IDRIVER_H_

namespace Driver
{

/**
 * @brief Driver interface
 * This interface must be implemented by every device driver in the system.
 */
class IDriver
{
public:
    virtual ~IDriver(){};


    /// Called to initialize a driver
    virtual void Init() = 0;

    /// Called to start a driver
    virtual void Start() = 0;

    /// Called to stop a driver
    virtual void Stop() = 0;
};

}//namespace Driver

#endif /* IDRIVER_H_ */
