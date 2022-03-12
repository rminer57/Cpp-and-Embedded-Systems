/*******************************************************************************
*
*                F U N C T I O N   S P E C I F I C A T I O N
*             COPYRIGHT 2001 MOTOROLA, INC. ALL RIGHTS RESERVED.
*                    MOTOROLA CONFIDENTIAL PROPRIETARY
*                       C TEMPLATE VERSION R01.00
*
********************************************************************************
*
*  FILE NAME: sequencerLog.cpp
*
*---------------------------------- PURPOSE ------------------------------------
*
*  This file contains the logging functions for data being sent and received
*  (if applicable from the interface functions called by the server) for the 
*  commmand group COMMAND_GROUP_setFuncs.
*
*--------------------------- PROJECT SPECIFIC DATA -----------------------------
*
*
*
*--------------------------- HEADER FILE INCLUDES ----------------------------*/
#ifndef TEST_UNIT_SUPPORT_H
#include "sequencerSupport.h"
#endif

#include "serverPublic.h"
#include "rf_audio_config.h"
//#ifndef CLIENT_CONTROL_H
//#include "clientControl.h"
//#endif

//#ifndef CONTROLLER_H
//#include "controller.h"
//#endif

//#ifndef _INC_FSTREAM
//#include <fstream.h>
//#endif
/*---------------------------- LOCAL CONSTANTS -------------------------------*/

/*--------------------------- LOCAL ENUMERATIONS -----------------------------*/

/*----------------------------- LOCAL DATA TYPES -----------------------------*/

/*------------------------ LOCAL FUNCTION PROTOTYPES -------------------------*/

/*------------------------------- GLOBAL  DATA -------------------------------*/
/* logfile used to record proceedings */
extern ofstream *logfile;

/* global table used to store logging functions */
extern logFuncTable logFuncGroupTable[MAX_COMMAND_GROUP_NUM];

/*******************************************************************************
*
*   FUNCTION NAME: LOG_sequencerInit
*
*---------------------------------- PURPOSE ------------------------------------
*
*   This function initializes the portions of the logFuncGroupTable that
*   COMMAND_GROUP_setFuncs deals with
*
*---------------------------------- SYNOPSIS -----------------------------------
*
*   PRECONDITIONS:   none
*
*   POSTCONDITIONS:  none
*
*   PARAMETERS:      none
*                    none
*
*   RETURN VALUE:    none
*
*---------------------------- DETAILED DESCRIPTION -----------------------------
*
*   This function sets the individual sent data and received data funciton pointers
*   within the logFuncGroupTable to specific logging function pointers created to
*   log the data sent and received for a particular interface function command call.
*
*******************************************************************************/
void LOG_sequencerInit(void)
{
  /* set table */
  logFuncGroupTable[COMMAND_GROUP_sequencer][COMMAND_setGlobal].sentDataFunc = &LOG_setGlobalSend;
  logFuncGroupTable[COMMAND_GROUP_sequencer][COMMAND_getGlobal].sentDataFunc = &LOG_getGlobalSend;
  logFuncGroupTable[COMMAND_GROUP_sequencer][COMMAND_getGlobal].recDataFunc  = &LOG_getGlobalRec;
  logFuncGroupTable[COMMAND_GROUP_sequencer][COMMAND_startSequence].sentDataFunc = &LOG_startSequenceSend;
}

void LOG_setGlobalSend(char* buf)
{
  HARNESS_setGlobal_t *sentData = (HARNESS_setGlobal_t *)buf;

  *logfile << "*** COMMAND: void setGlobal(int globalNumber, int globalValue) ***\n\n" 
           << "\tDATA SENT:" << endl
           << "\t\tint globalNumber   = " << dec << (sentData->globalNumber) << endl
		   << "\t\tint globalValue    = " << dec << (sentData->globalValue) << endl;
}

void LOG_getGlobalSend(char* buf)
{
  HARNESS_getGlobal_t *sentData = (HARNESS_getGlobal_t *)buf;
  *logfile << "*** COMMAND: void getGlobal(int globalNumber) ***\n\n" 
           << "\tDATA SENT:" << endl
           << "\t\tint globalNumber = " << (sentData->globalNumber) << endl;
}

void LOG_getGlobalRec(char* buf)
{
  int *retData = (int *)buf;

  *logfile << "\tRETURN DATA RECEIVED:\n"
           << "\t\tint return global register value = " << *retData << endl
           << "\n&&& COMMAND COMPLETED &&&\n\n";
}

void LOG_startSequenceSend(char* buf)
{
  HARNESS_startSequence_t *sentData = (HARNESS_startSequence_t *)buf;

  *logfile << "*** COMMAND: void startSequence(int sequenceID) ***\n\n" 
           << "\tDATA SENT:" << endl
           << "\t\tint sequenceID = " << (sentData->sequenceID) << endl;
}

/****************************************************************
*  REVISION HISTORY
*
*  Add new history comments after <NEW HISTORY> 
*  and before <OLD HISTORY>.
*
****************************************************************
<NEW HISTORY>
  06/2001   Mark Antilla               Initial creation
<OLD HISTORY>
****************************************************************
*  END OF HISTORY TEMPLATE
****************************************************************/
