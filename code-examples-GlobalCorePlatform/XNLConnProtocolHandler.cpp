// {{{RME classifier 'Logical View::XCMP::XNL::XNLConnectionProtocolHandler::XNLConnProtocolHandler'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "XNLConnProtocolHandler.h"
#endif

#include <xnl_win32_comp.h>
#include <XNLConnProtocolHandler.h>
#include <Array.h>
#include <Connection.h>
#include <DataBuffer.h>
#include <TimerVirtual.h>
#include <XNLAuthFailedEvent.h>
#include <XNLConnKeyEntry.h>
#include <XNLConnKeyList.h>
#include <XNLDevAuthKeyReply.h>
#include <XNLDevConnReply.h>
#include <XNLDevConnReq.h>
#include <XNLMessage.h>
#include <XNLProtocolMsg.h>
#include <XNLPrvStatus.h>
#include <XNLReplyFailEvent.h>
#include <XNLRoutingEntry.h>
#include <XNLStatus.h>
#include <XNLSysMapBrdcst.h>
#include <XNLSystemMap.h>
#include <XNLTimerInterthreadMsg.h>
class XNLProtocolFailedEvent;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'TRANS_ID_BASE_START'
#define TRANS_ID_BASE_START 1
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
XNLConnProtocolHandler::XNLConnProtocolHandler( void )
	: m_bMasterDevice( false )
	, m_pInitConn( 0 )
	, m_devType( 0 )
	, m_prefXNLAddr( 0 )
	, m_transactionIdBase( TRANS_ID_BASE_START )
	, m_pPrvStatus( 0 )
	, m_pAddrMgr( 0 )
	, m_pConnKeyList( 0 )
	, m_replWaitTime( 0 )
	, m_pOutstandingRequest( 0 )
	, m_expiredTimerCnt( 0 )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
XNLConnProtocolHandler::XNLConnProtocolHandler( const XNLConnProtocolHandler & rtg_arg )
	: ListenerBase( rtg_arg )
	, NotifierBase( rtg_arg )
	, m_bMasterDevice( rtg_arg.m_bMasterDevice )
	, m_pXNL( rtg_arg.m_pXNL )
	, m_pInitConn( rtg_arg.m_pInitConn )
	, m_devType( rtg_arg.m_devType )
	, m_prefXNLAddr( rtg_arg.m_prefXNLAddr )
	, m_transactionIdBase( rtg_arg.m_transactionIdBase )
	, m_pPrvStatus( rtg_arg.m_pPrvStatus )
	, m_pAddrMgr( rtg_arg.m_pAddrMgr )
	, m_pConnKeyList( rtg_arg.m_pConnKeyList )
	, m_replWaitTime( rtg_arg.m_replWaitTime )
	, m_pOutstandingRequest( rtg_arg.m_pOutstandingRequest )
	, m_expiredTimerCnt( rtg_arg.m_expiredTimerCnt )
	, m_timer( rtg_arg.m_timer )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
XNLConnProtocolHandler & XNLConnProtocolHandler::operator=( const XNLConnProtocolHandler & rtg_arg )
{
	if( this != &rtg_arg )
	{
		ListenerBase::operator=( rtg_arg );
		NotifierBase::operator=( rtg_arg );
		m_bMasterDevice = rtg_arg.m_bMasterDevice;
		m_pXNL = rtg_arg.m_pXNL;
		m_pInitConn = rtg_arg.m_pInitConn;
		m_devType = rtg_arg.m_devType;
		m_prefXNLAddr = rtg_arg.m_prefXNLAddr;
		m_transactionIdBase = rtg_arg.m_transactionIdBase;
		m_pPrvStatus = rtg_arg.m_pPrvStatus;
		m_pAddrMgr = rtg_arg.m_pAddrMgr;
		m_pConnKeyList = rtg_arg.m_pConnKeyList;
		m_replWaitTime = rtg_arg.m_replWaitTime;
		m_pOutstandingRequest = rtg_arg.m_pOutstandingRequest;
		m_expiredTimerCnt = rtg_arg.m_expiredTimerCnt;
		m_timer = rtg_arg.m_timer;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'init(const XNLInit&,Connection*,XNL::AddrMgr*)'
void XNLConnProtocolHandler::init( const XNLInit & xnlInit, Connection * pConnection, XNL::AddrMgr * pAddrMgr )
{
	// {{{USR
	// In case we were already running and init was called again due
	// to another device assuming mastership, we need to make sure the
	// timer expiration data is reset.
	stopTimer();

	m_prefXNLAddr = xnlInit.getPreferredAddr();
	m_devType = xnlInit.getDeviceType();

	// Set the connection to the master device (0 if we're the master)
	m_pInitConn = pConnection;

	// If we are being reinitialized, then delete any existing Conn/Key pairs. For
	// masters, this list will contain all outstanding conn/key pairs for devices that
	// are in the process of connecting. For non-masters, it will contain a single
	// conn/key pair for authenticating the master.
	if (m_pConnKeyList)
		delete m_pConnKeyList;

	m_pConnKeyList = new XNLConnKeyList;

	// Find out if we're running on the master
	m_bMasterDevice = m_pPrvStatus->isMyDeviceMaster();

	if (m_bMasterDevice)
	{
		// Initialize the static counter used for assigning a transactionID base
		m_transactionIdBase = TRANS_ID_BASE_START;

		// Create an address manager to handle assignment of XNL addresses
		m_pAddrMgr = pAddrMgr;

		// Update connection info for the master
		m_pPrvStatus->setDeviceConnected(true, m_pPrvStatus->getMasterXNLAddr(),
										 m_pPrvStatus->getMasterDevice(),
										 XNL_AUTH_LVL_INT, assignTransactionIdBase(), pConnection);
	}
	else
	{
		// Just in case we used to be the master
		if (m_pAddrMgr)
			m_pAddrMgr = 0;

		// Start the process of establishing a connection to the new master
		requestAuthKey(m_pPrvStatus->getMasterXNLAddr());
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'processMessage(XNLProtocolMsg*,Connection*)'
bool XNLConnProtocolHandler::processMessage( XNLProtocolMsg * pMsg, Connection * pConnection )
{
	// {{{USR
	bool bSuccess = false;

	if (pMsg && pConnection)
	{
		// Get the opcode.
		XNLProtocolOpcodes opcode = pMsg->getOpcode();

		if (m_bMasterDevice)
		{
			// The handler on a master device only processes the following messages:
			switch (opcode)
			{
			case XNL_DEVICE_AUTH_KEY_REQUEST:
				// Request for an authorization key received. Generate a reply
				// and send it back to the requester.
				bSuccess = processAuthKeyReq(pMsg, pConnection);
				break;

			case XNL_DEVICE_CONN_REQUEST:
				// Validate the connection request and send a reply
				// with either acceptance or rejection status.
				bSuccess = processConnRequest((XNLDevConnReq*)pMsg, pConnection);
				break;

			case XNL_DEVICE_SYSMAP_REQUEST:
				// Send out a SysMap broadcast to the requestor
				bSuccess = sendSysMapBrdcst(pMsg->getSourceAddr(), pConnection);
				break;

			default:
				// ERROR LOG HERE
				break;
			}
		}
		else
		{
			// The handler on a non-master device only processes the following messages:
			switch (opcode)
			{
			case XNL_DEVICE_AUTH_KEY_REPLY:
				// Authorization key received so now we need to generate a
				// connection request
				bSuccess = processAuthKeyReply((XNLDevAuthKeyReply*)pMsg, pConnection);
				break;

			case XNL_DEVICE_CONN_REPLY:
				// Reply to our connection request has been received.
				bSuccess = processConnReply((XNLDevConnReply*)pMsg, pConnection);
				break;

			case XNL_DEVICE_SYSMAP_BRDCST:
				// System map has been broadcast
				bSuccess = processSysMapBrdcst((XNLSysMapBrdcst*)pMsg);
				break;

			default:
				// ERROR LOG HERE
				break;
			}
		}

	} // end if (pMsg && pConnection
	else
	{
		// ERROR LOG HERE
	}

	if (pMsg)
		delete pMsg;

	return bSuccess;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLConnProtocolHandler(XNL*,XNLPrvStatus*,TimerVirtual*,uint16_t)'
XNLConnProtocolHandler::XNLConnProtocolHandler( XNL * pXNL, XNLPrvStatus * pPrvStatus, TimerVirtual * timer, uint16_t timerTickBase )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_pXNL(pXNL), m_bMasterDevice(false), m_devType(0),
	  m_prefXNLAddr(0), m_pInitConn(0), m_pPrvStatus(pPrvStatus),
	  m_pAddrMgr(0), m_transactionIdBase(TRANS_ID_BASE_START),
	  m_pConnKeyList(0), m_timer(timer), m_pOutstandingRequest(0), m_expiredTimerCnt(0)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// See constructor initializer

	// Wait 250ms for replies
	m_replWaitTime = 250 / timerTickBase;

	// Register as a listener so we'll be notified when the timer expires.
	// The timer only runs when we explicitly start it and it doesn't rearm
	// itself upon expiration. This, combined with the fact that the timer is
	// used exclusively by the protocol handler makes it ok to do a single
	// registration up front and remain registered until we are destroyed.
	m_timer->registerListener(this, TimerVirtual::Event::TIMER_EVENT);	
	// }}}USR
}
// }}}RME

// {{{RME operation 'requestAuthKey(uint16_t)'
void XNLConnProtocolHandler::requestAuthKey( uint16_t masterXNLAddr )
{
	// {{{USR
	// Create an authorization key request
	XNLProtocolMsg* pMsg = new XNLProtocolMsg(XNL_DEVICE_AUTH_KEY_REQUEST);

	// Store the address for the master
	pMsg->setDestAddr(masterXNLAddr);

	// Serialize the message.
	Array* pData = pMsg->serialize();

	if (pData)
	{
		// add mutex protection and check if the connection exists.
		m_pXNL->lockRoutingEntryMutex(true);
		if (m_pXNL->doesConnectionExist(m_pInitConn) && m_pInitConn->send(pData))
		{
			// Start the timer
			m_timer->set(m_replWaitTime);

			// Save the outstanding request so that we can resend it if
			// we time out waiting for the reply
			m_pOutstandingRequest = pMsg;
			pMsg = 0;
		}
		else
		{
			// If we failed to send, it's because something serious happened
			// so don't bother setting the timer

			// ERROR LOG HERE

			delete pData;
		}
		m_pXNL->lockRoutingEntryMutex(false);
	}
	else
	{
		// ERROR LOG HERE
	}

	// If we didn't successfully send the msg, then delete it
	if (pMsg != 0)
		delete pMsg;
	// }}}USR
}
// }}}RME

// {{{RME operation 'processAuthKeyReq(XNLProtocolMsg*,Connection*)'
bool XNLConnProtocolHandler::processAuthKeyReq( XNLProtocolMsg * pRequest, Connection * pConnection )
{
	// {{{USR
	bool bSuccess = false;

	// Create a message for sending the reply.
	XNLDevAuthKeyReply* pReply = new XNLDevAuthKeyReply;

	// Set the XNL address for the master
	pReply->setSourceAddr(m_pPrvStatus->getMyXNLAddr());

	// Assign a temporary address to the device.
	pReply->setXNLAddr(m_pAddrMgr->assignTmpXNLAddr());

	// Generate an authorization key and store it in the message.
	DataBuffer* pKey = generateAuthKey(pConnection);
	pReply->setAuthKey(pKey);

	// Serialize the message and send it off.
	Array* pData = pReply->serialize();

	if (pData)
	{
		// add mutex protection and check if the connection exists.
		m_pXNL->lockRoutingEntryMutex(true);
		if (m_pXNL->doesConnectionExist(pConnection))
		{
			bSuccess = pConnection->send(pData);
		}
		m_pXNL->lockRoutingEntryMutex(false);

		if (!bSuccess)
			delete pData;
	}

	delete pReply;

	return bSuccess;
	// }}}USR
}
// }}}RME

// {{{RME operation 'processAuthKeyReply(XNLDevAuthKeyReply*,Connection*)'
bool XNLConnProtocolHandler::processAuthKeyReply( XNLDevAuthKeyReply * pAuthKeyRep, Connection * pConnection )
{
	// {{{USR
	bool bSuccess = false;

	// Make sure we're expecting an auth key reply... It's possible that we timed out
	// and sent a 2nd request and so we're ending up with an extra (delayed) reply.
	if ((m_pOutstandingRequest != 0) && (m_pOutstandingRequest->getOpcode() == XNL_DEVICE_AUTH_KEY_REQUEST))
	{
		// Yup, this is the reply we're waiting for so stop the timer
		stopTimer();

		// Create a connection request message.
		XNLDevConnReq* pConnReq = new XNLDevConnReq;

		// Set the master's XNL address.
		pConnReq->setDestAddr(pAuthKeyRep->getSourceAddr());

		// Set the source address for this device to the temporary
		// addr that was sent back in the auth. key reply message.
		pConnReq->setSourceAddr(pAuthKeyRep->getXNLAddr());

		// Set the auth level
		pConnReq->setAuthLevel(XNL_AUTH_LVL_INT);

		// Get the auth key
		m_pXNL->lockRoutingEntryMutex(true);
		XNLRoutingEntry *connRtEntry = m_pXNL->getRoutingEntry(pConnection);
		m_pXNL->lockRoutingEntryMutex(false);
		uint32_t *authKey = 0;
		uint32_t delta_val = 0;
		if(connRtEntry != 0)
		{
			authKey = (connRtEntry->getXNLAuthKeySets())->getAuthLevelKey(XNL_AUTH_LVL_INT);
			delta_val = (connRtEntry->getXNLAuthKeySets())->getDeltaVal(XNL_AUTH_LVL_INT);
		}
		else
		{
			//Log Error
		}

		// Encrypt the auth key
		DataBuffer* pAuthValue = encryptKey(pAuthKeyRep->getAuthKey(), XNL_AUTH_LVL_INT, authKey, delta_val);

		// Make a copy of the encrypted key for later use in authenticating the master.
		DataBuffer* pEncryptedKey = new DataBuffer(pAuthValue);

		// Store the auth value in the dev conn request message.
		pConnReq->setAuthValue(pAuthValue);

		// Set the device type.
		pConnReq->setDeviceType(m_devType);

		// Set the device's preferred XNL address
		pConnReq->setPrefXNLAddr(m_prefXNLAddr);

		// There shouldn't be any conn/key pairs in the list but check just in case
		// and if we find it, delete it
		XNLConnKeyEntry* pConnKey = m_pConnKeyList->delink(pConnection);

		if (pConnKey)
			delete pConnKey;

		// Save the encrypted key and connection for when the dev conn reply comes back
		m_pConnKeyList->addToTail(pConnection, pEncryptedKey);

		// Serialize the message and send it off.
		Array* pData = pConnReq->serialize();

		if (pData)
		{
			// add mutex protection and check if the connection exists.
			m_pXNL->lockRoutingEntryMutex(true);
			if (m_pXNL->doesConnectionExist(pConnection) && pConnection->send(pData))
			{
				// Start the timer
				m_timer->set(m_replWaitTime);

				// Save the outstanding request so that we can resend it if
				// we time out waiting for the reply
				m_pOutstandingRequest = pConnReq;
				pConnReq = 0;

				bSuccess = true;
			}
			else
			{
				// If we failed to send, it's because something serious happened
				// so don't bother setting the timer

				// ERROR LOG HERE

				delete pData;
			}
			m_pXNL->lockRoutingEntryMutex(false);
		}

		// If we didn't successfully send the msg, then delete it
		if (pConnReq != 0)
			delete pConnReq;
	}
	else
	{
		// This is a reply we're no longer interested in so ignore it
		bSuccess = true;
	}

	return bSuccess;
	// }}}USR
}
// }}}RME

// {{{RME operation 'processConnRequest(XNLDevConnReq*,Connection*)'
bool XNLConnProtocolHandler::processConnRequest( XNLDevConnReq * pConnReq, Connection * pConnection )
{
	// {{{USR
	bool bSuccess = false;
	bool bSendSysMap = false;

	// Create a reply message
	XNLDevConnReply* pConnReply = new XNLDevConnReply;

	// Set the source address
	pConnReply->setSourceAddr(m_pPrvStatus->getMyXNLAddr());

	// Set the destination address
	pConnReply->setDestAddr(pConnReq->getSourceAddr());

	// Get the auth level
	XNLAuthLevels authLevel = pConnReq->getAuthLevel();

	// Get the auth key based on the auth level
	m_pXNL->lockRoutingEntryMutex(true);
	XNLRoutingEntry *connRtEntry = m_pXNL->getRoutingEntry(pConnection);
	m_pXNL->lockRoutingEntryMutex(false);

	uint32_t *authKey = 0;
	uint32_t delta_val = 0;
	AUTHKEYFUNCPTR authKeyFuncPtr = 0;
	bool bAuthValid = false;
	// Create pMasterAuth to re-encrypt the encrypted key that was sent to us and return it to
	// conn-requesting device in the reply so that the device can authenticate us as the master
	DataBuffer* pMasterAuth = 0; 

	if(connRtEntry != 0)
	{
		authKeyFuncPtr = (connRtEntry->getAuthKeyFuncPtr());
		if (authKeyFuncPtr == 0) {
			authKey = (connRtEntry->getXNLAuthKeySets())->getAuthLevelKey(authLevel);
			delta_val = (connRtEntry->getXNLAuthKeySets())->getDeltaVal(authLevel);
		}
	}
	else
	{
		//Log Error
	}

	// Get the encrypted auth value that was sent in the connection request
	DataBuffer* pAuthValue = pConnReq->getAuthValue();

	// Authenticate the device.
	if (authKeyFuncPtr == 0) {
		// Single Key
		bAuthValid = authenticateDevice(pAuthValue, authLevel, pConnection, authKey, delta_val);
	} else {
		// Single or Multiple Keys

		// Get the connection/authKey pair that we created earlier when we first
		// sent them the authorization key.
		XNLConnKeyEntry* pConnKey = m_pConnKeyList->delink(pConnection);

		if (pConnKey)
		{
			// Get the random key associated with this connection
			const DataBuffer* randomKey = pConnKey->getKey();

			// Call callback function to authenticate the pAuthValue key
			pMasterAuth = authKeyFuncPtr(pAuthValue, authLevel, randomKey);
			if (pMasterAuth) {
				bAuthValid = true;
			}
			delete pConnKey;
		}
	}

	if (bAuthValid)
	{
		bSuccess = true;

		// Get a unique transactionID base to be used by the device
		// for all future messages.
		uint8_t transIdBase = assignTransactionIdBase();
		pConnReply->setTransactionIdBase(transIdBase);

		uint16_t devXNLAddr;
		XNLDevice deviceAddr;

		// Lock the routing list
		m_pXNL->lockRoutingEntryMutex(true);

		// See if this device has previously connected. This might happen if he
		// reset or something. If so, we want to re-assign the same addresses that
		// we gave him before.
		const XNLRoutingEntry* pEntry = m_pXNL->getRoutingEntry(pConnection);

		if ((pEntry != 0) && pEntry->isDeviceValid())
		{
			// Yup, he's previously authenticated
			devXNLAddr = pEntry->getXNLAddr();
			deviceAddr = pEntry->getDevice();
		}
		else
		{
			// New connection...

			// Get an XNL address to assign to a device
			uint16_t prefXNLAddr = pConnReq->getPrefXNLAddr();
			devXNLAddr = m_pAddrMgr->assignXNLAddr(prefXNLAddr);

			// Assign a unique ID for this device
			uint8_t deviceType = pConnReq->getDeviceType();

			// Create a logical address for the device and set it in the reply
			deviceAddr = m_pAddrMgr->assignLogicalAddr(deviceType);

			// No IDs available for assignment
			if (deviceAddr.getId() == 0)
				bSuccess = false;
		}

	    // Unlock the routing list
	    m_pXNL->lockRoutingEntryMutex(false);

		if (bSuccess)
		{
			// if the device request no xnl ack, then set the m_xnlDisableAckFlag to true

			XNLRoutingEntry* xnlEntry = m_pXNL->getRoutingEntry(pConnection);
			xnlEntry->setXNLDisableAckFlag(pConnReq->getXNLDisableAckFlag());
		

			// if device request no xnl ack, then return the reply that no xnl ack will sent out
			// add for GCP Enhancement, mdpq74
			pConnReply->setXNLDisableAckFlag(pConnReq->getXNLDisableAckFlag());


			// Store the addresses in the msg
			pConnReply->setXNLAddr(devXNLAddr);
			pConnReply->setDeviceAddr(deviceAddr);

			// Set the result code
			pConnReply->setResult(XNL_SUCCESS);

			if (authKeyFuncPtr == 0) {
				// Re-encrypt the encrypted value that was sent to us and return it
				// in the reply so that the device can authenticate us as the master
				pMasterAuth = encryptKey(pAuthValue, authLevel, authKey, delta_val);
			}
			pConnReply->setAuthValue(pMasterAuth);

			// Update the routing table entry
			m_pXNL->validateRoutingEntry(pConnection, devXNLAddr, deviceAddr);

			// Update the device's connection info and generate the "device
			// connected" event.
			m_pPrvStatus->setDeviceConnected(false, devXNLAddr, deviceAddr,
								   			 (uint8_t)authLevel, transIdBase, pConnection);

			// Set a flag so we'll know to send out the system map after we send
			// out the reply
			bSendSysMap = true;
		}
	}
	else
	{
		// Announce XNL_AUTH_FAILED_EVENT
		m_pPrvStatus->setAuthFailedEvent(pConnection);
	}

	if (!bSuccess)
	{
		if (pMasterAuth)
		{
			// Ownership of the buffer was passed to us so delete it.
			delete pMasterAuth;
		}

		// Set the result code to indicate the request has failed. Note that since
		// it failed, we don't bother assigning addresses, device IDs, etc.
		pConnReply->setResult(XNL_FAILURE);

		// Set the encrypted value to all 0's
		uint8_t buf[AUTH_VALUE_SZ];

		for (int i = 0; i < AUTH_VALUE_SZ; i++)
			buf[i] = 0;

		DataBuffer* pAuth = new DataBuffer(buf, AUTH_VALUE_SZ);
		pConnReply->setAuthValue(pAuth);
	}	

	if (pAuthValue)
	{
		// Ownership of the buffer was passed to us so delete it now that we're done.
		delete pAuthValue;
	}

	// Serialize the message and send it off.
	Array* pData = pConnReply->serialize();

	if (pData)
	{
		// add mutex protection and check if the connection exists.
		m_pXNL->lockRoutingEntryMutex(true);
		if(m_pXNL->doesConnectionExist(pConnection))
		{
			bSuccess = pConnection->send(pData);
		}
		m_pXNL->lockRoutingEntryMutex(false);

		if (!bSuccess)
			delete pData;
	}

	delete pConnReply;

	if (bSendSysMap)
	{
		// Send the updates system map over all connections.
		sendSysMapBrdcst(0x0000);
	}

	return bSuccess;
	// }}}USR
}
// }}}RME

// {{{RME operation 'processConnReply(XNLDevConnReply*,Connection*)'
bool XNLConnProtocolHandler::processConnReply( XNLDevConnReply * pConnReply, Connection * pConnection )
{
	// {{{USR
	// The only time we return false is if master authentication fails
	bool bSuccess = true;

	// Make sure we're expecting a dev conn reply... It's possible that we timed out
	// and sent a 2nd request and so we're ending up with an extra (delayed) reply.
	if ((m_pOutstandingRequest != 0) && (m_pOutstandingRequest->getOpcode() == XNL_DEVICE_CONN_REQUEST))
	{
		// Yup, this is the reply we're waiting for so stop the timer
		stopTimer();

		if (pConnReply->getResult() == XNL_SUCCESS)
		{
			// Get the returned auth value so we can verify that the msg came from the master
			DataBuffer* pMasterAuth = pConnReply->getAuthValue();

			// Get the auth key based on the auth level
			m_pXNL->lockRoutingEntryMutex(true);
			XNLRoutingEntry *connRtEntry = m_pXNL->getRoutingEntry(pConnection);
			m_pXNL->lockRoutingEntryMutex(false);
			uint32_t *authKey = 0;
			uint32_t delta_val = 0;
			if(connRtEntry != 0)
			{
				authKey = (connRtEntry->getXNLAuthKeySets())->getAuthLevelKey(XNL_AUTH_LVL_INT);
				delta_val = (connRtEntry->getXNLAuthKeySets())->getDeltaVal(XNL_AUTH_LVL_INT);
			}
			else
			{
				//Log Error
			}

			// Authenticate the device.
			if (authenticateDevice(pMasterAuth, XNL_AUTH_LVL_INT, pConnection, authKey, delta_val))
			{
				// Update the device's connection info and generate the "device connected" event.
				m_pPrvStatus->setDeviceConnected(true, pConnReply->getXNLAddr(), pConnReply->getDeviceAddr(),
									   		 	 XNL_AUTH_LVL_INT, pConnReply->getTransactionIdBase(), pConnection);
			}
			else
			{
				// Unregister the "bad" master so we don't talk to him anymore
				m_pXNL->unregisterConnection(pConnection);

				// Return false so XNL will know there's a problem with the current master
				bSuccess = false;

				// Announce XNL_AUTH_FAILED_EVENT
				m_pPrvStatus->setAuthFailedEvent(pConnection);
			}

			delete pMasterAuth;
		}
		else
		{
			// Announce XNL_REPLY_FAIL_EVENT
			m_pPrvStatus->setReplyFailEvent(pConnection);

			// Re-start the connection sequence again
			requestAuthKey(m_pPrvStatus->getMasterXNLAddr());
		}

	}
	else
	{
		// This is a reply we're no longer interested in so ignore it
		bSuccess = true;
	}

	return bSuccess;
	// }}}USR
}
// }}}RME

// {{{RME operation 'processSysMapBrdcst(XNLSysMapBrdcst*)'
bool XNLConnProtocolHandler::processSysMapBrdcst( XNLSysMapBrdcst * pBrdcst )
{
	// {{{USR
	// Get the system map from the message
	XNLSystemMap* pSysMap = pBrdcst->getSystemMap();

	if (pSysMap)
	{
		// Update the system map with the one we just received
		m_pPrvStatus->setSystemMap(pSysMap);

		// Generate a "device connected" event so any listeners will know
		// a new device is connected. Set all the device info to 0.
		m_pPrvStatus->setDeviceConnected(false, 0x0000, XNLDevice(0,0), 0, 0, 0);
	}
	else
	{
		// ERROR LOG HERE
	}

	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'generateAuthKey(const Connection*)'
DataBuffer * XNLConnProtocolHandler::generateAuthKey( const Connection * pConnection )
{
	// {{{USR
	DataBuffer* pRetKey = 0;

	// See if we've already generated an authorization key for this connection.
	// This could happen if for some reason a msg was missed, the device reset
	// during the authentication process, etc...
	const XNLConnKeyEntry* pConnKey = m_pConnKeyList->find(pConnection);

	if (pConnKey)
	{
		// We've already issued a key so make a copy to return to the caller
		pRetKey = new DataBuffer(pConnKey->getKey());
	}
	else
	{
		// Create a buffer with 0 size, no front padding, and 8 bytes of rear padding
		DataBuffer* pKey = new DataBuffer(0, 0, false, 0, AUTH_KEY_SZ);
		
		uint32_t key;

		// xnlRand() returns a 4-byte value so loop and call it until we have as
		// many bytes as we need.
		int cnt = AUTH_KEY_SZ / 4;

		for (int i = 0; i < cnt; i++)
		{
			key = xnlRand();
			key = xutil_htonl(key);
			pKey->append((void*)&key, 4);
		}

		// Make a copy of the key to return to the caller
		pRetKey = new DataBuffer(pKey);

		// Store the connection/key pair for later validation
		m_pConnKeyList->addToTail(pConnection, pKey);
	}

	return pRetKey;
	// }}}USR
}
// }}}RME

// {{{RME operation 'assignTransactionIdBase()'
uint8_t XNLConnProtocolHandler::assignTransactionIdBase( void )
{
	// {{{USR
	uint8_t transIdBase = m_transactionIdBase;

	// Increment to the next available value
	++m_transactionIdBase;

	return transIdBase;
	// }}}USR
}
// }}}RME

// {{{RME operation 'authenticateDevice(const DataBuffer*,XNLAuthLevels,const Connection*,uint32_t*,uint32_t)'
bool XNLConnProtocolHandler::authenticateDevice( const DataBuffer * pAuthValue, XNLAuthLevels authLevel, const Connection * pConn, uint32_t * authKey, uint32_t delta_val )
{
	// {{{USR
	bool bValid = false;

	// Get the connection/authKey pair that we created earlier when we first
	// sent them the authorization key.
	XNLConnKeyEntry* pConnKey = m_pConnKeyList->delink(pConn);

	if (pConnKey)
	{
		// Get the auth key associated with this connection
		const DataBuffer* pKey = pConnKey->getKey();

		// Using the appropriate secret key, based on the auth level,
		// encrpyt the authKey we originally sent out
		DataBuffer* pEncryptedKey = encryptKey(pKey, authLevel, authKey, delta_val);

		if (pEncryptedKey)
		{
			if (pEncryptedKey->getSize() == pAuthValue->getSize())
			{
				int bufSz = pEncryptedKey->getSize();

				for (int i = 0; i < bufSz; i++)
				{
					bValid = ((*pEncryptedKey)[i] == (*pAuthValue)[i]);

					if (!bValid)
						break;
				}
			}

			delete pEncryptedKey;
		}
		else
		{
			// ERROR LOG HERE
		}

		delete pConnKey;
	}

	return bValid;
	// }}}USR
}
// }}}RME

// {{{RME operation 'encryptKey(const DataBuffer*,XNLAuthLevels,uint32_t*,uint32_t)'
DataBuffer * XNLConnProtocolHandler::encryptKey( const DataBuffer * randomKey, XNLAuthLevels authLvl, uint32_t * authKey, uint32_t delta_val )
{
	// {{{USR

	// Convert auth key into two 32 bit words
	uint32_t y = ((*randomKey)[0]<<24)+((*randomKey)[1]<<16)+((*randomKey)[2]<<8)+(*randomKey)[3];
	uint32_t z = ((*randomKey)[4]<<24)+((*randomKey)[5]<<16)+((*randomKey)[6]<<8)+(*randomKey)[7];

	uint32_t* k = authKey;
	uint32_t delta = delta_val;

	DataBuffer* pEncryptedData = 0;

	if (k != 0)
	{
		uint32_t sum = 0;

		// Encrypt random number with secret 128 bit key also using public domain Tiny Encryption Algorithm
		for (int n = 32; n > 0; n--)                                                  
		{
		  sum += delta;
		  y += (z<<4)+k[0] ^ z+sum ^ (z>>5)+k[1];
		  z += (y<<4)+k[2] ^ y+sum ^ (y>>5)+k[3];                  
		}

		// Create a buffer big enough to hold the auth value bytes
		pEncryptedData = new DataBuffer(0, 0, false, 0, AUTH_VALUE_SZ);
		uint32_t tmpVal = xutil_htonl(y);
		pEncryptedData->append((void*)&tmpVal, 4);
		tmpVal = xutil_htonl(z);
		pEncryptedData->append((void*)&tmpVal, 4);
	}

	return pEncryptedData;

	// }}}USR
}
// }}}RME

// {{{RME operation '~XNLConnProtocolHandler()'
XNLConnProtocolHandler::~XNLConnProtocolHandler( void )
{
	// {{{USR
	if (m_timer)
	{
		// Make sure the timer is stopped
		m_timer->set(0);

		// Unregister as a listener of the timer and then destroy the timer
		m_timer->unregisterListener(this, TimerVirtual::Event::TIMER_EVENT);

		delete m_timer;
	}

	if (m_pOutstandingRequest)
		delete m_pOutstandingRequest;

	if (m_pConnKeyList)
		delete m_pConnKeyList;
	// }}}USR
}
// }}}RME

// {{{RME operation 'sendSysMapBrdcst(uint16_t,Connection*)'
bool XNLConnProtocolHandler::sendSysMapBrdcst( uint16_t destAddr, Connection * pConn )
{
	// {{{USR
	bool bSuccess = true;

	// Create a message for sending the reply.
	XNLSysMapBrdcst reply;

	// Set the XNL address for the master
	reply.setSourceAddr(m_pPrvStatus->getMyXNLAddr());

	// Set the destination address to that of the requesting device
	reply.setDestAddr(destAddr);

	// There should be a system map but make sure. If there is, make a copy.
	// and store it in the message. Otherwise, leave the map empty
	const XNLSystemMap* pSysMap = m_pPrvStatus->getSystemMap();

	if (pSysMap)
		reply.setSystemMap(new XNLSystemMap(*pSysMap));

	// Serialize the message and send it off.
	DataBuffer* pData = (DataBuffer*)reply.serialize();

	if (pData)
	{
		m_pXNL->lockRoutingEntryMutex(true);
		// See if we're sending to everyone or just a single device
		if (pConn)
		{
	        if( m_pXNL->doesConnectionExist(pConn) )
	        {
			    bSuccess = pConn->send(pData);
	        }
		}
		else
		{
			// If we are successful, then XNL will consume the buffer and return 0
			bSuccess = ((pData = m_pXNL->routeXnlCtrlMsg(pData)) == 0);
		}
		m_pXNL->lockRoutingEntryMutex(false);

		if (!bSuccess)
			delete pData;
	}

	return bSuccess;
	// }}}USR
}
// }}}RME

// {{{RME operation 'eventOccurred(const EventBase* const)'
void XNLConnProtocolHandler::eventOccurred( const EventBase * const event )
{
	// {{{USR
	// Create a timer expiration message and put it in XNL's message queue
	XNLTimerInterthreadMsg* pMsg = new XNLTimerInterthreadMsg(XNLTimerInterthreadMsg::TIMER_EXP_CONN_PROTO);
	m_pXNL->addToMsgQueue(pMsg);
	// }}}USR
}
// }}}RME

// {{{RME operation 'procTimerExpiration()'
void XNLConnProtocolHandler::procTimerExpiration( void )
{
	// {{{USR
	// If there's no outstanding request, then ignore the timer expiration
	if (m_pOutstandingRequest)
	{
		// Bump up the "timed out" counter
		m_expiredTimerCnt += 1;

		// We try sending the msg a total of 5 times before giving up
		if (m_expiredTimerCnt < 5)
		{
			// Make a copy of the request and resend it
			Array* pData = m_pOutstandingRequest->serialize();

			// add mutex protection and check if the connection exists.
			m_pXNL->lockRoutingEntryMutex(true);
			if (m_pXNL->doesConnectionExist(m_pInitConn) && m_pInitConn->send(pData))
			{
				// Restart the timer
				m_timer->set(m_replWaitTime);
			}
			else
			{
				// ERROR LOG HERE

				delete pData;
			}
			m_pXNL->lockRoutingEntryMutex(false);
		}
		else
		{
			m_pPrvStatus->setXNLProtocolFailed(m_pOutstandingRequest, XNLProtocolFailedEvent::XNL_PROTO_MSG_NO_REPLY);
			m_pOutstandingRequest = 0;
			m_expiredTimerCnt = 0;
		}
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'stopTimer()'
void XNLConnProtocolHandler::stopTimer( void )
{
	// {{{USR
	// Stop the timer if it's still running
	m_timer->set(0);

	// Reset the counter that tracks how many times we timed out while
	// awaiting the reply
	m_expiredTimerCnt = 0;

	// The request is no longer outstanding so delete it
	if (m_pOutstandingRequest)
	{
		delete m_pOutstandingRequest;
		m_pOutstandingRequest = 0;
	}
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
