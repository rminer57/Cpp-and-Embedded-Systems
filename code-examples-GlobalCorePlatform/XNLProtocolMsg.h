// {{{RME classifier 'Logical View::XCMP::XNL::XNL_Protocol_Msgs::XNLProtocolMsg'

#ifndef XNLProtocolMsg_H
#define XNLProtocolMsg_H

#ifdef PRAGMA
#pragma interface "XNLProtocolMsg.h"
#endif

#include <xnl_win32_comp.h>
#include <Serializable_D.h>
#include <XNLProtocolIdentifiers.h>
#include <XNLProtocolOpcodes.h>
class DataBuffer;
class XNLMessage;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class XNLProtocolMsg : public Serializable_D
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

protected:
	// {{{RME classAttribute 'm_xnlOpcode'
	XNLProtocolOpcodes m_xnlOpcode;
	// }}}RME
	// {{{RME classAttribute 'm_protocolId'
	XNLProtocolIdentifiers m_protocolId;
	// }}}RME
	// {{{RME classAttribute 'm_destAddr'
	uint16_t m_destAddr;
	// }}}RME
	// {{{RME classAttribute 'm_sourceAddr'
	uint16_t m_sourceAddr;
	// }}}RME
	// {{{RME classAttribute 'm_transactionId'
	uint16_t m_transactionId;
	// }}}RME
	// {{{RME classAttribute 'm_payloadSz'
	uint16_t m_payloadSz;
	// }}}RME
	// {{{RME classAttribute 'm_xnlFlags'
	uint8_t m_xnlFlags;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	XNLProtocolMsg( void );
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~XNLProtocolMsg( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	XNLProtocolMsg( const XNLProtocolMsg & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	XNLProtocolMsg & operator=( const XNLProtocolMsg & rtg_arg );
	// }}}RME
	// {{{RME operation 'getXNLMsgOpcode(const DataBuffer *)'
	static XNLProtocolOpcodes getXNLMsgOpcode( const DataBuffer * xnlPMsg );
	// }}}RME
	// {{{RME operation 'getXNLMsgDestAddr(const DataBuffer *)'
	static uint16_t getXNLMsgDestAddr( const DataBuffer * xnlPMsg );
	// }}}RME
	// {{{RME operation 'getXNLMsgSrcAddr(const DataBuffer *)'
	static uint16_t getXNLMsgSrcAddr( const DataBuffer * xnlPMsg );
	// }}}RME
	// {{{RME operation 'getOpcode()'
	XNLProtocolOpcodes getOpcode( void ) const;
	// }}}RME
	// {{{RME operation 'getProtocolId()'
	XNLProtocolIdentifiers getProtocolId( void ) const;
	// }}}RME
	// {{{RME operation 'setProtocolId(XNLProtocolIdentifiers)'
	void setProtocolId( XNLProtocolIdentifiers protocolId );
	// }}}RME
	// {{{RME operation 'getDestAddr()'
	uint16_t getDestAddr( void ) const;
	// }}}RME
	// {{{RME operation 'setDestAddr(uint16_t)'
	void setDestAddr( uint16_t destAddr );
	// }}}RME
	// {{{RME operation 'getSourceAddr()'
	uint16_t getSourceAddr( void ) const;
	// }}}RME
	// {{{RME operation 'setSourceAddr(uint16_t)'
	void setSourceAddr( uint16_t sourceAddr );
	// }}}RME
	// {{{RME operation 'getTransactionId()'
	uint16_t getTransactionId( void ) const;
	// }}}RME
	// {{{RME operation 'setTransactionId(uint16_t)'
	void setTransactionId( uint16_t transactionId );
	// }}}RME
	// {{{RME operation 'serialize()'
	virtual Array * serialize( void );
	// }}}RME
	// {{{RME operation 'unserialize(Array*)'
	virtual bool unserialize( Array * buf );
	// }}}RME
	// {{{RME operation 'XNLProtocolMsg(XNLProtocolOpcodes)'
	XNLProtocolMsg( XNLProtocolOpcodes opcode );
	// }}}RME
	// {{{RME operation 'addValue(DataBuffer*,uint16_t,unsigned int)'
	static bool addValue( DataBuffer * pBuf, uint16_t value, unsigned int offset = 0 );
	// }}}RME
	// {{{RME operation 'addValue(DataBuffer*,uint32_t,unsigned int)'
	static bool addValue( DataBuffer * pBuf, uint32_t value, unsigned int offset = 0 );
	// }}}RME
	// {{{RME operation 'appendValue(DataBuffer*,uint16_t)'
	static bool appendValue( DataBuffer * pBuf, uint16_t value );
	// }}}RME
	// {{{RME operation 'appendValue(DataBuffer*,uint32_t)'
	static bool appendValue( DataBuffer * pBuf, uint32_t value );
	// }}}RME
	// {{{RME operation 'unpackValue(const DataBuffer*,uint8_t,unsigned int)'
	static uint32_t unpackValue( const DataBuffer * pBuf, uint8_t numBytes, unsigned int offset = 0 );
	// }}}RME
	// {{{RME operation 'getPayloadSize()'
	uint16_t getPayloadSize( void ) const;
	// }}}RME

protected:
	// {{{RME operation 'setPayloadSize(uint16_t)'
	void setPayloadSize( uint16_t payloadSz );
	// }}}RME

public:
	// {{{RME operation 'setMsgCount(uint8_t)'
	void setMsgCount( uint8_t msgCnt );
	// }}}RME
	// {{{RME operation 'getMsgCount()'
	uint8_t getMsgCount( void ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* XNLProtocolMsg_H */

// }}}RME
