// {{{RME classifier 'Logical View::Private::Private Serial Devices::SerialCommon::mcBsp::McBsp'

#ifndef McBsp_H
#define McBsp_H

#ifdef PRAGMA
#pragma interface "McBsp.h"
#endif

#include <serial_comp.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// Define register offset
#ifdef OMAP_HALI_C55
	#define RO       0x01
#else
	#define RO       0x02
#endif

// Register size is 16 bits

#define DRR2     RO * 0
#define DRR1     RO * 1
#define DXR2     RO * 2
#define DXR1     RO * 3
#define SPCR2    RO * 4
#define SPCR1    RO * 5
#define RCR2     RO * 6
#define RCR1     RO * 7
#define XCR2     RO * 8
#define XCR1     RO * 9
#define SRGR2    RO * 10
#define SRGR1    RO * 11
#define MCR2     RO * 12
#define MCR1     RO * 13
#define RCERA    RO * 14
#define RCERB    RO * 15
#define XCERA    RO * 16
#define XCERB    RO * 17
#define PCR      RO * 18
#define RCERC    RO * 19
#define RCERD    RO * 20
#define XCERC    RO * 21
#define XCERD    RO * 22
#define RCERE    RO * 23
#define RCERF    RO * 24
#define XCERE    RO * 25
#define XCERF    RO * 26
#define RCERG    RO * 27
#define RCERH    RO * 28
#define XCERG    RO * 29 
#define XCERH    RO * 30


//---------------------
// BitField Definitions
//---------------------

// Reserved bitfields are not defined.


// SPCR1 - Serial Port Control Register 1
defineBitField(DLB, unsigned short, SPCR1, 15, 1);
defineBitField(RJUST, unsigned short, SPCR1, 13, 2);
defineBitField(CLKSTP, unsigned short, SPCR1, 11, 2);
defineBitField(DXENA, unsigned short, SPCR1, 7, 1);
defineBitField(RINTM, unsigned short, SPCR1, 4, 2);
defineBitField(RSYNCERR, unsigned short, SPCR1, 3, 1);
defineBitField(RFULL, unsigned short, SPCR1, 2, 1);
defineBitField(RRDY, unsigned short, SPCR1, 1, 1);
defineBitField(RRST, unsigned short, SPCR1, 0, 1);


// SPCR2 - Serial Port Control Register 2
defineBitField(FREE, unsigned short, SPCR2, 9, 1);
defineBitField(SOFT, unsigned short, SPCR2, 8, 1);
defineBitField(FRST, unsigned short, SPCR2, 7, 1);
defineBitField(GRST, unsigned short, SPCR2, 6, 1);
defineBitField(XINTM, unsigned short, SPCR2, 4, 2);
defineBitField(XSYNCERR, unsigned short, SPCR2, 3, 1);
defineBitField(XEMPTY, unsigned short, SPCR2, 2, 1);
defineBitField(XRDY, unsigned short, SPCR2, 1, 1);
defineBitField(XRST, unsigned short, SPCR2, 0, 1);

//RCR1 - Reveice Control Register 1
defineBitField(RFRLEN1, unsigned short, RCR1, 8, 7);
defineBitField(RWDLEN1, unsigned short, RCR1, 5, 2);

//RCR2 - Receive Control Register 2
defineBitField(RPHASE, unsigned short, RCR2, 15, 1);
defineBitField(RFRLEN2, unsigned short, RCR2, 8, 7);
defineBitField(RWDLEN2, unsigned short, RCR2, 5, 2);
defineBitField(RCOMPAND, unsigned short, RCR2, 3, 2);
defineBitField(RFIG, unsigned short, RCR2, 2, 1);
defineBitField(RDATDLY, unsigned short, RCR2, 0, 2);

//XCR1 - Transmit Control Register 1
defineBitField(XFRLEN1, unsigned short, XCR1, 8, 7);
defineBitField(XWDLEN1, unsigned short, XCR1, 5, 2);

//XCR2 - Transmit Control Register 2
defineBitField(XPHASE, unsigned short, XCR2, 15, 1);
defineBitField(XFRLEN2, unsigned short, XCR2, 8, 7);
defineBitField(XWDLEN2, unsigned short, XCR2, 5, 2);
defineBitField(XCOMPAND, unsigned short, XCR2, 3, 2);
defineBitField(XFIG, unsigned short, XCR2, 2, 1);
defineBitField(XDATDLY, unsigned short, XCR2, 0, 2);

//SRGR1 - Sample Rate Generator 1 Register
defineBitField(FWID, unsigned short, SRGR1, 8, 8);
defineBitField(CLKGDV, unsigned short, SRGR1, 0, 8);

//SRGR2 - Sample Rate Generator 2 Register
defineBitField(GSYNC, unsigned short, SRGR2, 15, 1);
defineBitField(CLKSP, unsigned short, SRGR2, 14, 1);
defineBitField(CLKSM, unsigned short, SRGR2, 13, 1);
defineBitField(FSGM, unsigned short, SRGR2, 12, 1);
defineBitField(FPER, unsigned short, SRGR2, 0, 12);

// MCR1 - Multichannel Control Register 1
defineBitField(RMCME, unsigned short, MCR1, 9, 1);
defineBitField(RPBBLK, unsigned short, MCR1, 7, 2);
defineBitField(RPABLK, unsigned short, MCR1, 5, 2);
defineBitField(RCBLK, unsigned short, MCR1, 2, 3);
defineBitField(RMCM, unsigned short, MCR1, 0, 1);

// MCR2 - Multichannel Control Register 1
defineBitField(XMCME, unsigned short, MCR2, 9, 1);
defineBitField(XPBBLK, unsigned short, MCR2, 7, 2);
defineBitField(XPABLK, unsigned short, MCR2, 5, 2);
defineBitField(XCBLK, unsigned short, MCR2, 2, 3);
defineBitField(XMCM, unsigned short, MCR2, 0, 2);

//PCR - Pin Control Register
defineBitField(IDLEEN, unsigned short, PCR, 14, 1);
defineBitField(XIOEN, unsigned short, PCR, 13, 1);
defineBitField(RIOEN, unsigned short, PCR, 12, 1);
defineBitField(FSXM, unsigned short, PCR, 11, 1);
defineBitField(FSRM, unsigned short, PCR, 10, 1);
defineBitField(CLKXM, unsigned short, PCR, 9, 1);
defineBitField(CLKRM, unsigned short, PCR, 8, 1);
defineBitField(SCLKME, unsigned short, PCR, 7, 1);
defineBitField(CLKSSTAT, unsigned short, PCR, 6, 1);
defineBitField(DXSTAT, unsigned short, PCR, 5, 1);
defineBitField(DRSTAT, unsigned short, PCR, 4, 1);
defineBitField(FSXP, unsigned short, PCR, 3, 1);
defineBitField(FSRP, unsigned short, PCR, 2, 1);
defineBitField(CLKXP, unsigned short, PCR, 1, 1);
defineBitField(CLKRP, unsigned short, PCR, 0, 1);


// RCERA - Transmit Channel Enable Register A
defineBitField(RCEA15, unsigned short, RCERA, 15, 1);
defineBitField(RCEA14, unsigned short, RCERA, 14, 1);
defineBitField(RCEA13, unsigned short, RCERA, 13, 1);
defineBitField(RCEA12, unsigned short, RCERA, 12, 1);
defineBitField(RCEA11, unsigned short, RCERA, 11, 1);
defineBitField(RCEA10, unsigned short, RCERA, 10, 1);
defineBitField(RCEA9, unsigned short, RCERA, 9, 1);
defineBitField(RCEA8, unsigned short, RCERA, 8, 1);
defineBitField(RCEA7, unsigned short, RCERA, 7, 1);
defineBitField(RCEA6, unsigned short, RCERA, 6, 1);
defineBitField(RCEA5, unsigned short, RCERA, 5, 1);
defineBitField(RCEA4, unsigned short, RCERA, 4, 1);
defineBitField(RCEA3, unsigned short, RCERA, 3, 1);
defineBitField(RCEA2, unsigned short, RCERA, 2, 1);
defineBitField(RCEA1, unsigned short, RCERA, 1, 1);
defineBitField(RCEA0, unsigned short, RCERA, 0, 1);

// RCERB - Transmit Channel Enable Register B
defineBitField(RCEB15, unsigned short, RCERB, 15, 1);
defineBitField(RCEB14, unsigned short, RCERB, 14, 1);
defineBitField(RCEB13, unsigned short, RCERB, 13, 1);
defineBitField(RCEB12, unsigned short, RCERB, 12, 1);
defineBitField(RCEB11, unsigned short, RCERB, 11, 1);
defineBitField(RCEB10, unsigned short, RCERB, 10, 1);
defineBitField(RCEB9, unsigned short, RCERB, 9, 1);
defineBitField(RCEB8, unsigned short, RCERB, 8, 1);
defineBitField(RCEB7, unsigned short, RCERB, 7, 1);
defineBitField(RCEB6, unsigned short, RCERB, 6, 1);
defineBitField(RCEB5, unsigned short, RCERB, 5, 1);
defineBitField(RCEB4, unsigned short, RCERB, 4, 1);
defineBitField(RCEB3, unsigned short, RCERB, 3, 1);
defineBitField(RCEB2, unsigned short, RCERB, 2, 1);
defineBitField(RCEB1, unsigned short, RCERB, 1, 1);
defineBitField(RCEB0, unsigned short, RCERB, 0, 1);

// RCERC - Receive Channel Enable Register 
defineBitField(RCEC15, unsigned short, RCERC, 15, 1);
defineBitField(RCEC14, unsigned short, RCERC, 14, 1);
defineBitField(RCEC13, unsigned short, RCERC, 13, 1);
defineBitField(RCEC12, unsigned short, RCERC, 12, 1);
defineBitField(RCEC11, unsigned short, RCERC, 11, 1);
defineBitField(RCEC10, unsigned short, RCERC, 10, 1);
defineBitField(RCEC9, unsigned short, RCERC, 9, 1);
defineBitField(RCEC8, unsigned short, RCERC, 8, 1);
defineBitField(RCEC7, unsigned short, RCERC, 7, 1);
defineBitField(RCEC6, unsigned short, RCERC, 6, 1);
defineBitField(RCEC5, unsigned short, RCERC, 5, 1);
defineBitField(RCEC4, unsigned short, RCERC, 4, 1);
defineBitField(RCEC3, unsigned short, RCERC, 3, 1);
defineBitField(RCEC2, unsigned short, RCERC, 2, 1);
defineBitField(RCEC1, unsigned short, RCERC, 1, 1);
defineBitField(RCEC0, unsigned short, RCERC, 0, 1);

// RCEDRD - Receive Channel Enable Register D
defineBitField(RCED15, unsigned short, RCERD, 15, 1);
defineBitField(RCED14, unsigned short, RCERD, 14, 1);
defineBitField(RCED13, unsigned short, RCERD, 13, 1);
defineBitField(RCED12, unsigned short, RCERD, 12, 1);
defineBitField(RCED11, unsigned short, RCERD, 11, 1);
defineBitField(RCED10, unsigned short, RCERD, 10, 1);
defineBitField(RCED9, unsigned short, RCERD, 9, 1);
defineBitField(RCED8, unsigned short, RCERD, 8, 1);
defineBitField(RCED7, unsigned short, RCERD, 7, 1);
defineBitField(RCED6, unsigned short, RCERD, 6, 1);
defineBitField(RCED5, unsigned short, RCERD, 5, 1);
defineBitField(RCED4, unsigned short, RCERD, 4, 1);
defineBitField(RCED3, unsigned short, RCERD, 3, 1);
defineBitField(RCED2, unsigned short, RCERD, 2, 1);
defineBitField(RCED1, unsigned short, RCERD, 1, 1);
defineBitField(RCED0, unsigned short, RCERD, 0, 1);

// RCERE - Receive Channel Enable Register E
defineBitField(RCEE15, unsigned short, RCERE, 15, 1);
defineBitField(RCEE14, unsigned short, RCERE, 14, 1);
defineBitField(RCEE13, unsigned short, RCERE, 13, 1);
defineBitField(RCEE12, unsigned short, RCERE, 12, 1);
defineBitField(RCEE11, unsigned short, RCERE, 11, 1);
defineBitField(RCEE10, unsigned short, RCERE, 10, 1);
defineBitField(RCEE9, unsigned short, RCERE, 9, 1);
defineBitField(RCEE8, unsigned short, RCERE, 8, 1);
defineBitField(RCEE7, unsigned short, RCERE, 7, 1);
defineBitField(RCEE6, unsigned short, RCERE, 6, 1);
defineBitField(RCEE5, unsigned short, RCERE, 5, 1);
defineBitField(RCEE4, unsigned short, RCERE, 4, 1);
defineBitField(RCEE3, unsigned short, RCERE, 3, 1);
defineBitField(RCEE2, unsigned short, RCERE, 2, 1);
defineBitField(RCEE1, unsigned short, RCERE, 1, 1);
defineBitField(RCEE0, unsigned short, RCERE, 0, 1);

// RCERF - Receive Channel Enable Register F
defineBitField(RCEF15, unsigned short, RCERF, 15, 1);
defineBitField(RCEF14, unsigned short, RCERF, 14, 1);
defineBitField(RCEF13, unsigned short, RCERF, 13, 1);
defineBitField(RCEF12, unsigned short, RCERF, 12, 1);
defineBitField(RCEF11, unsigned short, RCERF, 11, 1);
defineBitField(RCEF10, unsigned short, RCERF, 10, 1);
defineBitField(RCEF9, unsigned short, RCERF, 9, 1);
defineBitField(RCEF8, unsigned short, RCERF, 8, 1);
defineBitField(RCEF7, unsigned short, RCERF, 7, 1);
defineBitField(RCEF6, unsigned short, RCERF, 6, 1);
defineBitField(RCEF5, unsigned short, RCERF, 5, 1);
defineBitField(RCEF4, unsigned short, RCERF, 4, 1);
defineBitField(RCEF3, unsigned short, RCERF, 3, 1);
defineBitField(RCEF2, unsigned short, RCERF, 2, 1);
defineBitField(RCEF1, unsigned short, RCERF, 1, 1);
defineBitField(RCEF0, unsigned short, RCERF, 0, 1);

// RCERG - Receive Channel Enable Register G
defineBitField(RCEG15, unsigned short, RCERG, 15, 1);
defineBitField(RCEG14, unsigned short, RCERG, 14, 1);
defineBitField(RCEG13, unsigned short, RCERG, 13, 1);
defineBitField(RCEG12, unsigned short, RCERG, 12, 1);
defineBitField(RCEG11, unsigned short, RCERG, 11, 1);
defineBitField(RCEG10, unsigned short, RCERG, 10, 1);
defineBitField(RCEG9, unsigned short, RCERG, 9, 1);
defineBitField(RCEG8, unsigned short, RCERG, 8, 1);
defineBitField(RCEG7, unsigned short, RCERG, 7, 1);
defineBitField(RCEG6, unsigned short, RCERG, 6, 1);
defineBitField(RCEG5, unsigned short, RCERG, 5, 1);
defineBitField(RCEG4, unsigned short, RCERG, 4, 1);
defineBitField(RCEG3, unsigned short, RCERG, 3, 1);
defineBitField(RCEG2, unsigned short, RCERG, 2, 1);
defineBitField(RCEG1, unsigned short, RCERG, 1, 1);
defineBitField(RCEG0, unsigned short, RCERG, 0, 1);

// RCEHRH - Receive Channel Enable Register H
defineBitField(RCEH15, unsigned short, RCERH, 15, 1);
defineBitField(RCEH14, unsigned short, RCERH, 14, 1);
defineBitField(RCEH13, unsigned short, RCERH, 13, 1);
defineBitField(RCEH12, unsigned short, RCERH, 12, 1);
defineBitField(RCEH11, unsigned short, RCERH, 11, 1);
defineBitField(RCEH10, unsigned short, RCERH, 10, 1);
defineBitField(RCEH9, unsigned short, RCERH, 9, 1);
defineBitField(RCEH8, unsigned short, RCERH, 8, 1);
defineBitField(RCEH7, unsigned short, RCERH, 7, 1);
defineBitField(RCEH6, unsigned short, RCERH, 6, 1);
defineBitField(RCEH5, unsigned short, RCERH, 5, 1);
defineBitField(RCEH4, unsigned short, RCERH, 4, 1);
defineBitField(RCEH3, unsigned short, RCERH, 3, 1);
defineBitField(RCEH2, unsigned short, RCERH, 2, 1);
defineBitField(RCEH1, unsigned short, RCERH, 1, 1);
defineBitField(RCEH0, unsigned short, RCERH, 0, 1);


// XCERA - Transmit Channel Enable Register A
defineBitField(XCEA15, unsigned short, XCERA, 15, 1);
defineBitField(XCEA14, unsigned short, XCERA, 14, 1);
defineBitField(XCEA13, unsigned short, XCERA, 13, 1);
defineBitField(XCEA12, unsigned short, XCERA, 12, 1);
defineBitField(XCEA11, unsigned short, XCERA, 11, 1);
defineBitField(XCEA10, unsigned short, XCERA, 10, 1);
defineBitField(XCEA9, unsigned short, XCERA, 9, 1);
defineBitField(XCEA8, unsigned short, XCERA, 8, 1);
defineBitField(XCEA7, unsigned short, XCERA, 7, 1);
defineBitField(XCEA6, unsigned short, XCERA, 6, 1);
defineBitField(XCEA5, unsigned short, XCERA, 5, 1);
defineBitField(XCEA4, unsigned short, XCERA, 4, 1);
defineBitField(XCEA3, unsigned short, XCERA, 3, 1);
defineBitField(XCEA2, unsigned short, XCERA, 2, 1);
defineBitField(XCEA1, unsigned short, XCERA, 1, 1);
defineBitField(XCEA0, unsigned short, XCERA, 0, 1);

// XCERB - Transmit Channel Enable Register B
defineBitField(XCEB15, unsigned short, XCERB, 15, 1);
defineBitField(XCEB14, unsigned short, XCERB, 14, 1);
defineBitField(XCEB13, unsigned short, XCERB, 13, 1);
defineBitField(XCEB12, unsigned short, XCERB, 12, 1);
defineBitField(XCEB11, unsigned short, XCERB, 11, 1);
defineBitField(XCEB10, unsigned short, XCERB, 10, 1);
defineBitField(XCEB9, unsigned short, XCERB, 9, 1);
defineBitField(XCEB8, unsigned short, XCERB, 8, 1);
defineBitField(XCEB7, unsigned short, XCERB, 7, 1);
defineBitField(XCEB6, unsigned short, XCERB, 6, 1);
defineBitField(XCEB5, unsigned short, XCERB, 5, 1);
defineBitField(XCEB4, unsigned short, XCERB, 4, 1);
defineBitField(XCEB3, unsigned short, XCERB, 3, 1);
defineBitField(XCEB2, unsigned short, XCERB, 2, 1);
defineBitField(XCEB1, unsigned short, XCERB, 1, 1);
defineBitField(XCEB0, unsigned short, XCERB, 0, 1);

// XCERC - Transmit Channel Enable Register 
defineBitField(XCEC15, unsigned short, XCERC, 15, 1);
defineBitField(XCEC14, unsigned short, XCERC, 14, 1);
defineBitField(XCEC13, unsigned short, XCERC, 13, 1);
defineBitField(XCEC12, unsigned short, XCERC, 12, 1);
defineBitField(XCEC11, unsigned short, XCERC, 11, 1);
defineBitField(XCEC10, unsigned short, XCERC, 10, 1);
defineBitField(XCEC9, unsigned short, XCERC, 9, 1);
defineBitField(XCEC8, unsigned short, XCERC, 8, 1);
defineBitField(XCEC7, unsigned short, XCERC, 7, 1);
defineBitField(XCEC6, unsigned short, XCERC, 6, 1);
defineBitField(XCEC5, unsigned short, XCERC, 5, 1);
defineBitField(XCEC4, unsigned short, XCERC, 4, 1);
defineBitField(XCEC3, unsigned short, XCERC, 3, 1);
defineBitField(XCEC2, unsigned short, XCERC, 2, 1);
defineBitField(XCEC1, unsigned short, XCERC, 1, 1);
defineBitField(XCEC0, unsigned short, XCERC, 0, 1);

// XCERD - Transmit Channel Enable Register D
defineBitField(XCED15, unsigned short, XCERD, 15, 1);
defineBitField(XCED14, unsigned short, XCERD, 14, 1);
defineBitField(XCED13, unsigned short, XCERD, 13, 1);
defineBitField(XCED12, unsigned short, XCERD, 12, 1);
defineBitField(XCED11, unsigned short, XCERD, 11, 1);
defineBitField(XCED10, unsigned short, XCERD, 10, 1);
defineBitField(XCED9, unsigned short, XCERD, 9, 1);
defineBitField(XCED8, unsigned short, XCERD, 8, 1);
defineBitField(XCED7, unsigned short, XCERD, 7, 1);
defineBitField(XCED6, unsigned short, XCERD, 6, 1);
defineBitField(XCED5, unsigned short, XCERD, 5, 1);
defineBitField(XCED4, unsigned short, XCERD, 4, 1);
defineBitField(XCED3, unsigned short, XCERD, 3, 1);
defineBitField(XCED2, unsigned short, XCERD, 2, 1);
defineBitField(XCED1, unsigned short, XCERD, 1, 1);
defineBitField(XCED0, unsigned short, XCERD, 0, 1);

// XCERE - Transmit Channel Enable Register E
defineBitField(XCEE15, unsigned short, XCERE, 15, 1);
defineBitField(XCEE14, unsigned short, XCERE, 14, 1);
defineBitField(XCEE13, unsigned short, XCERE, 13, 1);
defineBitField(XCEE12, unsigned short, XCERE, 12, 1);
defineBitField(XCEE11, unsigned short, XCERE, 11, 1);
defineBitField(XCEE10, unsigned short, XCERE, 10, 1);
defineBitField(XCEE9, unsigned short, XCERE, 9, 1);
defineBitField(XCEE8, unsigned short, XCERE, 8, 1);
defineBitField(XCEE7, unsigned short, XCERE, 7, 1);
defineBitField(XCEE6, unsigned short, XCERE, 6, 1);
defineBitField(XCEE5, unsigned short, XCERE, 5, 1);
defineBitField(XCEE4, unsigned short, XCERE, 4, 1);
defineBitField(XCEE3, unsigned short, XCERE, 3, 1);
defineBitField(XCEE2, unsigned short, XCERE, 2, 1);
defineBitField(XCEE1, unsigned short, XCERE, 1, 1);
defineBitField(XCEE0, unsigned short, XCERE, 0, 1);

// XCERF - Transmit Channel Enable Register F
defineBitField(XCEF15, unsigned short, XCERF, 15, 1);
defineBitField(XCEF14, unsigned short, XCERF, 14, 1);
defineBitField(XCEF13, unsigned short, XCERF, 13, 1);
defineBitField(XCEF12, unsigned short, XCERF, 12, 1);
defineBitField(XCEF11, unsigned short, XCERF, 11, 1);
defineBitField(XCEF10, unsigned short, XCERF, 10, 1);
defineBitField(XCEF9, unsigned short, XCERF, 9, 1);
defineBitField(XCEF8, unsigned short, XCERF, 8, 1);
defineBitField(XCEF7, unsigned short, XCERF, 7, 1);
defineBitField(XCEF6, unsigned short, XCERF, 6, 1);
defineBitField(XCEF5, unsigned short, XCERF, 5, 1);
defineBitField(XCEF4, unsigned short, XCERF, 4, 1);
defineBitField(XCEF3, unsigned short, XCERF, 3, 1);
defineBitField(XCEF2, unsigned short, XCERF, 2, 1);
defineBitField(XCEF1, unsigned short, XCERF, 1, 1);
defineBitField(XCEF0, unsigned short, XCERF, 0, 1);

// XCERG - Transmit Channel Enable Register G
defineBitField(XCEG15, unsigned short, XCERG, 15, 1);
defineBitField(XCEG14, unsigned short, XCERG, 14, 1);
defineBitField(XCEG13, unsigned short, XCERG, 13, 1);
defineBitField(XCEG12, unsigned short, XCERG, 12, 1);
defineBitField(XCEG11, unsigned short, XCERG, 11, 1);
defineBitField(XCEG10, unsigned short, XCERG, 10, 1);
defineBitField(XCEG9, unsigned short, XCERG, 9, 1);
defineBitField(XCEG8, unsigned short, XCERG, 8, 1);
defineBitField(XCEG7, unsigned short, XCERG, 7, 1);
defineBitField(XCEG6, unsigned short, XCERG, 6, 1);
defineBitField(XCEG5, unsigned short, XCERG, 5, 1);
defineBitField(XCEG4, unsigned short, XCERG, 4, 1);
defineBitField(XCEG3, unsigned short, XCERG, 3, 1);
defineBitField(XCEG2, unsigned short, XCERG, 2, 1);
defineBitField(XCEG1, unsigned short, XCERG, 1, 1);
defineBitField(XCEG0, unsigned short, XCERG, 0, 1);

// XCERH - Transmit Channel Enable Register H
defineBitField(XCEH15, unsigned short, XCERH, 15, 1);
defineBitField(XCEH14, unsigned short, XCERH, 14, 1);
defineBitField(XCEH13, unsigned short, XCERH, 13, 1);
defineBitField(XCEH12, unsigned short, XCERH, 12, 1);
defineBitField(XCEH11, unsigned short, XCERH, 11, 1);
defineBitField(XCEH10, unsigned short, XCERH, 10, 1);
defineBitField(XCEH9, unsigned short, XCERH, 9, 1);
defineBitField(XCEH8, unsigned short, XCERH, 8, 1);
defineBitField(XCEH7, unsigned short, XCERH, 7, 1);
defineBitField(XCEH6, unsigned short, XCERH, 6, 1);
defineBitField(XCEH5, unsigned short, XCERH, 5, 1);
defineBitField(XCEH4, unsigned short, XCERH, 4, 1);
defineBitField(XCEH3, unsigned short, XCERH, 3, 1);
defineBitField(XCEH2, unsigned short, XCERH, 2, 1);
defineBitField(XCEH1, unsigned short, XCERH, 1, 1);
defineBitField(XCEH0, unsigned short, XCERH, 0, 1);







// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* McBsp_H */

// }}}RME
