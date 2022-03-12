// {{{RME classifier 'Logical View::OS Abstraction Layer::TimeSpec'

#ifndef TimeSpec_H
#define TimeSpec_H

#ifdef PRAGMA
#pragma interface "TimeSpec.h"
#endif

// {{{RME general 'documentation'
/* {{{USR
Represents a time with two numbers.  One number is in the seconds, and the other is the nanoseconds.  Combining these two unsigned integers gives a great deal of range and resolution.  This time can specify a period or a specific time from some known epoch.

NOTE: The use of unsigned integers for the two components has repercusions that should be understood by clients, albeit problems should be rare.  Subtraction should be used only after doing the appropriate comparisons because 0 will be returned if the result would be negative.  Addition of numbers that add up to larger than what can be represented in the unsigned integer shall return the maximum representable time.  If a time is needed that is longer than what can be represented with unsigned integers, long variables should be used with the appropriate division, and counting of timer expirations etc.
   }}}USR */
// }}}RME

#include <osal_build.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class TimeSpec
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
	// {{{RME classAttribute 'm_sec'
	uint32_t m_sec;
	// }}}RME
	// {{{RME classAttribute 'm_nsec'
	uint32_t m_nsec;
	// }}}RME
	// {{{RME classAttribute 'BILLION'
	static const uint32_t BILLION;
	// }}}RME
	// {{{RME classAttribute 'UINTMAX'
	static const uint32_t UINTMAX;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~TimeSpec( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	TimeSpec( const TimeSpec & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	TimeSpec & operator=( const TimeSpec & rtg_arg );
	// }}}RME
	// {{{RME operation 'TimeSpec(uint32_t,uint32_t)'
	// {{{RME general 'documentation'
	/* {{{USR
	Constructs a TimeSpec object.  If the nanoseconds are greater than or equal to 1,000,000,000, it will be reduced to less than 1,000,000,000, and the seconds will be updated appropriately.
	   }}}USR */
	// }}}RME
	TimeSpec( uint32_t seconds = 0, uint32_t nanoseconds = 0 );
	// }}}RME
	// {{{RME operation 'getSeconds()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns the number of seconds represented by this Time object.  The nanoseconds are not included.
	   }}}USR */
	// }}}RME
	uint32_t getSeconds( void ) const;
	// }}}RME
	// {{{RME operation 'getNanoseconds()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns the number of nanoseconds represented by this Time.  The total Time is the seconds plus this nanoseconds.
	   }}}USR */
	// }}}RME
	uint32_t getNanoseconds( void ) const;
	// }}}RME
	// {{{RME operation 'setSeconds(uint32_t)'
	// {{{RME general 'documentation'
	/* {{{USR
	Sets the number of seconds represented by this Time.
	   }}}USR */
	// }}}RME
	void setSeconds( uint32_t seconds );
	// }}}RME
	// {{{RME operation 'setNanoseconds(uint32_t)'
	// {{{RME general 'documentation'
	/* {{{USR
	Sets the number of seconds represented by this Time.
	   }}}USR */
	// }}}RME
	void setNanoseconds( uint32_t nanoseconds );
	// }}}RME
	// {{{RME operation 'operator ==(const TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns true if the TimeSpec objects represent the same time.
	   }}}USR */
	// }}}RME
	bool operator ==( const TimeSpec otherTime );
	// }}}RME
	// {{{RME operation 'operator >(const TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns true if this TimeSpec object represent a time greater than the passed in TimeSpec object.
	   }}}USR */
	// }}}RME
	bool operator >( const TimeSpec otherTime );
	// }}}RME
	// {{{RME operation 'operator <(const TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns true if this TimeSpec object represent a time less than the passed in TimeSpec object.
	   }}}USR */
	// }}}RME
	bool operator <( const TimeSpec otherTime );
	// }}}RME
	// {{{RME operation 'operator +(const TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns a TimeSpec object that represents the sum of the time of this TimeSpec object and the passed in TimeSpec object.  If the sum is larger than the resolution available with an unsigned integer, the largest possible representable time will be returned.
	   }}}USR */
	// }}}RME
	TimeSpec operator +( const TimeSpec otherTime );
	// }}}RME
	// {{{RME operation 'operator -(const TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns a TimeSpec object that represents the difference between the time of this TimeSpec object and the passed in TimeSpec object.  Since all number are unsigned, 0 is returned if this TimeSpec is less than the passed in TimeSpec.
	   }}}USR */
	// }}}RME
	TimeSpec operator -( const TimeSpec otherTime );
	// }}}RME
	// {{{RME operation 'operator >=(const TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns true if this TimeSpec object represent a time greater than or equal to the passed in TimeSpec object.
	   }}}USR */
	// }}}RME
	bool operator >=( const TimeSpec otherTime );
	// }}}RME
	// {{{RME operation 'operator <=(const TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns true if this TimeSpec object represent a time less than or equal to the passed in TimeSpec object.
	   }}}USR */
	// }}}RME
	bool operator <=( const TimeSpec otherTime );
	// }}}RME
	// {{{RME operation 'operator +=(const TimeSpec)'
	// {{{RME general 'documentation'
	/* {{{USR
	Increments a TimeSpec object by the value of the other TimeSpec object.  If the sum is larger than the resolution available with an unsigned integer, the largest possible representable time will be returned.
	   }}}USR */
	// }}}RME
	TimeSpec operator +=( const TimeSpec otherTime );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TimeSpec_H */

// }}}RME
