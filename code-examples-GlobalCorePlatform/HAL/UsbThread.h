// {{{RME classifier 'Logical View::UsbPrivate::UsbOsFacade::UsbThread'

#ifndef UsbThread_H
#define UsbThread_H

#ifdef PRAGMA
#pragma interface "UsbThread.h"
#endif

#include <usbimp.h>
#include <Thread.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR



// }}}USR
// }}}RME

class UsbThread : public Thread
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
	// {{{RME classAttribute 'pMainBody'
	int ( * pMainBody )(  void * );
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~UsbThread( void );
	// }}}RME
	// {{{RME operation 'UsbThread(int (*)(void *))'
	UsbThread( int ( * thread_ptr )(  void * ) );
	// }}}RME
	// {{{RME operation 'main()'
	void * main( void );
	// }}}RME
	// {{{RME operation 'createThread(int,int (*)(void *),uint16_t,char *)'
	static UsbThread * createThread( int priority, int ( * thread_entry )(  void * ), uint16_t stackSize, char * name );
	// }}}RME
	// {{{RME operation 'deleteUSBThread(Thread *)'
	void deleteUSBThread( Thread * Thread_ptr );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UsbThread_H */

// }}}RME
