/*!
 *    @file             HAL_Manager_dialysate_control_DK_TM4C123G.cpp
 *    @brief            HAL manager implementation
 *
 *    @author           $Author: Chi Pham (phamc) $
 *
 *    @version          $Revision: 1.7 $
 *
 *    @date             $Date: 2015/07/07 10:58:42EDT $
 *
 *    @par Description
 *                      HAL manager implementation for the Tiva DK board for dialysate control
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

#include <cstddef>
#include <bsp.h>
#include <config.h>
#include <Utility.h>

#include <HAL_Manager.h>
#include <HAL_ID.h>
#include <HAL_Assert.h>

// HAL Specific IO
#include <OutputPinTiva.h>
#include <InputPinTiva.h>
#include <CounterTiva.h>
#include <TimerTiva.h>
#include <PwmTiva.h>
#include <UartTiva.h>
#include <AdcTiva.h>
#include <PwmTimerTiva.h>
#include <SpiTiva.h>
#include <TimerTivaShared.h>
#include <CanTiva.h>
#include <EepromTiva.h>

// Tivaware includes
#include <inc/hw_nvic.h>
#include <inc/hw_memmap.h>
#include <driverLib/sysctl.h>
#include <driverLib/gpio.h>
#include <driverLib/timer.h>
#include <driverLib/pwm.h>
#include <driverLib/ssi.h>
#include <driverLib/uart.h>


H_DEFINE_THIS_MODULE("HAL_Manager.cpp")

namespace HAL
{

// Timers, counters and PWM all use timer resources separately, and split
// timers are common across different functions. However, the Tivaware
// timer API expects the configuration of split timers to occur at the
// same time, which breaks the HAL manager model. The enums below allow
// the consistent setting up of timers/PWMs/counters in Tivaware
enum timerConfig
{
	TIMER0_CFG = (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_CAP_TIME_UP  | TIMER_CFG_B_CAP_TIME_UP),
	TIMER1_CFG = (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_CAP_TIME_UP  | TIMER_CFG_B_PWM),
	TIMER2_CFG = (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_CAP_COUNT_UP | TIMER_CFG_B_CAP_COUNT_UP),
	TIMER3_CFG = (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC     | TIMER_CFG_B_PWM),
	TIMER4_CFG = (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PWM          | TIMER_CFG_B_PWM),
	TIMER5_CFG = (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_CAP_COUNT_UP | TIMER_CFG_B_CAP_COUNT_UP),
	TIMER6_CFG = (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC     | TIMER_CFG_B_PERIODIC),
	TIMER7_CFG = (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_ONE_SHOT     | TIMER_CFG_B_ONE_SHOT),
};

void HAL_Manager::Init()
{
    ICounter* pCounter = NULL;
    ITimer*   pTimer   = NULL;


    // Init all the input pins
    for(int idx = 0; idx < HAL::HAL_ID::INPUT_PIN_ID_MAX; ++idx)
    {
        IInputPin* pPin = GetInputPin(static_cast<HAL::HAL_ID::InputPinID>(idx));
        pPin->Init();
    }

    // Init all the counters
    for(int idx = 0; idx < HAL::HAL_ID::COUNTER_ID_MAX; ++idx)
    {
        pCounter = GetCounter(static_cast<HAL::HAL_ID::CounterID>(idx));
        pCounter->Init();
    }

    // Init all the timers
    for(int idx = 0; idx < HAL::HAL_ID::TIMER_ID_MAX; ++idx)
    {
        pTimer = GetTimer(static_cast<HAL::HAL_ID::TimerID>(idx));
        pTimer->Init();
    }

    // Init all the PWMs
    for(int idx = 0; idx < HAL::HAL_ID::PWM_ID_MAX; ++idx)
    {
        IPwm* pPwm = GetPwm(static_cast<HAL::HAL_ID::PwmID>(idx));
        pPwm->Init();
    }

    // Init all the ADCs
    for(int idx = 0; idx < HAL::HAL_ID::ADC_ID_MAX; ++idx)
    {
        IAdcPeripheral* pAdc = GetAdc(static_cast<HAL::HAL_ID::AdcID>(idx));
        H_ASSERT(pAdc != NULL);
        pAdc->Init();
    }

    // Init all the Uarts
    for(int idx = 0; idx < HAL::HAL_ID::UART_ID_MAX; ++idx)
    {
        IUartPeripheral* pUart = GetUart(static_cast<HAL::HAL_ID::UartID>(idx));
        H_ASSERT(pUart != NULL);
        pUart->Init();
    }
    // Init all the EEPROMs
    for(int idx = 0; idx < HAL::HAL_ID::EEPROM_ID_MAX; ++idx)
    {
        IEepromPeripheral* pEeprom = GetEeprom(static_cast<HAL::HAL_ID::EepromID>(idx));
        if (pEeprom != NULL)
        {
            pEeprom->Init();
        }
    }
}

void HAL_Manager::Start()
{
    ITimer*   pTimer   = NULL;

    // Arm shared periodic timers at their proper rates
    pTimer= HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
    pTimer->ArmPeriodic(100000); // 100ms timer

    pTimer= HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_10MS);
    H_ASSERT(pTimer != NULL);
    pTimer->ArmPeriodic(10000); // 10ms timer

    pTimer= HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_1MS);
    H_ASSERT(pTimer != NULL);
    pTimer->ArmPeriodic(1000); // 1ms timer
    // Enable the 11ms timer as a source for ADCs
    static_cast<TimerTiva *>(pTimer)->EnableADCTrigger(true);

}

IOutputPin* HAL_Manager::GetOutputPin(HAL::HAL_ID::OutputPinID ID)
{
    IOutputPin* returnVal = NULL;

    switch (ID)
    {
    // LED
    case HAL::HAL_ID::OUTPUT_PIN_ID_U301_ALIVE:
        static OutputPinTiva PL2(GPIO_PORTL_BASE, GPIO_PIN_2);
        returnVal =  &PL2;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_COM_RCVD_PP:
        static OutputPinTiva PL3(GPIO_PORTL_BASE, GPIO_PIN_3);
        returnVal =  &PL3;
        break;

    // Blood Pump
    case HAL::HAL_ID::OUTPUT_PIN_ID_BPDIR:
        static OutputPinTiva PF1(GPIO_PORTF_BASE, GPIO_PIN_1);
        returnVal =  &PF1;
        break;

    // Heparin Syringe
    case HAL::HAL_ID::OUTPUT_PIN_ID_HSDIR:
        static OutputPinTiva PG1(GPIO_PORTG_BASE, GPIO_PIN_1);
        returnVal =  &PG1;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_HSRST:
        static OutputPinTiva PG3(GPIO_PORTG_BASE, GPIO_PIN_3);
        returnVal =  &PG3;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_HSSLEEP:
        static OutputPinTiva hssleep(GPIO_PORTG_BASE, GPIO_PIN_4);
        returnVal =  &hssleep;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_DECAY:
        static OutputPinTiva hsdecay(GPIO_PORTM_BASE, GPIO_PIN_2);
        returnVal =  &hsdecay;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_MODE0:
        static OutputPinTiva hsmode0(GPIO_PORTM_BASE, GPIO_PIN_3);
        returnVal =  &hsmode0;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_MODE1:
        static OutputPinTiva hsmode1(GPIO_PORTM_BASE, GPIO_PIN_4);
        returnVal =  &hsmode1;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_MODE2:
        static OutputPinTiva hsmode2(GPIO_PORTM_BASE, GPIO_PIN_5);
        returnVal =  &hsmode2;
        break;

    //
    // DRV8860
    //
    case HAL::HAL_ID::OUTPUT_PIN_ID_VALVE_DIN:
        static OutputPinTiva PQ2(GPIO_PORTQ_BASE, GPIO_PIN_2);
        returnVal =  &PQ2;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_VALVE_CLK:
        static OutputPinTiva PQ0(GPIO_PORTQ_BASE, GPIO_PIN_0);
        returnVal =  &PQ0;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_VALVE_LATCH_L:
        static OutputPinTiva PQ1(GPIO_PORTQ_BASE, GPIO_PIN_1);
        returnVal =  &PQ1;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_VALVE_EN:
        GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_5);         // no pin access to PH5
        static OutputPinTiva PH5_Dummy1(GPIO_PORTH_BASE, GPIO_PIN_5);
        returnVal =  &PH5_Dummy1;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_PNEUMATIC_EN:                   // no pin access to PH5
        GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_5);
        static OutputPinTiva PH5_Dummy6(GPIO_PORTH_BASE, GPIO_PIN_5);
        returnVal =  &PH5_Dummy6;
        break;

    //
    // Pressure Sensors
    //
    case HAL::HAL_ID::OUTPUT_PIN_ID_S0_CP:  // Pressure Sensors (Differential Amplifier) Select 0 ADC Mux
        static OutputPinTiva PN0(GPIO_PORTN_BASE, GPIO_PIN_0);
        returnVal =  &PN0;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_S1_CP:  // Pressure Sensors (Differential Amplifier) Select 1 ADC Mux
        static OutputPinTiva PN1(GPIO_PORTN_BASE, GPIO_PIN_1);
        returnVal =  &PN1;
        break;

    // Therapy Buzzer
    case HAL::HAL_ID::OUTPUT_PIN_ID_BUZZER_CP:
        static OutputPinTiva PG7(GPIO_PORTG_BASE, GPIO_PIN_7);
        returnVal =  &PG7;
        break;

    //
    // board-to-board connector output
    //
    case HAL::HAL_ID::OUTPUT_PIN_ID_TBCP_GUIB:
        static OutputPinTiva PL4(GPIO_PORTL_BASE, GPIO_PIN_4);
        returnVal =  &PL4;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_TBCP_DUFB:
        static OutputPinTiva PL6(GPIO_PORTL_BASE, GPIO_PIN_6);
        returnVal =  &PL6;
        break;

    //
    // board-to-board connector output
    //
    case HAL::HAL_ID::OUTPUT_PIN_ID_BP_LIGHT:
        static OutputPinTiva PP3(GPIO_PORTP_BASE, GPIO_PIN_3);
        returnVal =  &PP3;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_MUTE_LIGHT:
        static OutputPinTiva PP4(GPIO_PORTP_BASE, GPIO_PIN_4);
        returnVal =  &PP4;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_STANDBY_LIGHT:
        static OutputPinTiva PP5(GPIO_PORTP_BASE, GPIO_PIN_5);
        returnVal =  &PP5;
        break;

    //
    // VGP Outputs
    //
    case HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN1:
        static OutputPinTiva vgp_EN1(GPIO_PORTQ_BASE, GPIO_PIN_4);
        returnVal =  &vgp_EN1;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN2:
        static OutputPinTiva vgp_EN2(GPIO_PORTQ_BASE, GPIO_PIN_5);
        returnVal =  &vgp_EN2;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN3:
        static OutputPinTiva vgp_EN3(GPIO_PORTQ_BASE, GPIO_PIN_6);
        returnVal =  &vgp_EN3;
        break;
    case HAL::HAL_ID::OUTPUT_PIN_ID_VGP_MODE:
        static OutputPinTiva vgp_MODE(GPIO_PORTA_BASE, GPIO_PIN_2);
        returnVal =  &vgp_MODE;
        break;

    default:
        H_ASSERT(0);
        break;
    }

    return returnVal;
}


IInputPin* HAL_Manager::GetInputPin(HAL::HAL_ID::InputPinID ID)
{
    IInputPin* returnVal = NULL;

    switch (ID)
    {
    // Connector Switch Inputs
    case HAL::HAL_ID::INPUT_PIN_ID_VALVE_DOUT:
        static InputPinTiva PQ3(GPIO_PORTQ_BASE, GPIO_PIN_3);
        returnVal =  &PQ3;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_PNEUMATIC_FAULT_L:
        GPIOPinTypeGPIOInput(GPIO_PORTH_BASE, GPIO_PIN_6);              // no pin access to PH6
        static InputPinTiva PH6_Dummy1(GPIO_PORTH_BASE, GPIO_PIN_6);    // no pin access to PH6
        returnVal =  &PH6_Dummy1;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_VALVE_FAULT_L:
        GPIOPinTypeGPIOInput(GPIO_PORTH_BASE, GPIO_PIN_6);              // no pin access to PH6
        static InputPinTiva PH6_Dummy2(GPIO_PORTH_BASE, GPIO_PIN_6);    // no pin access to PH6
        returnVal =  &PH6_Dummy2;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_AABSAIR_CP:
        static InputPinTiva aabsair(GPIO_PORTK_BASE, GPIO_PIN_6, false);
        returnVal =  &aabsair;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_VABSAIR_CP:
        static InputPinTiva vabsair(GPIO_PORTK_BASE, GPIO_PIN_3, false);
        returnVal =  &vabsair;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_DUFB_TBCP:
        static InputPinTiva PL5(GPIO_PORTL_BASE, GPIO_PIN_5);
        returnVal =  &PL5;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_KEYPAD_STAND_BY_CP:
        static InputPinTiva PH5(GPIO_PORTH_BASE, GPIO_PIN_0, true, INPUT_PIN_HANDLER_BOTH_EDGES);
        returnVal =  &PH5;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_KEYPAD_MUTE_TOGGLE_CP:
        static InputPinTiva PH1(GPIO_PORTH_BASE, GPIO_PIN_1, true, INPUT_PIN_HANDLER_BOTH_EDGES);
        returnVal =  &PH1;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_KEYPAD_BLOOD_PUMP_OFF_CP:
        static InputPinTiva PH2(GPIO_PORTH_BASE, GPIO_PIN_2, true, INPUT_PIN_HANDLER_BOTH_EDGES);
        returnVal =  &PH2;
        break;        // Blood Pump
    case HAL::HAL_ID::INPUT_PIN_ID_BPPOS_W:
        static InputPinTiva bppos_w(GPIO_PORTD_BASE, GPIO_PIN_1, true, INPUT_PIN_HANDLER_BOTH_EDGES);
        returnVal =  &bppos_w;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_BPPOS_S:
        static InputPinTiva bppos_s(GPIO_PORTD_BASE, GPIO_PIN_2, true, INPUT_PIN_HANDLER_BOTH_EDGES);
        returnVal =  &bppos_s;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_BPDS:
        static InputPinTiva bpds(GPIO_PORTD_BASE, GPIO_PIN_3, true, INPUT_PIN_HANDLER_BOTH_EDGES);
        returnVal =  &bpds;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_BPT:
        static InputPinTiva bpt(GPIO_PORTD_BASE, GPIO_PIN_0);
        returnVal =  &bpt;
        break;

    case HAL::HAL_ID::INPUT_PIN_ID_HS_HOME_L:
        static InputPinTiva PG2(GPIO_PORTG_BASE, GPIO_PIN_2, false);
        returnVal =  &PG2;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_HS_POS:
        static InputPinTiva PG5(GPIO_PORTG_BASE, GPIO_PIN_5, false);
        returnVal =  &PG5;
        break;

    case HAL::HAL_ID::INPUT_PIN_ID_VGP_OTW_L:
        static InputPinTiva vgp_OTW_L(GPIO_PORTN_BASE, GPIO_PIN_4);
        returnVal =  &vgp_OTW_L;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_VGP_FAULT_L:
        static InputPinTiva vgp_FAULT_L(GPIO_PORTN_BASE, GPIO_PIN_5);
        returnVal =  &vgp_FAULT_L;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL2_CP:
        static InputPinTiva vgp_HALL2_CP(GPIO_PORTA_BASE, GPIO_PIN_5, false, INPUT_PIN_HANDLER_BOTH_EDGES);
        returnVal =  &vgp_HALL2_CP;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL3_CP:
        static InputPinTiva vgp_HALL3_CP(GPIO_PORTB_BASE, GPIO_PIN_3, false, INPUT_PIN_HANDLER_BOTH_EDGES);
        returnVal =  &vgp_HALL3_CP;
        break;
    case HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL1_CP:
        static InputPinTiva vgp_HALL1_CP(GPIO_PORTA_BASE, GPIO_PIN_4, false, INPUT_PIN_HANDLER_BOTH_EDGES);
        returnVal =  &vgp_HALL1_CP;
        break;

    default:
        H_ASSERT(0);
        break;
    }

    return returnVal;
}


ICounter* HAL_Manager::GetCounter(HAL::HAL_ID::CounterID ID)
{
    ICounter* returnVal = NULL;

    switch (ID)
    {
    case HAL::HAL_ID::COUNTER_ID_TACH_BP:
        // This is T0CCP0
        static CounterTiva PD0(TIMER0_BASE, TIMER0_CFG, TIMER_A);
        returnVal =  &PD0;
        break;
    case HAL::HAL_ID::COUNTER_ID_POS1_BP:
        // This is T0CCP1
        static CounterTiva PD1(TIMER0_BASE, TIMER0_CFG, TIMER_B);
        returnVal =  &PD1;
        break;
    case HAL::HAL_ID::COUNTER_ID_POS2_BP:
        // This is T1CCP0
        static CounterTiva PD2(TIMER1_BASE, TIMER1_CFG, TIMER_A);
        returnVal =  &PD2;
        break;
    case HAL::HAL_ID::COUNTER_ID_ENCODER1_HS:
        // This is T2CCP0
        static CounterTiva PM0(TIMER2_BASE, TIMER2_CFG, TIMER_A);
        returnVal =  &PM0;
        break;
    case HAL::HAL_ID::COUNTER_ID_ENCODER2_HS:
        // This is T2CCP1
        static CounterTiva PM1(TIMER2_BASE, TIMER2_CFG, TIMER_B);
        returnVal =  &PM1;
        break;
    case HAL::HAL_ID::COUNTER_ID_TACH_VGP:
        // This is T5CCP1, PB3
        static CounterTiva counterTachVGP(TIMER5_BASE, TIMER5_CFG, TIMER_B);
        returnVal =  &counterTachVGP;
        break;
    default:
        H_ASSERT(0);
        break;
    }

    return returnVal;
}

ITimer* HAL_Manager::GetTimer(HAL::HAL_ID::TimerID ID)
{
    ITimer* returnVal = NULL;

    switch (ID)
    {
    case HAL::HAL_ID::TIMER_ID_100MS:
        // This Timer6A
        static TimerTiva trigger100ms(TIMER6_BASE, TIMER6_CFG, TIMER_A, BSP_CLOCK_FREQUENCY);
        returnVal =  &trigger100ms;
        break;
    case HAL::HAL_ID::TIMER_ID_10MS:
        // This is Timer6B
        static TimerTiva trigger10ms(TIMER6_BASE, TIMER6_CFG, TIMER_B, BSP_CLOCK_FREQUENCY);
        returnVal =  &trigger10ms;
        break;
    case HAL::HAL_ID::TIMER_ID_1MS:
        // This is Timer 3A
        static TimerTiva timer1ms(TIMER3_BASE, TIMER3_CFG, TIMER_A, BSP_CLOCK_FREQUENCY);
        returnVal =  &timer1ms;
        break;
    case HAL::HAL_ID::TIMER_ID_VALVE_CTRL:
        // Timer7B
        static TimerTiva valveCtrlTimer(TIMER7_BASE, TIMER7_CFG, TIMER_B, BSP_CLOCK_FREQUENCY);
        returnVal =  &valveCtrlTimer;
        break;
    case HAL::HAL_ID::TIMER_ID_SHARED:
        returnVal = GetTimerShared(HAL::HAL_ID::TIMER_ID_SHARED);
        break;
    default:
        H_ASSERT(false);
        break;
    }

    return returnVal;
}

ITimerShared* HAL_Manager::GetTimerShared(HAL_ID::TimerID ID)
{
    ITimerShared* returnVal = NULL;
    static TimerTivaShared sharedTimer(NVIC_ST_CTRL, BSP_CLOCK_FREQUENCY);  // shared timer singleton
    switch (ID)
    {
    case HAL::HAL_ID::TIMER_ID_SHARED:
        returnVal = &sharedTimer;
        break;
    default:
        break;
    }

    return returnVal;
}

IAdcPeripheral* HAL_Manager::GetAdc(HAL::HAL_ID::AdcID ID)
{
    IAdcPeripheral* returnVal = NULL;
    uint32_t reference = ADC_REF_EXT_3V;

    // Switch to internal reference if not running on TBHB
    if(CONFIG_USE_EVAL_BOARD())
    {
        reference = ADC_REF_INT;
    }

    switch (ID)
    {
    case HAL::HAL_ID::ADC_ID_PRESSURE:   // pressure
    {
#ifdef USE_NEW_SEQUENCE  // Note:  Needs ADC1_BASE configured in pinmux
        uint32_t adcStepConfigs[HAL::HAL_ID::ADC_CHAN_PRESSURE_MAX];
        adcStepConfigs[HAL::HAL_ID::ADC_CHAN_PRESSURE_AIPS]= ADC_CTL_CH0;                               // ain0 PE3
        adcStepConfigs[HAL::HAL_ID::ADC_CHAN_PRESSURE_VPS]= ADC_CTL_CH0;                                // ain0 PE3
        adcStepConfigs[HAL::HAL_ID::ADC_CHAN_PRESSURE_AOPS]= ADC_CTL_CH0 | ADC_CTL_IE | ADC_CTL_END;    // ain0 PE3

        HAL::TivaADC_SeqConfig adcConfig = { ADC_TRIGGER_PROCESSOR,        //.trigger
                                             HAL::ADC_PRI3,                //.priority
                                             &adcStepConfigs[0],           //.stepConfigs
                                             ARRAY_DIM(adcStepConfigs)};   //.stepConfigsSize
        ///
        /// Todo: Talk to TI to find out why we cant enable ADC1
        /// in the pinmux s/w without causing massive changes/conflicts
        /// within the pinfile
        ///
        SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC1);
        static AdcTiva adcPressure(ADC1_BASE, HAL::ADC_SS1, &adcConfig);
#else
        uint32_t adcStepConfigs[1] = { ADC_CTL_CH0 | ADC_CTL_IE | ADC_CTL_END};                         //  AIN0 Pin12 PE3
        HAL::TivaADC_SeqConfig adcConfig = { ADC_TRIGGER_PROCESSOR,        //.trigger by processor since it needs to be sync'd with mux
                                             HAL::ADC_PRI3,                //.priority
                                             &adcStepConfigs[0],           //.stepConfigs
                                             ARRAY_DIM(adcStepConfigs)};   //.stepConfigsSize

        static AdcTiva adcPressure(ADC0_BASE, HAL::ADC_SS3, &adcConfig, reference);
#endif
            returnVal =  &adcPressure;
            break;
    }
    case HAL::HAL_ID::ADC_ID_LINE_CLAMP:
    {
        uint32_t adcStepConfigs[HAL_ID::ADC_CHAN_LINE_CLAMP_MAX];
        adcStepConfigs[HAL_ID::ADC_CHAN_LINE_CLAMP_VLCS_CP] = ADC_CTL_CH3;                             // PE0, AIN3
        adcStepConfigs[HAL_ID::ADC_CHAN_LINE_CLAMP_ALCS_CP] = ADC_CTL_CH4 | ADC_CTL_IE | ADC_CTL_END;  // PD7, AIN4

        HAL::TivaADC_SeqConfig adcConfig = { ADC_TRIGGER_TIMER,            //.trigger Tied to 1ms timer, see ::Start()
                                             HAL::ADC_PRI2,                //.priority
                                             &adcStepConfigs[0],           //.stepConfigs
                                             ARRAY_DIM(adcStepConfigs)};   //.stepConfigsSize

        static AdcTiva adcLineClamp(ADC0_BASE, HAL::ADC_SS2, &adcConfig, reference);
        returnVal =  &adcLineClamp;
        break;
    }
    case HAL::HAL_ID::ADC_ID_BLOOD_SENSOR:
    {
        uint32_t adcStepConfigs[HAL_ID::ADC_CHAN_BLOOD_SENSOR_MAX];
        adcStepConfigs[HAL_ID::ADC_CHAN_BLOOD_SENSOR_AABS_BLO_CP] = ADC_CTL_CH1;                             // PE2, AIN1
        adcStepConfigs[HAL_ID::ADC_CHAN_BLOOD_SENSOR_VABS_BLO_CP] = ADC_CTL_CH2 | ADC_CTL_IE | ADC_CTL_END;  // PE1, AIN2

        HAL::TivaADC_SeqConfig adcConfig = { ADC_TRIGGER_TIMER,            //.trigger, Tied to 1ms timer, see ::Start()
                                             HAL::ADC_PRI1,                //.priority
                                             &adcStepConfigs[0],           //.stepConfigs
                                             ARRAY_DIM(adcStepConfigs)};   //.stepConfigsSize

        static AdcTiva adcTubeSensor(ADC0_BASE, HAL::ADC_SS1, &adcConfig, reference);
        returnVal =  &adcTubeSensor;
        break;
    }
    case HAL::HAL_ID::ADC_ID_ABD:
    {
        uint32_t adcStepConfigs[HAL_ID::ADC_CHAN_ABD_MAX];
        adcStepConfigs[HAL_ID::ADC_CHAN_ABD_VABS_AIR_CP] = ADC_CTL_CH9;                             //PE4 , AIN9
        adcStepConfigs[HAL_ID::ADC_CHAN_ABD_AABS_AIR_CP] = ADC_CTL_CH8 | ADC_CTL_IE | ADC_CTL_END;  //PE5 , AIN8

        HAL::TivaADC_SeqConfig adcConfig = { ADC_TRIGGER_TIMER,            //.trigger always to generate
                                             HAL::ADC_PRI0,                //.priority
                                             &adcStepConfigs[0],           //.stepConfigs
                                             ARRAY_DIM(adcStepConfigs)};   //.stepConfigsSize

        static AdcTiva adcABD(ADC0_BASE, HAL::ADC_SS0, &adcConfig, reference);
        returnVal =  &adcABD;
        break;
    }
    default:
        H_ASSERT(0);
        break;
    }

    return returnVal;
}


IPwm* HAL_Manager::GetPwm(HAL::HAL_ID::PwmID ID)
{
#define VGP_TIMER_PWM
    IPwm* pwm = NULL;
    static PwmTiva PF0(PWM0_BASE, PWM_GEN_0, PWM_OUT_0, PWM_OUT_0_BIT, BSP_CLOCK_FREQUENCY); // This is PF0, M0PWM0
    static PwmTiva PF2(PWM0_BASE, PWM_GEN_1, PWM_OUT_2, PWM_OUT_2_BIT, BSP_CLOCK_FREQUENCY); // This is PF2, M0PWM0
    static PwmTiva PG0(PWM0_BASE, PWM_GEN_2, PWM_OUT_4, PWM_OUT_4_BIT, BSP_CLOCK_FREQUENCY); // This is PG0, M0PWM4
    PWMClockSet(PWM0_BASE, PWM_SYSCLK_DIV_16);

    switch (ID)
    {
    case HAL::HAL_ID::PWM_ID_BPCMD:
        pwm = &PF0;
        break;
    case HAL::HAL_ID::PWM_ID_HSCMD:
        pwm = &PG0;
        break;
    case HAL::HAL_ID::PWM_ID_LCP:
#ifdef VGP_TIMER_PWM // GEN 1 is needed by VGP driver
        static PwmTiva PF2(PWM0_BASE, PWM_GEN_1, PWM_OUT_2, PWM_OUT_2_BIT, BSP_CLOCK_FREQUENCY); // This is PF2, M0PWM2
        pwm = &PF2;
#else
        static PwmTimerTiva PD6(TIMER4_BASE, (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PWM | TIMER_CFG_B_PWM), TIMER_A, BSP_CLOCK_FREQUENCY); // This is T4CCP0
        pwm = &PD6;
#endif
        break;

    case HAL::HAL_ID::PWM_ID_VGP_IN1:
        // This is T1CCP1
        static PwmTimerTiva vgpPwm1(TIMER1_BASE, TIMER1_CFG, TIMER_B, BSP_CLOCK_FREQUENCY);
        pwm = &vgpPwm1;
        break;
    case HAL::HAL_ID::PWM_ID_VGP_IN2:
        // This is T3CCP1
        static PwmTimerTiva vgpPwm2(TIMER3_BASE, TIMER3_CFG, TIMER_B, BSP_CLOCK_FREQUENCY);
        pwm = &vgpPwm2;
        break;
    case HAL::HAL_ID::PWM_ID_VGP_IN3:
        // This is T4CCP0
        static PwmTimerTiva vgpPwm3(TIMER4_BASE, TIMER4_CFG, TIMER_A, BSP_CLOCK_FREQUENCY); // This is T4CCP0
        pwm = &vgpPwm3;
        break;
    default:
        H_ASSERT(0);
        break;
    }

    return pwm;

}


IUartPeripheral* HAL_Manager::GetUart(HAL::HAL_ID::UartID ID)
{
    IUartPeripheral* returnVal = NULL;

    switch (ID)
    {

    case HAL::HAL_ID::UART_ID_GUIB:
        static UartTiva uartGUI(UART0_BASE, BSP_CLOCK_FREQUENCY, 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE) );
        returnVal =  &uartGUI;
        break;
    case HAL::HAL_ID::UART_ID_NIBP:
        static UartTiva uartNIBP(UART5_BASE, BSP_CLOCK_FREQUENCY, 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE) );
        returnVal =  &uartNIBP;
        break;
    case HAL::HAL_ID::UART_ID_SW_DEBUG:
#if CONFIG_USE_BOARD_TEST()
        static UartTiva uartSW_DEBUG(UART0_BASE, BSP_CLOCK_FREQUENCY, 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE) );
#else
        static UartTiva uartSW_DEBUG(UART4_BASE, BSP_CLOCK_FREQUENCY, 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE) );
#endif
        returnVal =  &uartSW_DEBUG;

        break;

    case HAL::HAL_ID::UART_ID_DUFB:
        static UartTiva uartDUFB(UART2_BASE, BSP_CLOCK_FREQUENCY, 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE) );
        returnVal =  &uartDUFB;
        break;
    case HAL::HAL_ID::UART_ID_TBPP:
        static UartTiva uartTBPP(UART6_BASE, BSP_CLOCK_FREQUENCY, 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE) );
        returnVal =  &uartTBPP;
        break;
    default:
        H_ASSERT(0);
        break;
    }

    return returnVal;
}




ICanPeripheral* HAL_Manager::GetCan(HAL_ID::CanID ID)
{
    ICanPeripheral* thePeripheral = NULL;
    switch (ID)
    {
        case HAL_ID::CAN_ID_SYSTEST:
            static CanTiva canSysTest(CAN0_BASE, BSP_CLOCK_FREQUENCY, 1000000);

            thePeripheral = &canSysTest;
            break;

        default:
            H_ASSERT(0);
            break;
    }

    return thePeripheral;
}
IEepromPeripheral* HAL_Manager::GetEeprom(HAL_ID::EepromID ID)
{
    EepromTiva* thePeripheral = NULL;
    switch (ID)
    {
        case HAL_ID::EEPROM_ID_TIVA:
            static EepromTiva eepromTiva;

            thePeripheral = &eepromTiva;
            break;

        default:
            H_ASSERT(0);
            break;
    }

    return thePeripheral;
}


IPeripheral * HAL_Manager::GetSWUpgradePeripheral(HAL::HAL_ID::SWUpgradeID ID)
{
    IPeripheral * returnVal = NULL;

    switch (ID)
    {
			
	 case HAL::HAL_ID::UART_SWUPGRADE_UART_LOADER:
        static UartTiva uartloader(UART0_BASE, BSP_CLOCK_FREQUENCY, 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE) );
        returnVal =  &uartloader;
     break;
	  
     case HAL::HAL_ID::UART_SWUPGRADE_UART_ROUTER:
        static UartTiva uartrouter(UART2_BASE, BSP_CLOCK_FREQUENCY, 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE) );
        returnVal =  &uartrouter;
     break;
	 
	 // PROGIN	 
     case HAL::HAL_ID::GPIOPIN_INPUT_BOOTCFG:
        static InputPinTiva bootcfgIN(GPIO_PORTB_BASE, GPIO_PIN_4);
        returnVal =  &bootcfgIN;
     break;		 
	 
     // PROGRST			
     case HAL::HAL_ID::GPIOPIN_OUTPUT_RESET_TBHB:
        static OutputPinTiva resetOUT(GPIO_PORTB_BASE, GPIO_PIN_2);
        returnVal =  &resetOUT;
     break;

	 // PROGOUT 
     case HAL::HAL_ID::GPIOPIN_OUTPUT_BOOTCFG_TBHB:
        static OutputPinTiva bootcfgOUT(GPIO_PORTB_BASE, GPIO_PIN_5); // all therapy processors and launchpad use same pin PB5 - not applicable to dialysates
        returnVal =  &bootcfgOUT;
     break;	 

     case HAL::HAL_ID::GPIOPIN_OUTPUT_LED1:
#if ( CONFIG_USE_EVAL_BOARD() )
	
        static OutputPinTiva led1(GPIO_PORTN_BASE, GPIO_PIN_1);  //  Led1(GPIO_PORTN_BASE, GPIO_PIN_1);
#else
        static OutputPinTiva led1(GPIO_PORTL_BASE, GPIO_PIN_2);  //  HAL::HAL_ID::OUTPUT_PIN_ID_U301_ALIVE
#endif	
        returnVal =  &led1;
     break;	
		
     case HAL::HAL_ID::GPIOPIN_OUTPUT_LED2:
#if ( CONFIG_USE_EVAL_BOARD() )
	
        static OutputPinTiva led2(GPIO_PORTN_BASE, GPIO_PIN_0);  //  Led2(GPIO_PORTN_BASE, GPIO_PIN_0);
#else
        static OutputPinTiva led2(GPIO_PORTL_BASE, GPIO_PIN_3);  //  HAL::HAL_ID::OUTPUT_PIN_ID_COM_RCVD_PP
#endif	
        returnVal =  &led1;
     break;		
	 	
     default:
        H_ASSERT(0);
        break;
    }

    return returnVal;
}


} /* namespace HAL */
