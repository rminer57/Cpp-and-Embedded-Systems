// {{{RME classifier 'Logical View::OS Abstraction Layer::TimerExpirationMsg'

#ifndef TimerExpirationMsg_H
#define TimerExpirationMsg_H

#ifdef PRAGMA
#pragma interface "TimerExpirationMsg.h"
#endif

// {{{RME general 'documentation'
/* {{{USR
This message is received when a timer expires.  When this message is received, the action() method should typically be invoked.  This method will execute the TimerAction that is associated with the Timer.  To determine if this expiration message is still current, isCurrent() can be used.

WARNING: Handling of this message is not thread-safe with deletion of the associated timer.  Therefore, this message should not be sent to another thread that is not responsible for Timer deletion.
   }}}USR */
// }}}RME

#include <osal_build.h>
#include <Message.h>
class Mutex;
class Timer;
class TimerAction;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class TimerExpirationMsg : public Message
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend class Timer;
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
	// {{{RME classAttribute 'm_timer'
	Timer * m_timer;
	// }}}RME
	// {{{RME classAttribute 'm_sequenceNum'
	unsigned int m_sequenceNum;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	TimerExpirationMsg( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	TimerExpirationMsg( const TimerExpirationMsg & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	TimerExpirationMsg & operator=( const TimerExpirationMsg & rtg_arg );
	// }}}RME
	// {{{RME operation 'getType()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns the current type identifier.
	   }}}USR */
	// }}}RME
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	// {{{RME general 'documentation'
	/* {{{USR
	returns "true" if the current type is an instance of the specified object type or any sub-class of the specified object type, otherwise returns "false"
	   }}}USR */
	// }}}RME
	virtual bool isType( ClassType type ) const;
	// }}}RME

protected:
	// {{{RME operation 'getSequenceNum()'
	// {{{RME general 'documentation'
	/* {{{USR
	Gets the sequence number in this TimerExpirationMsg.
	   }}}USR */
	// }}}RME
	unsigned int getSequenceNum( void ) const;
	// }}}RME
	// {{{RME operation 'TimerExpirationMsg(unsigned int,Timer *)'
	// {{{RME general 'documentation'
	/* {{{USR

	   }}}USR */
	// }}}RME
	TimerExpirationMsg( unsigned int seqNum, Timer * timer );
	// }}}RME
	// {{{RME operation 'getTimer()'
	// {{{RME general 'documentation'
	/* {{{USR
	Gets the timer associated with this TimerExpirationMsg, or 0 if unavailable.
	   }}}USR */
	// }}}RME
	Timer * getTimer( void ) const;
	// }}}RME

public:
	// {{{RME operation 'serialize()'
	// {{{RME general 'documentation'
	/* {{{USR
	This method returns a serialized version of the object.  This can be used to send this object, or store it, to where it can be unserialized.  0 should be returned if this is not supported.

	   }}}USR */
	// }}}RME
	Array * serialize( void );
	// }}}RME
	// {{{RME operation 'unserialize(Array *)'
	// {{{RME general 'documentation'
	/* {{{USR
	This abstract method unserializes an object from a DataBuffer that contains a serialized object.  It does the unserialization required for the given class implementing this method.  The memory space of the buffer sent in is not reused and ownership is retained by the caller.  The return value is true if unserialization works, and false if the buffer does not contain a proper serialized version of the object.
	   }}}USR */
	// }}}RME
	bool unserialize( Array * buf );
	// }}}RME
	// {{{RME operation 'getMaxSize()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns the maximum size, in bytes, of the serialized version of this object.
	   }}}USR */
	// }}}RME
	unsigned int getMaxSize( void );
	// }}}RME
	// {{{RME operation 'isCurrent()'
	// {{{RME general 'documentation'
	/* {{{USR
	Returns true if this expiration message is current, which means another timer expiration has not happened on the associated timer, due to either a periodic timer firing again, or a firing before a timer setting change.
	   }}}USR */
	// }}}RME
	bool isCurrent( void );
	// }}}RME
	// {{{RME operation 'action()'
	// {{{RME general 'documentation'
	/* {{{USR
	This method represents what is to be done when the timer expires.  The return value is true if it worked and false if it did not.
	   }}}USR */
	// }}}RME
	bool action( void );
	// }}}RME
	// {{{RME operation 'getAction()'
	// {{{RME general 'documentation'
	/* {{{USR
	Gets the timer action.  Returns 0 if unavailable.
	   }}}USR */
	// }}}RME
	TimerAction * getAction( void );
	// }}}RME
	// {{{RME operation '~TimerExpirationMsg()'
	// {{{RME general 'documentation'
	/* {{{USR

	   }}}USR */
	// }}}RME
	~TimerExpirationMsg( void );
	// }}}RME

protected:
	// {{{RME operation 'clearTimer()'
	// {{{RME general 'documentation'
	/* {{{USR
	Clears the Timer reference.  This is used when the Timer is being deleted.
	   }}}USR */
	// }}}RME
	void clearTimer( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TimerExpirationMsg_H */

// }}}RME
