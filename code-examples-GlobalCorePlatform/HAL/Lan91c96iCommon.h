// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::Lan91c96iCommon'

#ifndef Lan91c96iCommon_H
#define Lan91c96iCommon_H

#ifdef PRAGMA
#pragma interface "Lan91c96iCommon.h"
#endif

#include <serial_comp.h>
#include <Configurable.h>
#include <Connection.h>
#include <EthernetTxEmptyEvent.h>
#include <ListenerBase.h>
#include <Mutex.h>
#include <NotifierBase.h>
class IOVirtual;
class Lan91c96iConfig;
class Lan91c96iIntSource;
class SCharArray;
class bitfield;
class peripheral_access;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>


// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Lan91c96iCommon : public NotifierBase, public ListenerBase
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
	// {{{RME classifier 'Status'
	class Status : public Connection::Status
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
		// {{{RME classAttribute 'm_isDataAvailable'
		bool m_isDataAvailable;
		// }}}RME

	protected:
		// {{{RME classAttribute 'm_actualLinkAvailability'
		bool m_actualLinkAvailability;
		// }}}RME

	public:
		// {{{RME associationEnd 'm_dataAvailableEvent'
		Connection::Status::Event m_dataAvailableEvent;
		// }}}RME
		// {{{RME associationEnd 'm_linkAvailable'
		Connection::Status::Event m_linkAvailable;
		// }}}RME
		// {{{RME associationEnd 'm_linkUnavailable'
		Connection::Status::Event m_linkUnavailable;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~Status( void );
		// }}}RME
		// {{{RME operation 'Status()'
		Status( void );
		// }}}RME
		// {{{RME operation 'isDataAvailable()'
		virtual bool isDataAvailable( void ) const;
		// }}}RME
		// {{{RME operation 'setDataAvailable(bool)'
		void setDataAvailable( bool dataAvailable );
		// }}}RME
		// {{{RME operation 'setAvailable(bool)'
		void setAvailable( bool availability );
		// }}}RME
		// {{{RME operation 'isAvailable()'
		bool isAvailable( void ) const;
		// }}}RME
	};
	// }}}RME
	// {{{RME classAttribute 'm_lan91c96iBaseAddress'
	unsigned int m_lan91c96iBaseAddress;
	// }}}RME
	// {{{RME classAttribute 'm_payLoadLength'
	unsigned int m_payLoadLength;
	// }}}RME
	// {{{RME classAttribute 'm_currentSendFrameBuffer'
	SCharArray * m_currentSendFrameBuffer;
	// }}}RME
	// {{{RME classAttribute 'm_intMask'
	unsigned int m_intMask;
	// }}}RME
	// {{{RME classAttribute 'm_preserveAddressPointer'
	unsigned int m_preserveAddressPointer;
	// }}}RME
	// {{{RME classAttribute 'm_preservedBank'
	unsigned int m_preservedBank;
	// }}}RME
	// {{{RME classAttribute 'm_frameAllocationPending'
	bool m_frameAllocationPending;
	// }}}RME

private:
	// {{{RME classAttribute 'm_rxOvrnCounter'
	unsigned int m_rxOvrnCounter;
	// }}}RME

protected:
	// {{{RME associationEnd 'm_status'
	Status * m_status;
	// }}}RME

public:
	// {{{RME associationEnd 'm_lan91c96iConfig'
	Lan91c96iConfig * m_lan91c96iConfig;
	// }}}RME
	// {{{RME associationEnd 'm_txEmptyEvent'
	EthernetTxEmptyEvent m_txEmptyEvent;
	// }}}RME
	// {{{RME associationEnd 'm_option'
	Configurable::Option * m_option;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	Lan91c96iCommon( void );
	// }}}RME
	// {{{RME operation 'Lan91c96iCommon(Lan91c96iConfig*)'
	Lan91c96iCommon( Lan91c96iConfig * config );
	// }}}RME
	// {{{RME operation 'handler()'
	void handler( void );
	// }}}RME
	// {{{RME operation 'sendFrame(SCharArray*)'
	void sendFrame( SCharArray * currentBuffer );
	// }}}RME
	// {{{RME operation 'receiveFrame()'
	SCharArray * receiveFrame( void );
	// }}}RME
	// {{{RME operation 'setInterrupt(unsigned int,bool)'
	void setInterrupt( unsigned int intValue, bool functionality );
	// }}}RME
	// {{{RME operation 'sendMMUCommand(unsigned int,unsigned int)'
	void sendMMUCommand( unsigned int mmuCommand, unsigned int numberOfPages );
	// }}}RME
	// {{{RME operation 'eventOccurred(const EventBase * const)'
	virtual void eventOccurred( const EventBase * const event );
	// }}}RME
	// {{{RME operation '~Lan91c96iCommon()'
	~Lan91c96iCommon( void );
	// }}}RME
	// {{{RME operation 'delay()'
	void delay( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Lan91c96iCommon_H */

// }}}RME
