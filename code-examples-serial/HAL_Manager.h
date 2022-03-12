/*!
 *    @file             HAL_Manager.h
 *    @brief            Header for HAL_Manager Class.
 *
 *    @author           $Author: Chi Pham (phamc) $
 *
 *    @version          $Revision: 1.3 $
 *
 *    @date             $Date: 2015/07/07 10:58:43EDT $
 *
 *    @par Description
 *                      This is HAL manager for the DUFB DUCP
 *    Timer Allocation:
 *      - PL4, T0CCP0, IFS, Counter
 *      - PL5  T0CCP1, DP-Hall 1, Counter (Tach)
 *      - PL6, T1CCP0, OFSU, Counter
 *      - PL7, T1CCP1, VGP-Hall 1, Counter (Tach)
 *      - PM0, T2CCP0, UFPS, Counter
 *      - internal, T2CCP1, Heater Control, One Shot Software Timer
 *      - PM2, T3CCP0, IP Step, PWM
 *      - PM3, T3CCP1, BCP Step, PWM
 *      - PM4, T4CCP0, WP Step, PWM
 *      - PM5, T4CCP1, UFP Step, PWM
 *      - PM6, T5CCP0, SPARE
 *      - PM7, T5CCP1, CP 5KHz, PWM
 *      - internal, T6A, 100 ms Timer
 *      - internal, T6B, 10 ms Timer
 *      - internal, T7A, DP Hall 1 Timer
 *      - internal, T7B, Valve Control Timer
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
#ifndef HAL_MANAGER_H_
#define HAL_MANAGER_H_


#include <HAL_ID.h>  // This file contains the IO names for the board
#include <IOutputPin.h>
#include <IInputPin.h>
#include <ICounter.h>
#include <ITimer.h>
#include <ITimerShared.h>
#include <IPwm.h>
#include <IUartPeripheral.h>
#include <IAdcPeripheral.h>
#include <ISpi.h>
#include <ICanPeripheral.h>
#include <IEepromPeripheral.h>
//include <inc/hw_nvic.h>
namespace HAL
{

class HAL_Manager
{
public:

    /// This function is called by BSP to initialize all the peripherals for a board.
    static void Init();

    /// @brief Used to start any interrupts in the HAL
    static void Start();

    /// Use this method to get output pins by ID for a board
    static IOutputPin* GetOutputPin(HAL_ID::OutputPinID ID);

    /// Use this method to get input pins by ID for a board
    static IInputPin* GetInputPin(HAL_ID::InputPinID ID);

    /// Returns a pointer to a counter by ID
    static ICounter* GetCounter(HAL_ID::CounterID ID);

    /// Returns a pointer to a timer by ID
    static ITimer* GetTimer(HAL_ID::TimerID ID);

    /// Shared timer
    static ITimerShared* GetTimerShared(HAL::HAL_ID::TimerID ID);

    /// Returns a pointer to a PWM by ID
    static IPwm* GetPwm(HAL_ID::PwmID ID);

    /// Returns a pointer to a UART by ID
    static IUartPeripheral* GetUart(HAL_ID::UartID ID);

    /// Returns a pointer to a ADC by ID
    static IAdcPeripheral* GetAdc(HAL_ID::AdcID ID);

    /// Returns a pointer to a CAN peripheral by ID
    static ICanPeripheral* GetCan(HAL_ID::CanID ID);

    /// Returns an EEPROM peripheral
    static IEepromPeripheral* GetEeprom(HAL_ID::EepromID ID);


	/// Returns a pointer to sw upgrade peripheral by ID
    static IPeripheral * GetSWUpgradePeripheral(HAL_ID::SWUpgradeID ID);	
};

} /* namespace HAL */
#endif /* HAL_MANAGER_H_ */
