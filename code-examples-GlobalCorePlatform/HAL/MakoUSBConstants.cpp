// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoUSBSubsystem::MakoUSBConstants'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoUSBConstants.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoUSBConstants.h>
#include <MakoPrivateBitfieldsReg4.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'USB1_TRANSCEIVER'
const int MakoUSBConstants::USB1_TRANSCEIVER( 0 );
// }}}RME

// {{{RME classAttribute 'USB2_TRANSCEIVER'
const int MakoUSBConstants::USB2_TRANSCEIVER( 1 );
// }}}RME

// {{{RME classAttribute 'USB_CURRENT_LIM_500mA'
const int MakoUSBConstants::USB_CURRENT_LIM_500mA( 1 );
// }}}RME

// {{{RME classAttribute 'USB_CURRENT_LIM_50mA'
const int MakoUSBConstants::USB_CURRENT_LIM_50mA( 0 );
// }}}RME

// {{{RME classAttribute 'USB_MODE_DEVICE'
const int MakoUSBConstants::USB_MODE_DEVICE( 0 );
// }}}RME

// {{{RME classAttribute 'USB_MODE_HOST'
const int MakoUSBConstants::USB_MODE_HOST( 1 );
// }}}RME

// {{{RME classAttribute 'USB_PULLDN_OFF'
const int MakoUSBConstants::USB_PULLDN_OFF( 0 );
// }}}RME

// {{{RME classAttribute 'USB_PULLDN_ON'
const int MakoUSBConstants::USB_PULLDN_ON( 1 );
// }}}RME

// {{{RME classAttribute 'USB_PULLUP_OFF'
const int MakoUSBConstants::USB_PULLUP_OFF( 0 );
// }}}RME

// {{{RME classAttribute 'USB_PULLUP_ON'
const int MakoUSBConstants::USB_PULLUP_ON( 1 );
// }}}RME

// {{{RME classAttribute 'USB_PWR_OFF'
const int MakoUSBConstants::USB_PWR_OFF( 0 );
// }}}RME

// {{{RME classAttribute 'USB_PWR_ON'
const int MakoUSBConstants::USB_PWR_ON( 1 );
// }}}RME

// {{{RME classAttribute 'USB_SPEED_FULL'
const int MakoUSBConstants::USB_SPEED_FULL( 1 );
// }}}RME

// {{{RME classAttribute 'USB_SPEED_LOW'
const int MakoUSBConstants::USB_SPEED_LOW( 0 );
// }}}RME

// {{{RME classAttribute 'MAKO_PHYIF_USB'
const int MakoUSBConstants::MAKO_PHYIF_USB( 1 );
// }}}RME

// {{{RME classAttribute 'MAKO_PHYIF_EIA232'
const int MakoUSBConstants::MAKO_PHYIF_EIA232( 0 );
// }}}RME

// {{{RME classAttribute 'USB_VBUS_0V'
const int MakoUSBConstants::USB_VBUS_0V( 0 );
// }}}RME

// {{{RME classAttribute 'USB_VBUS_5V'
const int MakoUSBConstants::USB_VBUS_5V( 1 );
// }}}RME

// {{{RME classAttribute 'VBUS_INDETERMINATE'
const int MakoUSBConstants::VBUS_INDETERMINATE( -999 );
// }}}RME

// {{{RME classAttribute 'VBUS_ERROR'
const int MakoUSBConstants::VBUS_ERROR( -99 );
// }}}RME

// {{{RME classAttribute 'USB_SUSPEND_ON'
const int MakoUSBConstants::USB_SUSPEND_ON( 1 );
// }}}RME

// {{{RME classAttribute 'USB_SUSPEND_OFF'
const int MakoUSBConstants::USB_SUSPEND_OFF( 1 );
// }}}RME

// {{{RME classAttribute 'USB_VBUS_DISCH_ON'
const int MakoUSBConstants::USB_VBUS_DISCH_ON( 1 );
// }}}RME

// {{{RME classAttribute 'USB_VBUS_DISCH_OFF'
const int MakoUSBConstants::USB_VBUS_DISCH_OFF( 0 );
// }}}RME

// {{{RME classAttribute 'USB_VBUS_MON_ON'
const int MakoUSBConstants::USB_VBUS_MON_ON( 1 );
// }}}RME

// {{{RME classAttribute 'USB_VBUS_MON_OFF'
const int MakoUSBConstants::USB_VBUS_MON_OFF( 0 );
// }}}RME

// {{{RME classAttribute 'MAKO_CTRL_STAT_DEFAULT'
const uint32_t MakoUSBConstants::MAKO_CTRL_STAT_DEFAULT( 0 );
// }}}RME

// {{{RME classAttribute 'MAKO_INT_EN_DEFAULT'
const uint32_t MakoUSBConstants::MAKO_INT_EN_DEFAULT( 0 );
// }}}RME

// {{{RME classAttribute 'MAKO_INT_FLAGS_DEFAULT'
const uint32_t MakoUSBConstants::MAKO_INT_FLAGS_DEFAULT( 0 );
// }}}RME

// {{{RME classAttribute 'USB_LDO_ON'
const int MakoUSBConstants::USB_LDO_ON( 1 );
// }}}RME

// {{{RME classAttribute 'USB_LDO_OFF'
const int MakoUSBConstants::USB_LDO_OFF( 0 );
// }}}RME

// {{{RME classAttribute 'USB_VBUS_INTR_EN'
const int MakoUSBConstants::USB_VBUS_INTR_EN( 1 );
// }}}RME

// {{{RME classAttribute 'MAKO_REG_CTRL_STAT'
const int MakoUSBConstants::MAKO_REG_CTRL_STAT( 0 );
// }}}RME

// {{{RME classAttribute 'MAKO_REG_INTR_EN'
const int MakoUSBConstants::MAKO_REG_INTR_EN( 2 );
// }}}RME

// {{{RME classAttribute 'MAKO_REG_FLAGS'
const int MakoUSBConstants::MAKO_REG_FLAGS( 1 );
// }}}RME

// {{{RME classAttribute 'IOVIRTUAL_PWRENABLE'
const int MakoUSBConstants::IOVIRTUAL_PWRENABLE( 2 );
// }}}RME

// {{{RME classAttribute 'IOVIRTUAL_VBUSDETECT'
const int MakoUSBConstants::IOVIRTUAL_VBUSDETECT( 4 );
// }}}RME

// {{{RME classAttribute 'IOVIRTUAL_DEVPUEN'
const int MakoUSBConstants::IOVIRTUAL_DEVPUEN( 0 );
// }}}RME

// {{{RME classAttribute 'IOVIRTUAL_SUSPEND'
const int MakoUSBConstants::IOVIRTUAL_SUSPEND( 3 );
// }}}RME

// {{{RME classAttribute 'USB_TRANSCEIVERS_BOTH'
const int MakoUSBConstants::USB_TRANSCEIVERS_BOTH( 2 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
