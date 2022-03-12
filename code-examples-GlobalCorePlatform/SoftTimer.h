// {{{RME classifier 'Logical View::Timers::SoftTimer'

#ifndef SoftTimer_H
#define SoftTimer_H

#ifdef PRAGMA
#pragma interface "SoftTimer.h"
#endif

#include <softtimers.h>
#include <TimerVirtual.h>
class SoftTimerFactory;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SoftTimer : public TimerVirtual
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class SoftTimerFactory;
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

protected:
	// {{{RME classAttribute 'm_rearm'
	bool m_rearm;
	// }}}RME
	// {{{RME classAttribute 'm_initialCount'
	unsigned int m_initialCount;
	// }}}RME
	// {{{RME classAttribute 'm_count'
	unsigned int m_count;
	// }}}RME
	// {{{RME associationEnd 'm_parent'
	SoftTimerFactory * m_parent;
	// }}}RME
	// {{{RME associationEnd 'm_event'
	TimerVirtual::Event * m_event;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	SoftTimer( const SoftTimer & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	SoftTimer & operator=( const SoftTimer & rtg_arg );
	// }}}RME
	// {{{RME operation 'SoftTimer(SoftTimerFactory*,bool,TimerVirtual::Event *)'
	SoftTimer( SoftTimerFactory * parent, bool rearm, TimerVirtual::Event * event );
	// }}}RME

private:
	// {{{RME operation 'trigger(unsigned int)'
	void trigger( unsigned int count );
	// }}}RME

public:
	// {{{RME operation 'set(unsigned int)'
	virtual void set( unsigned int count );
	// }}}RME
	// {{{RME operation 'get()'
	virtual unsigned int get( void ) const;
	// }}}RME
	// {{{RME operation '~SoftTimer()'
	virtual ~SoftTimer( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SoftTimer_H */

// }}}RME
