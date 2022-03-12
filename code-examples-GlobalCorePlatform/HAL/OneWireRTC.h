// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::OneWire_Interface::DeviceDrivers::OneWireRTC'

#ifndef OneWireRTC_H
#define OneWireRTC_H

#ifdef PRAGMA
#pragma interface "OneWireRTC.h"
#endif

#include <serial_comp.h>
#include <OneWireDevice.h>
#include <RTCVirtual.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// The following definitions were imported from the TI version of time.h

/*****************************************************************************/
/* limits.h   v2.25                                                         */
/* Copyright (c) 1996-2003 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _LIMITS
#define _LIMITS

#define MB_LEN_MAX               1    /* MAX # BYTES IN MULTI-BYTE    */
#define CHAR_BIT                 8    /* NUMBER OF BITS IN TYPE CHAR  */
#define SCHAR_MIN             -128    /* MIN VALUE FOR SIGNED CHAR    */
#define SCHAR_MAX              127    /* MAX VALUE FOR SIGNED CHAR    */
#define UCHAR_MAX              255    /* MAX VALUE FOR UNSIGNED CHAR  */

#ifdef __signed_chars__
#define CHAR_MIN         SCHAR_MIN    /* MIN VALUE FOR CHAR           */
#define CHAR_MAX         SCHAR_MAX    /* MAX VALUE FOR CHAR           */
#else
#define CHAR_MIN                 0
#define CHAR_MAX         UCHAR_MAX
#endif
 
#define SHRT_MIN            -32768    /* MIN VALUE FOR SHORT          */
#define SHRT_MAX             32767    /* MAX VALUE FOR SHORT          */
#define USHRT_MAX            65535    /* MAX VALUE FOR UNSIGNED SHORT */

#define INT_MIN         (-INT_MAX-1)  /* MIN VALUE FOR INT            */
#define INT_MAX         2147483647    /* MAX VALUE FOR INT            */
#define UINT_MAX        4294967295    /* MAX VALUE FOR UNSIGNED INT   */

#define LONG_MIN        (-LONG_MAX-1) /* MIN VALUE FOR LONG           */
#define LONG_MAX        2147483647    /* MAX VALUE FOR LONG           */
#define ULONG_MAX       4294967295    /* MAX VALUE FOR UNSIGNED LONG  */

#endif

/*****************************************************************************/
/* linkage.h   v2.25                                                        */
/* Copyright (c) 1998-2003 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _LINKAGE
#define _LINKAGE

/* No modifiers are needed to access code or data */

#define _CODE_ACCESS
#define _DATA_ACCESS

/*--------------------------------------------------------------------------*/
/* Define _IDECL ==> how inline functions are declared                      */
/*--------------------------------------------------------------------------*/
#ifdef _INLINE
#define _IDECL static __inline
#define _IDEFN static __inline
#define __INLINE static __inline
#else
#define _IDECL extern _CODE_ACCESS
#define _IDEFN _CODE_ACCESS
#define __INLINE __EXTERN
#endif

#endif /* ifndef _LINKAGE */

/*****************************************************************************/
/* time.h     v2.25                                                         */
/* Copyright (c) 1990-2003  Texas Instruments Incorporated                   */
/*****************************************************************************/

#ifndef _TIME
#define _TIME

// Linkage.h was imported as part of this file.
//#include <linkage.h>

#if defined(__TMS470__) || defined(_TMS320C2000)
#define CLOCKS_PER_SEC 1000
#else
#define CLOCKS_PER_SEC 200000000 /* 200 MHz */
#endif

#ifndef NULL
#define NULL      0
#endif

#if defined(_TMS320C6X) || defined(__TMS320C6X__)
typedef unsigned int clock_t;
typedef unsigned int time_t;
#else
typedef unsigned long clock_t;
typedef unsigned long time_t;
#endif /* c6x */

#ifndef _SIZE_T
#define _SIZE_T
#ifdef __TMS320C2000__
typedef unsigned long size_t;
#else
typedef unsigned size_t;
#endif /* C2000 */
#endif /* ! _SIZE_T */

struct tm 
{
    int tm_sec;      /* seconds after the minute   - [0,59]  */
    int tm_min;      /* minutes after the hour     - [0,59]  */
    int tm_hour;     /* hours after the midnight   - [0,23]  */
    int tm_mday;     /* day of the month           - [1,31]  */
    int tm_mon;      /* months since January       - [0,11]  */
    int tm_year;     /* years since 1900                     */
    int tm_wday;     /* days since Sunday          - [0,6]   */
    int tm_yday;     /* days since Jan 1st         - [0,365] */
    int tm_isdst;    /* Daylight Savings Time flag           */
};

/*************************************************************************/
/* TIME ZONE STRUCTURE DEFINITION                                        */
/*************************************************************************/
typedef struct 
{
    short daylight;
    long  timezone;
    char  tzname[4];
    char  dstname[4];
} TZ;

extern _DATA_ACCESS TZ _tz;

/****************************************************************************/
/* FUNCTION DECLARATIONS.  (NOTE : clock AND time ARE SYSTEM SPECIFIC)      */
/****************************************************************************/
_CODE_ACCESS clock_t    clock(void);             
_CODE_ACCESS time_t     time(time_t *_timer);   
 
_CODE_ACCESS time_t     mktime(struct tm *_tptr);
_CODE_ACCESS double     difftime(time_t _time1, time_t _time0);
      _IDECL char      *ctime(const time_t *_timer);
_CODE_ACCESS char      *asctime(const struct tm *_timeptr);
_CODE_ACCESS struct tm *gmtime(const time_t *_timer);
_CODE_ACCESS struct tm *localtime(const time_t *_timer);
_CODE_ACCESS size_t     strftime(char *_out, size_t _maxsize, 
				 const char *_format,
				 const struct tm *_timeptr);

#if defined(_INLINE) || defined(_CTIME_)

_IDEFN char *ctime(const time_t *timer)
{
   return(asctime(localtime(timer)));
}

#endif /* _INLINE || _CTIME_ */

#endif /* _TIME */

// }}}USR
// }}}RME

class OneWireRTC : public OneWireDevice, public RTCVirtual
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
	OneWireRTC( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~OneWireRTC( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* OneWireRTC_H */

// }}}RME
