// {{{RME classifier 'Logical View::XCMP::XNL::XNLProtocolOpcodes'

#ifndef XNLProtocolOpcodes_H
#define XNLProtocolOpcodes_H

#ifdef PRAGMA
#pragma interface "XNLProtocolOpcodes.h"
#endif

#include <xnl_win32_comp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

enum XNLProtocolOpcodes
{
	XNL_MASTER_PRESENT_BRDCST = 0x0001
  , XNL_MASTER_STATUS_BRDCST = 0x0002
  , XNL_DEVICE_MASTER_QUERY = 0x0003
  , XNL_DEVICE_AUTH_KEY_REQUEST = 0x0004
  , XNL_DEVICE_AUTH_KEY_REPLY = 0x0005
  , XNL_DEVICE_CONN_REQUEST = 0x0006
  , XNL_DEVICE_CONN_REPLY = 0x0007
  , XNL_DEVICE_SYSMAP_REQUEST = 0x0008
  , XNL_DEVICE_SYSMAP_BRDCST = 0x0009
  , XNL_DEVICE_RESET_MSG = 0x000A
  , XNL_DATA_MSG = 0x000B
  , XNL_DATA_MSG_ACK = 0x000C
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* XNLProtocolOpcodes_H */

// }}}RME
