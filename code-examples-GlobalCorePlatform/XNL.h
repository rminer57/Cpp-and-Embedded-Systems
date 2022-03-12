// {{{RME classifier 'Logical View::XCMP::XNL::XNL'

#ifndef XNL_H
#define XNL_H

#ifdef PRAGMA
#pragma interface "XNL.h"
#endif

#include <xnl_win32_comp.h>
#include <Channel.h>
#include <Connection.h>
#include <Message.h>
#include <Thread.h>
#include <XNLAuthKeySets.h>
#include <XNLChannelStatus.h>
#include <XNLInit.h>
#include <XNLPrvStatus.h>
#include <XNLRxMsgQueue.h>
class DataBuffer;
class MessageQueue;
class Mutex;
class TimerVirtualFactory;
class XNLCommFailedEvent;
class XNLConnProtocolHandler;
class XNLDataMsg;
class XNLDevAuthKeyReply;
class XNLDevAuthKeyReq;
class XNLDevConnReply;
class XNLDevConnReq;
class XNLDevMasterQuery;
class XNLDevice;
class XNLMasterArbitrator;
class XNLMasterPresentBrdcst;
class XNLMasterStsBrdcst;
class XNLMessage;
class XNLProtocolMsg;
class XNLResetEvent;
class XNLResetMsg;
class XNLRoutingEntry;
class XNLRxInterthreadMsg;
class XNLStatus;
class XNLSysMapBrdcst;
class XNLSysMapData;
class XNLSysMapReq;
class XNLSystemMap;
class XNLTimerInterthreadMsg;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
// This function must be implemented by any product picking up this component. XNL will call
// this function to obtain a 4-byte random number. It is up to the products to ensure that they
// return a "good" number as it will be used for such things as authentication.
extern uint32_t xnlRand();

// The following function pointer is used for multiple key authentication.
// It takes 3 parameters: value to be authenticated, auth level,and random key.
// It returns re-encrypted key used to reply to the requesting device.
// This function must be implemented by the product team.
// XNL will call this function to authenticate the multiple XNL keys.
typedef DataBuffer* (*AUTHKEYFUNCPTR)(const DataBuffer*, XNLAuthLevels, const DataBuffer*);

// }}}USR
// }}}RME
// {{{RME classifier 'XNLSendInterthreadMsg' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'AddrMgr' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Logical View::XCMP::XNL::XNL::AddrMgr::DeviceTypeNode' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLThreadEndMsg' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLUnregisterConnectionMsg' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLRegisterConnectionMsg' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'XNLSendInterthreadMsg' classAttribute 'XNL_SEND_SPECIFIC_MSG_TYPE'
#define XNL_SEND_SPECIFIC_MSG_TYPE SPECIFIC_MSG_TYPE_BASE + 1
// }}}RME

class XNL : public Thread, public Channel
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

public:
	// {{{RME classifier 'XNLSendInterthreadMsg'
	class XNLSendInterthreadMsg : public Message
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
		// {{{RME classAttribute 'm_xnlMsg'
		XNLMessage * m_xnlMsg;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
		XNLSendInterthreadMsg( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		XNLSendInterthreadMsg( const XNLSendInterthreadMsg & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		XNLSendInterthreadMsg & operator=( const XNLSendInterthreadMsg & rtg_arg );
		// }}}RME

	public:
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'serialize()'
		Array * serialize( void );
		// }}}RME
		// {{{RME operation 'unserialize(Array *)'
		bool unserialize( Array * buf );
		// }}}RME
		// {{{RME operation 'getXNLMsg()'
		XNLMessage * getXNLMsg( void );
		// }}}RME
		// {{{RME operation 'XNLSendInterthreadMsg(XNLMessage *)'
		XNLSendInterthreadMsg( XNLMessage * xnlMsg );
		// }}}RME
		// {{{RME operation '~XNLSendInterthreadMsg()'
		~XNLSendInterthreadMsg( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'AddrMgr'
	class AddrMgr
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

	public:
		// {{{RME classifier 'DeviceTypeNode'
		class DeviceTypeNode
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
			// {{{RME classAttribute 'm_next'
			DeviceTypeNode * m_next;
			// }}}RME
			// {{{RME classAttribute 'm_deviceType'
			uint8_t m_deviceType;
			// }}}RME
			// {{{RME classAttribute 'm_deviceIDBitmap'
			uint8_t m_deviceIDBitmap[ 32 ];
			// }}}RME
			// {{{RME classAttribute 'm_mutex'
			Mutex * m_mutex;
			// }}}RME

		protected:
			// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
			DeviceTypeNode( const DeviceTypeNode & rtg_arg );
			// }}}RME
			// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
			DeviceTypeNode & operator=( const DeviceTypeNode & rtg_arg );
			// }}}RME

		public:
			// {{{RME operation 'DeviceTypeNode(uint8_t,XNL::AddrMgr::DeviceTypeNode*)'
			DeviceTypeNode( uint8_t devType, DeviceTypeNode * nextNode );
			// }}}RME
			// {{{RME operation 'assignID()'
			uint8_t assignID( void );
			// }}}RME
			// {{{RME operation 'getNext()'
			DeviceTypeNode * getNext( void );
			// }}}RME
			// {{{RME operation 'getDeviceType()'
			uint8_t getDeviceType( void ) const;
			// }}}RME
			// {{{RME operation 'unassignID(uint8_t)'
			void unassignID( uint8_t deviceID );
			// }}}RME
			// {{{RME operation '~DeviceTypeNode()'
			virtual ~DeviceTypeNode( void );
			// }}}RME
		};
		// }}}RME

	private:
		// {{{RME classAttribute 'm_permXNLAddr'
		uint16_t m_permXNLAddr;
		// }}}RME
		// {{{RME classAttribute 'm_pReservedXNLAddrArr'
		uint16_t * m_pReservedXNLAddrArr;
		// }}}RME
		// {{{RME classAttribute 'm_tmpXNLAddr'
		uint16_t m_tmpXNLAddr;
		// }}}RME
		// {{{RME classAttribute 'm_prefAddrArrIndex'
		unsigned int m_prefAddrArrIndex;
		// }}}RME
		// {{{RME classAttribute 'm_prefAddrArrSz'
		unsigned int m_prefAddrArrSz;
		// }}}RME
		// {{{RME classAttribute 'm_deviceTypeList'
		DeviceTypeNode * m_deviceTypeList;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
		AddrMgr( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		AddrMgr( const AddrMgr & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		AddrMgr & operator=( const AddrMgr & rtg_arg );
		// }}}RME

	public:
		// {{{RME operation 'assignXNLAddr(uint16_t)'
		uint16_t assignXNLAddr( uint16_t prefXNLAddr );
		// }}}RME
		// {{{RME operation 'assignTmpXNLAddr()'
		uint16_t assignTmpXNLAddr( void );
		// }}}RME
		// {{{RME operation 'assignLogicalAddr(uint8_t)'
		XNLDevice assignLogicalAddr( uint8_t devType );
		// }}}RME
		// {{{RME operation 'AddrMgr(uint8_t)'
		AddrMgr( uint8_t maxPrefAddresses );
		// }}}RME
		// {{{RME operation '~AddrMgr()'
		~AddrMgr( void );
		// }}}RME
		// {{{RME operation 'unassignLogicalAddr(const XNLDevice&)'
		void unassignLogicalAddr( const XNLDevice & logicalAddr ) const;
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'XNLThreadEndMsg'
	class XNLThreadEndMsg : public Message
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

	public:
		// {{{RME classAttribute 'XNL_THREAD_END_MSG_TYPE'
		static const unsigned int XNL_THREAD_END_MSG_TYPE;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~XNLThreadEndMsg( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		XNLThreadEndMsg( const XNLThreadEndMsg & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		XNLThreadEndMsg & operator=( const XNLThreadEndMsg & rtg_arg );
		// }}}RME
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'serialize()'
		virtual Array * serialize( void );
		// }}}RME
		// {{{RME operation 'unserialize(Array*)'
		virtual bool unserialize( Array * buf );
		// }}}RME
		// {{{RME operation 'XNLThreadEndMsg()'
		XNLThreadEndMsg( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'XNLUnregisterConnectionMsg'
	class XNLUnregisterConnectionMsg : public Message
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

	public:
		// {{{RME classAttribute 'XNL_UNREGISTER_CONN_TYPE'
		static const unsigned int XNL_UNREGISTER_CONN_TYPE;
		// }}}RME

	private:
		// {{{RME classAttribute 'm_connection'
		Connection * m_connection;
		// }}}RME

	public:
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~XNLUnregisterConnectionMsg( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		XNLUnregisterConnectionMsg( const XNLUnregisterConnectionMsg & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		XNLUnregisterConnectionMsg & operator=( const XNLUnregisterConnectionMsg & rtg_arg );
		// }}}RME
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'serialize()'
		virtual Array * serialize( void );
		// }}}RME
		// {{{RME operation 'unserialize(Array*)'
		virtual bool unserialize( Array * buf );
		// }}}RME
		// {{{RME operation 'XNLUnregisterConnectionMsg(Connection *)'
		XNLUnregisterConnectionMsg( Connection * connection );
		// }}}RME
		// {{{RME operation 'getConnection()'
		Connection * getConnection( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'XNLRegisterConnectionMsg'
	class XNLRegisterConnectionMsg : public Message
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

	public:
		// {{{RME classAttribute 'XNL_REGISTER_CONN_TYPE'
		static const unsigned int XNL_REGISTER_CONN_TYPE;
		// }}}RME

	private:
		// {{{RME classAttribute 'm_connection'
		Connection * m_connection;
		// }}}RME
		// {{{RME classAttribute 'm_authKeySets'
		XNLAuthKeySets * m_authKeySets;
		// }}}RME
		// {{{RME classAttribute 'm_authKeyFuncPtr'
		AUTHKEYFUNCPTR m_authKeyFuncPtr;
		// }}}RME

	public:
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~XNLRegisterConnectionMsg( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		XNLRegisterConnectionMsg( const XNLRegisterConnectionMsg & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		XNLRegisterConnectionMsg & operator=( const XNLRegisterConnectionMsg & rtg_arg );
		// }}}RME
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'serialize()'
		virtual Array * serialize( void );
		// }}}RME
		// {{{RME operation 'unserialize(Array*)'
		virtual bool unserialize( Array * buf );
		// }}}RME
		// {{{RME operation 'XNLRegisterConnectionMsg(Connection *,XNLAuthKeySets *,AUTHKEYFUNCPTR)'
		XNLRegisterConnectionMsg( Connection * connection, XNLAuthKeySets * authKeySets, AUTHKEYFUNCPTR authKeyFuncPtr = 0 );
		// }}}RME
		// {{{RME operation 'getConnection()'
		Connection * getConnection( void );
		// }}}RME
		// {{{RME operation 'getAuthKeySets()'
		XNLAuthKeySets * getAuthKeySets( void );
		// }}}RME
		// {{{RME operation 'getFunctionPtr()'
		AUTHKEYFUNCPTR getFunctionPtr( void );
		// }}}RME
	};
	// }}}RME

private:
	// {{{RME classAttribute 'm_XNLVersionNumber'
	static const uint32_t m_XNLVersionNumber;
	// }}}RME
	// {{{RME classAttribute 'm_dataMsgSent'
	bool m_dataMsgSent;
	// }}}RME
	// {{{RME classAttribute 'XNL_MSG_QUEUE_NAME'
	static const char * const XNL_MSG_QUEUE_NAME;
	// }}}RME
	// {{{RME classAttribute 'm_xnlThreadRunning'
	bool m_xnlThreadRunning;
	// }}}RME
	// {{{RME classAttribute 'm_masterDetermined'
	bool m_masterDetermined;
	// }}}RME
	// {{{RME classAttribute 'm_timerTickBase'
	uint16_t m_timerTickBase;
	// }}}RME
	// {{{RME classAttribute 'm_xnlClassInstance'
	static XNL * m_xnlClassInstance;
	// }}}RME

protected:
	// {{{RME associationEnd 'm_xnlMsgQueue'
	MessageQueue * m_xnlMsgQueue;
	// }}}RME
	// {{{RME associationEnd 'm_xnlInitInfo'
	XNLInit m_xnlInitInfo;
	// }}}RME
	// {{{RME associationEnd 'm_xnlRoutingList'
	XNLRoutingEntry ** m_xnlRoutingList;
	// }}}RME
	// {{{RME associationEnd 'm_rxMsgQueue'
	XNLRxMsgQueue m_rxMsgQueue;
	// }}}RME
	// {{{RME associationEnd 'm_xnlChanStatus'
	XNLChannelStatus m_xnlChanStatus;
	// }}}RME
	// {{{RME associationEnd 'm_xnlPrvStatus'
	XNLPrvStatus m_xnlPrvStatus;
	// }}}RME
	// {{{RME associationEnd 'm_routingEntryMutex'
	Mutex * m_routingEntryMutex;
	// }}}RME
	// {{{RME associationEnd 'm_addrMgr'
	AddrMgr * m_addrMgr;
	// }}}RME
	// {{{RME associationEnd 'm_masterArbitrator'
	XNLMasterArbitrator * m_masterArbitrator;
	// }}}RME
	// {{{RME associationEnd 'm_xnlConnProtoHandler'
	XNLConnProtocolHandler * m_xnlConnProtoHandler;
	// }}}RME
	// {{{RME associationEnd 'm_timerFactory'
	TimerVirtualFactory * m_timerFactory;
	// }}}RME

private:
	// {{{RME operation 'registerConnectionUtil(Connection *,XNLAuthKeySets *,AUTHKEYFUNCPTR)'
	bool registerConnectionUtil( Connection * connection, XNLAuthKeySets * authKeySets, AUTHKEYFUNCPTR authKeyFuncPtr = 0 );
	// }}}RME
	// {{{RME operation 'unregisterConnectionUtil(Connection *)'
	bool unregisterConnectionUtil( Connection * connection );
	// }}}RME

public:
	// {{{RME operation 'validateRoutingEntry(Connection *,uint16_t,XNLDevice &)'
	virtual bool validateRoutingEntry( Connection * conn, uint16_t xnlAddr, XNLDevice & logDev );
	// }}}RME
	// {{{RME operation 'connect(ChannelAddress *,unsigned int *)'
	virtual bool connect( ChannelAddress * address, unsigned int * transId );
	// }}}RME
	// {{{RME operation 'connect(ChannelAddress *)'
	virtual bool connect( ChannelAddress * address );
	// }}}RME
	// {{{RME operation 'disconnect(unsigned int *)'
	virtual bool disconnect( unsigned int * transId );
	// }}}RME
	// {{{RME operation 'disconnect()'
	virtual bool disconnect( void );
	// }}}RME
	// {{{RME operation 'send(Array *)'
	virtual bool send( Array * buffer );
	// }}}RME
	// {{{RME operation 'send(Array *,unsigned int *)'
	virtual bool send( Array * xnlMsg, unsigned int * transId );
	// }}}RME
	// {{{RME operation 'receive()'
	Array * receive( void );
	// }}}RME
	// {{{RME operation 'getXNLVersionNum()'
	uint32_t getXNLVersionNum( void ) const;
	// }}}RME
	// {{{RME operation 'getDataMsgSent()'
	bool getDataMsgSent( void ) const;
	// }}}RME
	// {{{RME operation 'getStatus()'
	virtual Connection::Status * getStatus( void );
	// }}}RME
	// {{{RME operation 'getXNLStatus()'
	virtual XNLStatus * getXNLStatus( void );
	// }}}RME
	// {{{RME operation 'addToRxDataQueue(XNLMessage *)'
	void addToRxDataQueue( XNLMessage * rxDataBuffer );
	// }}}RME
	// {{{RME operation 'addToMsgQueue(Message *)'
	void addToMsgQueue( Message * itMsg );
	// }}}RME
	// {{{RME operation 'routeXnlCtrlMsg(DataBuffer *)'
	DataBuffer * routeXnlCtrlMsg( DataBuffer * dataBuf );
	// }}}RME

private:
	// {{{RME operation 'routeTxMsg(XNLMessage *)'
	XNLMessage * routeTxMsg( XNLMessage * xnlMsg );
	// }}}RME
	// {{{RME operation 'sendTxMsg(XNLRoutingEntry &,DataBuffer *,bool)'
	bool sendTxMsg( XNLRoutingEntry & routingEntry, DataBuffer * dataBuf, bool waitForAck = true );
	// }}}RME

protected:
	// {{{RME operation 'main()'
	virtual void * main( void );
	// }}}RME

private:
	// {{{RME operation 'operator =(const XNL &)'
	XNL & operator=( const XNL & xnl );
	// }}}RME
	// {{{RME operation 'XNL(const XNL &)'
	XNL( const XNL & xnl );
	// }}}RME

protected:
	// {{{RME operation 'XNL()'
	XNL( void );
	// }}}RME
	// {{{RME operation 'XNL(const XNLInit &,TimerVirtualFactory*,uint16_t)'
	XNL( const XNLInit & initInfo, TimerVirtualFactory * timerFactory, uint16_t timerTickBase );
	// }}}RME

public:
	// {{{RME operation '~XNL()'
	virtual ~XNL( void );
	// }}}RME
	// {{{RME operation 'createXNLThread(int,const XNLInit &,TimerVirtualFactory*,uint16_t)'
	static Thread * createXNLThread( int priority, const XNLInit & initInfo, TimerVirtualFactory * timerFactory, uint16_t timerTickBase );
	// }}}RME
	// {{{RME operation 'destroyXNLThread()'
	void destroyXNLThread( void );
	// }}}RME
	// {{{RME operation 'procResetMsg(XNLProtocolMsg*,Connection*)'
	void procResetMsg( XNLProtocolMsg * xnlPMsg, Connection * conn );
	// }}}RME

protected:
	// {{{RME operation 'assumeMasterStatus()'
	void assumeMasterStatus( void );
	// }}}RME

public:
	// {{{RME operation 'rerouteDataMsg(XNLDataMsg*,Connection*)'
	void rerouteDataMsg( XNLDataMsg * xnlDataMsg, Connection * pConn );
	// }}}RME
	// {{{RME operation 'getRoutingEntry(Connection*)'
	XNLRoutingEntry * getRoutingEntry( Connection * pConn ) const;
	// }}}RME
	// {{{RME operation 'lockRoutingEntryMutex(bool)'
	void lockRoutingEntryMutex( bool bLock );
	// }}}RME
	// {{{RME operation 'encryptKey(const DataBuffer*,XNLAuthLevels,uint32_t*,uint32_t)'
	static DataBuffer * encryptKey( const DataBuffer * pAuthValue, XNLAuthLevels authLevel, uint32_t * authKey, uint32_t delta_val );
	// }}}RME
	// {{{RME operation 'getInstance()'
	static const XNL * getInstance( void );
	// }}}RME
	// {{{RME operation 'procDataMsg(XNLDataMsg *)'
	void procDataMsg( XNLDataMsg * xnlDataMsg );
	// }}}RME
	// {{{RME operation 'unregisterConnection(Connection *,bool)'
	bool unregisterConnection( Connection * connection, bool bWaitTillComplete = true );
	// }}}RME
	// {{{RME operation 'registerConnection(Connection *,XNLAuthKeySets *,AUTHKEYFUNCPTR,bool)'
	bool registerConnection( Connection * connection, XNLAuthKeySets * authKeySets, AUTHKEYFUNCPTR authKeyFuncPtr = 0, bool bWaitTillComplete = true );
	// }}}RME
	// {{{RME operation 'doesConnectionExist(Connection *)'
	bool doesConnectionExist( Connection * conn );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLSendInterthreadMsg' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'AddrMgr' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Logical View::XCMP::XNL::XNL::AddrMgr::DeviceTypeNode' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLThreadEndMsg' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLUnregisterConnectionMsg' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLRegisterConnectionMsg' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* XNL_H */

// }}}RME
