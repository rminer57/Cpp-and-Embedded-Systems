/*!
 *    @file             $Source: DriverManager.cpp $
 *    @brief            Driver manager implementation
 *
 *    @author           $Author: ronald dean (deanr1) $
 *
 *    @version          $Revision: 1.7 $
 *
 *    @date             $Date: 2015/06/24 16:56:39EDT $
 *
 *    @par Description
 *                      Driver manager implementation for the Tiva DK board for dialysate control
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
#include <bsp.h>
#include <cstddef>
#include <DriverManager.h>
#include <DriverAssert.h>
#include <FlowSensorDriver.h>
#include <DRV8825MotorDriver.h>
#include <DRV8813MotorDriver.h>
#include <DRV8312MotorDriver.h>
#include <DRV8313MotorDriver.h>
#include <DRV8860CoilDriver.h>
#include <LED.h>
#include <PressureSensorDriver.h>
#include <CondoSensorDriver.h>
#include <TempSensorDriver.h>
#include <TachometerDriver.h>
#include <BitBangerDriver.h>
#include <MuxDriver.h>
#include <ChipSelectDriver.h>
#include <ADS1120AdcDriver.h>
#include <ID.h>
#include <AdcSampler.h>
#include <SerialPortDriver.h>
#include <IpcDriver.h>
#include <config.h>
#include <IHallEffectSensorDriver.h>
#include <ILevelSensorDriver.h>
#include <DRV5503HallEffectSensorDriver.h>
#include <DRV8803MotorDriver.h>
#include <DegasLevelSensorDriver.h>
#include <EepromMemoryDriver.h>
#include <Utility.h>
#include <MotorSpeedControlDriver.h>
#include <IPidController.h>

// HAL includes
#include <HAL_Manager.h>
#include <HAL_ID.h>
#include <ICounter.h>
#include <ITimer.h>
#include <ITimerShared.h>
#include <IPwm.h>
#include <IEeprom.h>

#define CAN_MSG_COUNT   10

D_DEFINE_THIS_MODULE("DriverManager.cpp")

namespace Driver
{

    /// ADS1120 chip select indexes
    enum
    {
        CHIP_SELECT_INDEX_FCS,
        CHIP_SELECT_INDEX_SCS,
        CHIP_SELECT_INDEX_OKS,
        CHIP_SELECT_INDEX_COUNT // Must be last
    }ChipSelectIndex;



void DriverManager::Init()
{

    // Init all the flow sensor drivers
    for(int idx = Driver::DIALYSATE_FLOW_SENSOR_ID_BASE; idx < Driver::DIALYSATE_FLOW_SENSOR_ID_MAX; ++idx)
    {
        IFlowSensorDriver* pFlowSensor = GetFlowSensorDriver(static_cast<Driver::ID>(idx));
        pFlowSensor->Init();
    }

    // Init all the motor drivers
    for(int idx = Driver::DIALYSATE_MOTOR_ID_BASE; idx < Driver::DIALYSATE_MOTOR_ID_MAX; ++idx)
    {
        IDriver* pMotor = GetMotorDriver(static_cast<Driver::ID>(idx));
        pMotor->Init();
    }

    // Init all the brushless motor drivers
    for(int idx = Driver::DIALYSATE_PWM_MOTOR_ID_BASE; idx < Driver::DIALYSATE_PWM_MOTOR_ID_MAX; ++idx)
    {
        IDriver* pMotor = GetPwmMotorDriver(static_cast<Driver::ID>(idx));
        pMotor->Init();
    }

    // Init all the brushless motor tachs
    for(int idx = Driver::DIALYSATE_TACHOMETER_ID_BASE; idx < Driver::DIALYSATE_TACHOMETER_ID_MAX; ++idx)
    {
        IDriver* pMotor = GetTachometerDriver(static_cast<Driver::ID>(idx));
        pMotor->Init();
    }

    // Init all the motor speed control drivers *after* BLDC's and Tach drivers are intialized
    for(int idx = Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_BASE; idx < Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_MAX; ++idx)
    {
        IDriver* pMotor = GetMotorDriver(static_cast<Driver::ID>(idx));
        pMotor->Init();
    }

    // Init all the LED drivers
    for(int idx = Driver::DIALYSATE_LED_ID_BASE; idx < Driver::DIALYSATE_LED_ID_MAX; ++idx)
    {
        ILedDriver* pLed = GetLedDriver(static_cast<Driver::ID>(idx));
        pLed->Init();
    }

    //Init all Condo Sensors
    for(int idx = Driver::DIALYSATE_CONDO_SENSOR_ID_BASE; idx < Driver::DIALYSATE_CONDO_SENSOR_ID_MAX; ++idx)
    {
        ICondoSensorDriver* pCondo = GetCondoSensorDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pCondo != NULL);
        pCondo->Init();
    }

    // Init all the temp sensor drivers
    for(int idx = Driver::DIALYSATE_TEMP_SENSOR_ID_BASE; idx < Driver::DIALYSATE_TEMP_SENSOR_ID_MAX; ++idx)
    {
        ITempSensorDriver* pTemp = GetTempSensorDriver(static_cast<Driver::ID>(idx));
        pTemp->Init();
    }

    //Init Mux
    for(int idx = Driver::DIALYSATE_MUX_ID_BASE; idx < Driver::DIALYSATE_MUX_ID_MAX; ++idx)
    {
        IMuxDriver* pDriver = GetMuxDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Init();
    }

    // Init chip selects
    for(int idx = Driver::DIALYSATE_CHIP_SEL_ID_BASE; idx < Driver::DIALYSATE_CHIP_SEL_ID_MAX; ++idx)
    {
        IChipSelectDriver* pDriver = GetChipSelectDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Init();
    }


    //Init all Pressure Sensors
    for(int idx = Driver::DIALYSATE_PRESSURE_SENSOR_ID_BASE; idx < Driver::DIALYSATE_PRESSURE_SENSOR_ID_MAX; ++idx)
    {
        IPressureSensorDriver* pPressure = GetPressureSensorDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pPressure != NULL);
        pPressure->Init();
    }

    //Init all Bit Banger Drivers
    for(int idx = Driver::DIALYSATE_BIT_BANGER_ID_BASE; idx < Driver::DIALYSATE_BIT_BANGER_ID_MAX; ++idx)
    {
        IBitBangerDriver* pBitBang = GetBitBangerDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pBitBang != NULL);
        pBitBang->Init();
    }
    
    //Init all Coil Drivers
    for(int idx = Driver::DIALYSATE_COIL_ID_BASE; idx < Driver::DIALYSATE_COIL_ID_MAX; ++idx)
    {
        ICoilDriver* pDriver = GetCoilDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Init();
    }

    // Init all ADCDrivers
    for(int idx = Driver::ADC_ID_BASE; idx < Driver::ADC_ID_MAX; ++idx)
    {
        IAdcDriver* pDriver = GetAdcDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Init();
    }

    // Init all SerialPortDrivers
    for(int idx = Driver::SERIAL_PORT_ID_BASE; idx < Driver::SERIAL_PORT_ID_MAX; ++idx)
    {
        ISerialPortDriver* pDriver = GetSerialPortDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Init();
    }

    // Init
    for(int idx = Driver::HALL_EFFECT_SENSOR_ID_FULL_VESSEL; idx < Driver::HALL_EFFECT_SENSOR_ID_MAX; ++idx)
    {
        Driver::IHallEffectSensorDriver* pDriver = GetHallEffectSensorDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Init();
    }

    // Init
    for(int idx = Driver::LEVEL_SENSOR_ID_DEGAS; idx < Driver::LEVEL_SENSOR_ID_MAX; ++idx)
    {
        Driver::ILevelSensorDriver* pDriver = GetLevelSensorDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Init();
    }

}

void DriverManager::StartAll()
{
    // Start all the flow sensor drivers
    for(int idx = Driver::DIALYSATE_FLOW_SENSOR_ID_BASE; idx < Driver::DIALYSATE_FLOW_SENSOR_ID_MAX; ++idx)
    {
        IFlowSensorDriver* pDriver = GetFlowSensorDriver(static_cast<Driver::ID>(idx));
        pDriver->Start();
    }

    // Start all the motor drivers
    for(int idx = Driver::DIALYSATE_MOTOR_ID_BASE; idx < Driver::DIALYSATE_MOTOR_ID_MAX; ++idx)
    {
        IMotorDriver* pDriver = GetMotorDriver(static_cast<Driver::ID>(idx));
        pDriver->Start();
    }

    // Start all the brushless motor drivers
    for(int idx = Driver::DIALYSATE_PWM_MOTOR_ID_BASE; idx < Driver::DIALYSATE_PWM_MOTOR_ID_MAX; ++idx)
    {
        IDriver* pMotor = GetPwmMotorDriver(static_cast<Driver::ID>(idx));
        pMotor->Start();
    }

    // Start all the brushless motor tachs
    for(int idx = Driver::DIALYSATE_TACHOMETER_ID_BASE; idx < Driver::DIALYSATE_TACHOMETER_ID_MAX; ++idx)
    {
        IDriver* pMotor = GetTachometerDriver(static_cast<Driver::ID>(idx));
        pMotor->Start();
    }

    // Init all the motor speed control drivers *after* BLDC's and Tach drivers are started
    for(int idx = Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_BASE; idx < Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_MAX; ++idx)
    {
        IDriver* pMotor = GetMotorDriver(static_cast<Driver::ID>(idx));
        pMotor->Start();
    }

    // Start all the LED drivers
    for(int idx = Driver::DIALYSATE_LED_ID_BASE; idx < Driver::DIALYSATE_LED_ID_MAX; ++idx)
    {
        ILedDriver* pLed = GetLedDriver(static_cast<Driver::ID>(idx));
        pLed->Start();
    }

    // Start all Condo Sensors
    for(int idx = Driver::DIALYSATE_CONDO_SENSOR_ID_BASE; idx < Driver::DIALYSATE_CONDO_SENSOR_ID_MAX; ++idx)
    {
        ICondoSensorDriver* pCondo = GetCondoSensorDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pCondo != NULL);
        pCondo->Start();
    }

    // Start all the temp sensor drivers
    for(int idx = Driver::DIALYSATE_TEMP_SENSOR_ID_BASE; idx < Driver::DIALYSATE_TEMP_SENSOR_ID_MAX; ++idx)
    {
        ITempSensorDriver* pTemp = GetTempSensorDriver(static_cast<Driver::ID>(idx));
        pTemp->Start();
    }

    //Start Mux
    for(int idx = Driver::DIALYSATE_MUX_ID_BASE; idx < Driver::DIALYSATE_MUX_ID_MAX; ++idx)
    {
        IMuxDriver* pDriver = GetMuxDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Start();
    }

    // Start all Pressure Sensors
    for(int idx = Driver::DIALYSATE_PRESSURE_SENSOR_ID_BASE; idx < Driver::DIALYSATE_PRESSURE_SENSOR_ID_MAX; ++idx)
    {
        IPressureSensorDriver* pPressure = GetPressureSensorDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pPressure != NULL);
        pPressure->Start();
    }

    for (int idx = Driver::DIALYSATE_BIT_BANGER_ID_BASE; idx < Driver::DIALYSATE_BIT_BANGER_ID_MAX; idx++)
    {
        IBitBangerDriver* pDriver = GetBitBangerDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Start();
    }
    
    //Start all Coil Drivers
    for(int idx = Driver::DIALYSATE_COIL_ID_BASE; idx < Driver::DIALYSATE_COIL_ID_MAX; ++idx)
    {
        ICoilDriver* pDriver = GetCoilDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Start();
    }

    // Start all ADCDrivers
    for(int idx = Driver::ADC_ID_BASE; idx < Driver::ADC_ID_MAX; ++idx)
    {
        IAdcDriver* pDriver = GetAdcDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Start();
    }
    // Start and Open all SerialPortDrivers
    for(int idx = Driver::SERIAL_PORT_ID_BASE; idx < Driver::SERIAL_PORT_ID_MAX; ++idx)
    {
        ISerialPortDriver* pDriver = GetSerialPortDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Start();
        pDriver->Open();
    }

    // Start
    for(int idx = Driver::LEVEL_SENSOR_ID_DEGAS; idx < Driver::LEVEL_SENSOR_ID_MAX; ++idx)
    {
        Driver::ILevelSensorDriver* pDriver = GetLevelSensorDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Start();
    }

    // Start
    for(int idx = Driver::HALL_EFFECT_SENSOR_ID_FULL_VESSEL; idx < Driver::HALL_EFFECT_SENSOR_ID_MAX; ++idx)
    {
        Driver::IHallEffectSensorDriver* pDriver = GetHallEffectSensorDriver(static_cast<Driver::ID>(idx));
        D_ASSERT(pDriver != NULL);
        pDriver->Start();
    }

#if (CONFIG_USE_EVAL_BOARD() || CONFIG_USE_BOARD_TEST())

    ///@todo Replaced warning: CONFIG_USE_EVAL_BOARD is defined to avoid Chip Select Asserts on Missing ADS1120s!

#else
     // Construct and start the driver utility that scans all of the SPI ADCs
     static AdcSampler adcSampler(*HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS));
     adcSampler.AddADC(Driver::DriverManager::GetAdcDriver(Driver::ADC_ID_SCS));
     adcSampler.AddADC(Driver::DriverManager::GetAdcDriver(Driver::ADC_ID_FCS));
     adcSampler.AddADC(Driver::DriverManager::GetAdcDriver(Driver::ADC_ID_OKS));
     adcSampler.StartSampling();
#endif
}

ICondoSensorDriver* DriverManager::GetCondoSensorDriver(Driver::ID ID)
{
    ICondoSensorDriver* returnVal = NULL;


    switch (ID)
    {
    case Driver::CONDO_SENSOR_ID_FCS:
    {
        HAL::ITimer*   pTimer   = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
        HAL::IAdc* pAdc = static_cast<HAL::IAdc*>(DriverManager::GetAdcDriver(ADC_ID_FCS));
//        static CondoSensorDriver pCds(*pTimer, *pAdc, ADC_CHAN_FCS_CONDO, 14.285f, 0.0f); // Number from first bench test of DUFB 10/13/2014
        static CondoSensorDriver pCds(*pTimer, *pAdc, ADC_CHAN_FCS_CONDO, 10.83f, 0.0f); // Quick BT cal with old sensors 10/15
        returnVal =  &pCds;
        break;
    }
    case Driver::CONDO_SENSOR_ID_SCS:
    {
        HAL::ITimer*   pTimer   = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
        HAL::IAdc* pAdc = static_cast<HAL::IAdc*>(DriverManager::GetAdcDriver(ADC_ID_SCS));
//        static CondoSensorDriver pScs(*pTimer, *pAdc, ADC_CHAN_SCS_CONDO,  14.285f, 0.0f); // Number from first bench test of DUFB 10/13/2014
        static CondoSensorDriver pScs(*pTimer, *pAdc, ADC_CHAN_SCS_CONDO,  10.83f, 0.0f);// Quick BT cal with old sensors 10/15
        returnVal =  &pScs;
        break;
    }
    case Driver::CONDO_SENSOR_ID_OKS:
    {
        HAL::ITimer*   pTimer   = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
        HAL::IAdc* pAdc = static_cast<HAL::IAdc*>(DriverManager::GetAdcDriver(ADC_ID_OKS));
//        static CondoSensorDriver pOks(*pTimer, *pAdc, ADC_CHAN_OKS_CONDO, 14.285f, 0.0f); // Number from first bench test of DUFB 10/13/2014
        static CondoSensorDriver pOks(*pTimer, *pAdc, ADC_CHAN_OKS_CONDO, 10.83f, 0.0f); // Quick BT cal with old sensors 10/15
        returnVal =  &pOks;
        break;
    }
    default:
        D_ASSERT(0);
        break;
    }

    return returnVal;
}

IBitBangerDriver* DriverManager::GetBitBangerDriver(Driver::ID ID)
{
    IBitBangerDriver* theDriver = NULL;
    HAL::ITimerShared* theTimer = NULL;
    HAL::IOutputPin* thePin = NULL;

    switch (ID)
    {
    case Driver::BIT_BANGER_ID_HEATER_CONTROL:
        theTimer = HAL::HAL_Manager::GetTimerShared(HAL::HAL_ID::TIMER_ID_SHARED);
        thePin = HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_HCMD_CP);
        static BitBangerDriver heaterControlBitBanger(*theTimer, *thePin, true);
        theDriver = &heaterControlBitBanger;
        break;
    default:
        D_ASSERT(0);
        break;
    }

    return theDriver;
}

ICoilDriver* DriverManager::GetCoilDriver(Driver::ID ID)
{
    ICoilDriver* returnVal = NULL;

    switch (ID)
    {
    case Driver::COIL_ID_VALVE_CONTROL:
        static DRV8860CoilDriver valveControlDriver(
                                                      *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VALVE_DIN),
                                                      *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VALVE_CLK),
                                                      *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VALVE_LATCH_L),
                                                      *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VALVE_EN),
                                                      *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_PNEUMATIC_EN),
                                                      *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_PNEUMATIC_DOUT),
                                                      *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VALVE_FAULT_L),
                                                      *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_PNEUMATIC_FAULT_L),
                                                      *HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_VALVE_CTRL)
                                                    );
        returnVal = &valveControlDriver;
        break;
    default:
        D_ASSERT(0);
        break;
    }

    return returnVal;
}


IAdcDriver*  DriverManager::GetAdcDriver(Driver::ID ID)
{
    IAdcDriver *theDriver = NULL;
    int numberOfChannels = 2;

    // Drivers are configured for channel 0 = Ain0, channel 1 = Ain2
    Driver::ADS1120ChannelConfig channelConfig[4] =
    {
            0x81 /* condo */,
            0xA1 /* temp */,
            0x81 /* dont care */,
            0x81 /* dont care */
    };

    if (CONFIG_USE_BOARD_TEST() == ENABLED)
    {
        channelConfig[0].register0 = 0x81;  // condo channel 0
        channelConfig[1].register0 = 0x91;  // unused channel 1
        channelConfig[2].register0 = 0xA1;  // temp channel 2
        channelConfig[3].register0 = 0xB1;  // test channel 3
        numberOfChannels = 4;
    }

    switch(ID)
    {
    case ADC_ID_SCS: // Sorbent Conductivity and Temp
    {
        static ADS1120AdcDriver adcSCS(*HAL::HAL_Manager::GetSpi(HAL::HAL_ID::SPI_ID_ANALOG),
                                       *GetChipSelectDriver(Driver::DIALYSATE_CHIP_SEL_SPI),
                                       CHIP_SELECT_INDEX_SCS,
                                       *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_SCS_DR_CP_L),
                                       &channelConfig[0],
                                       numberOfChannels);
        theDriver = &adcSCS;
        break;
    }
    case ADC_ID_FCS: // Final Conductivity and Temp
    {
        static ADS1120AdcDriver adcFCS(*HAL::HAL_Manager::GetSpi(HAL::HAL_ID::SPI_ID_ANALOG),
                                        *GetChipSelectDriver(Driver::DIALYSATE_CHIP_SEL_SPI),
                                        CHIP_SELECT_INDEX_FCS,
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_FCS_DR_CP_L),
                                        &channelConfig[0],
                                        numberOfChannels);
        theDriver = &adcFCS;
        break;
    }
    case ADC_ID_OKS: // Output Conductivity and Temp
    {
        static ADS1120AdcDriver adcOKS(*HAL::HAL_Manager::GetSpi(HAL::HAL_ID::SPI_ID_ANALOG),
                                        *GetChipSelectDriver(Driver::DIALYSATE_CHIP_SEL_SPI),
                                        CHIP_SELECT_INDEX_OKS,
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_OKS_DR_CP_L),
                                        &channelConfig[0],
                                        numberOfChannels);

        theDriver = &adcOKS;
        break;
    }
    default:
        D_ASSERT(0);
        break;
    }

    return theDriver;
}

IMuxDriver* DriverManager::GetMuxDriver(Driver::ID ID)
{
    IMuxDriver* theDriver = NULL;
    HAL::ITimer* pTimer = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_10MS);

    static const unsigned int sizeOfPressureMux = 4;
    static bool pressureMux[sizeOfPressureMux] = { true, true, true, true };

    switch (ID)
    {
        case Driver::MUX_ID_DIALYSATE_PRESSURE_SENSORS:
        {
            HAL::IOutputPin* pS0 = HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_S0_CP);
            HAL::IOutputPin* pS1 = HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_S1_CP);
            HAL::IOutputPin* pS2 = NULL;  // unused for this mux
            static MuxDriver psMux(*pTimer, pS0, pS1, pS2, pressureMux, sizeOfPressureMux);
            theDriver = &psMux;
        }
        break;
        default:
            D_ASSERT(0);
            break;
    }

    return theDriver;
}

IChipSelectDriver* DriverManager::GetChipSelectDriver(Driver::ID ID)
{
    IChipSelectDriver* theDriver;
   switch(ID)
   {
    case Driver::DIALYSATE_CHIP_SEL_SPI:
        {
            HAL::IOutputPin* pSCS_EN = HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_SCS_EN_CP_L);
            HAL::IOutputPin* pFCS_EN = HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_FCS_EN_CP_L);
            HAL::IOutputPin* pOKS_EN = HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_OKS_EN_CP_L);

            HAL::IOutputPin* pChipSelectPins[CHIP_SELECT_INDEX_COUNT];

            pChipSelectPins[CHIP_SELECT_INDEX_FCS] = pFCS_EN;
            pChipSelectPins[CHIP_SELECT_INDEX_SCS] = pSCS_EN;
            pChipSelectPins[CHIP_SELECT_INDEX_OKS] = pOKS_EN;

            static ChipSelectDriver chipSelectDriver(&pChipSelectPins[0], CHIP_SELECT_INDEX_COUNT);

            theDriver = &chipSelectDriver;
        }
        break;
    default:
        D_ASSERT(0);
        break;
   }

    return theDriver;
}


IPressureSensorDriver* DriverManager::GetPressureSensorDriver(Driver::ID ID)
{
    IPressureSensorDriver* returnVal = NULL;
    IMuxDriver* pMux = GetMuxDriver(Driver::MUX_ID_DIALYSATE_PRESSURE_SENSORS);
    HAL::ITimer* pTimer = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
    HAL::IAdc* pAdc = HAL::HAL_Manager::GetAdc(HAL::HAL_ID::ADC_ID_PRESS_IN_CP);
    uint32_t muxValue;

    //
    // Note: Mux values are the following:
    // SPS: 00B
    // MFPS: 01B
    // DPIS: 10B
    // SOPS: 11B
    //
    switch (ID)
    {
    case Driver::PRESSURE_SENSOR_ID_SPS:
    {
        muxValue = 0;
        static PressureSensorDriver sps(*pTimer, *pAdc, HAL::HAL_ID::ADC_CHAN_PRESSURE_SPS,  *pMux, muxValue);
        returnVal =  &sps;
        break;
    }
    case Driver::PRESSURE_SENSOR_ID_MFPS:
    {
        muxValue = 1;
        static PressureSensorDriver mfps(*pTimer, *pAdc, HAL::HAL_ID::ADC_CHAN_PRESSURE_MFPS, *pMux, muxValue);
        returnVal =  &mfps;
        break;
    }
    case Driver::PRESSURE_SENSOR_ID_DPIS:
    {
        muxValue = 2;
        static PressureSensorDriver dpis(*pTimer, *pAdc, HAL::HAL_ID::ADC_CHAN_PRESSURE_DPIS, *pMux, muxValue);
        returnVal =  &dpis;
        break;
    }
    case Driver::PRESSURE_SENSOR_ID_SOPS:
    {
        muxValue = 3;
        static PressureSensorDriver sops(*pTimer, *pAdc, HAL::HAL_ID::ADC_CHAN_PRESSURE_SOPS, *pMux, muxValue);
        returnVal =  &sops;
        break;
    }

    default:
        D_ASSERT(0);
        break;
    }

    return returnVal;
}

ITachometerDriver* DriverManager::GetTachometerDriver(Driver::ID ID)
{
    ITachometerDriver* returnVal = NULL;

    switch (ID)
    {
    case Driver::TACHOMETER_ID_DP1:
    {
        HAL::ITimer*   pTimer   = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
        HAL::ICounter* pCounter = HAL::HAL_Manager::GetCounter(HAL::HAL_ID::COUNTER_ID_TACH_DP1);
        static TachometerDriver dp1Tach(
                                        *pCounter,
                                        *pTimer,
                                        ITachometer::TACH_MODE_EDGE_COUNT,
                                        BSP_CLOCK_FREQUENCY,                                        // change to HAL::SYSCLK when defined
                                        4,                                                          // motor ticks per armature rotation
                                        1.0                                                         // gear ratio if taching other than rotor
                                       );
        returnVal =  &dp1Tach;
        break;
    }
    case Driver::TACHOMETER_ID_DP2:
    {
        HAL::ITimer*   pTimer   = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
        HAL::ICounter* pCounter = HAL::HAL_Manager::GetCounter(HAL::HAL_ID::COUNTER_ID_TACH_DP2);
        static TachometerDriver dp2Tach(
                                        *pCounter,
                                        *pTimer,
                                        ITachometer::TACH_MODE_EDGE_COUNT,
                                        BSP_CLOCK_FREQUENCY,                                        // change to HAL::SYSCLK when defined
                                        4,                                                          // motor ticks per armature rotation
                                        1.0                                                         // gear ratio if taching other than rotor
                                       );
        returnVal =  &dp2Tach;
        break;
    }
    default:
        D_ASSERT(0);
        break;
    }

    return returnVal;
}

IFlowSensorDriver* DriverManager::GetFlowSensorDriver(Driver::ID ID)
{
    IFlowSensorDriver* returnVal = NULL;

    switch (ID)
    {
    case Driver::FLOW_SENSOR_ID_IFS:
    {
        HAL::ICounter* pCounter = HAL::HAL_Manager::GetCounter(HAL::HAL_ID::COUNTER_ID_IFS);
        HAL::ITimer* pTimer = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
        static FlowSensorDriver ifs(*pCounter, *pTimer);
        returnVal = &ifs;
    }
        break;

    case Driver::FLOW_SENSOR_ID_OFSU:
    {
        HAL::ICounter* pCounter = HAL::HAL_Manager::GetCounter(HAL::HAL_ID::COUNTER_ID_OFSU);
        HAL::ITimer* pTimer = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
        static FlowSensorDriver ofsu(*pCounter, *pTimer);
        returnVal = &ofsu;
    }
        break;

    case Driver::FLOW_SENSOR_ID_IPS:
    {
        HAL::ICounter* pCounter = HAL::HAL_Manager::GetCounter(HAL::HAL_ID::COUNTER_ID_IPS);
        HAL::ITimer* pTimer = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
        static FlowSensorDriver ufps(*pCounter, *pTimer);
        returnVal = &ufps;
    }
        break;

    default:
        D_ASSERT(0);
        break;
    }

    return returnVal;
}

IMotorDriver* DriverManager::GetMotorDriver(Driver::ID ID)
{
    IMotorDriver* returnVal = NULL;

    switch (ID)
    {
    case Driver::MOTOR_ID_WP:
        static DRV8825MotorDriver motor_WP(
                                        200, // Motor is 1.8 degrees per step, 200 ppr
                                        DRV8825MotorDriver::StepMode_32Micro,
                                        true,
                                        400,
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_WP_EN_L),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_WP_DIR),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_WP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_WP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_WP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_WP_RST_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_WP_FAULT_L),
                                        *HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_10MS),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_WP_STEP)
                                      );
        returnVal = &motor_WP;
        break;

    case Driver::MOTOR_ID_UP:
        static DRV8825MotorDriver motor_UP(
                                        200, // Motor is 1.8 degrees per step, 200 ppr
                                        DRV8825MotorDriver::StepMode_32Micro,
                                        true,
                                        400,
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_UFP_EN_L),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_UFP_DIR),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_UFP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_UFP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_UFP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_UFP_RST_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_UP_FAULT_L),
                                        *HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_10MS),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_UFP_STEP)
                                      );
        returnVal = &motor_UP;
        break;

    case Driver::MOTOR_ID_BCP:
        static DRV8825MotorDriver motor_BCP(
                                        200, // Motor is 1.8 degrees per step, 200 ppr
                                        DRV8825MotorDriver::StepMode_32Micro,
                                        true,
                                        400,
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_BCP_EN_L),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_BCP_DIR),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_BCP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_BCP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_BCP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_BCP_RST_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_BCP_FAULT_L),
                                        *HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_10MS),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_BCP_STEP)
                                      );
        returnVal = &motor_BCP;
        break;

    case Driver::MOTOR_ID_IP:
        static DRV8825MotorDriver motor_IP(
                                        200, // Motor is 1.8 degrees per step, 200 ppr
                                        DRV8825MotorDriver::StepMode_32Micro,
                                        true,
                                        400,
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_IP_EN_L),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_IP_DIR),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_IP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_IP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_IP_MODE),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_IP_RST_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_IP_FAULT_L),
                                        *HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_10MS),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_IP_STEP)
                                      );
        returnVal = &motor_IP;
        break;
    case Driver::MOTOR_ID_GRP:
        static Driver::DRV8803MotorDriver motor_GRP(
                                        HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_GRP_PWM),                  // IN1
                                        NULL,                                                                   // IN2 (not used on DUFB)
                                        NULL,                                                                   // IN3 (not used on DUFB)
                                        NULL,                                                                   // IN4 (not used on DUFB)
                                        *HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_10MS),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_GRP_EN_L),   // nENBL
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DUMMY),      // RESET (always enabled on DUFB)
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DUMMY)         // nFAULT (no access now)
                                      );
        returnVal = &motor_GRP;
        break;
    case Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_DP1:
        /// Note: isA type of IMotorDriver*
        returnVal = static_cast <Driver::IMotorDriver*> (Driver::DriverManager::GetMotorSpeedControlDriver(Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_DP1));
        break;
    case Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_DP2:
        /// Note: isA type of IMotorDriver*
        returnVal = static_cast <Driver::IMotorDriver*> (Driver::DriverManager::GetMotorSpeedControlDriver(Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_DP2));
        break;
    default:
        D_ASSERT(0);
        break;
    }

    return returnVal;
}

Driver::IPwmMotorDriver* DriverManager::GetPwmMotorDriver(Driver::ID ID)
{

    IPwmMotorDriver* returnVal = NULL;

    switch (ID)
    {
    ///@note the PWM pins on the DP and VGP on the Rev 2 DUCP boards are wired incorrectly. In1 drives
    ///      motor coil 3, in2 drives coil 1 and in3 drives coil 2. The DRV831x startup
    ///      are called with the correction to the mis-wiring. Note that the enable pins must follow
    ///      the PWM pins, so those are rewired also.
    case Driver::PWM_MOTOR_ID_DP1:
#if (CONFIG_USE_DRV8312())
        static Driver::DRV8312MotorDriver dp1(
                                        HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_EN1),      // Old EN1 maps to RESET A
                                        HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_EN2),      // Old EN2 maps to RESET B
                                        HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_EN3),      // Old EN3 maps to RESET C
                                        HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_MODE),       // Mode0 not avail until EVT
										///@todo FAULT PIN COPIED TO OTW SINCE HW REV2 DOES NOT HAVE ENOUGH IOs TO
										///		 SUPPORT THE ADDITIONAL PIN. NEED TO DEFINE THE OTW PIN TO THE
										///		 CORRECT IO ONCE THE NEXT REV OF HARDWARE IS COMPLETE.
                                        HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_FAULT_L),    // Old fault maps to nFAULT
                                        HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_FAULT_L),    // Old fault maps to nFAULT
                                        HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_HALL2_CP),   // Old Hall1 maps to HallA
                                        HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_HALL3_CP),   // Old Hall2 maps to HallB
                                        HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_HALL1_CP),   // Old Hall3 maps to HallC
                                        *HAL::HAL_Manager::GetTimerShared(HAL::HAL_ID::TIMER_ID_SHARED),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_DP_IN1),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_DP_IN2),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_DP_IN3));
#else
#if (CONFIG_USE_DRV8313())
        static DRV8313MotorDriver dp1(
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_EN3),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_EN1),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_EN2),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_RST_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_FAULT_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_HALL1_CP),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_HALL2_CP),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_HALL3_CP),
                                        *HAL::HAL_Manager::GetTimerShared(HAL::HAL_ID::TIMER_ID_SHARED),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_DP_IN3),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_DP_IN1),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_DP_IN2),
                                        BSP_CLOCK_FREQUENCY);
#else
        static DRV8813MotorDriver dp1(
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_EN1),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_EN2),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_EN3),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_DP_RST_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_FAULT_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_HALL1_CP),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_HALL2_CP),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_DP_HALL3_CP),
                                        *HAL::HAL_Manager::GetTimerShared(HAL::HAL_ID::TIMER_ID_SHARED),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_DP_IN1),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_DP_IN2),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_DP_IN3),
                                        BSP_CLOCK_FREQUENCY);
#endif
#endif
        returnVal = &dp1;
        break;

    case Driver::PWM_MOTOR_ID_DP2:
#if (CONFIG_USE_DRV8312())
        static Driver::DRV8312MotorDriver dp2(
                                        HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN1),     // Old EN1 maps to RESET A
                                        HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN2),     // Old EN2 maps to RESET B
                                        HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN3),     // Old EN3 maps to RESET C
                                        HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_MODE),     // Mode0 not avail until EVT
										///@todo FAULT PIN COPIED TO OTW SINCE HW REV2 DOES NOT HAVE ENOUGH IOs TO
										///		 SUPPORT THE ADDITIONAL PIN. NEED TO DEFINE THE OTW PIN TO THE
										///		 CORRECT IO ONCE THE NEXT REV OF HARDWARE IS COMPLETE.
                                        HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_FAULT_L),   // OverTemperature Warning
                                        HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_FAULT_L),   // Old fault maps to nFAULT
                                        HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL2_CP),  // Old Hall1 maps to HallA
                                        HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL3_CP),  // Old Hall2 maps to HallB
                                        HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL1_CP),  // Old Hall3 maps to HallC
                                        *HAL::HAL_Manager::GetTimerShared(HAL::HAL_ID::TIMER_ID_SHARED),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_VGP_IN1),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_VGP_IN2),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_VGP_IN3));
#else
#if (CONFIG_USE_DRV8313())
        static DRV8313MotorDriver dp2(
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN3),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN1),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN2),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_RST_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_FAULT_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL1_CP),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL2_CP),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL3_CP),
                                        *HAL::HAL_Manager::GetTimerShared(HAL::HAL_ID::TIMER_ID_SHARED),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_VGP_IN3),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_VGP_IN1),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_VGP_IN2),
                                        BSP_CLOCK_FREQUENCY);
#else
        static DRV8813MotorDriver dp2(
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN1),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN2),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_EN3),
                                        *HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_VGP_RST_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_FAULT_L),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL1_CP),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL2_CP),
                                        *HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_VGP_HALL3_CP),
                                        *HAL::HAL_Manager::GetTimerShared(HAL::HAL_ID::TIMER_ID_SHARED),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_VGP_IN1),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_VGP_IN2),
                                        *HAL::HAL_Manager::GetPwm(HAL::HAL_ID::PWM_ID_VGP_IN3),
                                        BSP_CLOCK_FREQUENCY);
#endif
#endif
        returnVal = &dp2;
        break;
    default:
        D_ASSERT(0);
        break;
    }

    return returnVal;

}

ITempSensorDriver* DriverManager::GetTempSensorDriver(Driver::ID ID)
{
    ITempSensorDriver* returnVal = NULL;

    switch (ID)
    {
    case Driver::TEMP_SENSOR_ID_FTS:
    {
        HAL::ITimer* pTimer = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
        HAL::IAdc* pAdc = DriverManager::GetAdcDriver(ADC_ID_FCS);
        static TempSensorDriver fts(*pTimer, *pAdc, ADC_CHAN_FCS_TEMP, 2000.0f);
        returnVal =  &fts;
        break;
    }
    case Driver::TEMP_SENSOR_ID_STS:
    {
        HAL::ITimer* pTimer = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
        HAL::IAdc* pAdc = DriverManager::GetAdcDriver(ADC_ID_SCS);
        static TempSensorDriver sts(*pTimer, *pAdc, ADC_CHAN_SCS_TEMP, 2000.0f);
        returnVal =  &sts;
        break;
    }
    case Driver::TEMP_SENSOR_ID_OTS:
    {
        HAL::ITimer* pTimer = HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_100MS);
        HAL::IAdc* pAdc = DriverManager::GetAdcDriver(ADC_ID_OKS);
        static TempSensorDriver ots(*pTimer, *pAdc, ADC_CHAN_OKS_TEMP, 2000.0f);
        returnVal =  &ots;
        break;
    }
    default:
        D_ASSERT(0);
        break;
    }

    return returnVal;
}

ILedDriver*  DriverManager::GetLedDriver(Driver::ID ID)
{
    ILedDriver* returnVal = NULL;

    switch (ID)
    {
    case Driver::LED_ID_STATUS:
    {
        static LED statusLED(*HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_U300_ALIVE), true, HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_10MS));
        returnVal =  &statusLED;
    }
        break;
    case Driver::LED_ID_COMMUNICATION:
    {
        static LED comsLED(*HAL::HAL_Manager::GetOutputPin(HAL::HAL_ID::OUTPUT_PIN_ID_COM_RCVD_CP), true, HAL::HAL_Manager::GetTimer(HAL::HAL_ID::TIMER_ID_10MS));
        returnVal =  &comsLED;
    }
        break;
    default:
        D_ASSERT(0);
        break;
    }

    return returnVal;
}

ISerialPortDriver* DriverManager::GetSerialPortDriver(Driver::ID ID)
{
    ISerialPortDriver *theDriver = NULL;


     switch(ID)
     {
     case SERIAL_PORT_ID_THERAPY:
     {
         static uint8_t therapyRxBuffer[2048];
         static uint8_t therapyTxBuffer[2048];
         // This is the port from the DUFB to the TBHB
         static SerialPortDriver therapyPort(  *HAL::HAL_Manager::GetUart(HAL::HAL_ID::UART_ID_TBCP),
                                                therapyRxBuffer,
                                                ARRAY_DIM(therapyRxBuffer),
                                                therapyTxBuffer,
                                                ARRAY_DIM(therapyTxBuffer));
         theDriver = &therapyPort;
     }
     break;
     case SERIAL_PORT_ID_PROTECTIVE:
     {
         static uint8_t protectiveRxBuffer[256];
         static uint8_t protectiveTxBuffer[256];
         // This is the port from the DUCP to the DUPP
         static SerialPortDriver protectivePort(  *HAL::HAL_Manager::GetUart(HAL::HAL_ID::UART_ID_DUPP),
                                                  protectiveRxBuffer,
                                                  ARRAY_DIM(protectiveRxBuffer),
                                                  protectiveTxBuffer,
                                                  ARRAY_DIM(protectiveTxBuffer));
         theDriver = &protectivePort;
     }
     break;
     case SERIAL_PORT_ID_DEBUG:
     {
         static uint8_t debugRxBuffer[2048];
         static uint8_t debugTxBuffer[2048];

         // Debug serial port
         static SerialPortDriver debugPort(  *HAL::HAL_Manager::GetUart(HAL::HAL_ID::UART_ID_DEBUG),
                                                  debugRxBuffer,
                                                  ARRAY_DIM(debugRxBuffer),
                                                  debugTxBuffer,
                                                  ARRAY_DIM(debugTxBuffer) );
         theDriver = &debugPort;
     }
     break;
     default:
         D_ASSERT(0);
         break;
     } //switch

     return theDriver;
}

IIpcDriver* DriverManager::GetIpcDriver(Driver::ID ID)
{
    IIpcDriver* theDriver = NULL;

    switch(ID)
    {
        case CAN_PORT_ID_SYSTEST:
        {
            static CanMsg rxMsg[CAN_MSG_COUNT];
            static CanMsg txMsg[CAN_MSG_COUNT];

            static IpcDriver sysTestCanDriver(*HAL::HAL_Manager::GetCan(HAL::HAL_ID::CAN_ID_SYSTEST),
                                              rxMsg, CAN_MSG_COUNT,
                                              txMsg, CAN_MSG_COUNT);

            theDriver = &sysTestCanDriver;
            break;
        }

        default:
            D_ASSERT(0);
            break;
    }

    return theDriver;
}

Driver::IHallEffectSensorDriver* DriverManager::GetHallEffectSensorDriver(Driver::ID ID)
{
    Driver::IHallEffectSensorDriver* theDriver = NULL;

    switch(ID)
    {
        case Driver::HALL_EFFECT_SENSOR_ID_FULL_VESSEL:
        {
            static Driver::DRV5503HallEffectSensorDriver hall1(*HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_LEVEL_SENSOR_HALL_1));
            theDriver = &hall1;
            break;
        }

        case Driver::HALL_EFFECT_SENSOR_ID_SPRAY:
        {
            static Driver::DRV5503HallEffectSensorDriver hall2(*HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_LEVEL_SENSOR_HALL_2));
            theDriver = &hall2;
            break;
        }

        case Driver::HALL_EFFECT_SENSOR_ID_UL_CONTROL:
        {
            static Driver::DRV5503HallEffectSensorDriver hall3(*HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_LEVEL_SENSOR_HALL_3));
            theDriver = &hall3;
            break;
        }

        case Driver::HALL_EFFECT_SENSOR_ID_LL_CONTROL:
        {
            static Driver::DRV5503HallEffectSensorDriver hall4(*HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_LEVEL_SENSOR_HALL_4));
            theDriver = &hall4;
            break;
        }

        case Driver::HALL_EFFECT_SENSOR_ID_EMPTY_VESSEL:
        {
            static Driver::DRV5503HallEffectSensorDriver hall5(*HAL::HAL_Manager::GetInputPin(HAL::HAL_ID::INPUT_PIN_ID_LEVEL_SENSOR_HALL_5));
            theDriver = &hall5;
            break;
        }

        default:
            D_ASSERT(0);
            break;
    }

    return theDriver;
}

Driver::ILevelSensorDriver* DriverManager::GetLevelSensorDriver(Driver::ID ID)
{
    Driver::ILevelSensorDriver* theDriver = NULL;
    Driver::IHallEffectSensor* h1 = GetHallEffectSensorDriver(Driver::HALL_EFFECT_SENSOR_ID_FULL_VESSEL);
    Driver::IHallEffectSensor* h2 = GetHallEffectSensorDriver(Driver::HALL_EFFECT_SENSOR_ID_SPRAY);
    Driver::IHallEffectSensor* h3 = GetHallEffectSensorDriver(Driver::HALL_EFFECT_SENSOR_ID_UL_CONTROL);
    Driver::IHallEffectSensor* h4 = GetHallEffectSensorDriver(Driver::HALL_EFFECT_SENSOR_ID_LL_CONTROL);
    Driver::IHallEffectSensor* h5 = GetHallEffectSensorDriver(Driver::HALL_EFFECT_SENSOR_ID_EMPTY_VESSEL);

    switch(ID)
    {
        case Driver::LEVEL_SENSOR_ID_DEGAS:
        {
            static Driver::DegasLevelSensorDriver gasLevel(h1,h2,h3,h4,h5);
            theDriver = &gasLevel;
            break;
        }

        default:
            D_ASSERT(0);
            break;
    }

    return theDriver;
}

Driver::IMemoryDriver* DriverManager::GetMemoryDriver(Driver::ID ID)
{
    // Only 1 memory type for now
    D_ASSERT(ID == Driver::MEMORY_DRIVER_ID_EEPROM);

    Driver::IMemoryDriver* theDriver = NULL;
    HAL::IEeprom* pEEPROM = HAL::HAL_Manager::GetEeprom();

    // Construct the one and only memory driver
    static EepromMemoryDriver memoryDriver(*pEEPROM);

    theDriver = &memoryDriver;

    return theDriver;
}

/// @brief Returns a PID controller by id
/// @brief Note: This is not a driver but access to the PID controller within
/// @brief any driver which also isA type of PID controller
/// @param ID driver ID
Driver::IPidController* DriverManager::GetPidController(Driver::ID ID)
{
    Driver::IPidController* controller = NULL;

    switch (ID)
    {
    case Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_DP1:
        /// Note: isA type of IPidController*
        controller = static_cast <Driver::IPidController*> (Driver::DriverManager::GetMotorSpeedControlDriver(Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_DP1));
        break;
    case Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_DP2:
          /// Note: isA type of IPidController*
          controller = static_cast <Driver::IPidController*> (Driver::DriverManager::GetMotorSpeedControlDriver(Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_DP2));
          break;
    default:
        D_ASSERT(0);
        break;
    }

    return controller;
}

/// @brief private static method to get common instance of speed control driver
/// @brief BldcMotorSpeedControlDriver is both an IMotorDriver and IPidController
/// @param id driver id
Driver::MotorSpeedControlDriver* DriverManager::GetMotorSpeedControlDriver(Driver::ID id)
{
    MotorSpeedControlDriver* returnVal = NULL;

    switch (id)
    {
    case Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_DP1:
        static Driver::MotorSpeedControlDriver bmsc_dp1(
                                        *DriverManager::GetPwmMotorDriver(Driver::PWM_MOTOR_ID_DP1),           // bldc motor to control
                                        *DriverManager::GetTachometerDriver(Driver::TACHOMETER_ID_DP1),          // bldc tach driver
                                        *HAL::HAL_Manager::GetTimerShared(HAL::HAL_ID::TIMER_ID_SHARED)         // shared timer
                                        );
        returnVal = &bmsc_dp1;
        break;
    case Driver::DIALYSATE_MOTOR_SPEED_CONTROL_ID_DP2:
        static Driver::MotorSpeedControlDriver bmsc_dp2(
                                        *DriverManager::GetPwmMotorDriver(Driver::PWM_MOTOR_ID_DP2),          //  motor to control
                                        *DriverManager::GetTachometerDriver(Driver::TACHOMETER_ID_DP2),         //  tach driver
                                        *HAL::HAL_Manager::GetTimerShared(HAL::HAL_ID::TIMER_ID_SHARED)         // shared timer
                                        );
        returnVal = &bmsc_dp2;
        break;
    default:
        D_ASSERT(0);
        break;
    }

    return returnVal;
}


} /* namespace Driver */
