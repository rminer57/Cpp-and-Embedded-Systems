// {{{RME classifier 'Logical View::Logging::DefaultLogger'

#ifndef DefaultLogger_H
#define DefaultLogger_H

#ifdef PRAGMA
#pragma interface "DefaultLogger.h"
#endif

#include <logbuf.h>
#include <Logger.h>
class Clock;
class DefaultLogRecord;
class LogDestination;
class Mutex;
class TimeSpec;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DefaultLogger : public Logger
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
	// {{{RME classAttribute 'm_severityThreshold'
	unsigned int m_severityThreshold;
	// }}}RME
	// {{{RME classAttribute 'm_destination'
	LogDestination * * m_destination;
	// }}}RME
	// {{{RME classAttribute 'm_numDestinations'
	unsigned int m_numDestinations;
	// }}}RME
	// {{{RME classAttribute 'm_maxDestinations'
	unsigned int m_maxDestinations;
	// }}}RME
	// {{{RME classAttribute 'm_clock'
	Clock * m_clock;
	// }}}RME
	// {{{RME classAttribute 'm_sequenceNumber'
	static unsigned int m_sequenceNumber;
	// }}}RME
	// {{{RME classAttribute 'm_enabled'
	bool m_enabled;
	// }}}RME
	// {{{RME classAttribute 'm_mutex'
	Mutex * m_mutex;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	DefaultLogger( const DefaultLogger & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	DefaultLogger & operator=( const DefaultLogger & rtg_arg );
	// }}}RME
	// {{{RME operation 'DefaultLogger(unsigned int)'
	DefaultLogger( unsigned int maxDestinations = 4 );
	// }}}RME
	// {{{RME operation '~DefaultLogger()'
	virtual ~DefaultLogger( void );
	// }}}RME
	// {{{RME operation 'log(LogRecord *,unsigned int)'
	virtual bool log( LogRecord * information, unsigned int severity = FATAL_SEVERITY );
	// }}}RME
	// {{{RME operation 'setSeverityThreshold(unsigned int)'
	void setSeverityThreshold( unsigned int threshold );
	// }}}RME
	// {{{RME operation 'getSeverityThreshold()'
	unsigned int getSeverityThreshold( void ) const;
	// }}}RME
	// {{{RME operation 'enable()'
	void enable( void );
	// }}}RME
	// {{{RME operation 'disable()'
	void disable( void );
	// }}}RME
	// {{{RME operation 'registerDestination(LogDestination *)'
	virtual bool registerDestination( LogDestination * destination );
	// }}}RME
	// {{{RME operation 'deregisterDestination(LogDestination *)'
	virtual void deregisterDestination( LogDestination * destination );
	// }}}RME
	// {{{RME operation 'getDefaultLogger()'
	static Logger * getDefaultLogger( void );
	// }}}RME
	// {{{RME operation 'willBeLogged(unsigned int)'
	bool willBeLogged( unsigned int severity = FATAL_SEVERITY ) const;
	// }}}RME

protected:
	// {{{RME operation 'generateTimeStamp()'
	TimeSpec generateTimeStamp( void );
	// }}}RME

public:
	// {{{RME operation 'log(Array *,unsigned int)'
	virtual bool log( Array * information, unsigned int severity = FATAL_SEVERITY );
	// }}}RME
};

// {{{RME classAttribute 'm_defaultLogger'
extern Logger * m_defaultLogger;
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DefaultLogger_H */

// }}}RME
