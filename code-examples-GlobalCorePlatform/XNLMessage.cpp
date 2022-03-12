// {{{RME classifier 'Logical View::XCMP::XNL::XNLMessage'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "XNLMessage.h"
#endif

#include <xnl_comp.h>
#include <XNLMessage.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'XNL_MSG_CLASS_TYPE'
const unsigned int XNLMessage::XNL_MSG_CLASS_TYPE( 7 );
// }}}RME

// {{{RME operation 'getType()'
ClassType XNLMessage::getType( void ) const
{
	// {{{USR
	return XNL_MSG_CLASS_TYPE;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLMessage()'
XNLMessage::XNLMessage( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_transactionId( 0 ),
	  m_isSendMessageToAll( false ),
	  m_originalDataBufferStart( 0 ),
	  m_deviceAuthLvl(XNL_AUTH_LVL_UNKNOWN),
	  m_msgPriority(XNL_NORMAL_TX_MSG_PRIORITY)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// Member-wise initialization of transaction ID to 0 in the C++ "ConstructorInitializer"
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLMessage(const XNLMessage&)'
XNLMessage::XNLMessage( const XNLMessage & xnlMessage )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: DataBuffer( &xnlMessage ),
	  m_fromDevice( xnlMessage.m_fromDevice ),
	  m_toDevice( xnlMessage.m_toDevice ),
	  m_transactionId( xnlMessage.m_transactionId ),
	  m_isSendMessageToAll( xnlMessage.m_isSendMessageToAll ),
	  m_originalDataBufferStart( xnlMessage.m_originalDataBufferStart ),
	  m_deviceAuthLvl(xnlMessage.m_deviceAuthLvl),
	  m_msgPriority(xnlMessage.m_msgPriority)

	// }}}USR
	// }}}RME
{
	// {{{USR
	// Member-wise initialization is in the C++ tab, "ConstructorInitializer" field

	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLMessage(void *,unsigned int,bool,unsigned int,unsigned int,unsigned int)'
XNLMessage::XNLMessage( void * buffer, unsigned int length, bool consumeBuffer, unsigned int frontPadding, unsigned int backPadding, unsigned int wasteCleanupThreshold )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: DataBuffer(buffer, length, consumeBuffer, frontPadding, backPadding, wasteCleanupThreshold),
	  m_transactionId( 0 ),
	  m_isSendMessageToAll( false ),
	  m_originalDataBufferStart( m_start ),
	  m_deviceAuthLvl(XNL_AUTH_LVL_UNKNOWN),
	  m_msgPriority(XNL_NORMAL_TX_MSG_PRIORITY)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// Member-wise initialization in C++ tab "ConstructorInitializer" field
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLMessage(const DataBuffer &,XNLDevice,XNLDevice,XCMPTransactionId,bool)'
XNLMessage::XNLMessage( const DataBuffer & dataBuffer, XNLDevice fromDevice, XNLDevice toDevice, XCMPTransactionId transactionId, bool isSendMessageToAll )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: DataBuffer( dataBuffer ),
	  m_fromDevice( fromDevice ),
	  m_toDevice( toDevice ),
	  m_transactionId( transactionId ),
	  m_isSendMessageToAll( isSendMessageToAll ),
	  m_originalDataBufferStart( m_start ),
	  m_deviceAuthLvl(XNL_AUTH_LVL_UNKNOWN),
	  m_msgPriority(XNL_NORMAL_TX_MSG_PRIORITY)

	// }}}USR
	// }}}RME
{
	// {{{USR
	// Member-wise initialization in C++ tab "ConstructorInitializer" field
	// }}}USR
}
// }}}RME

// {{{RME operation '~XNLMessage()'
XNLMessage::~XNLMessage( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'getFromDevice()'
XNLDevice XNLMessage::getFromDevice( void ) const
{
	// {{{USR
	return m_fromDevice;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getToDevice()'
XNLDevice XNLMessage::getToDevice( void ) const
{
	// {{{USR
	return m_toDevice;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getTransactionId()'
XCMPTransactionId XNLMessage::getTransactionId( void ) const
{
	// {{{USR
	return m_transactionId;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setTransactionId(XCMPTransactionId)'
void XNLMessage::setTransactionId( XCMPTransactionId transactionId )
{
	// {{{USR
	m_transactionId = transactionId;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isSendMessageToAll()'
bool XNLMessage::isSendMessageToAll( void ) const
{
	// {{{USR
	return m_isSendMessageToAll;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setFromDevice(const XNLDevice&)'
void XNLMessage::setFromDevice( const XNLDevice & device )
{
	// {{{USR
	m_fromDevice = device;

	// }}}USR
}
// }}}RME

// {{{RME operation 'setToDevice(const XNLDevice&)'
void XNLMessage::setToDevice( const XNLDevice & device )
{
	// {{{USR
	m_toDevice = device;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setIsSendMessageToAll(bool)'
void XNLMessage::setIsSendMessageToAll( bool isSendMessageToAll )
{
	// {{{USR
	m_isSendMessageToAll = isSendMessageToAll;
	// }}}USR
}
// }}}RME

// {{{RME operation 'resetDataBufferStart()'
void XNLMessage::resetDataBufferStart( void )
{
	// {{{USR
	m_start = m_originalDataBufferStart;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setDataBufferStart()'
void XNLMessage::setDataBufferStart( void )
{
	// {{{USR
	m_originalDataBufferStart = m_start;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool XNLMessage::isType( ClassType type ) const
{
	// {{{USR
	return (type == XNL_MSG_CLASS_TYPE ? true : DataBuffer::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDeviceAuthLvl()'
XNLAuthLevels XNLMessage::getDeviceAuthLvl( void ) const
{
	// {{{USR
	return m_deviceAuthLvl;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setDeviceAuthLvl(XNLAuthLevels)'
void XNLMessage::setDeviceAuthLvl( XNLAuthLevels authLevel )
{
	// {{{USR
	m_deviceAuthLvl = authLevel;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getMsgPriority()'
XNLInterthreadMsgPriority XNLMessage::getMsgPriority( void ) const
{
	// {{{USR
	return m_msgPriority;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setMsgPriority(XNLInterthreadMsgPriority)'
void XNLMessage::setMsgPriority( XNLInterthreadMsgPriority msgPriority )
{
	// {{{USR
	m_msgPriority = msgPriority;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
