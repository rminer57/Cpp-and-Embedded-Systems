// {{{RME classifier 'Logical View::XCMP::XNL::XNL_Protocol_Msgs::XNLDevConnReq'

#ifndef XNLDevConnReq_H
#define XNLDevConnReq_H

#ifdef PRAGMA
#pragma interface "XNLDevConnReq.h"
#endif

#include <xnl_win32_comp.h>
#include <XNLAuthLevels.h>
#include <XNLProtocolMsg.h>
class DataBuffer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'AUTH_VALUE_SZ'
#define AUTH_VALUE_SZ 8
// }}}RME

class XNLDevConnReq : public XNLProtocolMsg
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
	// {{{RME classAttribute 'm_prefXNLAddr'
	uint16_t m_prefXNLAddr;
	// }}}RME
	// {{{RME classAttribute 'm_deviceType'
	uint8_t m_deviceType;
	// }}}RME
	// {{{RME classAttribute 'm_authLvl'
	XNLAuthLevels m_authLvl;
	// }}}RME
	// {{{RME classAttribute 'm_encryptAuthValue'
	DataBuffer * m_encryptAuthValue;
	// }}}RME

public:
	// {{{RME operation 'getAuthLevel()'
	XNLAuthLevels getAuthLevel( void ) const;
	// }}}RME
	// {{{RME operation 'setAuthLevel(XNLAuthLevels)'
	void setAuthLevel( XNLAuthLevels authLvl );
	// }}}RME
	// {{{RME operation 'getDeviceType()'
	uint8_t getDeviceType( void ) const;
	// }}}RME
	// {{{RME operation 'setDeviceType(uint8_t)'
	void setDeviceType( uint8_t devtype );
	// }}}RME
	// {{{RME operation 'getPrefXNLAddr()'
	uint16_t getPrefXNLAddr( void ) const;
	// }}}RME
	// {{{RME operation 'setPrefXNLAddr(uint16_t)'
	void setPrefXNLAddr( uint16_t devAddr );
	// }}}RME
	// {{{RME operation 'getAuthValue()'
	DataBuffer * getAuthValue( void );
	// }}}RME
	// {{{RME operation 'setAuthValue(DataBuffer *)'
	void setAuthValue( DataBuffer * authValue );
	// }}}RME
	// {{{RME operation 'serialize()'
	virtual Array * serialize( void );
	// }}}RME
	// {{{RME operation 'unserialize(Array*)'
	virtual bool unserialize( Array * buf );
	// }}}RME
	// {{{RME operation 'XNLDevConnReq()'
	XNLDevConnReq( void );
	// }}}RME
	// {{{RME operation '~XNLDevConnReq()'
	~XNLDevConnReq( void );
	// }}}RME

private:
	// {{{RME operation 'XNLDevConnReq(const XNLDevConnReq &)'
	XNLDevConnReq( const XNLDevConnReq & rtg_arg );
	// }}}RME
	// {{{RME operation 'operator=(const XNLDevConnReq &)'
	XNLDevConnReq & operator=( const XNLDevConnReq & rtg_arg );
	// }}}RME

public:
	// {{{RME operation 'getXNLDisableAckFlag()'
	uint8_t getXNLDisableAckFlag( void );
	// }}}RME
	// {{{RME operation 'setXNLDisableAckFlag(uint8_t)'
	void setXNLDisableAckFlag( uint8_t flagValue );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* XNLDevConnReq_H */

// }}}RME
