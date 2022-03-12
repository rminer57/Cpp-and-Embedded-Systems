// {{{RME classifier 'Logical View::Private::peripheral_access'

#ifndef peripheral_access_H
#define peripheral_access_H

#ifdef PRAGMA
#pragma interface "peripheral_access.h"
#endif

#include <misc_comp.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#ifdef OMAP_HALI_C55
typedef volatile ioport unsigned int * peripheral_address;
typedef volatile ioport unsigned short * peripheral_address_short;
#else
typedef volatile unsigned int * peripheral_address;
typedef volatile unsigned short * peripheral_address_short;
#endif

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* peripheral_access_H */

// }}}RME
