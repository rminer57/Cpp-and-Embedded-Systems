// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::deployment_utilities::units'

#ifndef units_H
#define units_H

#ifdef PRAGMA
#pragma interface "units.h"
#endif

#include <HALtestLib_win32.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
// Frequency units
#define FREQUENCYSTEP 5
#define HZ  (1)
// currently frequency step is ignorred for testing purposes
//#define KHZ (1000*HZ/FREQUENCYSTEP)
#define KHZ (1000*HZ)
#define MHZ (1000*KHZ)

// dB
#define UDB 1           // micro dB
#define MDB (UDB*1000)  // milli dB
#define DB (MDB*1000)   // dB

// voltage
#define UV 1            // microvolts
#define MV (1000*UV)    // millivolts
#define VOLTS (1000*MV) // volts

// power
#define UW 1            // micro Watts
#define MW (UW*1000)    // milli Watts
#define WATTS (MW*1000) // Watts

// Current
#define UA       1              // micro Amps
#define MA      (UA*1000)  // milli Amps
#define AMPS (MA*1000)  // Amps


// Time
#define US       1              // micro Second
#define MS      (US*1000)  // milli Seconds
#define SECS  (MS*1000)  // Second



// }}}USR
// }}}RME

class units
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
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* units_H */

// }}}RME
