/*!
 *    @file             DriverManager.h
 *    @brief            Header for DriverManager Class.
 *
 *    @author           $Author: bill tonnies (tonniesb1) $
 *
 *    @version          $Revision: 1.2 $
 *
 *    @date             $Date: 2015/05/08 12:05:17EDT $
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

#ifndef DRIVERMANAGER_H_
#define DRIVERMANAGER_H_

#include <IFlowSensorDriver.h>
#include <IMotorDriver.h>
#include <IPwmMotorDriver.h>
#include <ILedDriver.h>
#include <ISwitchDriver.h>
#include <IPressureSensorDriver.h>
#include <ICondoSensorDriver.h>
#include <ITempSensorDriver.h>
#include <ITachometerDriver.h>
#include <IBitBangerDriver.h>
#include <IMuxDriver.h>
#include <ICoilDriver.h>
#include <DriverID.h>
#include <IAdcDriver.h>
#include <IChipSelectDriver.h>
#include <ISerialPortDriver.h>
#include <IIpcDriver.h>
#include <IHallEffectSensorDriver.h>
#include <ILevelSensorDriver.h>
#include <IMemoryDriver.h>
#include <IPidController.h>
#include <MotorSpeedControlDriver.h>

namespace Driver
{
class DriverManager
{
public:

    /// This function is called by application to initialize all drivers
    static void Init();

    /// This function is called by the application to start all of the drivers
    static void StartAll();

    /// Use this method to get a flow sensor driver by ID
    static IFlowSensorDriver* GetFlowSensorDriver(Driver::ID ID);

    /// Use this method to get a motor driver by ID
    static IMotorDriver* GetMotorDriver(Driver::ID ID);
    static IPwmMotorDriver* GetPwmMotorDriver(Driver::ID ID);

    /// Use this method to get an LED driver by ID
    static ILedDriver*  GetLedDriver(Driver::ID ID);

    /// Use this method to get a Switch Driver by ID
    static ISwitchDriver*  GetSwitchDriver(Driver::ID ID);

    /// Use this method to get a Mux Driver by ID
    static IMuxDriver* GetMuxDriver(Driver::ID ID);

    static IChipSelectDriver* GetChipSelectDriver(Driver::ID ID);

    /// Use this method to get a Pressure Driver by ID
    static IPressureSensorDriver* GetPressureSensorDriver(Driver::ID ID);

    /// Use this method to get a Condo Driver by ID
    static ICondoSensorDriver* GetCondoSensorDriver(Driver::ID ID);

    /// Use this method to get a Temperature Driver by ID
    static ITempSensorDriver* GetTempSensorDriver(Driver::ID ID);

    static ITachometerDriver* GetTachometerDriver(Driver::ID ID);

    static IBitBangerDriver* GetBitBangerDriver(Driver::ID ID);
    
    /// Use this method to get a Coil Driver by ID
    static ICoilDriver* GetCoilDriver(Driver::ID ID);

    /// Returns a AdcDriver which is an IAdcDriver instead of an IAdcPeripheral
    static IAdcDriver*  GetAdcDriver(Driver::ID ID);

    /// Returns a serial port driver by ID
    static ISerialPortDriver* GetSerialPortDriver(Driver::ID ID);

    /// Returns a CAN port driver by ID
    static IIpcDriver* GetIpcDriver(Driver::ID ID);

    /// Returns a Hall Effect Sensor driver by ID
    static Driver::IHallEffectSensorDriver* GetHallEffectSensorDriver(Driver::ID ID);

    /// Returns a level detect driver by ID
    static Driver::ILevelSensorDriver* GetLevelSensorDriver(Driver::ID ID);

    /// Returns a memory driver by ID
    static Driver::IMemoryDriver* GetMemoryDriver(Driver::ID ID);

    /// @brief Returns a PID controller by id
    /// @brief Note: This is not a driver but access to the PID controller within
    /// @brief any driver which also isA type of PID controller
    /// @param ID driver ID
    static Driver::IPidController* GetPidController(Driver::ID ID);

private:
    /// @brief Private method which returns an instance of the BLDC speed control drivers
    /// @param ID driver ID
    static Driver::MotorSpeedControlDriver* GetMotorSpeedControlDriver(Driver::ID ID);
};

}// namespace Driver


#endif /* DRIVERMANAGER_H_ */
