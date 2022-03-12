/*!
 *    @file             ISerialPortDriver.h
 *    @brief            Header for ISerialPortDriver Class.
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.1 $
 *
 *    @date             $Date: 2015/05/07 14:16:30EDT $
 *
 *    @par Description 
 *                      Full serial interface including driver
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

#ifndef ISERIALPORTDRIVER_H_
#define ISERIALPORTDRIVER_H_
#include <ISerialPort.h>
#include <IDriver.h>

namespace Driver
{

class ISerialPortDriver: public ISerialPort, public IDriver
{

};

} //namespace Driver

#endif /* ISERIALPORTDRIVER_H_ */
