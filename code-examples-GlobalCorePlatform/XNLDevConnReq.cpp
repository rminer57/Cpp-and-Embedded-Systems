// {{{RME classifier 'Logical View::XCMP::XNL::XNL_Protocol_Msgs::XNLDevConnReq'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "XNLDevConnReq.h"
#endif

#include <xnl_win32_comp.h>
#include <XNLDevConnReq.h>
#include <DataBuffer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
#define XNL_ACK_FLAG_POSITION 0x08
// }}}USR
// }}}RME

// {{{RME classAttribute 'PAYLOAD_SZ'
#define PAYLOAD_SZ AUTH_VALUE_SZ + 4
// }}}RME

// {{{RME operation 'getAuthLevel()'
XNLAuthLevels XNLDevConnReq::getAuthLevel( void ) const
{
	// {{{USR
	return (m_authLvl);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setAuthLevel(XNLAuthLevels)'
void XNLDevConnReq::setAuthLevel( XNLAuthLevels authLvl )
{
	// {{{USR
	m_authLvl = authLvl;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDeviceType()'
uint8_t XNLDevConnReq::getDeviceType( void ) const
{
	// {{{USR
	return (m_deviceType);

	// }}}USR
}
// }}}RME

// {{{RME operation 'setDeviceType(uint8_t)'
void XNLDevConnReq::setDeviceType( uint8_t devtype )
{
	// {{{USR
	m_deviceType = devtype;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getPrefXNLAddr()'
uint16_t XNLDevConnReq::getPrefXNLAddr( void ) const
{
	// {{{USR
	return (m_prefXNLAddr);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setPrefXNLAddr(uint16_t)'
void XNLDevConnReq::setPrefXNLAddr( uint16_t devAddr )
{
	// {{{USR
	m_prefXNLAddr = devAddr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getAuthValue()'
DataBuffer * XNLDevConnReq::getAuthValue( void )
{
	// {{{USR
	DataBuffer* pAuthValue = m_encryptAuthValue;
	m_encryptAuthValue = 0;
	return (pAuthValue);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setAuthValue(DataBuffer *)'
void XNLDevConnReq::setAuthValue( DataBuffer * authValue )
{
	// {{{USR
	if (m_encryptAuthValue != 0)
		delete m_encryptAuthValue;

	m_encryptAuthValue = authValue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize()'
Array * XNLDevConnReq::serialize( void )
{
	// {{{USR
	bool bSuccess = false;

	// Set the size of the data specific to the ConnectionRequest message
	setPayloadSize(PAYLOAD_SZ);

	// Have the base class serialize any common data
	DataBuffer* pBuf = (DataBuffer*)XNLProtocolMsg::serialize();

	if (pBuf)
	{
		// Pack the preferred XNL address
		if (appendValue(pBuf, m_prefXNLAddr))
		{
			// Pack the device type
			if (pBuf->append(&m_deviceType, sizeof(m_deviceType)))
			{
				// The auth level is an enum so we have to cast it to
				// the correct type
				uint8_t authLvl = (uint8_t)m_authLvl;

				// Pack the auth level
				if (pBuf->append(&authLvl, sizeof(authLvl)))
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
bool XNLDevConnReq::unserialize( Array * buf )
{
	// {{{USR
	bool bSuccess = false;
	m_payloadSz = 0;

	// Let the base class unserialize any common data
	if (XNLProtocolMsg::unserialize(buf))
	{
		DataBuffer* pBuf = (DataBuffer*)buf;

		if (m_payloadSz == PAYLOAD_SZ)
		{
			int index = 0;

			// Unpack the preferred XNL address
			m_prefXNLAddr = (uint16_t)unpackValue(pBuf, sizeof(m_prefXNLAddr), index);
			index += sizeof(m_prefXNLAddr);

			// Unpack the device type
			m_deviceType = (*pBuf)[index++];

			// Unpack the auth level
			m_authLvl = (XNLAuthLevels)((*pBuf)[index++]);

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
			// otherwise, we set our authValue ptr to reference the buffer.
			delete buf;
		}
	}

	return bSuccess;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLDevConnReq()'
XNLDevConnReq::XNLDevConnReq( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: XNLProtocolMsg(XNL_DEVICE_CONN_REQUEST), m_authLvl(XNL_AUTH_LVL_INT), m_deviceType(0), m_encryptAuthValue(0), m_prefXNLAddr(0)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// See constructor initializer
	// }}}USR
}
// }}}RME

// {{{RME operation '~XNLDevConnReq()'
XNLDevConnReq::~XNLDevConnReq( void )
{
	// {{{USR
	if (m_encryptAuthValue != 0)
		delete m_encryptAuthValue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLDevConnReq(const XNLDevConnReq &)'
XNLDevConnReq::XNLDevConnReq( const XNLDevConnReq & rtg_arg )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: XNLProtocolMsg( rtg_arg )
	, m_prefXNLAddr( rtg_arg.m_prefXNLAddr )
	, m_deviceType( rtg_arg.m_deviceType )
	, m_authLvl( rtg_arg.m_authLvl )
	, m_encryptAuthValue(0)
	// }}}USR
	// }}}RME
{
	// {{{USR
	if(rtg_arg.m_encryptAuthValue != 0)
	{
		m_encryptAuthValue=rtg_arg.m_encryptAuthValue->copyToDataBuffer();
	}

	// }}}USR
}
// }}}RME

// {{{RME operation 'operator=(const XNLDevConnReq &)'
XNLDevConnReq & XNLDevConnReq::operator=( const XNLDevConnReq & rtg_arg )
{
	// {{{USR
	if( this != &rtg_arg )
	{
		XNLProtocolMsg::operator=( rtg_arg );
		m_prefXNLAddr = rtg_arg.m_prefXNLAddr;
		m_deviceType = rtg_arg.m_deviceType;
		m_authLvl = rtg_arg.m_authLvl;

		if(m_encryptAuthValue)
		{
			delete m_encryptAuthValue;
			m_encryptAuthValue=0;
		}

		if(rtg_arg.m_encryptAuthValue != 0)
		{
			m_encryptAuthValue=rtg_arg.m_encryptAuthValue->copyToDataBuffer();
		}

	}
	return *this;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getXNLDisableAckFlag()'
uint8_t XNLDevConnReq::getXNLDisableAckFlag( void )
{
	// {{{USR
	// Get only the XNL Ack Flag value and strip the rest

	return (m_xnlFlags & XNL_ACK_FLAG_POSITION);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setXNLDisableAckFlag(uint8_t)'
void XNLDevConnReq::setXNLDisableAckFlag( uint8_t flagValue )
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
