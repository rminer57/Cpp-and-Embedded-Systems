// {{{RME classifier 'Logical View::XCMP::XNL::XNL_Protocol_Msgs::XNLDevAuthKeyReq'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "XNLDevAuthKeyReq.h"
#endif

#include <xnl_win32_comp.h>
#include <XNLDevAuthKeyReq.h>
#include <DataBuffer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
XNLDevAuthKeyReq::~XNLDevAuthKeyReq( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
XNLDevAuthKeyReq::XNLDevAuthKeyReq( const XNLDevAuthKeyReq & rtg_arg )
	: XNLProtocolMsg( rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
XNLDevAuthKeyReq & XNLDevAuthKeyReq::operator=( const XNLDevAuthKeyReq & rtg_arg )
{
	if( this != &rtg_arg )
		XNLProtocolMsg::operator=( rtg_arg );
	return *this;
}
// }}}RME

// {{{RME operation 'unserialize(Array*)'
bool XNLDevAuthKeyReq::unserialize( Array * buf )
{
	// {{{USR

	// Let the base class unserialize any common data
	// In this case, that's all of the data.

	bool bSuccess = XNLProtocolMsg::unserialize(buf);

	if (m_payloadSz != 0)
	{
		// then the subclass needs to delete the buffer.
		delete (buf);
	}

	return bSuccess;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLDevAuthKeyReq()'
XNLDevAuthKeyReq::XNLDevAuthKeyReq( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:XNLProtocolMsg(XNL_DEVICE_AUTH_KEY_REQUEST)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// see constructor initializer
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
