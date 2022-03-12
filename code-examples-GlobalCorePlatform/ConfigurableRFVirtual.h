// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Hardware Abstraction Layer::Configurable RF Deck::ConfigurableRFVirtual'

#ifndef ConfigurableRFVirtual_H
#define ConfigurableRFVirtual_H

#ifdef PRAGMA
#pragma interface "ConfigurableRFVirtual.h"
#endif

#include <hal.h>
#include <Configurable.h>
#include <EventBase.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RFVirtualOption' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Event' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class ConfigurableRFVirtual : public Configurable
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
	// {{{RME classifier 'RFVirtualOption'
	class RFVirtualOption : public Configurable::Option
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
		// {{{RME classAttribute 'RF_VIRTUAL_OPTION'
		static const unsigned int RF_VIRTUAL_OPTION;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~RFVirtualOption( void );
		// }}}RME
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'isType(ClassType)'
		virtual bool isType( ClassType type ) const;
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'Event'
	class Event : public EventBase
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
		// {{{RME classAttribute 'RF_VIRTUAL_EVENT'
		static const unsigned int RF_VIRTUAL_EVENT;
		// }}}RME
		// {{{RME classAttribute 'TRANSMIT_ON'
		static const unsigned int TRANSMIT_ON;
		// }}}RME
		// {{{RME classAttribute 'TRANSMIT_STANDBY'
		static const unsigned int TRANSMIT_STANDBY;
		// }}}RME
		// {{{RME classAttribute 'RECEIVE_ON'
		static const unsigned int RECEIVE_ON;
		// }}}RME
		// {{{RME classAttribute 'RECEIVE_STANDBY'
		static const unsigned int RECEIVE_STANDBY;
		// }}}RME
		// {{{RME classAttribute 'RECEIVE_FAULT'
		static const unsigned int RECEIVE_FAULT;
		// }}}RME
		// {{{RME classAttribute 'TRANSMIT_FAULT'
		static const unsigned int TRANSMIT_FAULT;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~Event( void );
		// }}}RME
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'isType(ClassType)'
		virtual bool isType( ClassType type ) const;
		// }}}RME
		// {{{RME operation 'Event(unsigned int)'
		Event( unsigned int event );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'Status'
	class Status
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
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~Status( void );
		// }}}RME
		// {{{RME operation 'isTransmitting()'
		virtual bool isTransmitting( void ) const = 0;
		// }}}RME
		// {{{RME operation 'isReceiving()'
		virtual bool isReceiving( void ) const = 0;
		// }}}RME
		// {{{RME operation 'receiveFaultDetect()'
		virtual bool receiveFaultDetect( void ) const = 0;
		// }}}RME
		// {{{RME operation 'transmitFaultDetect()'
		virtual bool transmitFaultDetect( void ) const = 0;
		// }}}RME
	};
	// }}}RME
	// {{{RME classAttribute 'RF_MIN_POWER'
	static const unsigned int RF_MIN_POWER;
	// }}}RME
	// {{{RME classAttribute 'RF_MAX_POWER'
	static const unsigned int RF_MAX_POWER;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~ConfigurableRFVirtual( void );
	// }}}RME
	// {{{RME operation 'enableTransmitter()'
	virtual bool enableTransmitter( void ) = 0;
	// }}}RME
	// {{{RME operation 'enableTransmitter(unsigned long,unsigned int,unsigned int)'
	virtual bool enableTransmitter( unsigned long freq, unsigned int channelDeviation, unsigned int power ) = 0;
	// }}}RME
	// {{{RME operation 'disableTransmitter()'
	virtual bool disableTransmitter( void ) = 0;
	// }}}RME
	// {{{RME operation 'enableReceiver()'
	virtual bool enableReceiver( void ) = 0;
	// }}}RME
	// {{{RME operation 'enableReceiver(unsigned long,unsigned int)'
	virtual bool enableReceiver( unsigned long freq, unsigned int channelBandwidth ) = 0;
	// }}}RME
	// {{{RME operation 'disableReceiver()'
	virtual bool disableReceiver( void ) = 0;
	// }}}RME
	// {{{RME operation 'getStatus()'
	virtual Status * getStatus( void ) = 0;
	// }}}RME
	// {{{RME operation 'tempEnableReceiver(unsigned long,unsigned int)'
	virtual bool tempEnableReceiver( unsigned long freq, unsigned int channelBandwidth ) = 0;
	// }}}RME
	// {{{RME operation 'tempEnableTransmitter(unsigned long,unsigned int,unsigned int)'
	virtual bool tempEnableTransmitter( unsigned long freq, unsigned int channelDeviation, unsigned int power ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'RFVirtualOption' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Event' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ConfigurableRFVirtual_H */

// }}}RME
