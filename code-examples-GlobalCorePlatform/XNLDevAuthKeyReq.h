// {{{RME classifier 'Logical View::XCMP::XNL::XNL_Protocol_Msgs::XNLDevAuthKeyReq'

#ifndef XNLDevAuthKeyReq_H
#define XNLDevAuthKeyReq_H

#ifdef PRAGMA
#pragma interface "XNLDevAuthKeyReq.h"
#endif

#include <xnl_win32_comp.h>
#include <XNLProtocolMsg.h>
class DataBuffer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class XNLDevAuthKeyReq : public XNLProtocolMsg
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~XNLDevAuthKeyReq( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	XNLDevAuthKeyReq( const XNLDevAuthKeyReq & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	XNLDevAuthKeyReq & operator=( const XNLDevAuthKeyReq & rtg_arg );
	// }}}RME
	// {{{RME operation 'unserialize(Array*)'
	virtual bool unserialize( Array * buf );
	// }}}RME
	// {{{RME operation 'XNLDevAuthKeyReq()'
	XNLDevAuthKeyReq( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* XNLDevAuthKeyReq_H */

// }}}RME
