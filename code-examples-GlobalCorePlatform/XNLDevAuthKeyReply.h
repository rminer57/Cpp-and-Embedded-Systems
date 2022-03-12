// {{{RME classifier 'Logical View::XCMP::XNL::XNL_Protocol_Msgs::XNLDevAuthKeyReply'

#ifndef XNLDevAuthKeyReply_H
#define XNLDevAuthKeyReply_H

#ifdef PRAGMA
#pragma interface "XNLDevAuthKeyReply.h"
#endif

#include <xnl_win32_comp.h>
#include <XNLProtocolMsg.h>
class DataBuffer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'AUTH_KEY_SZ'
#define AUTH_KEY_SZ 8
// }}}RME

class XNLDevAuthKeyReply : public XNLProtocolMsg
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
	// {{{RME classAttribute 'm_tmpXNLAddr'
	uint16_t m_tmpXNLAddr;
	// }}}RME
	// {{{RME classAttribute 'm_unencryptAuthValue'
	DataBuffer * m_unencryptAuthValue;
	// }}}RME

public:
	// {{{RME operation 'getXNLAddr()'
	uint16_t getXNLAddr( void ) const;
	// }}}RME
	// {{{RME operation 'setXNLAddr(uint16_t)'
	void setXNLAddr( uint16_t xnlAddr );
	// }}}RME
	// {{{RME operation 'getAuthKey()'
	DataBuffer * getAuthKey( void );
	// }}}RME
	// {{{RME operation 'setAuthKey(DataBuffer *)'
	void setAuthKey( DataBuffer * authdb );
	// }}}RME
	// {{{RME operation 'serialize()'
	virtual Array * serialize( void );
	// }}}RME
	// {{{RME operation 'unserialize(Array*)'
	virtual bool unserialize( Array * buf );
	// }}}RME
	// {{{RME operation 'XNLDevAuthKeyReply()'
	XNLDevAuthKeyReply( void );
	// }}}RME
	// {{{RME operation '~XNLDevAuthKeyReply()'
	~XNLDevAuthKeyReply( void );
	// }}}RME

private:
	// {{{RME operation 'XNLDevAuthKeyReply(const XNLDevAuthKeyReply &)'
	XNLDevAuthKeyReply( const XNLDevAuthKeyReply & rtg_arg );
	// }}}RME
	// {{{RME operation 'operator=(const XNLDevAuthKeyReply &)'
	XNLDevAuthKeyReply & operator=( const XNLDevAuthKeyReply & rtg_arg );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* XNLDevAuthKeyReply_H */

// }}}RME
