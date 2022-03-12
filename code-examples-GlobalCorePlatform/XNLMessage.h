// {{{RME classifier 'Logical View::XCMP::XNL::XNLMessage'

#ifndef XNLMessage_H
#define XNLMessage_H

#ifdef PRAGMA
#pragma interface "XNLMessage.h"
#endif

#include <xnl_comp.h>
#include <DataBuffer.h>
#include <XCMPTransactionId.h>
#include <XNLAuthLevels.h>
#include <XNLDevice.h>
#include <XNLInterthreadMsgPriority.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#ifdef __LITTLE_ENDIAN__

// htonl means host to network long
#define xutil_htonl(addr) ((((uint32_t)(addr) & 0x000000FF) << 24) | \
(((uint32_t)(addr) & 0x0000FF00) << 8) | \
(((uint32_t)(addr) & 0x00FF0000) >> 8) | \
(((uint32_t)(addr) & 0xFF000000) >> 24))

#define xutil_ntohl(addr) xutil_htonl(addr)

#define xutil_htons(addr) ((((uint16_t)(addr) & 0x000000FF) << 8) | \
(((uint16_t)(addr) & 0x0000FF00) >> 8))

#define xutil_ntohs(addr) xutil_htons(addr)

#else

#define xutil_htonl(addr) ((uint32_t)(addr))

#define xutil_ntohl(addr) ((uint32_t)(addr))

#define xutil_htons(addr) ((uint16_t)(addr))

#define xutil_ntohs(addr) ((uint16_t)(addr))

#endif

// }}}USR
// }}}RME

class XNLMessage : public DataBuffer
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
	// {{{RME classAttribute 'm_isSendMessageToAll'
	bool m_isSendMessageToAll;
	// }}}RME
	// {{{RME classAttribute 'm_transactionId'
	XCMPTransactionId m_transactionId;
	// }}}RME
	// {{{RME classAttribute 'm_originalDataBufferStart'
	unsigned int m_originalDataBufferStart;
	// }}}RME

public:
	// {{{RME classAttribute 'XNL_MSG_CLASS_TYPE'
	static const unsigned int XNL_MSG_CLASS_TYPE;
	// }}}RME

private:
	// {{{RME classAttribute 'm_deviceAuthLvl'
	XNLAuthLevels m_deviceAuthLvl;
	// }}}RME
	// {{{RME classAttribute 'm_msgPriority'
	XNLInterthreadMsgPriority m_msgPriority;
	// }}}RME

protected:
	// {{{RME associationEnd 'm_toDevice'
	XNLDevice m_toDevice;
	// }}}RME
	// {{{RME associationEnd 'm_fromDevice'
	XNLDevice m_fromDevice;
	// }}}RME

public:
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'XNLMessage()'
	XNLMessage( void );
	// }}}RME
	// {{{RME operation 'XNLMessage(const XNLMessage&)'
	XNLMessage( const XNLMessage & xnlMessage );
	// }}}RME
	// {{{RME operation 'XNLMessage(void *,unsigned int,bool,unsigned int,unsigned int,unsigned int)'
	XNLMessage( void * buffer, unsigned int length, bool consumeBuffer = false, unsigned int frontPadding = DEFAULT_FRONT_PADDING, unsigned int backPadding = DEFAULT_BACK_PADDING, unsigned int wasteCleanupThreshold = MAX_SIZE );
	// }}}RME
	// {{{RME operation 'XNLMessage(const DataBuffer &,XNLDevice,XNLDevice,XCMPTransactionId,bool)'
	XNLMessage( const DataBuffer & dataBuffer, XNLDevice fromDevice, XNLDevice toDevice, XCMPTransactionId transactionId = 0, bool isSendMessageToAll = false );
	// }}}RME
	// {{{RME operation '~XNLMessage()'
	virtual ~XNLMessage( void );
	// }}}RME
	// {{{RME operation 'getFromDevice()'
	XNLDevice getFromDevice( void ) const;
	// }}}RME
	// {{{RME operation 'getToDevice()'
	XNLDevice getToDevice( void ) const;
	// }}}RME
	// {{{RME operation 'getTransactionId()'
	XCMPTransactionId getTransactionId( void ) const;
	// }}}RME
	// {{{RME operation 'setTransactionId(XCMPTransactionId)'
	void setTransactionId( XCMPTransactionId transactionId );
	// }}}RME
	// {{{RME operation 'isSendMessageToAll()'
	bool isSendMessageToAll( void ) const;
	// }}}RME
	// {{{RME operation 'setFromDevice(const XNLDevice&)'
	void setFromDevice( const XNLDevice & device );
	// }}}RME
	// {{{RME operation 'setToDevice(const XNLDevice&)'
	void setToDevice( const XNLDevice & device );
	// }}}RME
	// {{{RME operation 'setIsSendMessageToAll(bool)'
	void setIsSendMessageToAll( bool isSendMessageToAll );
	// }}}RME
	// {{{RME operation 'resetDataBufferStart()'
	void resetDataBufferStart( void );
	// }}}RME
	// {{{RME operation 'setDataBufferStart()'
	void setDataBufferStart( void );
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'getDeviceAuthLvl()'
	XNLAuthLevels getDeviceAuthLvl( void ) const;
	// }}}RME
	// {{{RME operation 'setDeviceAuthLvl(XNLAuthLevels)'
	void setDeviceAuthLvl( XNLAuthLevels authLevel );
	// }}}RME
	// {{{RME operation 'getMsgPriority()'
	XNLInterthreadMsgPriority getMsgPriority( void ) const;
	// }}}RME
	// {{{RME operation 'setMsgPriority(XNLInterthreadMsgPriority)'
	void setMsgPriority( XNLInterthreadMsgPriority msgPriority );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* XNLMessage_H */

// }}}RME
