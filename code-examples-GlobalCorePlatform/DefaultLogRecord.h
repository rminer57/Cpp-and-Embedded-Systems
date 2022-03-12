// {{{RME classifier 'Logical View::Logging::DefaultLogRecord'

#ifndef DefaultLogRecord_H
#define DefaultLogRecord_H

#ifdef PRAGMA
#pragma interface "DefaultLogRecord.h"
#endif

#include <logbuf.h>
#include <LogRecord.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DefaultLogRecord : public LogRecord
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
	// {{{RME classAttribute 'm_timeStamp'
	TimeSpec m_timeStamp;
	// }}}RME
	// {{{RME classAttribute 'm_sequenceNumber'
	unsigned int m_sequenceNumber;
	// }}}RME
	// {{{RME classAttribute 'm_severity'
	unsigned int m_severity;
	// }}}RME
	// {{{RME classAttribute 'm_data'
	Array * m_data;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	DefaultLogRecord( void );
	// }}}RME
	// {{{RME operation 'DefaultLogRecord(const DefaultLogRecord&)'
	DefaultLogRecord( const DefaultLogRecord & rec );
	// }}}RME
	// {{{RME operation 'DefaultLogRecord(Array *,unsigned int,TimeSpec,unsigned int)'
	DefaultLogRecord( Array * information, unsigned int severity, TimeSpec timestamp, unsigned int sequenceNumber );
	// }}}RME
	// {{{RME operation 'operator =(const DefaultLogRecord&)'
	DefaultLogRecord & operator=( const DefaultLogRecord & rhs );
	// }}}RME
	// {{{RME operation 'getData()'
	const Array * getData( void ) const;
	// }}}RME
	// {{{RME operation 'getSequenceNumber()'
	unsigned int getSequenceNumber( void ) const;
	// }}}RME
	// {{{RME operation 'getSeverity()'
	unsigned int getSeverity( void ) const;
	// }}}RME
	// {{{RME operation 'getTimeStamp()'
	const TimeSpec getTimeStamp( void ) const;
	// }}}RME
	// {{{RME operation '~DefaultLogRecord()'
	~DefaultLogRecord( void );
	// }}}RME
	// {{{RME operation 'clone()'
	virtual LogRecord * clone( void ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DefaultLogRecord_H */

// }}}RME
