// {{{RME classifier 'Logical View::XCMP::XNL::XNL_Protocol_Msgs::XNLDevAuthKeyReply'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "XNLDevAuthKeyReply.h"
#endif

#include <xnl_win32_comp.h>
#include <XNLDevAuthKeyReply.h>
#include <DataBuffer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'PAYLOAD_SZ'
#define PAYLOAD_SZ AUTH_KEY_SZ + 2
// }}}RME

// {{{RME operation 'getXNLAddr()'
uint16_t XNLDevAuthKeyReply::getXNLAddr( void ) const
{
	// {{{USR
	return (m_tmpXNLAddr);
	// }}}USR
}
// }}}RME

// {{{RME operation 'setXNLAddr(uint16_t)'
void XNLDevAuthKeyReply::setXNLAddr( uint16_t xnlAddr )
{
	// {{{USR
	m_tmpXNLAddr = xnlAddr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getAuthKey()'
DataBuffer * XNLDevAuthKeyReply::getAuthKey( void )
{
	// {{{USR
	DataBuffer* pRetBuf = m_unencryptAuthValue;
	m_unencryptAuthValue = 0;
	return pRetBuf;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setAuthKey(DataBuffer *)'
void XNLDevAuthKeyReply::setAuthKey( DataBuffer * authdb )
{
	// {{{USR
	if (m_unencryptAuthValue != 0)
		delete m_unencryptAuthValue;

	m_unencryptAuthValue = authdb;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize()'
Array * XNLDevAuthKeyReply::serialize( void )
{
	// {{{USR
	bool bSuccess = false;

	// Set the size of the data specific to the AuthKey Reply message
	setPayloadSize(PAYLOAD_SZ);

	// Have the base class serialize any common data
	DataBuffer* pBuf = (DataBuffer*)XNLProtocolMsg::serialize();

	if (pBuf)
	{
		// Pack the temporary XNL address
		if (appendValue(pBuf, m_tmpXNLAddr))
		{
			// Pack the unencrypted authorization key
			bSuccess = pBuf->append(m_unencryptAuthValue);
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
bool XNLDevAuthKeyReply::unserialize( Array * buf )
{
	// {{{USR
	bool bSuccess = false;

	// Let the base class unserialize any common data
	if (XNLProtocolMsg::unserialize(buf))
	{
		DataBuffer* pBuf = (DataBuffer*)buf;

		if (m_payloadSz == PAYLOAD_SZ)
		{
			m_tmpXNLAddr = (uint16_t)unpackValue(pBuf, sizeof(m_tmpXNLAddr), 0);

			// Remove the data at the front of the msg so the only thing left is
			// the auth key.
			pBuf->erase(0, sizeof(m_tmpXNLAddr));

			// Store a pointer to the authorization key.
			m_unencryptAuthValue = pBuf;

			bSuccess = true;
		}
		else
		{
			// ERROR LOG HERE

			
			// CAUTION: The buffer only gets deleted if an error occurred because,
			// otherwise, we set our authValue ptr to reference the buffer.
			if (m_payloadSz > 0)
				delete buf;
		}
	}

	return bSuccess;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLDevAuthKeyReply()'
XNLDevAuthKeyReply::XNLDevAuthKeyReply( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: XNLProtocolMsg(XNL_DEVICE_AUTH_KEY_REPLY), m_unencryptAuthValue(0), m_tmpXNLAddr(0)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// See constructor initializer
	// }}}USR
}
// }}}RME

// {{{RME operation '~XNLDevAuthKeyReply()'
XNLDevAuthKeyReply::~XNLDevAuthKeyReply( void )
{
	// {{{USR
	if (m_unencryptAuthValue != 0)
		delete m_unencryptAuthValue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLDevAuthKeyReply(const XNLDevAuthKeyReply &)'
XNLDevAuthKeyReply::XNLDevAuthKeyReply( const XNLDevAuthKeyReply & rtg_arg )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: XNLProtocolMsg( rtg_arg )
	, m_tmpXNLAddr( rtg_arg.m_tmpXNLAddr )
	, m_unencryptAuthValue( 0 )
	// }}}USR
	// }}}RME
{
	// {{{USR
	if(rtg_arg.m_unencryptAuthValue != 0)
	{
		m_unencryptAuthValue=rtg_arg.m_unencryptAuthValue->copyToDataBuffer();
	}

	// }}}USR
}
// }}}RME

// {{{RME operation 'operator=(const XNLDevAuthKeyReply &)'
XNLDevAuthKeyReply & XNLDevAuthKeyReply::operator=( const XNLDevAuthKeyReply & rtg_arg )
{
	// {{{USR
	if( this != &rtg_arg )
	{
		XNLProtocolMsg::operator=( rtg_arg );
		m_tmpXNLAddr = rtg_arg.m_tmpXNLAddr;

		if(m_unencryptAuthValue != 0)
		{
			delete m_unencryptAuthValue;
			m_unencryptAuthValue=0;
		}

		if(rtg_arg.m_unencryptAuthValue != 0)
		{
			m_unencryptAuthValue=rtg_arg.m_unencryptAuthValue->copyToDataBuffer();
		}

	}
	return *this;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
