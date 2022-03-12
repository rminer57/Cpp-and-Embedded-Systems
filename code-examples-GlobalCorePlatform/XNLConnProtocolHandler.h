// {{{RME classifier 'Logical View::XCMP::XNL::XNLConnectionProtocolHandler::XNLConnProtocolHandler'

#ifndef XNLConnProtocolHandler_H
#define XNLConnProtocolHandler_H

#ifdef PRAGMA
#pragma interface "XNLConnProtocolHandler.h"
#endif

#include <xnl_win32_comp.h>
#include <ListenerBase.h>
#include <NotifierBase.h>
#include <XNL.h>
#include <XNLAuthLevels.h>
#include <XNLInit.h>
#include <XNLProtocolFailedEvent.h>
#include <XNLProtocolIdentifiers.h>
#include <XNLProtocolOpcodes.h>
class Array;
class Connection;
class DataBuffer;
class TimerVirtual;
class XNLAuthFailedEvent;
class XNLConnKeyEntry;
class XNLConnKeyList;
class XNLDevAuthKeyReply;
class XNLDevConnReply;
class XNLDevConnReq;
class XNLMessage;
class XNLProtocolMsg;
class XNLPrvStatus;
class XNLReplyFailEvent;
class XNLRoutingEntry;
class XNLStatus;
class XNLSysMapBrdcst;
class XNLSystemMap;
class XNLTimerInterthreadMsg;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
// This function must be implemented by any product picking up this component. XNL will call
// this function to obtain a 4-byte random number. It is up to the products to ensure that they
// return a "good" number as it will be used for such things as authentication.
extern uint32_t xnlRand();

// }}}USR
// }}}RME

class XNLConnProtocolHandler : public ListenerBase, public NotifierBase
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
	// {{{RME classAttribute 'm_bMasterDevice'
	bool m_bMasterDevice;
	// }}}RME
	// {{{RME classAttribute 'm_pXNL'
	XNL * m_pXNL;
	// }}}RME
	// {{{RME classAttribute 'm_pInitConn'
	Connection * m_pInitConn;
	// }}}RME
	// {{{RME classAttribute 'm_devType'
	uint8_t m_devType;
	// }}}RME
	// {{{RME classAttribute 'm_prefXNLAddr'
	uint16_t m_prefXNLAddr;
	// }}}RME
	// {{{RME classAttribute 'm_transactionIdBase'
	uint8_t m_transactionIdBase;
	// }}}RME
	// {{{RME classAttribute 'm_pPrvStatus'
	XNLPrvStatus * m_pPrvStatus;
	// }}}RME
	// {{{RME classAttribute 'm_pAddrMgr'
	XNL::AddrMgr * m_pAddrMgr;
	// }}}RME
	// {{{RME classAttribute 'm_pConnKeyList'
	XNLConnKeyList * m_pConnKeyList;
	// }}}RME
	// {{{RME classAttribute 'm_replWaitTime'
	uint16_t m_replWaitTime;
	// }}}RME
	// {{{RME classAttribute 'm_pOutstandingRequest'
	XNLProtocolMsg * m_pOutstandingRequest;
	// }}}RME
	// {{{RME classAttribute 'm_expiredTimerCnt'
	uint8_t m_expiredTimerCnt;
	// }}}RME

protected:
	// {{{RME associationEnd 'm_timer'
	TimerVirtual * m_timer;
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	XNLConnProtocolHandler( void );
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	XNLConnProtocolHandler( const XNLConnProtocolHandler & rtg_arg );
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	XNLConnProtocolHandler & operator=( const XNLConnProtocolHandler & rtg_arg );
	// }}}RME

public:
	// {{{RME operation 'init(const XNLInit&,Connection*,XNL::AddrMgr*)'
	void init( const XNLInit & xnlInit, Connection * pConnection, XNL::AddrMgr * pAddrMgr = 0 );
	// }}}RME
	// {{{RME operation 'processMessage(XNLProtocolMsg*,Connection*)'
	bool processMessage( XNLProtocolMsg * pMsg, Connection * pConnection );
	// }}}RME
	// {{{RME operation 'XNLConnProtocolHandler(XNL*,XNLPrvStatus*,TimerVirtual*,uint16_t)'
	XNLConnProtocolHandler( XNL * pXNL, XNLPrvStatus * pPrvStatus, TimerVirtual * timer, uint16_t timerTickBase );
	// }}}RME

private:
	// {{{RME operation 'requestAuthKey(uint16_t)'
	void requestAuthKey( uint16_t masterXNLAddr );
	// }}}RME
	// {{{RME operation 'processAuthKeyReq(XNLProtocolMsg*,Connection*)'
	bool processAuthKeyReq( XNLProtocolMsg * pRequest, Connection * pConnection );
	// }}}RME
	// {{{RME operation 'processAuthKeyReply(XNLDevAuthKeyReply*,Connection*)'
	bool processAuthKeyReply( XNLDevAuthKeyReply * pAuthKeyRep, Connection * pConnection );
	// }}}RME
	// {{{RME operation 'processConnRequest(XNLDevConnReq*,Connection*)'
	bool processConnRequest( XNLDevConnReq * pConnReq, Connection * pConnection );
	// }}}RME
	// {{{RME operation 'processConnReply(XNLDevConnReply*,Connection*)'
	bool processConnReply( XNLDevConnReply * pConnReply, Connection * pConnection );
	// }}}RME
	// {{{RME operation 'processSysMapBrdcst(XNLSysMapBrdcst*)'
	bool processSysMapBrdcst( XNLSysMapBrdcst * pBrdcst );
	// }}}RME
	// {{{RME operation 'generateAuthKey(const Connection*)'
	DataBuffer * generateAuthKey( const Connection * pConnection );
	// }}}RME
	// {{{RME operation 'assignTransactionIdBase()'
	uint8_t assignTransactionIdBase( void );
	// }}}RME
	// {{{RME operation 'authenticateDevice(const DataBuffer*,XNLAuthLevels,const Connection*,uint32_t*,uint32_t)'
	bool authenticateDevice( const DataBuffer * pAuthValue, XNLAuthLevels authLevel, const Connection * pConn, uint32_t * authKey, uint32_t delta_val );
	// }}}RME

public:
	// {{{RME operation 'encryptKey(const DataBuffer*,XNLAuthLevels,uint32_t*,uint32_t)'
	DataBuffer * encryptKey( const DataBuffer * randomKey, XNLAuthLevels authLvl, uint32_t * authKey, uint32_t delta_val );
	// }}}RME
	// {{{RME operation '~XNLConnProtocolHandler()'
	virtual ~XNLConnProtocolHandler( void );
	// }}}RME
	// {{{RME operation 'sendSysMapBrdcst(uint16_t,Connection*)'
	bool sendSysMapBrdcst( uint16_t destAddr, Connection * pConn = 0 );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase* const)'
	virtual void eventOccurred( const EventBase * const event );
	// }}}RME
	// {{{RME operation 'procTimerExpiration()'
	void procTimerExpiration( void );
	// }}}RME
	// {{{RME operation 'stopTimer()'
	void stopTimer( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* XNLConnProtocolHandler_H */

// }}}RME
