// {{{RME classifier 'Logical View::OS Abstraction Layer::OSALi_win32::OSALiClock'

#ifndef OSALiClock_H
#define OSALiClock_H

#ifdef PRAGMA
#pragma interface "OSALiClock.h"
#endif

// {{{RME general 'documentation'
/* {{{USR

   }}}USR */
// }}}RME

#include <osal_build.h>
#include <Clock.h>
class TimeSpec;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <time.h>
// }}}USR
// }}}RME

class OSALiClock : public Clock
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
	// {{{RME classAttribute 'm_realtimeClock'
	static OSALiClock * m_realtimeClock;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	OSALiClock( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	OSALiClock( const OSALiClock & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	OSALiClock & operator=( const OSALiClock & rtg_arg );
	// }}}RME
	// {{{RME operation 'getClock(TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	This method returns a Clock instance that has at least the minimumResolution, or a default clock if no resolution or a (0,0) resolution is specified.  If a clock meeting the minimumResolution is not available, 0 is returned.  The object returned is owned by the system and the caller should NOT delete it.
	   }}}USR */
	// }}}RME
	static Clock * getClock( TimeSpec minimumResolution = TimeSpec() );
	// }}}RME
	// {{{RME operation '~OSALiClock()'
	// {{{RME general 'documentation'
	/* {{{USR

	   }}}USR */
	// }}}RME
	~OSALiClock( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* OSALiClock_H */

// }}}RME
