// {{{RME classifier 'Logical View::XCMP::XNL::XNL_Protocol_Msgs::XNLDevConnReply'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "XNLDevConnReply.h"
#endif

#include <xnl_win32_comp.h>
#include <XNLDevConnReply.h>
#include <DataBuffer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
#define XNL_ACK_FLAG_POSITION 0x08
// }}}USR
// }}}RME

// {{{RME classAttribute 'PAYLOAD_SZ'
#define PAYLOAD_SZ 14
// }}}RME

// {{{RME operation 'getResult()'
uint8_t XNLDevConnReply::getResult( void ) const
{
	// {{{USR
	return (m_resultCode);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setResult(uint8_t)'
void XNLDevConnReply::setResult( uint8_t result )
{
	// {{{USR
	m_resultCode = result;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getTransactionIdBase()'
uint8_t XNLDevConnReply::getTransactionIdBase( void ) const
{
	// {{{USR
	return (m_transactionIdBase);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setTransactionIdBase(uint8_t)'
void XNLDevConnReply::setTransactionIdBase( uint8_t transIdBase )
{
	// {{{USR
	m_transactionIdBase = transIdBase;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getXNLAddr()'
uint16_t XNLDevConnReply::getXNLAddr( void ) const
{
	// {{{USR
	return (m_xnlAddr);

	// }}}USR
}
// }}}RME

// {{{RME operation 'setXNLAddr(uint16_t)'
void XNLDevConnReply::setXNLAddr( uint16_t addr )
{
	// {{{USR
	m_xnlAddr = addr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize()'
Array * XNLDevConnReply::serialize( void )
{
	// {{{USR
	bool bSuccess = false;

	// Set the size of the data specific to the Connection Reply message
	setPayloadSize(PAYLOAD_SZ);

	// Have the base class serialize any common data
	DataBuffer* pBuf = (DataBuffer*)XNLProtocolMsg::serialize();

	if (pBuf)
	{
		// Pack the result code
		if (pBuf->append(&m_resultCode, sizeof(m_resultCode)))
		{
			// Pack the transactionID base
			if (pBuf->append(&m_transactionIdBase, sizeof(m_transactionIdBase)))
			{
				// Pack the assigned XNL address
				if (appendValue(pBuf, m_xnlAddr))
				{
					// Pack the logical address
					uint8_t tmpVal = m_deviceAddr.getDeviceType();
					if (pBuf->append(&tmpVal, sizeof(tmpVal)))
					{
						tmpVal = m_deviceAddr.getId();
						if (pBuf->append(&tmpVal, sizeof(tmpVal)))
						{
							// Pack the encrypted authorization value
							if (m_encryptAuthValue != 0)
								bSuccess = pBuf->append(m_encryptAuthValue);
							else
							{
								// It will fail on the unserialize side but go ahead and
								// allow the message to be serialized/sent.
								bSuccess = true;
							}
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
bool XNLDevConnReply::unserialize( Array * buf )
{
	// {{{USR
	bool bSuccess = false;

	// Let the base class unserialize any common data
	if (XNLProtocolMsg::unserialize(buf))
	{
		DataBuffer* pBuf = (DataBuffer*)buf;

		if (m_payloadSz == PAYLOAD_SZ)
		{
			int index = 0;

			// Unpack the result code
			m_resultCode = (*pBuf)[index++];

			// Unpack the transactionID base
			m_transactionIdBase = (*pBuf)[index++];

			// Unpack the assigned XNL address
			m_xnlAddr = (uint16_t)unpackValue(pBuf, sizeof(m_xnlAddr), index);
			index += sizeof(m_xnlAddr);

			// Unpack the logical address
			m_deviceAddr.setDeviceType((*pBuf)[index++]);
			m_deviceAddr.setId((*pBuf)[index++]);

			// Remove the data at the front of the msg so the only thing left is
			// the auth key.
			pBuf->erase(0, index);

			// Store a pointer to the encrypted authorization value
			m_encryptAuthValue = pBuf;

			bSuccess = true;
		}
		else
		{
			m_encryptAuthValue = 0;

			// ERROR LOG HERE

			// CAUTION: The buffer only gets deleted if an error occurred because,
			// otherwise, we set our encrypted auth value ptr to reference the buffer.
			delete buf;
		}
	}

	return bSuccess;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLDevConnReply()'
XNLDevConnReply::XNLDevConnReply( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: XNLProtocolMsg(XNL_DEVICE_CONN_REPLY), m_resultCode(0),
	  m_transactionIdBase(0), m_xnlAddr(0), m_deviceAddr(0,0), m_encryptAuthValue(0)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// See constructor initializer
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDeviceAddr()'
XNLDevice XNLDevConnReply::getDeviceAddr( void ) const
{
	// {{{USR
	return m_deviceAddr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setDeviceAddr(const XNLDevice&)'
void XNLDevConnReply::setDeviceAddr( const XNLDevice & deviceAddr )
{
	// {{{USR
	m_deviceAddr = deviceAddr;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getAuthValue()'
DataBuffer * XNLDevConnReply::getAuthValue( void )
{
	// {{{USR
	DataBuffer* pAuthValue = m_encryptAuthValue;
	m_encryptAuthValue = 0;
	return (pAuthValue);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setAuthValue(DataBuffer *)'
void XNLDevConnReply::setAuthValue( DataBuffer * authValue )
{
	// {{{USR
	if (m_encryptAuthValue != 0)
		delete m_encryptAuthValue;

	m_encryptAuthValue = authValue;
	// }}}USR
}
// }}}RME

// {{{RME operation '~XNLDevConnReply()'
XNLDevConnReply::~XNLDevConnReply( void )
{
	// {{{USR
	if (m_encryptAuthValue)
		delete m_encryptAuthValue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLDevConnReply(const XNLDevConnReply & )'
XNLDevConnReply::XNLDevConnReply( const XNLDevConnReply & rtg_arg )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
		: XNLProtocolMsg( rtg_arg )
		, m_resultCode( rtg_arg.m_resultCode )
		, m_transactionIdBase( rtg_arg.m_transactionIdBase )
		, m_xnlAddr( rtg_arg.m_xnlAddr )
		, m_deviceAddr( rtg_arg.m_deviceAddr )
		, m_encryptAuthValue( 0 )
	// }}}USR
	// }}}RME
{
	// {{{USR
	if ( rtg_arg.m_encryptAuthValue )
	{
		m_encryptAuthValue=rtg_arg.m_encryptAuthValue->copyToDataBuffer();
	}

	// }}}USR
}
// }}}RME

// {{{RME operation 'getXNLDisableAckFlag()'
uint8_t XNLDevConnReply::getXNLDisableAckFlag( void )
{
	// {{{USR
	// Get only the XNL Ack Flag value and strip the rest

	return (m_xnlFlags & XNL_ACK_FLAG_POSITION);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setXNLDisableAckFlag(uint8_t)'
void XNLDevConnReply::setXNLDisableAckFlag( uint8_t flagValue )
{
	// {{{USR
	// Set only the XNL Ack Flag value
	m_xnlFlags = (flagValue & XNL_ACK_FLAG_POSITION);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
