// {{{RME classifier 'Logical View::HAL Instantiation::Serial Devices::LAN::Ethernet::Smsc::LAN91C96I::Lan91c96iBitFields'

#ifndef Lan91c96iBitFields_H
#define Lan91c96iBitFields_H

#ifdef PRAGMA
#pragma interface "Lan91c96iBitFields.h"
#endif

#include <serial_comp.h>
#include <bitfield.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
//
//	LAN91C96I
//
//	Rx Status word definition
//
#define RX_FRAME_ALGN_ERR		0x8000		// Alignment error
#define RX_FRAME_BROADCAST		0x4000		// Broadcast frame
#define RX_FRAME_BAD_CRC		0x2000		// Bad CRC
#define RX_FRAME_ODD_BYTES		0x1000		// Rx Frame has an ODD number of bytes
#define RX_FRAME_TOO_LONG		0x0800		// Frame is longer than 1518 bytes (IEEE802.3 Max size)
#define RX_FRAME_TOO_SHORT		0x0400		// Frame is shorter than 64 bytes (IEEE802.3 Min size)
#define RX_FRAME_MULTICAST		0x0001		// Frame was Multicast

#define RX_ERRORS (RX_FRAME_ALGN_ERR | RX_FRAME_BAD_CRC | RX_FRAME_TOO_LONG | RX_FRAME_TOO_SHORT)

#define TX_UNDERRUN_ERROR			0x8000
#define LINK_OK_ERROR				0x4000
#define COUNTER_ROLLOVER			0x1000
#define EXCESSIVE_DEFERRAL		0x0800
#define LOST_CARRIER_SENSE		0x0400
#define LATE_COLLISION				0x0200
#define WAKE_UP					0x0100
#define TX_DEFERRED				0x0080
#define LAST_TX_FRAME_BRDCAST		0x0040
#define SIGNAL_QUALITY_ERROR_TEST	0x0020
#define SIXTEEN_COL_REACHED		0x0010
#define LAST_TX_FRAME_MULTICAST	0x0008
#define MULTIPLE_COLLISIONS			0x0004
#define SNGL_COLLISION				0x0002
#define TX_SUCCEED				0x0001

#define FATAL_TX_ERROR		(TX_UNDERRUN_ERROR | LOST_CARRIER_SENSE | SIGNAL_QUALITY_ERROR_TEST | SIXTEEN_COL_REACHED )

// Add the filter to the receive method
#define TX_FRAME_REMOVED 1

// Allocation time in the Lan91c96i depends on the number of pages to be allocated. 0 <= numberOfPages <= 5
// The calculation is as follows: (numberOfPages + 1)*256 = numberOfBytes * 200 nanoseconds
// Worst case scenario is numberOfPages = 5, then (5+1)*256*200 nanoseconds = 0.0003072 = 3,072 nanoseconds
//
// Assuming that the ARM9 running at 192 MHz, the instruction cycle is 5.208 nanosec. A while loop has 6 assembly instruction with a total of 
// 24 cycles, a while loop is executed in 24 * 5.208 nanoseconds = 124.992 nanoseconds (or approximate 125 nanoseconds)
// 
// An allocation attempt takes 3,072 nanoseconds worst case scenario (if Rx buffer is empty and allocating maximum Tx frame), each while loop 
// is executed in 125 nanoseconds then the max number of while loops shall be 3072/125 = 24.576 or 25 

#define MAX_TX_ALLOCATION_ATTEMPTS		25
#define PAGES_NOT_REQUIRED	0
#define PTR_WAIT				5

//
//	LAN91C96I Registers
//


// Bank Selection is used to access the registers in the LAN91C96I
//
// Each Bank registers is 16-bit wide
//
// Bank Map
//
//  Offset  Bank0       Bank1       Bank2       Bank3       Bank4
//
//  0       TCR         CONFIG      MMU Command             ECOR (Low Byte)
//                                                          ECSR (High Byte)
//
//  2       EPH Status  BASE        PNR RRR     MULTICAST
//                                              TABLE
//
//  4       RCR         Individual  FIFO        MULTICAST
//                      Address     Ports       TABLE                                             
//                      IA0 - 1
//
//  6       COUNTER     IA2 - 3     Pointer     MULTICAST
//                                              TABLE
//
//  8       MIR         IA4 - 5     DATA        Management
//
//  A       MCR         General     DATA        Revision
//                      Purpose
//
//  C       Reserved    Control     Interrupt	ERCV
//
//  E       |<----- Bank Select Register ----->| 


// Register offset
#define REG_OFFSET 0x02


//  Bank Select Register
 
#define	BANK_SELECT_REG		0x000E
defineBitField(BANK,unsigned short,BANK_SELECT_REG,0,3);

//  BS210
//    000   Bank 0
//    001   Bank 1
//    010   Bank 2
//    011   Bank 3
#define BANK0   0x00
#define BANK1   0x01
#define BANK2   0x02
#define BANK3   0x03

// Bank 0
/* Bank 0 Register Definitions */

// TCR	Transmit Control Register   Bank 0  Offset 0
#define	TCR_REG				(REG_OFFSET * 0)
defineBitField(FDSE,unsigned short,TCR_REG,15,1);
defineBitField(ETEN_TYPE,unsigned short,TCR_REG,14,1);
defineBitField(EPH_LOOP,unsigned short,TCR_REG,13,1);
defineBitField(STP_SQET,unsigned short,TCR_REG,12,1);
defineBitField(FDUPLX,unsigned short,TCR_REG,11,1);
defineBitField(MON_CSN,unsigned short,TCR_REG,10,1);
defineBitField(NOCRC,unsigned short,TCR_REG,8,1);
defineBitField(PAD_EN,unsigned short,TCR_REG,7,1);
defineBitField(TXP_EN,unsigned short,TCR_REG,3,1);
defineBitField(FORCOL,unsigned short,TCR_REG,2,1);
defineBitField(LOOP,unsigned short,TCR_REG,1,1);
defineBitField(TXENA,unsigned short,TCR_REG,0,1);

// Ethernet Protocol Handler (EPH) Status Register  Bank 0 Offset 2 Status of Last Tx Packet 
#define EPH_STATUS_REG      (REG_OFFSET * 1)
defineBitField(TX_UNRN,unsigned short,EPH_STATUS_REG,15,1);
defineBitField(LINK_OK,unsigned short,EPH_STATUS_REG,14,1);
defineBitField(RES,unsigned short,EPH_STATUS_REG,13,1);
defineBitField(CTRL_ROL,unsigned short,EPH_STATUS_REG,12,1);
defineBitField(EXC_DEF,unsigned short,EPH_STATUS_REG,11,1);
defineBitField(LOST_CARR,unsigned short,EPH_STATUS_REG,10,1);
defineBitField(LATCOL,unsigned short,EPH_STATUS_REG,9,1);
defineBitField(WAKEUP,unsigned short,EPH_STATUS_REG,8,1);
defineBitField(TX_DEFR,unsigned short,EPH_STATUS_REG,7,1);
defineBitField(LTX_BRD,unsigned short,EPH_STATUS_REG,6,1);
defineBitField(SQET,unsigned short,EPH_STATUS_REG,5,1);
defineBitField(EPH16COL,unsigned short,EPH_STATUS_REG,4,1);
defineBitField(LTX_MULT,unsigned short,EPH_STATUS_REG,3,1);
defineBitField(MUL_COL,unsigned short,EPH_STATUS_REG,2,1);
defineBitField(SNGL_COL,unsigned short,EPH_STATUS_REG,1,1);
defineBitField(TX_SUC,unsigned short,EPH_STATUS_REG,0,1);

#define TX_SUCCESSFUL 0x0001

// Receive Control Register  Bank 0 Offset 4
#define RCR_REG				(REG_OFFSET * 2)
defineBitField(SOFT_RST,unsigned short,RCR_REG,15,1);
defineBitField(FILT_CAR,unsigned short,RCR_REG,14,1);
defineBitField(STRIP_CRC,unsigned short,RCR_REG,9,1);
defineBitField(RX_EN,unsigned short,RCR_REG,8,1);
defineBitField(ALMUL,unsigned short,RCR_REG,2,1);
defineBitField(PRMS,unsigned short,RCR_REG,1,1);
defineBitField(RX_ABORT,unsigned short,RCR_REG,0,1);

// Counter Register			Bank 0 Offset 6
#define ECR_REG				(REG_OFFSET * 3)
defineBitField(EXC_DEF_TX_COUNTER,unsigned short,ECR_REG,12,4);
defineBitField(DEF_TX_COUNTER,unsigned short,ECR_REG,8,4);
defineBitField(MULTIPLE_COLLISION_COUNTER,unsigned short,ECR_REG,4,4);
defineBitField(SINGLE_COLLISION_COUNTER,unsigned short,ECR_REG,0,4);
defineBitField(COUNTER_REGISTER,unsigned short,ECR_REG,0,15);

// Memory Information Register Bank 0 Offset 8
#define MIR_REG				(REG_OFFSET * 4)
defineBitField(FREE_MEM_AVAIL,unsigned short,MIR_REG,8,8);
defineBitField(MEM_SIZE,unsigned short,MIR_REG,0,8);

// Memory Configuration Register  Bank 0 Offset 10
#define MCR_REG				(REG_OFFSET * 5)
defineBitField(MEM_SIZE_MULT,unsigned short,MCR_REG,8,8);
defineBitField(MEM_RSVD_FOR_TX,unsigned short,MCR_REG,0,8);

// This constatnt will fix the number of bytes fixed for Transmission only
// It is calculated as: BYTES = Index * Pages * M  
// Where:
//  M = 1
// Pages = 256
// Bytes = 1536 bytes (Max number of  bytes in a frame
// Then: Index = BYTES/(Pages* M) = 1536/(256) = 6  
#define TX_MEM_ONE_FRAME 6


// Bank 1
// Register Definition

// Configuration Register	Bank 1 Offset 0
#define CR_REG				(REG_OFFSET * 0)
defineBitField(NO_WAIT,unsigned short,CR_REG,12,1);
defineBitField(FULL_STEP,unsigned short,CR_REG,10,1);
defineBitField(SET_SQLCH,unsigned short,CR_REG,9,1);
defineBitField(AUI_SELECT,unsigned short,CR_REG,8,1);
defineBitField(CR16BIT,unsigned short,CR_REG,7,1);
defineBitField(DIS_LINK,unsigned short,CR_REG,6,1);
defineBitField(INT_SEL1,unsigned short,CR_REG,2,1);
defineBitField(INT_SEL0,unsigned short,CR_REG,1,1);

// Base Address Register	Bank 1 Offset 2
#define BAR_REG				(REG_OFFSET * 1)
// This register holds the I/O address decode option chosen fro the I/O and ROM
// space. It is part of the EEPROM saved setup, and is not usually modified
// during running time
defineBitField(A15_A13,unsigned short,BAR_REG,13,3);
defineBitField(A9_A5,unsigned short,BAR_REG,8,5);
defineBitField(ROM_SIZE,unsigned short,BAR_REG,6,2);
defineBitField(RA18_RA14,unsigned short,BAR_REG,1,5);


#define IA0_REG             (REG_OFFSET * 2)  // Individual Address Register 0
#define IA2_REG             (REG_OFFSET * 3)  // Individual Address Register 2
#define IA4_REG             (REG_OFFSET * 4)  // Individual Address Register 4


// General Address Register	Bank 1 Offset 10
#define GPR_REG             (REG_OFFSET * 5)		// General Address Register
defineBitField(HIGH_DATA_BYTE,unsigned short,GPR_REG,8,8);
defineBitField(LOW_DATA_BYTE,unsigned short,GPR_REG,0,8);

#define CTR_REG             (REG_OFFSET * 6)		// Control Register
defineBitField(RCV_BAD,unsigned short,CTR_REG,14,1);
defineBitField(PWR_DN,unsigned short,CTR_REG,13,1);
defineBitField(WAKEUP_EN,unsigned short,CTR_REG,12,1);
defineBitField(AUTO_RELEASE,unsigned short,CTR_REG,11,1);
defineBitField(LE_ENABLE,unsigned short,CTR_REG,7,1);
defineBitField(CR_ENABLE,unsigned short,CTR_REG,6,1);
defineBitField(TE_ENABLE,unsigned short,CTR_REG,5,1);
defineBitField(EEPROM_SEL,unsigned short,CTR_REG,2,1);
defineBitField(RELOAD,unsigned short,CTR_REG,1,1);
defineBitField(STORE,unsigned short,CTR_REG,0,1);
defineBitField(RELOAD_STORE,unsigned short,CTR_REG,0,2);

// Bank 2
// Register Definition

#define MMUCR_REG           (REG_OFFSET * 0)      // MMU Command Register
defineBitField(MMU_COMMAND,unsigned short,MMUCR_REG,4,4);
defineBitField(N2_N0,unsigned short,MMUCR_REG,0,3);
defineBitField(N0_BUSY,unsigned short,MMUCR_REG,0,1);
defineBitField(MMUCR,unsigned short,MMUCR_REG,0,8);

#define MMUCMD_BUSY							0x01	//  MMU busy don't mod PNR
#define NOOP                                0x00
#define ALLOCATE_MEMORY_FOR_TX        		0x02
#define RESET_MMU                           0x04
#define REMOVE_FRAME_FROM_TOP_RX_FIFO       0x06
#define REMOVE_FRAME_FROM_TOP_TX_FIFO       0x07
#define REMOVE_AND_RELEASE_TOP_OF_RX_FIFO   0x08
#define RELEASE_SPECIFIC_PACKET             0x0A
#define ENQUEUE_PACKET_NUMBER_INTO_TX_FIFO  0x0C
#define RESET_TX_FIFOS                      0x0E

#define AUTO_TX_REG         (REG_OFFSET * 0)  // Auto TX Register  
defineBitField(AUTO_TX_START,unsigned short,AUTO_TX_REG,8,8);

#define PNR_REG             (REG_OFFSET * 1)      // Packet Number @ Tx Area
defineBitField(TX_PACKET_NUMBER,unsigned short,PNR_REG,5,0);

#define ARR_REG             (REG_OFFSET * 1)  // Allocation Result Register
defineBitField(ALLOC_FAILED,unsigned short,ARR_REG,15,1);
defineBitField(ALLOCATED_PACKET_NUMBER,unsigned short,ARR_REG,8,5);

#define FIFO_REG            (REG_OFFSET * 2)      // FIFOs
defineBitField(REMPTY,unsigned short int,FIFO_REG,15,1);
defineBitField(RX_FIFO_PACKET_NUMBER,unsigned short,FIFO_REG,8,5);
defineBitField(TEMPTY,unsigned short int,FIFO_REG,7,1);
defineBitField(TX_FIFO_PACKET_NUMBER,unsigned short,FIFO_REG,0,5);

#define PTR_REG             (REG_OFFSET * 3)      // Pointer Register
defineBitField(RCV,unsigned short,PTR_REG,15,1);
defineBitField(AUTO_INCR,unsigned short,PTR_REG,14,1);
defineBitField(READ,unsigned short,PTR_REG,13,1);
defineBitField(ETEN,unsigned short,PTR_REG,12,1);
defineBitField(AUTO_TX,unsigned short,PTR_REG,11,1);
defineBitField(POINTER_HIGH,unsigned short,PTR_REG,8,3);
defineBitField(POINTER_LOW,unsigned short,PTR_REG,0,8);
defineBitField(POINTER,unsigned short,PTR_REG,0,11);

#define RCV			0x8000
#define AUTO_INCR		0x4000
#define READ			0x2000


#define DATA_HIGH           (REG_OFFSET * 4)
#define DATA_LOW            (REG_OFFSET * 5)

#define INT_REG             (REG_OFFSET * 6)      // Interrupt Mask Register (Upper Byte)
defineBitField(TX_IDLE_MASK,unsigned short,INT_REG,15,1); 
defineBitField(ERCV_MASK,unsigned short,INT_REG,14,1);	
defineBitField(EPH_MASK,unsigned short,INT_REG,13,1);		
defineBitField(RX_OVRN_MASK,unsigned short,INT_REG,12,1); 
defineBitField(ALLOC_MASK,unsigned short,INT_REG,11,1);	
defineBitField(TX_EMPTY_MASK,unsigned short,INT_REG,10,1);
defineBitField(TX_MASK,unsigned short,INT_REG,9,1);		
defineBitField(RCV_MASK,unsigned short,INT_REG,8,1);		

defineBitField(INT_MASK,unsigned short,INT_REG,8,8);

defineBitField(TX_IDLE_INT,unsigned short,INT_REG,7,1);  // Interrupt Status Register
defineBitField(ERCV_INT,unsigned short,INT_REG,6,1);
defineBitField(EPH_INT,unsigned short,INT_REG,5,1);
defineBitField(RX_OVRN_INT,unsigned short,INT_REG,4,1);
defineBitField(ALLOC_INT,unsigned short,INT_REG,3,1);
defineBitField(TX_EMPTY_INT,unsigned short,INT_REG,2,1);
defineBitField(TX_INT,unsigned short,INT_REG,1,1);
defineBitField(RCV_INT,unsigned short,INT_REG,0,1);

defineBitField(IST,unsigned short,INT_REG,0,8);


#define ACK_REG              (REG_OFFSET * 6)     // Interrupt Acknowledge Register
defineBitField(ACK_ERCV_INT,unsigned short,INT_REG,6,1);
defineBitField(ACK_RX_OVRN_INT,unsigned short,INT_REG,4,1);
defineBitField(ACK_TX_EMPTY_INT,unsigned short,INT_REG,2,1);
defineBitField(ACK_TX_INT,unsigned short,INT_REG,1,1);

// following definitions work for ISR, IAR & IMR */
#define TX_IDLE_INT_MASK	0x80
#define ERCV_INT_MASK		0x40
#define EPH_INT_MASK		0x20
#define RX_OVRN_INT_MASK	0x10
#define ALLOC_INT_MASK		0x08
#define TX_EMPTY_INT_MASK	0x04
#define TX_INT_MASK			0x02
#define RCV_INT_MASK		0x01

#define ENABLED_INTERRUPTS  (EPH_INT_MASK | RX_OVRN_INT_MASK | RCV_INT_MASK)

// Bank 3
// Register Definition

#define MT0_REG              (REG_OFFSET * 0)
defineBitField(MCAST0,unsigned short,MT0_REG,8,0);

#define MT1_REG              (REG_OFFSET * 0)
defineBitField(MCAST1,unsigned short,MT1_REG,8,8);

#define MT2_REG              (REG_OFFSET * 1)
defineBitField(MCAST2,unsigned short,MT2_REG,8,0);

#define MT3_REG              (REG_OFFSET * 1)
defineBitField(MCAST3,unsigned short,MT3_REG,8,8);

#define MT4_REG              (REG_OFFSET * 2)
defineBitField(MCAST4,unsigned short,MT4_REG,8,0);

#define MT5_REG              (REG_OFFSET * 2)
defineBitField(MCAST5,unsigned short,MT5_REG,8,8);

#define MT6_REG              (REG_OFFSET * 3)
defineBitField(MCAST6,unsigned short,MT6_REG,8,0);

#define MT7_REG              (REG_OFFSET * 3)
defineBitField(MCAST7,unsigned short,MT7_REG,8,8);

#define MGMT_REG             (REG_OFFSET * 4)
defineBitField(nXNDEC,unsigned short,MGMT_REG,11,1);
defineBitField(IOS2,unsigned short,MGMT_REG,10,1);
defineBitField(IOS1,unsigned short,MGMT_REG,9,1);
defineBitField(IOS0,unsigned short,MGMT_REG,8,1);
defineBitField(MDOE,unsigned short,MGMT_REG,3,1);
defineBitField(MCLK,unsigned short,MGMT_REG,2,1);
defineBitField(MDI,unsigned short,MGMT_REG,1,1);
defineBitField(MD0,unsigned short,MGMT_REG,0,1);


#define REVISION_REG         (REG_OFFSET * 5)     // IC's CHIP & Revision numbers
defineBitField(CHIP,unsigned short,REVISION_REG,4,4);
defineBitField(REV,unsigned short,REVISION_REG,0,4);

#define ERCV_REG             (REG_OFFSET * 6)     // Early Receive Register
defineBitField(RCV_COUNTER,unsigned short,ERCV_REG,8,8);
defineBitField(RCV_DISCRD,unsigned short,ERCV_REG,7,1);
defineBitField(ERCV_THRESHOLD,unsigned short,ERCV_REG,5,0);
// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Lan91c96iBitFields_H */

// }}}RME
