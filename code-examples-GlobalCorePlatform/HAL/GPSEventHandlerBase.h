// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::GPS_Interface::InstantGPS_MG4100::GPSEventHandlerBase'

#ifndef GPSEventHandlerBase_H
#define GPSEventHandlerBase_H

#ifdef PRAGMA
#pragma interface "GPSEventHandlerBase.h"
#endif

#include <HALtestLib_win32.h>
#include <InstantGPS_mg4100.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class GPSEventHandlerBase
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	GPSEventHandlerBase( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~GPSEventHandlerBase( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	GPSEventHandlerBase( const GPSEventHandlerBase & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	GPSEventHandlerBase & operator=( const GPSEventHandlerBase & rtg_arg );
	// }}}RME
	// {{{RME operation 'processEvent(unsigned int,void *,int)'
	virtual void processEvent( unsigned int eventcode, void * optionaldataptr, int optionalarg ) = 0;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* GPSEventHandlerBase_H */

// }}}RME
