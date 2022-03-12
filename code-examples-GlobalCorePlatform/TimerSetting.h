// {{{RME classifier 'Logical View::OS Abstraction Layer::TimerSetting'

#ifndef TimerSetting_H
#define TimerSetting_H

#ifdef PRAGMA
#pragma interface "TimerSetting.h"
#endif

// {{{RME general 'documentation'
/* {{{USR
Contains settings for a timer.  This includes the first expiration time, whether this first time is absolute or not, and an interval time for reloading of the timer.  Absolute means that the clock time matches the first time.  Non-absolute means that the first time is an interval from now (expiration = currentClockTime + firstTime).
   }}}USR */
// }}}RME

#include <osal_build.h>
#include <TimeSpec.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class TimerSetting
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
	// {{{RME classAttribute 'm_intervalTime'
	TimeSpec m_intervalTime;
	// }}}RME
	// {{{RME classAttribute 'm_firstTime'
	TimeSpec m_firstTime;
	// }}}RME
	// {{{RME classAttribute 'm_firstTimeAbsolute'
	bool m_firstTimeAbsolute;
	// }}}RME

public:
	// {{{RME associationEnd 'ownee'
	TimeSpec * ownee;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~TimerSetting( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	TimerSetting( const TimerSetting & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	TimerSetting & operator=( const TimerSetting & rtg_arg );
	// }}}RME
	// {{{RME operation 'TimerSetting(TimeSpec,bool,TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	Constructs a TimerSetting object.
	   }}}USR */
	// }}}RME
	TimerSetting( TimeSpec firstTime = TimeSpec(), bool firstTimeAbsolute = false, TimeSpec intervalTime = TimeSpec() );
	// }}}RME
	// {{{RME operation 'setFirstTime(TimeSpec,bool)'
	// {{{RME general 'documentation'
	/* {{{USR
	Sets the time for the first expiration of the timer.  The Time object ownership is transferred to the TimerSetting object after this call.
	   }}}USR */
	// }}}RME
	void setFirstTime( TimeSpec time, bool absolute = false );
	// }}}RME
	// {{{RME operation 'setIntervalTime(TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	This method sets the interval time between timer expirations on a periodic timer.  0 means not periodic, which is the default if not set.  The Time object ownership is transferred to the TimerSetting object after this call.
	   }}}USR */
	// }}}RME
	void setIntervalTime( TimeSpec time );
	// }}}RME
	// {{{RME operation 'getFirstTime()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns a TimeSpec object that represents the first expiration time.
	   }}}USR */
	// }}}RME
	TimeSpec getFirstTime( void ) const;
	// }}}RME
	// {{{RME operation 'getIntervalTime()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns the TimeSpec object that represents the reload expiration time.  
	   }}}USR */
	// }}}RME
	TimeSpec getIntervalTime( void ) const;
	// }}}RME
	// {{{RME operation 'getFirstTimeAbsolute()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns if the first expiration time is absolute or not (relative to when the timer was set).
	   }}}USR */
	// }}}RME
	bool getFirstTimeAbsolute( void ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TimerSetting_H */

// }}}RME
