// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::Connection'

#ifndef Connection_H
#define Connection_H

#ifdef PRAGMA
#pragma interface "Connection.h"
#endif

#include <conn.h>
#include <Configurable.h>
#include <EventBase.h>
#include <NotifierBase.h>
#include <TypedBaseClass.h>
class Array;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Status' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::Connection::Status::Event' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'ConnectionOption' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class Connection : public Configurable
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
	class Status : public TypedBaseClass, public NotifierBase
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
			// {{{RME classAttribute 'AVAILABLE'
			static const unsigned int AVAILABLE;
			// }}}RME
			// {{{RME classAttribute 'DATA_AVAILABLE'
			static const unsigned int DATA_AVAILABLE;
			// }}}RME
			// {{{RME classAttribute 'UNAVAILABLE'
			static const unsigned int UNAVAILABLE;
			// }}}RME
			// {{{RME classAttribute 'CONNECTION_EVENT'
			static const unsigned int CONNECTION_EVENT;
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
		// {{{RME classAttribute 'CONNECTION_STATUS'
		static const unsigned int CONNECTION_STATUS;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~Status( void );
		// }}}RME
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'isType(ClassType)'
		virtual bool isType( ClassType type ) const;
		// }}}RME
		// {{{RME operation 'isDataAvailable()'
		virtual bool isDataAvailable( void ) const;
		// }}}RME
		// {{{RME operation 'isAvailable()'
		virtual bool isAvailable( void ) const;
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'ConnectionOption'
	class ConnectionOption : public Configurable::Option
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
		// {{{RME classAttribute 'CONNECTION_OPTION'
		static const unsigned int CONNECTION_OPTION;
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
		ConnectionOption( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~ConnectionOption( void );
		// }}}RME
		// {{{RME operation 'getType()'
		virtual ClassType getType( void ) const;
		// }}}RME
		// {{{RME operation 'isType(ClassType)'
		virtual bool isType( ClassType type ) const;
		// }}}RME
	};
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Connection( void );
	// }}}RME
	// {{{RME operation 'send(Array *)'
	virtual bool send( Array * buffer ) = 0;
	// }}}RME
	// {{{RME operation 'receive()'
	virtual Array * receive( void ) = 0;
	// }}}RME
	// {{{RME operation 'getStatus()'
	virtual Status * getStatus( void ) = 0;
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
// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::Connection::Status::Event' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'ConnectionOption' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Connection_H */

// }}}RME
