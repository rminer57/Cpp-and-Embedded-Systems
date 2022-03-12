// {{{RME classifier 'Logical View::XCMP::XNL::XNL_Protocol_Msgs::XNLDevConnReply'

#ifndef XNLDevConnReply_H
#define XNLDevConnReply_H

#ifdef PRAGMA
#pragma interface "XNLDevConnReply.h"
#endif

#include <xnl_win32_comp.h>
#include <XNLDevice.h>
#include <XNLProtocolMsg.h>
class DataBuffer;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'XNL_SUCCESS'
#define XNL_SUCCESS 1
// }}}RME

// {{{RME classAttribute 'XNL_FAILURE'
#define XNL_FAILURE 0
// }}}RME

class XNLDevConnReply : public XNLProtocolMsg
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
	// {{{RME classAttribute 'm_resultCode'
	uint8_t m_resultCode;
	// }}}RME
	// {{{RME classAttribute 'm_transactionIdBase'
	uint8_t m_transactionIdBase;
	// }}}RME
	// {{{RME classAttribute 'm_xnlAddr'
	uint16_t m_xnlAddr;
	// }}}RME
	// {{{RME classAttribute 'm_deviceAddr'
	XNLDevice m_deviceAddr;
	// }}}RME
	// {{{RME classAttribute 'm_encryptAuthValue'
	DataBuffer * m_encryptAuthValue;
	// }}}RME

public:
	// {{{RME operation 'getResult()'
	uint8_t getResult( void ) const;
	// }}}RME
	// {{{RME operation 'setResult(uint8_t)'
	void setResult( uint8_t result );
	// }}}RME
	// {{{RME operation 'getTransactionIdBase()'
	uint8_t getTransactionIdBase( void ) const;
	// }}}RME
	// {{{RME operation 'setTransactionIdBase(uint8_t)'
	void setTransactionIdBase( uint8_t transIdBase );
	// }}}RME
	// {{{RME operation 'getXNLAddr()'
	uint16_t getXNLAddr( void ) const;
	// }}}RME
	// {{{RME operation 'setXNLAddr(uint16_t)'
	void setXNLAddr( uint16_t addr );
	// }}}RME
	// {{{RME operation 'serialize()'
	virtual Array * serialize( void );
	// }}}RME
	// {{{RME operation 'unserialize(Array*)'
	virtual bool unserialize( Array * buf );
	// }}}RME
	// {{{RME operation 'XNLDevConnReply()'
	XNLDevConnReply( void );
	// }}}RME
	// {{{RME operation 'getDeviceAddr()'
	XNLDevice getDeviceAddr( void ) const;
	// }}}RME
	// {{{RME operation 'setDeviceAddr(const XNLDevice&)'
	void setDeviceAddr( const XNLDevice & deviceAddr );
	// }}}RME
	// {{{RME operation 'getAuthValue()'
	DataBuffer * getAuthValue( void );
	// }}}RME
	// {{{RME operation 'setAuthValue(DataBuffer *)'
	void setAuthValue( DataBuffer * authValue );
	// }}}RME
	// {{{RME operation '~XNLDevConnReply()'
	virtual ~XNLDevConnReply( void );
	// }}}RME

protected:
	// {{{RME operation 'XNLDevConnReply(const XNLDevConnReply & )'
	XNLDevConnReply( const XNLDevConnReply & rtg_arg );
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

#endif /* XNLDevConnReply_H */

// }}}RME
