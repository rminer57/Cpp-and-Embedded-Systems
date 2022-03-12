/*******************************************************************************
*
*                         C++  IMPLEMENTATION  F I L E
*
*            COPYRIGHT 2011 MOTOROLA, INC. ALL RIGHTS RESERVED.
*                    MOTOROLA CONFIDENTIAL PROPRIETARY
*
********************************************************************************
*
*   FILE NAME      : 
*
*-------------------------------- PURPOSE --------------------------------------
*
*  
*
*--------------------------- DEPENDENCY COMMENTS -------------------------------
*
* 
*------------------------------- REVISIONS -------------------------------------
*
* Date        Name      Description
* ----------  --------  --------------------------------------------
* 12/29/2010 R.Miner    Initial Creation
* 

*******************************************************************************/
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

 /* Used to store the current state of a state machine */
  typedef unsigned int sm_state_t;

  /* Used to store a state machine event */
  typedef unsigned int sm_event_t;

/* Function pointer for and action routine called from a state machine. The 
  action routine always receives the event that resulted in a call to it and
  any data associated with that event */
typedef void  (* action_function_t)(sm_event_t , void *);

/* The definition of an entry in the stateEventMatrix state table. It contains the event,
   and action routine to call when the event occurs, and the next state to
   enter following the event */
   
typedef struct
{
    action_function_t    action    ;
    sm_event_t           event     ;
    sm_state_t           next_state;

} sm_stateEventMatrix_entry_t, * sm_stateEventMatrix_entry_ptr_t ;

/* The definition of a stateEventMatrix state. Contains the number of events in the state and 
   the event table (an array of sdp_stateEventMatrix_entry_t). */
typedef struct 
{
    unsigned int       number_of_events;
    sm_stateEventMatrix_entry_t *   event_table;
} sm_stateEventMatrix_state_t;

/* The definition of a state event matrix. The stateEventMatrix contains a number of states, 
   a state table (an array of sdp_stateEventMatrix_state_t), and initialization function, and
   a current state */
typedef struct
{
    unsigned int       number_of_states;
    sm_stateEventMatrix_state_t *   state_table;
    sm_state_t         current_state;

} sm_stateEventMatrix_t;

/************************************/
/* state event matrix definitions   */
/************************************/

/* State Machine Event definitions for the xnl. */

typedef enum 
{
    /* message events */
	SM_EVENT_UNKNOWN,
    XNL_SM_EVENT_KEY_REQUEST_SENT,
    XNL_SM_EVENT_KEY_REPLY,
    XNL_SM_EVENT_CONN_REQUEST_SENT,
    XNL_SM_EVENT_CONN_REQUEST_REPLY,
    XNL_SM_EVENT_DEVICE_SYSMAP_BRDCST,
	XNL_SM_EVENT_AUTHENTICATED,
	XCMP_VALID_MESSAGE,
	XNL_SM_EVENT_RADIORESET,
    XNL_SM_EVENT_IGNORE
} sm_event_values_enum_t;

typedef enum 
{
    STATE_UNINITIALIZED = 0,          /* State 0 */
    XNL_STATE_AUTHENTICATION_PROCEEDING,  /* State 1 */
    XNL_STATE_AUTHENTICATION_OK           /* State 2 */

} sm_state_values_t;

/*************************************************************************
*
*   CLASS NAME:
*
*   RELATIONSHIPS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PUBLIC METHODS AND ATTRIBUTES:           
*                      
*   
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
class stateMachine
{
public:

  stateMachine();
  ~stateMachine();
  sm_state_t getState(void);
  sm_state_t setState( sm_state_t newstate );

  /* This holds the current state of the xnl. used for test and debug */
  char * xnl_sm_state_name;  

};

  void trigger_sm_event(sm_event_values_enum_t event, void * data);

  void radio_reset_action( sm_event_t event, void * data_ptr ); 
  void ignore_action( sm_event_t event, void * data_ptr );
  void xnl_authenticate_action( sm_event_t event, void * data_ptr );
  void xcmp_message_action( sm_event_t event, void * data_ptr );

  /* identifies messages as being from vris or from the command terminal */
  sm_event_values_enum_t event_parser( void * msg_ptr );


 

#endif  stateMachine::