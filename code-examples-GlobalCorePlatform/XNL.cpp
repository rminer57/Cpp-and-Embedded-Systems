// {{{RME classifier 'Logical View::XCMP::XNL::XNL'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "XNL.h"
#endif

#include <xnl_win32_comp.h>
#include <XNL.h>
#include <DataBuffer.h>
#include <MessageQueue.h>
#include <Mutex.h>
#include <TimerVirtualFactory.h>
#include <XNLCommFailedEvent.h>
#include <XNLConnProtocolHandler.h>
#include <XNLDataMsg.h>
#include <XNLDevAuthKeyReply.h>
#include <XNLDevAuthKeyReq.h>
#include <XNLDevConnReply.h>
#include <XNLDevConnReq.h>
#include <XNLDevMasterQuery.h>
#include <XNLDevice.h>
#include <XNLMasterArbitrator.h>
#include <XNLMasterPresentBrdcst.h>
#include <XNLMasterStsBrdcst.h>
#include <XNLMessage.h>
#include <XNLProtocolMsg.h>
#include <XNLResetEvent.h>
#include <XNLResetMsg.h>
#include <XNLRoutingEntry.h>
#include <XNLRxInterthreadMsg.h>
#include <XNLStatus.h>
#include <XNLSysMapBrdcst.h>
#include <XNLSysMapData.h>
#include <XNLSysMapReq.h>
#include <XNLSystemMap.h>
#include <XNLTimerInterthreadMsg.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLSendInterthreadMsg' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'AddrMgr' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Logical View::XCMP::XNL::XNL::AddrMgr::DeviceTypeNode' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLThreadEndMsg' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLUnregisterConnectionMsg' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLRegisterConnectionMsg' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'AddrMgr' classAttribute 'PERM_XNL_ADDR_START'
#define PERM_XNL_ADDR_START 1
// }}}RME

// {{{RME classifier 'AddrMgr' classAttribute 'TMP_XNL_ADDR_START'
#define TMP_XNL_ADDR_START 0xffff
// }}}RME

// {{{RME classifier 'XNLSendInterthreadMsg'

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
XNL::XNLSendInterthreadMsg::XNLSendInterthreadMsg( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
XNL::XNLSendInterthreadMsg::XNLSendInterthreadMsg( const XNLSendInterthreadMsg & rtg_arg )
	: Message( rtg_arg )
	, m_xnlMsg( rtg_arg.m_xnlMsg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
XNL::XNLSendInterthreadMsg & XNL::XNLSendInterthreadMsg::operator=( const XNLSendInterthreadMsg & rtg_arg )
{
	if( this != &rtg_arg )
	{
		Message::operator=( rtg_arg );
		m_xnlMsg = rtg_arg.m_xnlMsg;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'getType()'
ClassType XNL::XNLSendInterthreadMsg::getType( void ) const
{
	// {{{USR
	return XNL_SEND_SPECIFIC_MSG_TYPE;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize()'
Array * XNL::XNLSendInterthreadMsg::serialize( void )
{
	// {{{USR
	return (Array *)0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'unserialize(Array *)'
bool XNL::XNLSendInterthreadMsg::unserialize( Array * buf )
{
	// {{{USR
	return false;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getXNLMsg()'
XNLMessage * XNL::XNLSendInterthreadMsg::getXNLMsg( void )
{
	// {{{USR
	XNLMessage * temp = m_xnlMsg;
	m_xnlMsg = 0;
	return (temp);
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLSendInterthreadMsg(XNLMessage *)'
XNL::XNLSendInterthreadMsg::XNLSendInterthreadMsg( XNLMessage * xnlMsg )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_xnlMsg(xnlMsg)
	// }}}USR
	// }}}RME
{
	// {{{USR
	unsigned int priority = getMinPriority();

	if(xnlMsg)
	{
	   priority = priority + xnlMsg->getMsgPriority();
	}
	setPriority(priority);

	// }}}USR
}
// }}}RME

// {{{RME operation '~XNLSendInterthreadMsg()'
XNL::XNLSendInterthreadMsg::~XNLSendInterthreadMsg( void )
{
	// {{{USR
	// delete the xnlmsg if it exists.
	if (m_xnlMsg)
	{
		delete m_xnlMsg;
	}
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'AddrMgr'

// {{{RME classifier 'DeviceTypeNode'

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
XNL::AddrMgr::DeviceTypeNode::DeviceTypeNode( const DeviceTypeNode & rtg_arg )
	: m_next( rtg_arg.m_next )
	, m_deviceType( rtg_arg.m_deviceType )
	, m_mutex( rtg_arg.m_mutex )
{
	for( int rtg_m_deviceIDBitmap_index = (32); --rtg_m_deviceIDBitmap_index >= 0; )
		m_deviceIDBitmap[ rtg_m_deviceIDBitmap_index ] = rtg_arg.m_deviceIDBitmap[ rtg_m_deviceIDBitmap_index ];
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
XNL::AddrMgr::DeviceTypeNode & XNL::AddrMgr::DeviceTypeNode::operator=( const DeviceTypeNode & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_next = rtg_arg.m_next;
		m_deviceType = rtg_arg.m_deviceType;
		for( int rtg_m_deviceIDBitmap_index = (32); --rtg_m_deviceIDBitmap_index >= 0; )
			m_deviceIDBitmap[ rtg_m_deviceIDBitmap_index ] = rtg_arg.m_deviceIDBitmap[ rtg_m_deviceIDBitmap_index ];
		m_mutex = rtg_arg.m_mutex;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'DeviceTypeNode(uint8_t,XNL::AddrMgr::DeviceTypeNode*)'
XNL::AddrMgr::DeviceTypeNode::DeviceTypeNode( uint8_t devType, DeviceTypeNode * nextNode )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_next(nextNode), m_deviceType(devType)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// Mutex to protect the bitmap
	m_mutex = Mutex::createMutex();

	// Initialize the bit map. ID 0 is reserved so set bit 0 in the first byte to 1
	m_deviceIDBitmap[0] = 1;

	for (int i = 1; i < 32; i++)
		m_deviceIDBitmap[i] = 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'assignID()'
uint8_t XNL::AddrMgr::DeviceTypeNode::assignID( void )
{
	// {{{USR
	uint8_t deviceID = 0;
	uint8_t mask;

	m_mutex->lock();

	for (int i = 0; (i < 32) && (deviceID == 0); i++)
	{
		// See if there are any unassigned bits in this byte
		if (m_deviceIDBitmap[i] != 0xff)
		{
			for (uint8_t j = 0; (j < 8) && (deviceID == 0); j++)
			{
				mask = 0x01 << j;

				if ((m_deviceIDBitmap[i] & mask) == 0)
				{
					// Unassigned so grab it. Note that bit 0 of byte 0 is reserved so
					// we'll never get to this statement for i and j both equal to 0.
					deviceID = (i * 8) + j;

					// Set the bit in the map to indicate it's no longer available
					m_deviceIDBitmap[i] |= mask;
				}
			}
		}
	}

	m_mutex->unlock();

	return deviceID;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getNext()'
XNL::AddrMgr::DeviceTypeNode * XNL::AddrMgr::DeviceTypeNode::getNext( void )
{
	// {{{USR
	return m_next;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDeviceType()'
uint8_t XNL::AddrMgr::DeviceTypeNode::getDeviceType( void ) const
{
	// {{{USR
	return m_deviceType;
	// }}}USR
}
// }}}RME

// {{{RME operation 'unassignID(uint8_t)'
void XNL::AddrMgr::DeviceTypeNode::unassignID( uint8_t deviceID )
{
	// {{{USR
	// No one should be trying to unassign ID 0 since it's reserved.
	if (deviceID != 0)
	{
		uint8_t bitNum = deviceID % 8;
		uint8_t byteNum = deviceID / 8;
		uint8_t mask = ~(0x01 << bitNum);
		m_mutex->lock();
		m_deviceIDBitmap[byteNum] &= mask;
		m_mutex->unlock();
	}
	// }}}USR
}
// }}}RME

// {{{RME operation '~DeviceTypeNode()'
XNL::AddrMgr::DeviceTypeNode::~DeviceTypeNode( void )
{
	// {{{USR
	delete m_mutex;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
XNL::AddrMgr::AddrMgr( void )
	: m_permXNLAddr( 1 )
	, m_pReservedXNLAddrArr( 0 )
	, m_tmpXNLAddr( TMP_XNL_ADDR_START )
	, m_prefAddrArrIndex( 0 )
	, m_prefAddrArrSz( 0 )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
XNL::AddrMgr::AddrMgr( const AddrMgr & rtg_arg )
	: m_permXNLAddr( rtg_arg.m_permXNLAddr )
	, m_pReservedXNLAddrArr( rtg_arg.m_pReservedXNLAddrArr )
	, m_tmpXNLAddr( rtg_arg.m_tmpXNLAddr )
	, m_prefAddrArrIndex( rtg_arg.m_prefAddrArrIndex )
	, m_prefAddrArrSz( rtg_arg.m_prefAddrArrSz )
	, m_deviceTypeList( rtg_arg.m_deviceTypeList )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
XNL::AddrMgr & XNL::AddrMgr::operator=( const AddrMgr & rtg_arg )
{
	if( this != &rtg_arg )
	{
		m_permXNLAddr = rtg_arg.m_permXNLAddr;
		m_pReservedXNLAddrArr = rtg_arg.m_pReservedXNLAddrArr;
		m_tmpXNLAddr = rtg_arg.m_tmpXNLAddr;
		m_prefAddrArrIndex = rtg_arg.m_prefAddrArrIndex;
		m_prefAddrArrSz = rtg_arg.m_prefAddrArrSz;
		m_deviceTypeList = rtg_arg.m_deviceTypeList;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'assignXNLAddr(uint16_t)'
uint16_t XNL::AddrMgr::assignXNLAddr( uint16_t prefXNLAddr )
{
	// {{{USR
	uint16_t xnlAddr = 0;
	int i;

	// See if the caller requested a specific address
	if ((prefXNLAddr > 0) && (prefXNLAddr < 0x8000))
	{
		// m_permXNLAddr contains the "next available" address. If the requested
		// address is less than the next available, then it's already assigned
		if (prefXNLAddr >= m_permXNLAddr)
		{
			// So far so good, now make sure another device hasn't already requested
			// (and received) that address
			for (i = 0; i < m_prefAddrArrIndex; i++)
			{
				if (m_pReservedXNLAddrArr[i] == prefXNLAddr)
					break;
			}

			if (i == m_prefAddrArrIndex)
			{
				// Make sure we haven't exceeded the max number of preferred addresses.
				if (i < m_prefAddrArrSz)
				{
					// Requested address has not yet been assigned
					xnlAddr = prefXNLAddr;
					m_pReservedXNLAddrArr[m_prefAddrArrIndex] = xnlAddr;
					++m_prefAddrArrIndex;		
				}
				else
				{
					// ERROR LOG HERE
				}
			}
		}
	}

	// If a preferred address wasn't assigned then give the next available
	while (xnlAddr == 0)
	{
		// Make sure next available address hasn't already been assigned
		// at someone else's request.
		for (i = 0; i < m_prefAddrArrIndex; i++)
		{
			if (m_permXNLAddr == m_pReservedXNLAddrArr[i])
				break;
		}

		if (i == m_prefAddrArrIndex)
		{
			// The next available was not previously requested as a preferred
			// address so go ahead and assign it.
			xnlAddr = m_permXNLAddr;
		}

		// We either just assigned the "next available" or it was already requested as a
		// preferred address earlier. Either way, it's no longer available for assignment
		// so bump up the counter.
		++m_permXNLAddr;
	}

	return xnlAddr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'assignTmpXNLAddr()'
uint16_t XNL::AddrMgr::assignTmpXNLAddr( void )
{
	// {{{USR
	uint16_t xnlAddr = m_tmpXNLAddr;

	// Decrement the counter so that it contains the next available address. We should
	// never get this far down but just in case...
	if (m_tmpXNLAddr == 0x8000)
		m_tmpXNLAddr = 0xffff;
	else
		--m_tmpXNLAddr;

	return xnlAddr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'assignLogicalAddr(uint8_t)'
XNLDevice XNL::AddrMgr::assignLogicalAddr( uint8_t devType )
{
	// {{{USR
	XNLDevice devAddr(0, 0);

	XNL::AddrMgr::DeviceTypeNode* node = m_deviceTypeList;

	// Find the node associated with this device type
	while (node != 0)
	{
		if (node->getDeviceType() == devType)
			break;
		else
			node = node->getNext();
	}

	if (node == 0)
	{
		// First time for this device type so create a node
		// and add it to the head of the list
		node = new DeviceTypeNode(devType, m_deviceTypeList);
		m_deviceTypeList = node;
	}

	uint8_t deviceID = node->assignID();

	if (deviceID != 0)
	{
		devAddr.setDeviceType(devType);
		devAddr.setId(deviceID);
	}
	else
	{
		// No IDs available for assignment

		// ERROR LOG HERE
	}

	return devAddr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'AddrMgr(uint8_t)'
XNL::AddrMgr::AddrMgr( uint8_t maxPrefAddresses )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_permXNLAddr(PERM_XNL_ADDR_START), m_tmpXNLAddr(TMP_XNL_ADDR_START), m_prefAddrArrIndex(0), m_prefAddrArrSz(maxPrefAddresses),
	  m_deviceTypeList(0)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// See constructor initializer list

	// Create and initialize an array to hold any out of sequence addresses
	// assigned as a result of being the requested "preferred" address.
	m_pReservedXNLAddrArr = new uint16_t[maxPrefAddresses];

	int i;

	for (i = 0; i < m_prefAddrArrSz; i++)
		m_pReservedXNLAddrArr[i] = 0;
	// }}}USR
}
// }}}RME

// {{{RME operation '~AddrMgr()'
XNL::AddrMgr::~AddrMgr( void )
{
	// {{{USR
	if (m_pReservedXNLAddrArr != 0)
		delete [] m_pReservedXNLAddrArr;

	XNL::AddrMgr::DeviceTypeNode* node;

	while ((node = m_deviceTypeList) != 0)
	{
		m_deviceTypeList = m_deviceTypeList->getNext();
		delete node;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'unassignLogicalAddr(const XNLDevice&)'
void XNL::AddrMgr::unassignLogicalAddr( const XNLDevice & logicalAddr ) const
{
	// {{{USR
	uint8_t devType = logicalAddr.getDeviceType();

	XNL::AddrMgr::DeviceTypeNode* node = m_deviceTypeList;

	while (node != 0)
	{
		if (node->getDeviceType() == devType)
		{
			node->unassignID(logicalAddr.getId());
			break;
		}
		else
			node = node->getNext();
	}
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'XNLThreadEndMsg'

// {{{RME classAttribute 'XNL_THREAD_END_MSG_TYPE'
const unsigned int XNL::XNLThreadEndMsg::XNL_THREAD_END_MSG_TYPE( SPECIFIC_MSG_TYPE_BASE + 3 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
XNL::XNLThreadEndMsg::~XNLThreadEndMsg( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
XNL::XNLThreadEndMsg::XNLThreadEndMsg( const XNLThreadEndMsg & rtg_arg )
	: Message( rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
XNL::XNLThreadEndMsg & XNL::XNLThreadEndMsg::operator=( const XNLThreadEndMsg & rtg_arg )
{
	if( this != &rtg_arg )
		Message::operator=( rtg_arg );
	return *this;
}
// }}}RME

// {{{RME operation 'getType()'
ClassType XNL::XNLThreadEndMsg::getType( void ) const
{
	// {{{USR
	return XNL_THREAD_END_MSG_TYPE;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize()'
Array * XNL::XNLThreadEndMsg::serialize( void )
{
	// {{{USR
	return (Array *)0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'unserialize(Array*)'
bool XNL::XNLThreadEndMsg::unserialize( Array * buf )
{
	// {{{USR
	return false;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLThreadEndMsg()'
XNL::XNLThreadEndMsg::XNLThreadEndMsg( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	setPriority(Message::getMinPriority());
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'XNLUnregisterConnectionMsg'

// {{{RME classAttribute 'XNL_UNREGISTER_CONN_TYPE'
const unsigned int XNL::XNLUnregisterConnectionMsg::XNL_UNREGISTER_CONN_TYPE( SPECIFIC_MSG_TYPE_BASE + 5 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
XNL::XNLUnregisterConnectionMsg::~XNLUnregisterConnectionMsg( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
XNL::XNLUnregisterConnectionMsg::XNLUnregisterConnectionMsg( const XNLUnregisterConnectionMsg & rtg_arg )
	: Message( rtg_arg )
	, m_connection( rtg_arg.m_connection )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
XNL::XNLUnregisterConnectionMsg & XNL::XNLUnregisterConnectionMsg::operator=( const XNLUnregisterConnectionMsg & rtg_arg )
{
	if( this != &rtg_arg )
	{
		Message::operator=( rtg_arg );
		m_connection = rtg_arg.m_connection;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'getType()'
ClassType XNL::XNLUnregisterConnectionMsg::getType( void ) const
{
	// {{{USR
	return XNL_UNREGISTER_CONN_TYPE;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize()'
Array * XNL::XNLUnregisterConnectionMsg::serialize( void )
{
	// {{{USR
	return (Array *)0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'unserialize(Array*)'
bool XNL::XNLUnregisterConnectionMsg::unserialize( Array * buf )
{
	// {{{USR
	return false;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLUnregisterConnectionMsg(Connection *)'
XNL::XNLUnregisterConnectionMsg::XNLUnregisterConnectionMsg( Connection * connection )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_connection(connection)
	// }}}USR
	// }}}RME
{
	// {{{USR
	setPriority(Message::getMaxPriority());
	// }}}USR
}
// }}}RME

// {{{RME operation 'getConnection()'
Connection * XNL::XNLUnregisterConnectionMsg::getConnection( void )
{
	// {{{USR
	return m_connection;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'XNLRegisterConnectionMsg'

// {{{RME classAttribute 'XNL_REGISTER_CONN_TYPE'
const unsigned int XNL::XNLRegisterConnectionMsg::XNL_REGISTER_CONN_TYPE( SPECIFIC_MSG_TYPE_BASE + 6 );
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
XNL::XNLRegisterConnectionMsg::~XNLRegisterConnectionMsg( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
XNL::XNLRegisterConnectionMsg::XNLRegisterConnectionMsg( const XNLRegisterConnectionMsg & rtg_arg )
	: Message( rtg_arg )
	, m_connection( rtg_arg.m_connection )
	, m_authKeySets( rtg_arg.m_authKeySets )
	, m_authKeyFuncPtr( rtg_arg.m_authKeyFuncPtr )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
XNL::XNLRegisterConnectionMsg & XNL::XNLRegisterConnectionMsg::operator=( const XNLRegisterConnectionMsg & rtg_arg )
{
	if( this != &rtg_arg )
	{
		Message::operator=( rtg_arg );
		m_connection = rtg_arg.m_connection;
		m_authKeySets = rtg_arg.m_authKeySets;
		m_authKeyFuncPtr = rtg_arg.m_authKeyFuncPtr;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'getType()'
ClassType XNL::XNLRegisterConnectionMsg::getType( void ) const
{
	// {{{USR
	return XNL_REGISTER_CONN_TYPE;
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize()'
Array * XNL::XNLRegisterConnectionMsg::serialize( void )
{
	// {{{USR
	return (Array *)0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'unserialize(Array*)'
bool XNL::XNLRegisterConnectionMsg::unserialize( Array * buf )
{
	// {{{USR
	return false;
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNLRegisterConnectionMsg(Connection *,XNLAuthKeySets *,AUTHKEYFUNCPTR)'
XNL::XNLRegisterConnectionMsg::XNLRegisterConnectionMsg( Connection * connection, XNLAuthKeySets * authKeySets, AUTHKEYFUNCPTR authKeyFuncPtr )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_connection(connection), m_authKeySets(authKeySets), m_authKeyFuncPtr(authKeyFuncPtr)
	// }}}USR
	// }}}RME
{
	// {{{USR
	setPriority(Message::getMaxPriority());
	// }}}USR
}
// }}}RME

// {{{RME operation 'getConnection()'
Connection * XNL::XNLRegisterConnectionMsg::getConnection( void )
{
	// {{{USR
	return m_connection;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getAuthKeySets()'
XNLAuthKeySets * XNL::XNLRegisterConnectionMsg::getAuthKeySets( void )
{
	// {{{USR
	return m_authKeySets;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getFunctionPtr()'
AUTHKEYFUNCPTR XNL::XNLRegisterConnectionMsg::getFunctionPtr( void )
{
	// {{{USR
	return m_authKeyFuncPtr;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classAttribute 'm_XNLVersionNumber'
const uint32_t XNL::m_XNLVersionNumber( 2 );
// }}}RME

// {{{RME classAttribute 'XNL_MSG_QUEUE_NAME'
const char * const XNL::XNL_MSG_QUEUE_NAME = "xnlMsgQueue";
// }}}RME

// {{{RME classAttribute 'm_xnlClassInstance'
XNL * XNL::m_xnlClassInstance = 0;
// }}}RME

// {{{RME operation 'registerConnectionUtil(Connection *,XNLAuthKeySets *,AUTHKEYFUNCPTR)'
bool XNL::registerConnectionUtil( Connection * connection, XNLAuthKeySets * authKeySets, AUTHKEYFUNCPTR authKeyFuncPtr )
{
	// {{{USR
	uint_fast8_t i;
	bool success = true;
	uint_fast8_t max = m_xnlInitInfo.getMaxNumConn();
	XNLDevice defaultDev(0,0);

	//make sure the new xcmp xnl strategy is in place
	//make sure a valid connection has been passed.
	if((!authKeySets) || (!connection))
	{
		return false;
	}


	// search for an available routing entry

	m_routingEntryMutex->lock();

	for (i = 0; i < max; ++i)
	{
		// if it is 0, then it is available for use.
	    if (m_xnlRoutingList[i] == 0)
	    {
	        break;
	    }
	}

	// check if there is room for a new connection...
	if (i < max)
	{
	    // if there is then create a new connection routing entry.
		// the connection will be registered when the routing entry is created.
	    m_xnlRoutingList[i] = new XNLRoutingEntry(connection, 0x0000, defaultDev, authKeySets, authKeyFuncPtr);

		// check if mastership has been determined
		if (m_masterDetermined)
		{
			// check if we're the master
			if (m_xnlPrvStatus.isMyDeviceMaster())
			{
				// Send a master status broadcast to the registering connection
				XNLMasterStsBrdcst msbMsg;
				msbMsg.setSourceAddr(m_xnlPrvStatus.getMasterXNLAddr()); // from the master
				msbMsg.setDestAddr(0x0000);  // to all devices	
				msbMsg.setXnlVersion(m_XNLVersionNumber);
				msbMsg.setMasterLogicalId(m_xnlPrvStatus.getMyDevice());
				msbMsg.setDataMsgSent(m_dataMsgSent);

				// serialize the master status broadcast msg and send it.
				DataBuffer* db = (DataBuffer*)msbMsg.serialize();

				if (db != 0)
				{
					if (sendTxMsg(*m_xnlRoutingList[i], db, false) == false)
					{
						// buffer ownership was not passed so delete this version of the dataBuf
						delete db;
					}
				}
			}
		}
	}
	else
	{
	    // we don't have room for another connection.
	    // LOG ERROR HERE
	    success = false;
	}

	m_routingEntryMutex->unlock();

	return (success);
	// }}}USR
}
// }}}RME

// {{{RME operation 'unregisterConnectionUtil(Connection *)'
bool XNL::unregisterConnectionUtil( Connection * connection )
{
	// {{{USR
	uint_fast8_t i;
	uint_fast8_t max = m_xnlInitInfo.getMaxNumConn();
	bool success = true;
	bool bSendSMB = false;

	m_routingEntryMutex->lock();

	// search for the connection in the routing entries
	for (i = 0; i < max; ++i)
	{
		// make sure the routing entry exists and that the connection matches...
	    if ((m_xnlRoutingList[i] != 0) && (m_xnlRoutingList[i]->getConnection() == connection))
	    {
			// i will equal the matching entry index.
	        break;
	    }
	}

	// check if the connection was found...
	if (i < max)
	{
		// routeXnlCtrlMsg needs the routing entry mutex so we can't actually send
		// the message until we're done here so set a flag so we'll know to send it
		// after we've unlocked the routing entry mutex
		bSendSMB = true;

		// Get the logical addr of the device for use in the disconnect event
		XNLDevice deviceAddr = m_xnlRoutingList[i]->getDevice();

	    // Remove the connection routing entry.
		// the connection will be unregistered when routing entry is destroyed
		delete m_xnlRoutingList[i];

	    m_xnlRoutingList[i] = 0;

		m_routingEntryMutex->unlock();

		m_xnlPrvStatus.setDeviceDisconnected(deviceAddr);

		// Free up the device ID so it can be reused
		m_addrMgr->unassignLogicalAddr(deviceAddr);
	}
	else
	{
		m_routingEntryMutex->unlock();

	    // we don't have that connection registered, so return false.
	    success = false;
	}

	// If we updated the system map and we're master, then we need to send the map out to everyone
	if (bSendSMB && m_xnlPrvStatus.isMyDeviceMaster())
	{
		// Send out an updated system map
		XNLSysMapBrdcst smb;

		// Set the XNL address for the master
		smb.setSourceAddr(m_xnlPrvStatus.getMyXNLAddr());

		// Set the destination address to "all devices"
		smb.setDestAddr(0x0000);

		// There should be a system map but make sure. If there is, make a copy.
		// and store it in the message. Otherwise, leave the map empty
		const XNLSystemMap* pSysMap = m_xnlPrvStatus.getSystemMap();

		if (pSysMap)
			smb.setSystemMap(new XNLSystemMap(*pSysMap));

		// Serialize the message and send it off.
		DataBuffer* pData = (DataBuffer*)smb.serialize();

		if (pData)
		{
			// If we are successful, then XNL will consume the buffer and return 0;
			// otherwise, we need to delete it
			if ((pData = routeXnlCtrlMsg(pData)) != 0)
				delete pData;
		}
	}

	return (success);

	// }}}USR
}
// }}}RME

// {{{RME operation 'validateRoutingEntry(Connection *,uint16_t,XNLDevice &)'
bool XNL::validateRoutingEntry( Connection * conn, uint16_t xnlAddr, XNLDevice & logDev )
{
	// {{{USR
	uint_fast8_t i;
	uint_fast8_t max = m_xnlInitInfo.getMaxNumConn();
	bool success = true;

	m_routingEntryMutex->lock();

	// search for connection in the routing table
	for (i = 0; i < max; ++i)
	{
		// if connections are equal, then we have found the routing entry.
	    if ((m_xnlRoutingList[i] != 0) && (m_xnlRoutingList[i]->getConnection() == conn))
	    {
	        break;
	    }
	}

	// check if the connection was found.
	if (i < max)
	{
	    // if there is then create a new connection routing entry.
		// the connection will be registered when the routing entry is created.
	    m_xnlRoutingList[i]->validateRoutingEntry(xnlAddr, logDev);

	}
	else
	{
	    // we don't record of this connection.
	    // LOG ERROR HERE
	    success = false;
	}

	m_routingEntryMutex->unlock();

	return (success);
	// }}}USR
}
// }}}RME

// {{{RME operation 'connect(ChannelAddress *,unsigned int *)'
bool XNL::connect( ChannelAddress * address, unsigned int * transId )
{
	// {{{USR
	// kick off master arbitration when the user connects.
	m_masterDetermined = m_masterArbitrator->masterArbInit(m_xnlInitInfo, m_addrMgr);

	// check to see if master was determined yet.
	if (m_masterDetermined)
	{
		// if so, then set the connected status
		m_xnlChanStatus.setConnected(true);

		if (m_xnlPrvStatus.isMyDeviceMaster())
		{
			// Initialize the connection protocol handler
			m_xnlConnProtoHandler->init(m_xnlInitInfo, 0, m_addrMgr);
		}
	}

	// don't currently support transaction ids for this event.
	// can use the XNL Master Event instead.
	// may eventually support both in the future.
	if (transId != 0)
	{
		*transId = 0;
	}

	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'connect(ChannelAddress *)'
bool XNL::connect( ChannelAddress * address )
{
	// {{{USR
	return connect(address,0);
	// }}}USR
}
// }}}RME

// {{{RME operation 'disconnect(unsigned int *)'
bool XNL::disconnect( unsigned int * transId )
{
	// {{{USR
	return (false);
	// }}}USR
}
// }}}RME

// {{{RME operation 'disconnect()'
bool XNL::disconnect( void )
{
	// {{{USR
	return (false);
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Array *)'
bool XNL::send( Array * buffer )
{
	// {{{USR
	// create the interthread message for sending data messages

	return (send(buffer,0));
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Array *,unsigned int *)'
bool XNL::send( Array * xnlMsg, unsigned int * transId )
{
	// {{{USR
	bool success = false;

	// make sure we are connected first.
	if (m_xnlChanStatus.isConnected())
	{
		// check to see if a DataBuffer was passed in instead of an XNLMessage
		if (xnlMsg->getType() == DataBuffer::DATA_BUFFER_ARRAY)
		{
			XNLDevice toAllDev(0,0);

			// if so, create an XNLMessage out of it.
			// default it to all devices and from all devices b/c if they aren't using an
			// XNLMessage, then the user doesn't care about addressing or transaction ids.
			XNLMessage *tmpMsg = new XNLMessage(*((DataBuffer *)xnlMsg), toAllDev, toAllDev);

			// delete what was passed in, since we don't need it any more.
			delete xnlMsg;

			// assign the variable to the new XNLMessage.
			xnlMsg = tmpMsg;
		}

		if (xnlMsg->getType() == XNLMessage::XNL_MSG_CLASS_TYPE)
		{
			// create the interthread message for sending data messages
			XNLSendInterthreadMsg * msgPtr = new XNLSendInterthreadMsg((XNLMessage *)xnlMsg);

			// put them into the XNL thread's message queue for processing
			addToMsgQueue(msgPtr);

			// right now we don't support transaction ids.
			if (transId != 0)
			{
				*transId = 0;
			}

			success = true;
		}
	}

	return (success);
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
Array * XNL::receive( void )
{
	// {{{USR
	// get the oldest received message out of the queue.
	XNLMessage *rxMsg = m_rxMsgQueue.delinkHead();

	// check to see if the queue is now empty.
	if (m_rxMsgQueue.isQueueEmpty())
	{
		// then we need to set data available to false.
		m_xnlChanStatus.setDataAvailable(false);
		
	}

	return (rxMsg);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getXNLVersionNum()'
uint32_t XNL::getXNLVersionNum( void ) const
{
	// {{{USR
	return (m_XNLVersionNumber);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getDataMsgSent()'
bool XNL::getDataMsgSent( void ) const
{
	// {{{USR
	return (m_dataMsgSent);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus()'
Connection::Status * XNL::getStatus( void )
{
	// {{{USR
	return (&m_xnlChanStatus);

	// }}}USR
}
// }}}RME

// {{{RME operation 'getXNLStatus()'
XNLStatus * XNL::getXNLStatus( void )
{
	// {{{USR
	return (&m_xnlPrvStatus);
	// }}}USR
}
// }}}RME

// {{{RME operation 'addToRxDataQueue(XNLMessage *)'
void XNL::addToRxDataQueue( XNLMessage * rxDataBuffer )
{
	// {{{USR
	// put the XNL Message in our receive queue...

	m_rxMsgQueue.addToTail(rxDataBuffer);


	// notify our event listeners that data is now available.
	m_xnlChanStatus.setDataAvailable(true);

	// }}}USR
}
// }}}RME

// {{{RME operation 'addToMsgQueue(Message *)'
void XNL::addToMsgQueue( Message * itMsg )
{
	// {{{USR
	m_xnlMsgQueue->send(itMsg);
	// }}}USR
}
// }}}RME

// {{{RME operation 'routeXnlCtrlMsg(DataBuffer *)'
DataBuffer * XNL::routeXnlCtrlMsg( DataBuffer * dataBuf )
{
	// {{{USR
	uint_fast8_t i;
	DataBuffer * tdb;
	uint_fast8_t max = m_xnlInitInfo.getMaxNumConn();

	bool success = true; // be optimistic and assume success

	// lock the mutex before accessing the routing table.
	m_routingEntryMutex->lock();

	for (i = 0; i < max; i++)
	{
		if (m_xnlRoutingList[i] != 0)
		{
			// make a copy to send...
			tdb = new DataBuffer(dataBuf);
			
	 		// now send the data buffer.
			// "false" indicates that it should not block waiting for ack.
			if (sendTxMsg(*m_xnlRoutingList[i], tdb, false) == false)
			{
				// then the send failed, so update the success flag.
				// don't break out of the loop, continue to send as required so that
				// other devices get a shot at the message.
				success = false;

				// buffer ownership was not passed so delete this version of the dataBuf
				delete tdb;
			}
		}
	}

	// unlock the routing table mutex
	m_routingEntryMutex->unlock();

	if (success)
	{
		delete dataBuf;
		dataBuf = 0;
	}

	return dataBuf;

	// }}}USR
}
// }}}RME

// {{{RME operation 'routeTxMsg(XNLMessage *)'
XNLMessage * XNL::routeTxMsg( XNLMessage * xnlMsg )
{
	// {{{USR
	// Non-master devices should only be sending messages via the master's connection.
	// Master devices will look at the destination address and then find the appropriate
	// connection to send it on.

	uint_fast8_t i;
	DataBuffer * tdb;
	uint_fast8_t max = m_xnlInitInfo.getMaxNumConn();

	bool success = true; // be optimistic and assume success

	// in case of failure need to store which entry was not reached
	XNLCommFailedEvent **failedConnections = new XNLCommFailedEvent *[max];
	uint8_t failedConnIndex = 0;


	// create a xnl data msg to send and initialize the common portions of it
	XNLDataMsg *xnlDataMsg = new XNLDataMsg();
	xnlDataMsg->setProtocolId(XNL_PROTO_XCMP);
	xnlDataMsg->setSourceAddr(m_xnlPrvStatus.getMyXNLAddr());
	xnlDataMsg->setTransactionId(xnlMsg->getTransactionId());

	// make a copy of the dataBuffer portion of the xnlMsg and put it into the data msg.
	xnlDataMsg->setDataPayload(new DataBuffer(xnlMsg));

	// Get the logical address of the device to which this msg is addressed
	XNLDevice dev = xnlMsg->getToDevice();

	// check to see if this message was address to our device specifically.
	// this allows a device to send a message to itself in case other applications
	// are expecting it.
	if (dev == m_xnlPrvStatus.getMyDevice())
	{
		// if so, make a copy of the xnl msg and 
		// put it in our rx queue so it can be processed.
		XNLMessage *tmpXnlMsg = new XNLMessage(*xnlMsg);
		addToRxDataQueue(tmpXnlMsg);
	}

	// see if we need to send to all devices. Only masters can directly send to all devices.
	// non masters will send the all devices addr to the master and have it resend it to all.
	bool allDevices = ((dev.getDeviceType() == XNL_DEVICE_TYPE_ALL) && (dev.getId() == XNL_DEVICE_ID_ALL));

	m_routingEntryMutex->lock();

	if (m_xnlPrvStatus.isMyDeviceMaster())
	{
	    // search all connections for the matching logical address contained in the XNL Message
	    for (i = 0; i < max; i++)
	    {
			if (m_xnlRoutingList[i] != 0)
			{
	        	// send it to the appropriate connections.
	        	// check for valid device. Device is set only after authentication is succesful.
	        	// check for specific device or all devices, or all devices of a particular type:
				// i.e the deviceTypes of dev and the entry match and dev's device ID is all device ID's
	        	if (m_xnlRoutingList[i]->isDeviceValid() &&
	                (m_xnlRoutingList[i]->isDevice(dev) || allDevices ||
	        		( (m_xnlRoutingList[i]->getDevice()).getDeviceType() == dev.getDeviceType() && 
						dev.getId() == XNL_DEVICE_ID_ALL) ))
				{	
					if(allDevices)
					{
						// Message is addressed to all devices
						xnlDataMsg->setDestAddr(0x0000);
					}
					else
					{
						// set the destination address for the message.
						xnlDataMsg->setDestAddr(m_xnlRoutingList[i]->getXNLAddr());
					}

					// set the msg count
					xnlDataMsg->setMsgCount(m_xnlRoutingList[i]->incrTxMsgCnt());

					// serialize the data message so it can be sent.
					tdb = (DataBuffer *)xnlDataMsg->serialize();
					
					// now send the serialize version of the xnl message.
					// Unless the device specifies no acks,this will need 
					// to be a blocking send until the ack is received or t.o. occurs.
					if (sendTxMsg(*m_xnlRoutingList[i], tdb,!(m_xnlRoutingList[i]->getXNLDisableAckFlag())) == false)
					{
						// then the send failed, so update the success flag.
						// don't break out of the loop, continue to send as required so that
						// other devices get a shot at the message.
						success = false;

	                    //create a commFailed event with a copy of the failed message.
						XNLMessage * xnlMsgCopy = new XNLMessage(*xnlMsg);
						failedConnections[failedConnIndex++] = new XNLCommFailedEvent(xnlMsgCopy, m_xnlRoutingList[i]->getConnection(),
	                       m_xnlRoutingList[i]->getDevice(), m_xnlRoutingList[i]->getXNLAddr());

						// buffer ownership was not passed so delete this version of the dataBuf
						delete tdb;
					}
				}
			}
	    }
	}
	else // we are not the master
	{
		uint16_t masterXNLAddr = m_xnlPrvStatus.getMasterXNLAddr();

	    // send the message on the master connection
	    // search all connections for the matching Master XNL address
	    for (i = 0; i < max; i++)
	    {
			// check to see if this is the master device
			if ((m_xnlRoutingList[i] != 0) && (m_xnlRoutingList[i]->isDevice(masterXNLAddr)))
			{
				// set the msg count
	            // even though this message may be destined for a device other than the master
	            // use the master message count.
				xnlDataMsg->setMsgCount(m_xnlRoutingList[i]->incrTxMsgCnt());
				break;	
			}
		}

		// make sure i is valid
		if (i < max)
		{
			if (allDevices)
			{
				// Message is addressed to all devices
				xnlDataMsg->setDestAddr(0x0000);
			}
			else
			{
				// This msg is addressed to a specific device, so lookup the XNL address
				// of the device for whom this msg was intended
				XNLSysMapData pData;

				if(m_xnlPrvStatus.getSystemMapData(dev, pData))
				{
					// If we found the device's address, set it in the message
					xnlDataMsg->setDestAddr(pData.getXNLAddr());
				}
				else
				{
					success = false;

					// ERROR LOG HERE
				}
			}

			if (success)
			{
				// serialize the data message so it can be sent.
				tdb = (DataBuffer *)xnlDataMsg->serialize();
					
				// now send the serialize version of the xnl message
				// this will need to be a blocking send until the ack is received or t.o. occurs.
				if (sendTxMsg(*m_xnlRoutingList[i], tdb) == false)
				{
					// then the send failed, so update the success flag.
					// don't break out of the loop, continue to send as required so that
					// other devices get a shot at the message.
					success = false;

					//create a commFailed event with a copy of the failed message.
					XNLMessage * xnlMsgCopy = new XNLMessage(*xnlMsg);
					failedConnections[failedConnIndex++] = new XNLCommFailedEvent(xnlMsgCopy, m_xnlRoutingList[i]->getConnection(),                  m_xnlRoutingList[i]->getDevice(), m_xnlRoutingList[i]->getXNLAddr());

					// buffer ownership was not passed so delete this version of the dataBuf
					delete tdb;
				}
			}
		}
	} // end not master

	m_routingEntryMutex->unlock();

	// if we were successful, then delete the xnlMsg.
	// otherwise, we just return the XNL msg to the caller to deal with.
	if (success == true)
	{
		delete xnlMsg;
		xnlMsg = 0;
	}
	else
	{
		// now process the comm failed events if there were any. It is important to do this
		// after we unlock the routingEntryMutex to avoid a deadlock condition.
		for(int j=0; j<failedConnIndex; j++)
		{
			m_xnlPrvStatus.incrFailedMsgCount(failedConnections[j]);
			// event must be handled before this call to incrFailedMsgCount returns since we delete 
			// the failed connection entry right away. Let xnlMsg be returned to the caller of routeTxMsg.
			delete failedConnections[j];
		}
	}
	// delete the xnl data msg class.
	delete (xnlDataMsg);

	// delete the array we created to hold comm failed event pointers
	delete [] failedConnections;

	return (xnlMsg);
	// }}}USR
}
// }}}RME

// {{{RME operation 'sendTxMsg(XNLRoutingEntry &,DataBuffer *,bool)'
bool XNL::sendTxMsg( XNLRoutingEntry & routingEntry, DataBuffer * dataBuf, bool waitForAck )
{
	// {{{USR
	bool success = true;

	DataBuffer* sendBuf;

	if (waitForAck)
	{
		// We need to send out a copy each time, not the original. The reason is that if
		// we fail to send after 5 attempts, then the caller will expect the buffer it passed
		// in to be intact so that it can be sent on in a "failed" event. But if the failure
		// is due to a timeout, then the buffer will have been consumed in the send so...
		sendBuf = new DataBuffer(dataBuf);
	}
	else
	{
		// No chance of a timeout which means if send fails, the buffer will not be consumed
		// and so it'll be intact for the caller. Therefore, no need to make a copy.
		sendBuf = dataBuf;
	}

	uint8_t retryCount = 5;  // should I make this configurable?

	while (retryCount > 0)
	{
		if (routingEntry.getConnection()->send(sendBuf) == false)
		{
			// then there was an error
			// LOG ERROR HERE

			retryCount--;

			// if we have exhausted our retries, then indicate failure.
			if (retryCount == 0)
			{
				success = false;
				// delete the sendBuf if waitForAck is true since we created a 
				// copy that we currently still own.
				if (waitForAck == true)
				{
					delete sendBuf;
				}

			}		
		}
		else
		{
			// then it was successful, so wait on the ack, if required.
			if (waitForAck == true)
			{
				// wait on the ack by waiting on the semaphore.
				// the eventOccurred for this connection will signal us when the ack is rx.
				if (routingEntry.waitForAck() == false)
				{
					// then a timeout occurred before the ack, so try again
					retryCount--;

					// if we have exhausted our retries, then indicate failure and leave
					// the original msg buffer intact for the caller.
					if (retryCount == 0)
					{
						success = false;
					}
					else
					{
						// We lost ownership of the copy we sent so make another copy
						// to send on the next try
						sendBuf = new DataBuffer(dataBuf);
					}
				}
				else
				{
					// setting the retryCount to 0 stops the retries.
					retryCount = 0;

					// delete the original data buffer since the copy was
					// sent and acknowledged
					delete dataBuf;
				}
			}
			else
			{
				// Successful so no need to retry and since we weren't waiting on
				// an ack, there's no copy of the msg to worry about cleaning up
				retryCount = 0;
			}
		}

	} // end while

	return (success);
	// }}}USR
}
// }}}RME

// {{{RME operation 'main()'
void * XNL::main( void )
{
	// {{{USR
	Message *msgPtr;
	XNLMessage *xnlMsg;
	XNLProtocolMsg *xnlPMsg = 0;
	bool newMasterDet;

	// run basically forever, or until the destroyXNLThread function is called to terminate
	// the thread.
	while (m_xnlThreadRunning)
	{
		newMasterDet = false;

	    // block until we receive one of XNL's interthread messages
	    msgPtr = m_xnlMsgQueue->receive();
	    
	    if (msgPtr->getType() == XNLRxInterthreadMsg::XNL_RX_SPECIFIC_MSG_TYPE)
	    {
			XNLRxInterthreadMsg * rxSpecMsg = (XNLRxInterthreadMsg *)msgPtr;
			DataBuffer *rxDb = rxSpecMsg->getDataBuf();

			// figure out what type the message is so we can unserialize it.
			switch (XNLProtocolMsg::getXNLMsgOpcode(rxDb))
			{
				case XNL_MASTER_STATUS_BRDCST:
				{
					xnlPMsg = new XNLMasterStsBrdcst();
					if (xnlPMsg->unserialize(rxDb))
					{
						newMasterDet = m_masterArbitrator->procMasterArbMsg(xnlPMsg, 
																			rxSpecMsg->getConnection());
						xnlPMsg = 0;
					}
				}
				break;

				case XNL_DEVICE_MASTER_QUERY:
				{
					xnlPMsg = new XNLDevMasterQuery();
					if (xnlPMsg->unserialize(rxDb))
					{

						// ignore the return value, since mastership won't change on a queury.
						m_masterArbitrator->procMasterArbMsg(xnlPMsg, rxSpecMsg->getConnection());
						xnlPMsg = 0;
					}
				}
				break;

				case XNL_DEVICE_AUTH_KEY_REQUEST:
				{
					// Only the master should get this type of message
					if (m_masterDetermined && m_xnlPrvStatus.isMyDeviceMaster())
					{
						xnlPMsg = new XNLDevAuthKeyReq();
						if (xnlPMsg->unserialize(rxDb))
						{
							m_xnlConnProtoHandler->processMessage(xnlPMsg, rxSpecMsg->getConnection());
							xnlPMsg = 0;
						}
					}
					else
					{
						delete rxDb;

						// LOG ERROR HERE
					}
				}
				break;

				case XNL_DEVICE_AUTH_KEY_REPLY:
				{
					// Only non-masters should get this type of message
					if (m_masterDetermined && !m_xnlPrvStatus.isMyDeviceMaster())
					{
						xnlPMsg = new XNLDevAuthKeyReply();
						if (xnlPMsg->unserialize(rxDb))
						{
							m_xnlConnProtoHandler->processMessage(xnlPMsg, rxSpecMsg->getConnection());
							xnlPMsg = 0;
						}
					}
					else
					{
						delete rxDb;

						// LOG ERROR HERE
					}
				}
				break;

				case XNL_DEVICE_CONN_REQUEST:
				{
					// Only the master should get this type of message
					if (m_masterDetermined && m_xnlPrvStatus.isMyDeviceMaster())
					{
						xnlPMsg = new XNLDevConnReq();
						if (xnlPMsg->unserialize(rxDb))
						{
							m_xnlConnProtoHandler->processMessage(xnlPMsg, rxSpecMsg->getConnection());
							xnlPMsg = 0;
						}
					}
					else
					{
						delete rxDb;

						// LOG ERROR HERE
					}
				}
				break;

				case XNL_DEVICE_CONN_REPLY:
				{
					// Only non-masters should get this type of message
					if (m_masterDetermined && !m_xnlPrvStatus.isMyDeviceMaster())
					{
						xnlPMsg = new XNLDevConnReply();
						if (xnlPMsg->unserialize(rxDb))
						{
							if (!m_xnlConnProtoHandler->processMessage(xnlPMsg, rxSpecMsg->getConnection()))
							{
								// The only reason processMessage would return false is if we failed to
								// authenticate the master. Since that's what happens, it means something's
								// not right with the device claiming to be master so see if we have the
								// potential to being master.
								if (m_xnlInitInfo.getMasterPriority() > 0)
								{
									// Yep, assume mastership
									assumeMasterStatus();
								}
							}

							xnlPMsg = 0;
						}
					}
					else
					{
						delete rxDb;

						// LOG ERROR HERE
					}
				}
				break;

				case XNL_DEVICE_SYSMAP_REQUEST:
				{
					// Only the master should get this type of message
					if (m_masterDetermined && m_xnlPrvStatus.isMyDeviceMaster())
					{
						xnlPMsg = new XNLSysMapReq();
						if (xnlPMsg->unserialize(rxDb))
						{
							m_xnlConnProtoHandler->processMessage(xnlPMsg, rxSpecMsg->getConnection());
							xnlPMsg = 0;
						}
					}
					else
					{
						delete rxDb;

						// LOG ERROR HERE
					}
				}
				break;

				case XNL_DEVICE_SYSMAP_BRDCST:
				{
					// Only non-masters should get this type of message
					if (m_masterDetermined && !m_xnlPrvStatus.isMyDeviceMaster())
					{
						xnlPMsg = new XNLSysMapBrdcst();
						if (xnlPMsg->unserialize(rxDb))
						{
							m_xnlConnProtoHandler->processMessage(xnlPMsg, rxSpecMsg->getConnection());
							xnlPMsg = 0;
						}
					}
					else
					{
						delete rxDb;

						// LOG ERROR HERE
					}
				}
				break;

				case XNL_DEVICE_RESET_MSG:
				{
					xnlPMsg = new XNLResetMsg();
					if (xnlPMsg->unserialize(rxDb))
					{
						// procResetMsg will return true if the message is meant for us and
						// we're being reset
						procResetMsg(xnlPMsg, rxSpecMsg->getConnection());
						xnlPMsg = 0;
					}
				}
				break;

				case XNL_DATA_MSG:
				{
					// We've received a data msg that needs to be handled. 
					// This should occur in a couple of cases. The 1st is if we are the Master and need to
					// reroute a message. The 2nd is if we are a non-master device, then we may have received
					// a data message before we fully processed a successful connection reply from the master.
					// In this case, our xnl addr may not have been set by the time the data msg was received,
					// so it will get routed here.
					// Both cases should check to see if the master has been determined before processing any
					// data messages.
					if (m_masterDetermined)
					{
						uint16_t destAddr = XNLProtocolMsg::getXNLMsgDestAddr(rxDb);
						
						// check if I'm the master. If so, this will be a reroute data msg case.
						if (m_xnlPrvStatus.isMyDeviceMaster())
						{
							xnlPMsg = new XNLDataMsg();
							if (xnlPMsg->unserialize(rxDb))
							{
								// Reroute the msg to the appropriate device(s)
								rerouteDataMsg((XNLDataMsg*)xnlPMsg, rxSpecMsg->getConnection());
								xnlPMsg = 0;
							}
						}
						else if ((destAddr == m_xnlPrvStatus.getMyXNLAddr() || destAddr == 0x0000) && rxSpecMsg->getRouteMsg() == false )
						{
							// i'm not the master and this is a data msg addressed to me (specifically or to all devices) 
							// then this message may have been received while XNL Thread was in the process of validating
							// my connection.
							// We dont want to ack this again (done in the XNLRoutingEntry eventOccurred())
							// but we might need to process it if it was sent to us
							xnlPMsg = new XNLDataMsg();
							if (xnlPMsg->unserialize(rxDb))
							{
								// process the data message
								procDataMsg((XNLDataMsg*)xnlPMsg);
								xnlPMsg = 0;
							}
						}
						else  // it's not a reroute, nor is it addressed to me, so can't do anything with it.
						{
							delete rxDb;
							// LOG ERROR HERE
						}
					}
					else  // master has not been determined, so don't process it.
					{
						delete rxDb;
						// LOG ERROR HERE
					}
				}
				break;

				default:
				{
					delete rxDb;  // delete the data buffer

					// LOG ERROR HERE
				}
			}

			if (xnlPMsg)
			{
				delete xnlPMsg;
				xnlPMsg = 0;
			}

			// flag that rxDb has been consumed.
			rxDb = 0;

			// check if the master determined changed.
			if (newMasterDet == true)
			{
				// if so, set it to the new master determined state.
	            m_masterDetermined = true;

				// if so, set it to the new master determined state.
				m_xnlChanStatus.setConnected(m_masterDetermined);

				// Initialize the connection protocol handler
				m_xnlConnProtoHandler->init(m_xnlInitInfo, rxSpecMsg->getConnection(), m_addrMgr);
			}
		}
	        
	    // check if it is an application request to send
	    else if (msgPtr->getType() ==  XNLSendInterthreadMsg::XNL_SEND_SPECIFIC_MSG_TYPE)
	    {
			if (m_masterDetermined && m_xnlChanStatus.isConnected())
			{
	    		// get the XNL message out of the interthread message
	        	xnlMsg = ((XNLSendInterthreadMsg *)msgPtr)->getXNLMsg();

				// route it to the appropriate devices
				if ((xnlMsg = routeTxMsg(xnlMsg)) != 0)
				{
					// then there was an error in sending it.
					// XNLCommFailedEvent should already be sent. Delete the failed message.
					delete xnlMsg;
					xnlMsg = 0;
				}
			}

			// Set a flag regardless of whether or not we were successful since the whole point is
			// to have a way to let late-connecting devices know that they may have missed a message.
			m_dataMsgSent = true;
			
	    }
		else if (msgPtr->getType() == XNLTimerInterthreadMsg::XNL_TIMER_SPECIFIC_MSG_TYPE)
		{
			// A timer has expired so notify the appropriate handler based on the flag in the msg
			switch(((XNLTimerInterthreadMsg*)msgPtr)->getTimerExpHandler())
			{
				case XNLTimerInterthreadMsg::TIMER_EXP_MSTR_ARB:
				{
					m_masterArbitrator->procTimerExpiration();
					break;
				}
				case XNLTimerInterthreadMsg::TIMER_EXP_CONN_PROTO:
				{
					m_xnlConnProtoHandler->procTimerExpiration();
					break;
				}
				default:
				{
					// No other timer expiration messages currently supported

					break;
				}
			}
		}
	    else if (msgPtr->getType() == XNLUnregisterConnectionMsg::XNL_UNREGISTER_CONN_TYPE)
	    {
			// get the connection out of the interthread message
			Connection* pConn = ((XNLUnregisterConnectionMsg *)msgPtr)->getConnection();
			//unregister the connection
			unregisterConnectionUtil(pConn);
		}
	    else if (msgPtr->getType() == XNLRegisterConnectionMsg::XNL_REGISTER_CONN_TYPE)
	    {
			// get the connection information out of the interthread message
			Connection* pConn = ((XNLRegisterConnectionMsg *)msgPtr)->getConnection();
			XNLAuthKeySets * authKeySets = ((XNLRegisterConnectionMsg *)msgPtr)->getAuthKeySets();
			AUTHKEYFUNCPTR funcPtr = ((XNLRegisterConnectionMsg *)msgPtr)->getFunctionPtr();

			//register the connection
			registerConnectionUtil(pConn, authKeySets, funcPtr);
		}
	    else if (msgPtr->getType() == XNLThreadEndMsg::XNL_THREAD_END_MSG_TYPE)
	    {
			// Don't need to do anything. This msg was sent to unblock the thread so
			// that it can end.
		}
	    
	    delete msgPtr;
	}

	return (void *)0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator =(const XNL &)'
XNL & XNL::operator=( const XNL & xnl )
{
	// {{{USR
	// no code, do not call. can't use generated default b/c XNL contains compositions
	// of things that have private assignment operators as well.

	return (const_cast<XNL &>(xnl));
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNL(const XNL &)'
XNL::XNL( const XNL & xnl )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	// no code, do not call. can't use generated default b/c XNL contains compositions
	// of things that have private copy constructors as well.
	// }}}USR
}
// }}}RME

// {{{RME operation 'XNL()'
XNL::XNL( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_dataMsgSent(false), m_xnlThreadRunning(false), m_masterDetermined(false), m_addrMgr(0), m_masterArbitrator(0), 
	m_xnlRoutingList(0), m_routingEntryMutex(0), m_xnlMsgQueue(0), m_xnlConnProtoHandler(0), m_timerFactory(0), m_timerTickBase(0)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'XNL(const XNLInit &,TimerVirtualFactory*,uint16_t)'
XNL::XNL( const XNLInit & initInfo, TimerVirtualFactory * timerFactory, uint16_t timerTickBase )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_xnlInitInfo(initInfo), m_dataMsgSent(false), m_xnlThreadRunning(true), m_masterDetermined(false),
	  m_xnlConnProtoHandler(0), m_timerFactory(timerFactory), m_timerTickBase(timerTickBase)
	// }}}USR
	// }}}RME
{
	// {{{USR
	bool ret;
	int error = 0;

	m_xnlClassInstance = this;

	uint_fast8_t max = m_xnlInitInfo.getMaxNumConn();

	// initialize the system map. Add 1 b/c we need to account for ourselves
	m_xnlPrvStatus.initSystemMap(max+1);

	// create an address manager for address assignment
	m_addrMgr = new AddrMgr(max);

	// create the master arbitration handler class and pass it a timer for its
	// own use. (Pass false on timer creation so that it doesn't automatically
	// rearm itself each time it expires.)
	m_masterArbitrator = new XNLMasterArbitrator(this, &m_xnlPrvStatus, m_timerFactory->getTimerVirtual(false), timerTickBase);

	// create a connection protocol handler and pass it a timer for its
	// own use. (Pass false on timer creation so that it doesn't automatically
	// rearm itself each time it expires.)
	m_xnlConnProtoHandler = new XNLConnProtocolHandler(this, &m_xnlPrvStatus, m_timerFactory->getTimerVirtual(false), timerTickBase);

	// create a mutex to protect the routing entry
	m_routingEntryMutex = Mutex::createMutex();

	// create an array of connections. 
	// Currently we will only support a fixed # of connections.
	m_xnlRoutingList = new XNLRoutingEntry *[max];

	for (uint_fast8_t i = 0; i < max; i++)
	{
	    m_xnlRoutingList[i] = 0;
	}

#ifdef WIN32
	// for windows testing , we need to make sure that the queue
	// which is stored as a file is removed.
	MessageQueue::remove(XNL_MSG_QUEUE_NAME);
#endif

	ret = MessageQueue::create(XNL_MSG_QUEUE_NAME);


	if (ret)
	{
#if defined(DEBUG) && defined(WIN32)
		printf("MessageQueue creation successful\n");
	}
	else
	{
		printf("MessageQueue creation failed\n");
#endif /* WIN32 DEBUG */
	}

	m_xnlMsgQueue = MessageQueue::open(XNL_MSG_QUEUE_NAME, 0, false, &error);

#if defined(DEBUG) && defined(WIN32)
	printf("returned from mq_open w/error code %d\n", error);

	if (m_xnlMsgQueue)
		printf("MessageQueue open successful\n");
	else
		printf("MessageQueue open failed\n");

#endif /* WIN32 DEBUG */

	XNLRoutingEntry::setXNLPtr(this);

	// }}}USR
}
// }}}RME

// {{{RME operation '~XNL()'
XNL::~XNL( void )
{
	// {{{USR
	uint_fast8_t i;
	uint_fast8_t max = m_xnlInitInfo.getMaxNumConn();

	// delete all of the allocated resources, if allocated...

	// if mutex is not allocated, then assume the routing list hasn't bee allocated either.
	if (m_routingEntryMutex)
	{
		m_routingEntryMutex->lock();

		for (i = 0; i < max; ++i)
		{
			// if it is 0, then it is available for use.
	    	if (m_xnlRoutingList[i] != 0)
	    	{
				// routing entry destructor will unregister connection.
	        	delete m_xnlRoutingList[i];
	    	}
		}

		delete [] m_xnlRoutingList;

		m_routingEntryMutex->unlock();

		delete m_routingEntryMutex;
	}

	if (m_addrMgr)
	{
		delete m_addrMgr;
	}

	if (m_masterArbitrator)
	{
		delete m_masterArbitrator;
	}

	if (m_xnlConnProtoHandler)
	{
		delete m_xnlConnProtoHandler;
	}

	if (m_xnlMsgQueue)
	{
		MessageQueue::remove(XNL_MSG_QUEUE_NAME);
		delete m_xnlMsgQueue;
	}


	// }}}USR
}
// }}}RME

// {{{RME operation 'createXNLThread(int,const XNLInit &,TimerVirtualFactory*,uint16_t)'
Thread * XNL::createXNLThread( int priority, const XNLInit & initInfo, TimerVirtualFactory * timerFactory, uint16_t timerTickBase )
{
	// {{{USR
	return (actuallyCreateThread(priority, new XNL(initInfo, timerFactory, timerTickBase), 2048, "XnlThread"));
	// }}}USR
}
// }}}RME

// {{{RME operation 'destroyXNLThread()'
void XNL::destroyXNLThread( void )
{
	// {{{USR

	// set the flag to end the thread.
	m_xnlThreadRunning = false;

	// put a "thread end" message on the queue to unblock the thread
	XNLThreadEndMsg* msg = new XNLThreadEndMsg;
	addToMsgQueue(msg);

	// }}}USR
}
// }}}RME

// {{{RME operation 'procResetMsg(XNLProtocolMsg*,Connection*)'
void XNL::procResetMsg( XNLProtocolMsg * xnlPMsg, Connection * conn )
{
	// {{{USR
	bool reRouteMsg = false;
	bool genResetEvent = false;
	bool toAllDevices = false;

	uint_fast8_t i;
	uint_fast8_t max = m_xnlInitInfo.getMaxNumConn();

	DataBuffer* buf = 0;

	// Get the XNL address of the device to whom this msg is addressed
	uint16_t destAddr = xnlPMsg->getDestAddr();

	// See if we're the master
	if (m_xnlPrvStatus.isMyDeviceMaster())
	{
		// If the message is meant for us or for all devices, then it's a system-wide reset
		if ((destAddr == m_xnlPrvStatus.getMyXNLAddr()) || (destAddr == 0x0000))
		{
			if (destAddr != 0x0000)
			{
				// Make sure it's addressed to "all devices"
				xnlPMsg->setDestAddr(0x0000);
			}

	        m_routingEntryMutex->lock();

			// Send a reset message to all devices
			for (i = 0; i < max; i++)
			{
				if (m_xnlRoutingList[i] != 0)
				{
					buf = (DataBuffer*)xnlPMsg->serialize();

					// "false" indicates that it should not block waiting for ack.
					if (sendTxMsg(*m_xnlRoutingList[i], buf, false) == false)
					{
						// Buffer ownership was not passed so delete this buffer
						delete buf;
					}
				}
			}

	        m_routingEntryMutex->unlock();

			// Need to generate a reset event since we're resetting
			genResetEvent = true;
			toAllDevices = true;
		}
		else
		{
			// The message is meant for someone else so we need to re-route it
			reRouteMsg = true;
		}
	}
	else
	{
		// We're not the master so see if this msg is meant for us specifically
		if (destAddr == m_xnlPrvStatus.getMyXNLAddr())
		{
			// Yup, it's addressed specifically to us so we need to generate a reset event
			genResetEvent = true;
		}
		else
		{
			// If it's marked for "all devices", then we need to generate a reset event
			if (destAddr == 0x0000)
			{
				genResetEvent = true;
			}
			else
			{
				// It's addressed to someone else. If we know who the master is (i.e. master XNL
				// address isn't 0), then send it to him so he can reroute it to the correct device
				if ((destAddr = m_xnlPrvStatus.getMasterXNLAddr()) != 0x0000)
					reRouteMsg = true;
			}
		}
	}

	// See if we need to re-route the msg to the correct device
	if (reRouteMsg)
	{
	    m_routingEntryMutex->lock();

		// Loop through the routing entry list until we find the entry matching the dest address
		for (i = 0; i < max; i++)
		{
			if ((m_xnlRoutingList[i] != 0) && (m_xnlRoutingList[i]->isDevice(destAddr)))
			{
				// Found it so send the message
				buf = (DataBuffer*)xnlPMsg->serialize();

				// "false" indicates that it should not block waiting for ack.
				if (sendTxMsg(*m_xnlRoutingList[i], buf, false) == false)
				{
					// Buffer ownership was not passed so delete this buffer
					delete buf;
				}

				break;
			}
		}

	    m_routingEntryMutex->unlock();
	}

	// If we're resetting then generate a reset event
	if (genResetEvent)
	{
		// Right now, we don't support SysMap. Once SysMap support is added, we
		// need to set srcDevice to the correct logical address.
		XNLDevice srcDevice(0,0);
		m_xnlPrvStatus.setDeviceReset(xnlPMsg->getSourceAddr(), srcDevice, toAllDevices);
	}

	delete xnlPMsg;
	// }}}USR
}
// }}}RME

// {{{RME operation 'assumeMasterStatus()'
void XNL::assumeMasterStatus( void )
{
	// {{{USR
	uint16_t xnlAddr = m_xnlPrvStatus.getMyXNLAddr();
	XNLDevice logicalAddr = m_xnlPrvStatus.getMyDevice();

	// Generate and send a master status broadcast msg with our priority set to the max
	XNLMasterStsBrdcst msb;
	msb.setSourceAddr(xnlAddr);
	msb.setDestAddr(0x0000);  // to all devices	
	msb.setXnlVersion(m_XNLVersionNumber);
	msb.setMasterLogicalId(logicalAddr);
	msb.setDataMsgSent(m_dataMsgSent);

	DataBuffer* pBuf = (DataBuffer*)msb.serialize();

	if (pBuf)
	{
		// Send it out to everyone
		if ((pBuf = routeXnlCtrlMsg(pBuf)) != 0)
		{
			// If there was a problem the databuf is returned to us
			// so delete it and log an error.
			delete pBuf;

			// LOG ERROR HERE
		}
	}

	// Set the master determined event. Indicate that we are the master.
	m_xnlPrvStatus.setMasterDetermined(true, xnlAddr, logicalAddr, m_dataMsgSent);

	// Initialize the connection protocol handler
	m_xnlConnProtoHandler->init(m_xnlInitInfo, 0, m_addrMgr);

	m_masterDetermined = true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'rerouteDataMsg(XNLDataMsg*,Connection*)'
void XNL::rerouteDataMsg( XNLDataMsg * xnlDataMsg, Connection * pConn )
{
	// {{{USR
	uint_fast8_t i;
	uint_fast8_t src_conn_index;
	DataBuffer * tdb;
	uint_fast8_t max = m_xnlInitInfo.getMaxNumConn();

	// in case of failure need to store which entry was not reached
	XNLCommFailedEvent **failedConnections = 0;
	uint8_t failedConnIndex = 0;

	// Make sure the msg that we're supposed to reroute came in on a valid connection. If
	// it didn't, then ignore it. To check, we need to search the routing list for the connection
	bool bValidConn = false;

	m_routingEntryMutex->lock();

	for (i = 0; i < max; i++)
	{
		if ((m_xnlRoutingList[i] != 0) && (m_xnlRoutingList[i]->getConnection() == pConn))
		{
			bValidConn = m_xnlRoutingList[i]->isDeviceValid();
			src_conn_index = i;
			break;
		}
	}
	 
	// If the msg came in on a valid connection, then go ahead and reroute it
	if (bValidConn)
	{
		// in case of an error, lets store the failed connection information.
		failedConnections = new XNLCommFailedEvent *[max];
	 
		// Get the XNL address of the device to which this msg is addressed
		uint16_t dev = xnlDataMsg->getDestAddr();


		// See if we need to send to all devices.XNL Addr is 0 for all devices
		bool allDevices = (dev == 0);

		// search all connections for the matching logical address contained in the XNL Message
		for (i = 0; i < max; i++)
		{
			if (m_xnlRoutingList[i] != 0)
			{
	       		// send it to the appropriate connections but make sure we don't send it back 
				// on the same connection it came in on..
	    	   	// check for valid device. Device is set only after authentication is successful.
	       		// check for specific device or all devices.
		       	if (m_xnlRoutingList[i]->isDeviceValid() &&
	    	       (m_xnlRoutingList[i]->isDevice(dev) || allDevices) &&
				   (i != src_conn_index))
				{	
	                // Set the msg count to the next value for communication with this device
	                // before rerouting the message since the master takes ownership of the message.
	                // This is required because the message count will not match if a message is routed through another
	                // device (i.e. it will have the intermediate device's count, not the final device's count.)
					xnlDataMsg->setMsgCount(m_xnlRoutingList[i]->incrTxMsgCnt());

					// serialize the data message so it can be sent.
					tdb = (DataBuffer *)xnlDataMsg->serialize();
					
					// now send the serialize version of the xnl message.
					// Unless the device specifies no acks,this will need 
					// to be a blocking send until the ack is received or t.o. occurs.
					if (sendTxMsg(*m_xnlRoutingList[i], tdb,!(m_xnlRoutingList[i]->getXNLDisableAckFlag())) == false)
					{
						// then the send failed, don't break out of the loop, continue to send 
						// as required so that other devices get a shot at the message.

						// buffer ownership was not passed so delete this version of the dataBuf
						delete tdb;

						// now use tdb to save the DataBuffer from the DataMsg so that we can use
						// it to create an XNL Message. We'll put it back in case there are other
						// devices that it needs to be sent to.

						tdb = xnlDataMsg->getDataPayload();

						// then there was an error in sending it.
						// generate the XNLCommFailedEvent

						XNLDevice toAllDevices(0,0);  // to specify to all devices if required

						// create an XNLMessage to be passed in the failed msg event.
						// contains data, from addr, to addr, and trans id.
						XNLMessage * xnlMsg = new XNLMessage(*tdb,
									m_xnlRoutingList[src_conn_index]->getDevice(),
									(allDevices) ? toAllDevices : m_xnlRoutingList[i]->getDevice(), 
									(XCMPTransactionId)xnlDataMsg->getTransactionId());

		               	//create a commFailed event.
						failedConnections[failedConnIndex++] = new XNLCommFailedEvent(xnlMsg, m_xnlRoutingList[i]->getConnection(),
	                 	 m_xnlRoutingList[i]->getDevice(), m_xnlRoutingList[i]->getXNLAddr());

						// now put the data payload back in the XNLDataMsg in case further routing
						// is required.
						
						xnlDataMsg->setDataPayload(tdb);

					}

					// We're sending to a specific device - which we found - so no need to
					// look through the rest of the list
					if (!allDevices)
						break;
				}
			}
		}

		m_routingEntryMutex->unlock();

		// now process the comm failed events if there were any. It is important to do this
		// after we unlock the routingEntryMutex to avoid a deadlock condition.
		for(int j=0; j<failedConnIndex; j++)
		{
			m_xnlPrvStatus.incrFailedMsgCount(failedConnections[j]);
			// event must be handled before this call returns
			// still let xnlMsg be returned.
			delete failedConnections[j];
		}

		// delete the array we created to hold comm failed event pointers
		delete [] failedConnections;

	} // end if (bValidConn)
	// else msg came in on an invalid connection. We must unlock the routing entry mutex, since we locked it unconditionally 
	// at the top 
	else
	{
	    m_routingEntryMutex->unlock();
	}

	delete xnlDataMsg;

	// }}}USR
}
// }}}RME

// {{{RME operation 'getRoutingEntry(Connection*)'
XNLRoutingEntry * XNL::getRoutingEntry( Connection * pConn ) const
{
	// {{{USR
	uint_fast8_t i;
	uint_fast8_t max = m_xnlInitInfo.getMaxNumConn();

	XNLRoutingEntry* pEntry = 0;

	for (i = 0; i < max; i++)
	{
		// See if the current entry's connection is a match
		if ((m_xnlRoutingList[i] != 0) && (m_xnlRoutingList[i]->getConnection() == pConn))
		{
			pEntry = m_xnlRoutingList[i];
			break;
		}
	}

	return pEntry;
	// }}}USR
}
// }}}RME

// {{{RME operation 'lockRoutingEntryMutex(bool)'
void XNL::lockRoutingEntryMutex( bool bLock )
{
	// {{{USR
	if (bLock)
		m_routingEntryMutex->lock();
	else
		m_routingEntryMutex->unlock();
	// }}}USR
}
// }}}RME

// {{{RME operation 'encryptKey(const DataBuffer*,XNLAuthLevels,uint32_t*,uint32_t)'
DataBuffer * XNL::encryptKey( const DataBuffer * pAuthValue, XNLAuthLevels authLevel, uint32_t * authKey, uint32_t delta_val )
{
	// {{{USR
	const XNL * xnlClassPtr = getInstance();
	DataBuffer * replyEncryptedKey = 0;
	 
	if (xnlClassPtr != 0)
	{
	    replyEncryptedKey = xnlClassPtr->m_xnlConnProtoHandler->encryptKey(pAuthValue, authLevel, authKey, delta_val);
	}
	 
	return replyEncryptedKey;


	// }}}USR
}
// }}}RME

// {{{RME operation 'getInstance()'
const XNL * XNL::getInstance( void )
{
	// {{{USR
	return m_xnlClassInstance;
	// }}}USR
}
// }}}RME

// {{{RME operation 'procDataMsg(XNLDataMsg *)'
void XNL::procDataMsg( XNLDataMsg * xnlDataMsg )
{
	// {{{USR
	DataBuffer *rxdb;
	//XNLDataMsg *xnlDataMsg; parameter passed in
	XNLMessage *xnlMsg;

	uint16_t xnlToDev;
	uint16_t sourceAddr = 0;

	XNLDevice xnlFromLogicalDevice;
	XNLDevice toAllDevices(0,0);  // to specify to all devices.

	XNLStatus  *xnlSts = getXNLStatus();


	// create an XNLMessage with the data, from, to and transaction id.
	// get the data buffer from the xnl data msg
	// the "toAddr" is either to all devices or to my device.

	// rxdb will be used to temporarily hold the data payload.
	rxdb = xnlDataMsg->getDataPayload();

	sourceAddr = xnlDataMsg->getSourceAddr();
	xnlToDev = xnlDataMsg->getDestAddr();

	XNLSysMapData pData; 
		
	if(xnlSts->getSystemMapData(sourceAddr, pData))
	{
		xnlFromLogicalDevice = pData.getLogicalDevAddr();

		// Do not make any assumptions on the message that it is from the master device. 
		// And it always retrieves the source address from the message and forwards that information to XNL for processing.
		xnlMsg = new XNLMessage(*rxdb, 
					xnlFromLogicalDevice,
					(xnlToDev == 0x0000) ? toAllDevices : xnlSts->getMyDevice(),
					(XCMPTransactionId)xnlDataMsg->getTransactionId());

		xnlMsg->setDeviceAuthLvl(pData.getAuthLevel());
								
		// put the XNL Message data buffer in XNL's rx queue. This will cause the data available event
		// to be generated.
		addToRxDataQueue(xnlMsg);

	}
	else
	{
		// LOG ERROR HERE
	}

	// since XNLMessage constructor doesn't consume the databuffer, we must do it now.
	delete rxdb;

	// delete the xnlDataMsg since it is no longer needed.
	delete xnlDataMsg;
	// }}}USR
}
// }}}RME

// {{{RME operation 'unregisterConnection(Connection *,bool)'
bool XNL::unregisterConnection( Connection * connection, bool bWaitTillComplete )
{
	// {{{USR
	bool bResult = true;
	if(bWaitTillComplete)
	{
	    // if caller wants to wait then call the real unregisterConnection
	    bResult = unregisterConnectionUtil(connection);
	}
	else
	{
	    // put a "unregister connection" message in the queue
	    // XNL will handle this unregister when it can, caller will have to wait
	    // for XNLDevDisconnectedEvent to know that the connection has been unregistered.
	    XNLUnregisterConnectionMsg* msg = new XNLUnregisterConnectionMsg(connection);
	    addToMsgQueue(msg);
	}
	return bResult;
	// }}}USR
}
// }}}RME

// {{{RME operation 'registerConnection(Connection *,XNLAuthKeySets *,AUTHKEYFUNCPTR,bool)'
bool XNL::registerConnection( Connection * connection, XNLAuthKeySets * authKeySets, AUTHKEYFUNCPTR authKeyFuncPtr, bool bWaitTillComplete )
{
	// {{{USR
	bool success = true;

	if (bWaitTillComplete)
	{
	    // just call the real registerConnection
	   success = registerConnectionUtil(connection, authKeySets, authKeyFuncPtr);
	}
	else
	{

	    //make sure the new xcmp xnl strategy is in place
	    //make sure a valid connection has been passed.
	    if((!authKeySets) || (!connection))
	    {
	        // no point queueing if invalid parameters are passed
		    success = false;
	    }
	    else
	    {
	        // put a "register connection" message in the queue
	        // XNL will handle this register when it can, caller will have to wait
	        // for XNLDevConnectedEvent to know that the connection has been registered.
	        XNLRegisterConnectionMsg* msg = new XNLRegisterConnectionMsg(connection, authKeySets, authKeyFuncPtr);
	        addToMsgQueue(msg);
	    }
	}
	return success;
	// }}}USR
}
// }}}RME

// {{{RME operation 'doesConnectionExist(Connection *)'
bool XNL::doesConnectionExist( Connection * conn )
{
	// {{{USR
	uint_fast8_t i;
	uint_fast8_t max = m_xnlInitInfo.getMaxNumConn();
	bool isFound = false;

	// search for the connection in the routing entries
	for (i = 0; i < max; ++i)
	{
		// make sure the routing entry exists and that the connection matches...
	    if ((m_xnlRoutingList[i] != 0) && (m_xnlRoutingList[i]->getConnection() == conn))
	    {
		    //set the connection found to true
			isFound = true;

			// i will equal the matching entry index.
	        break;
	    }
	}

	return isFound;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLSendInterthreadMsg' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'AddrMgr' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Logical View::XCMP::XNL::XNL::AddrMgr::DeviceTypeNode' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLThreadEndMsg' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLUnregisterConnectionMsg' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'XNLRegisterConnectionMsg' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
