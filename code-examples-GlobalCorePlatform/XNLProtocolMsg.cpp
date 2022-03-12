// {{{RME classifier 'Logical View::XCMP::XNL::XNL_Protocol_Msgs::XNLProtocolMsg'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "XNLProtocolMsg.h"
#endif

#include <xnl_comp.h>
#include <XNLProtocolMsg.h>
#include <DataBuffer.h>
#include <XNLMessage.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'BASE_MSG_SZ'
#define BASE_MSG_SZ 12
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
XNLProtocolMsg::XNLProtocolMsg( void )
	: m_payloadSz( 0 )
	, m_xnlFlags( 0 )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
XNLProtocolMsg::~XNLProtocolMsg( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
XNLProtocolMsg::XNLProtocolMsg( const XNLProtocolMsg & rtg_arg )
	: Serializable_D( rtg_arg )
	, m_xnlOpcode( rtg_arg.m_xnlOpcode )
	, m_protocolId( rtg_arg.m_protocolId )
	, m_destAddr( rtg_arg.m_destAddr )
	, m_sourceAddr( rtg_arg.m_sourceAddr )
	, m_transactionId( rtg_arg.m_transactionId )
	, m_payloadSz( rtg_arg.m_payloadSz )
	, m_xnlFlags( rtg_arg.m_xnlFlags )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
XNLProtocolMsg & XNLProtocolMsg::operator=( const XNLProtocolMsg & rtg_arg )
{
	if( this != &rtg_arg )
	{
		Serializable_D::operator=( rtg_arg );
		m_xnlOpcode = rtg_arg.m_xnlOpcode;
		m_protocolId = rtg_arg.m_protocolId;
		m_destAddr = rtg_arg.m_destAddr;
		m_sourceAddr = rtg_arg.m_sourceAddr;
		m_transactionId = rtg_arg.m_transactionId;
		m_payloadSz = rtg_arg.m_payloadSz;
		m_xnlFlags = rtg_arg.m_xnlFlags;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'getXNLMsgOpcode(const DataBuffer *)'
XNLProtocolOpcodes XNLProtocolMsg::getXNLMsgOpcode( const DataBuffer * xnlPMsg )
{
	// {{{USR
	uint16_t val = (uint16_t)unpackValue(xnlPMsg, 2, 0);
	return (XNLProtocolOpcodes)val;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getXNLMsgDestAddr(const DataBuffer *)'
uint16_t XNLProtocolMsg::getXNLMsgDestAddr( const DataBuffer * xnlPMsg )
{
	// {{{USR
	uint16_t addr = (uint16_t)unpackValue(xnlPMsg, 2, 4);
	return addr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getXNLMsgSrcAddr(const DataBuffer *)'
uint16_t XNLProtocolMsg::getXNLMsgSrcAddr( const DataBuffer * xnlPMsg )
{
	// {{{USR
	uint16_t addr = (uint16_t)unpackValue(xnlPMsg, 2, 6);
	return addr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getOpcode()'
XNLProtocolOpcodes XNLProtocolMsg::getOpcode( void ) const
{
	// {{{USR
	return (m_xnlOpcode);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getProtocolId()'
XNLProtocolIdentifiers XNLProtocolMsg::getProtocolId( void ) const
{
	// {{{USR
	return (m_protocolId);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setProtocolId(XNLProtocolIdentifiers)'
void XNLProtocolMsg::setProtocolId( XNLProtocolIdentifiers protocolId )
{
	// {{{USR
	m_protocolId = protocolId;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDestAddr()'
uint16_t XNLProtocolMsg::getDestAddr( void ) const
{
	// {{{USR
	return (m_destAddr);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setDestAddr(uint16_t)'
void XNLProtocolMsg::setDestAddr( uint16_t destAddr )
{
	// {{{USR
	m_destAddr = destAddr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getSourceAddr()'
uint16_t XNLProtocolMsg::getSourceAddr( void ) const
{
	// {{{USR
	return (m_sourceAddr);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setSourceAddr(uint16_t)'
void XNLProtocolMsg::setSourceAddr( uint16_t sourceAddr )
{
	// {{{USR
	m_sourceAddr = sourceAddr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getTransactionId()'
uint16_t XNLProtocolMsg::getTransactionId( void ) const
{
	// {{{USR
	return (m_transactionId);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setTransactionId(uint16_t)'
void XNLProtocolMsg::setTransactionId( uint16_t transactionId )
{
	// {{{USR
	m_transactionId = transactionId;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize()'
Array * XNLProtocolMsg::serialize( void )
{
	// {{{USR
	bool bSuccess = false;

	// Create a buffer big enough to hold the common data plus any payload
	DataBuffer* pBuf = new DataBuffer(0, 0, false, 0, BASE_MSG_SZ + m_payloadSz);

	// The opcode is an enum so cast it to a uint16_t before attempting to pack it
	if (appendValue(pBuf, (uint16_t)m_xnlOpcode))
	{
		// The protocol ID is an enum so cast it to a uint8_t before
		// attempting to pack it.
		uint8_t tmpByte = (uint8_t)m_protocolId;
		if (pBuf->append(&tmpByte, sizeof(tmpByte)))
		{
			// Pack the XNL msg flags
			if (pBuf->append(&m_xnlFlags, sizeof(m_xnlFlags)))
			{
				// Pack the destination address
				if (appendValue(pBuf, m_destAddr))
				{
					// Pack the source address
					if (appendValue(pBuf, m_sourceAddr))
					{
						// Pack the transaction ID
						if (appendValue(pBuf, m_transactionId))
						{
							// Pack the size of the payload
							bSuccess = appendValue(pBuf, m_payloadSz);
						}
					}
				}
			}
		}
	}

	if (!bSuccess)
	{
		delete pBuf;
		pBuf = 0;
	}

	return pBuf;
	// }}}USR
}
// }}}RME

// {{{RME operation 'unserialize(Array*)'
bool XNLProtocolMsg::unserialize( Array * buf )
{
	// {{{USR

	bool bSuccess = false;

	if (buf)
	{
		DataBuffer* pBuf = (DataBuffer*)buf;

		// Make sure the message has a minimum size equal to that of the base
		// protocol message
		if (pBuf->getSize() >= BASE_MSG_SZ)
		{
			int index = 0;

			// Get the opcode from the message
			m_xnlOpcode = (XNLProtocolOpcodes)unpackValue(pBuf, 2, index);
			index += 2;

			// Get the protocol ID
			m_protocolId = (XNLProtocolIdentifiers)((*pBuf)[index++]);
			
			// Unpack the byte containing the XNL flags
			m_xnlFlags = (*pBuf)[index++];

			// Get the dest address
			m_destAddr = (uint16_t)unpackValue(pBuf, sizeof(m_destAddr), index);
			index += sizeof(m_destAddr);

			// Get the source address
			m_sourceAddr = (uint16_t)unpackValue(pBuf, sizeof(m_sourceAddr), index);
			index += sizeof(m_sourceAddr);

			// Get the transaction ID
			m_transactionId = (uint16_t)unpackValue(pBuf, sizeof(m_transactionId), index);
			index += sizeof(m_transactionId);

			// Get the payload size
			m_payloadSz = (uint16_t)unpackValue(pBuf, sizeof(m_payloadSz), index);

			if (m_payloadSz == 0)
			{
				// Consume the buffer
				delete pBuf;
			}
			else
			{
				// "Delete" the data we unserialized from the buffer so that data belonging to
				// any derived classes will appear to be at offset 0. (Note that we're not truly
				// deleting it from the buffer. erase() only causes the start location of the
				// DataBuffer to be shifted over but the bytes are still there. But it's a cheaper
				// operation than doing an extract.)
				pBuf->erase(0, BASE_MSG_SZ);
			}

			bSuccess = true;
		}
		else
		{
			// ERROR LOG HERE

			delete buf;
		}
	}

	return bSuccess;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLProtocolMsg(XNLProtocolOpcodes)'
XNLProtocolMsg::XNLProtocolMsg( XNLProtocolOpcodes opcode )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_xnlOpcode(opcode), m_protocolId(XNL_PROTO_XNL_CTRL), m_destAddr(0),
	  m_sourceAddr(0), m_transactionId(0), m_payloadSz(0), m_xnlFlags(0)

	// }}}USR
	// }}}RME
{
	// {{{USR
	// See constructor initializer
	// }}}USR
}
// }}}RME

// {{{RME operation 'addValue(DataBuffer*,uint16_t,unsigned int)'
bool XNLProtocolMsg::addValue( DataBuffer * pBuf, uint16_t value, unsigned int offset )
{
	// {{{USR
	value = xutil_htons(value);
	return pBuf->add((void*)&value, sizeof(value), offset);
	// }}}USR
}
// }}}RME

// {{{RME operation 'addValue(DataBuffer*,uint32_t,unsigned int)'
bool XNLProtocolMsg::addValue( DataBuffer * pBuf, uint32_t value, unsigned int offset )
{
	// {{{USR
	value = xutil_htonl(value);
	return pBuf->add((void*)&value, sizeof(value), offset);
	// }}}USR
}
// }}}RME

// {{{RME operation 'appendValue(DataBuffer*,uint16_t)'
bool XNLProtocolMsg::appendValue( DataBuffer * pBuf, uint16_t value )
{
	// {{{USR
	value = xutil_htons(value);
	return pBuf->append((void*)&value, sizeof(value));
	// }}}USR
}
// }}}RME

// {{{RME operation 'appendValue(DataBuffer*,uint32_t)'
bool XNLProtocolMsg::appendValue( DataBuffer * pBuf, uint32_t value )
{
	// {{{USR
	value = xutil_htonl(value);
	return pBuf->append((void*)&value, sizeof(value));
	// }}}USR
}
// }}}RME

// {{{RME operation 'unpackValue(const DataBuffer*,uint8_t,unsigned int)'
uint32_t XNLProtocolMsg::unpackValue( const DataBuffer * pBuf, uint8_t numBytes, unsigned int offset )
{
	// {{{USR
	uint32_t value = 0;

	if (numBytes > 0 && (numBytes <= 4))
	{
		// Make sure we're not trying to unpack outside buffer
		if (pBuf && (pBuf->getSize() >= (offset + numBytes)))
		{
			for (int i = numBytes-1; i >= 0; i--)
			{
				value |= ((uint32_t)((*pBuf)[offset++])) << (i*8);
			}
		}
	}

	return value;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getPayloadSize()'
uint16_t XNLProtocolMsg::getPayloadSize( void ) const
{
	// {{{USR
	return m_payloadSz;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setPayloadSize(uint16_t)'
void XNLProtocolMsg::setPayloadSize( uint16_t payloadSz )
{
	// {{{USR
	m_payloadSz = payloadSz;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setMsgCount(uint8_t)'
void XNLProtocolMsg::setMsgCount( uint8_t msgCnt )
{
	// {{{USR
	// clear the existing lower 3 bits, just in case something was previously set
	m_xnlFlags &= ~(0x07);

	// Mask off the lower 3 bits in the specified count and set
	// them into the byte containing the various flags
	m_xnlFlags |= (msgCnt & 0x7);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getMsgCount()'
uint8_t XNLProtocolMsg::getMsgCount( void ) const
{
	// {{{USR
	return (m_xnlFlags & 0x07);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
