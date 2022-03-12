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

#include "StateMachine.h"



static sm_stateEventMatrix_entry_t state_table_uninitialized[] =
{  
   /***********************************************************************************************************
   * Action Routine                  Event                          Next State     *
   ************************************************************************************************************/                         
    {  ignore_action,          XNL_SM_EVENT_KEY_REQUEST_SENT,        XNL_STATE_AUTHENTICATION_PROCEEDING }, 
    {  radio_reset_action,     XNL_SM_EVENT_RADIORESET,              STATE_UNINITIALIZED }, 
	{  ignore_action,          XNL_SM_EVENT_IGNORE,                  STATE_UNINITIALIZED },    
};       
    
static sm_stateEventMatrix_entry_t state_table_authentication_proceeding [] =
{  
   /***********************************************************************************************************
   * Action Routine                  Event                          Next State     *
   ************************************************************************************************************/ 
   {  xnl_authenticate_action,   XNL_SM_EVENT_KEY_REPLY,           XNL_STATE_AUTHENTICATION_PROCEEDING },
   {  xnl_authenticate_action,   XNL_SM_EVENT_CONN_REQUEST_SENT,   XNL_STATE_AUTHENTICATION_PROCEEDING },
   {  xnl_authenticate_action,   XNL_SM_EVENT_CONN_REQUEST_REPLY,  XNL_STATE_AUTHENTICATION_PROCEEDING }, 
   {  xnl_authenticate_action,   XNL_SM_EVENT_AUTHENTICATED,       XNL_STATE_AUTHENTICATION_OK },   // good CONN_REPLY
   {  radio_reset_action,        XNL_SM_EVENT_RADIORESET,          STATE_UNINITIALIZED },  
   {  ignore_action,             XNL_SM_EVENT_IGNORE,              STATE_UNINITIALIZED }    
};

static sm_stateEventMatrix_entry_t state_table_authentication_ok [] =
{  
   /***********************************************************************************************************
   * Action Routine                  Event                          Next State     *
   ************************************************************************************************************/ 
   {  xcmp_message_action,        XNL_SM_EVENT_DEVICE_SYSMAP_BRDCST, XNL_STATE_AUTHENTICATION_OK },
   {  xcmp_message_action,        XCMP_VALID_MESSAGE,                XNL_STATE_AUTHENTICATION_OK },
   {  radio_reset_action,         XNL_SM_EVENT_RADIORESET,           STATE_UNINITIALIZED }, 
   {  ignore_action,              XNL_STATE_AUTHENTICATION_OK,       XNL_STATE_AUTHENTICATION_OK } 

};


/* Pointers to the particular tables containing events and actions per state */
sm_stateEventMatrix_state_t states_table [] =
{
   /************************************************************************************************************
   * Number of events in the state                                       Event table                           *
   *************************************************************************************************************/

   { sizeof(state_table_uninitialized)/sizeof(sm_stateEventMatrix_entry_t),  state_table_uninitialized},
   { sizeof(state_table_authentication_proceeding)/sizeof(sm_stateEventMatrix_entry_t), state_table_authentication_proceeding},
   { sizeof(state_table_authentication_ok)/sizeof(sm_stateEventMatrix_entry_t),    state_table_authentication_ok},
   { 0, (sm_stateEventMatrix_entry_t *) ((void *)0)}            
};


/*************************************************************************************************************************************
* Number of states in the stateEventMatrix   State Table   Initial State                                                                          *
**************************************************************************************************************************************/
sm_stateEventMatrix_t stateEventMatrixTable = { sizeof(states_table)/sizeof(sm_stateEventMatrix_state_t), states_table, STATE_UNINITIALIZED };


  stateMachine::stateMachine()
  {
  
  }
   stateMachine::~stateMachine(){}
/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
void  radio_reset_action( sm_event_t event, void * data_ptr ){}
/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
void  ignore_action( sm_event_t event, void * data_ptr ){}
/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
void  xnl_authenticate_action( sm_event_t event, void * data_ptr ){}
/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
void  xcmp_message_action( sm_event_t event, void * data_ptr ){}

// to use this statemachine we must,  
// 1. receive a message.  
// 2. validate the message 
// 3. find the statemachine event code corresponding to the message
// 4. call  xnl_sm_event(event_id, xnl_msg_ptr);


/*************************************************************************
*
*   FUNCTION NAME   xnl_sm_event
*
*---------------------------------- PURPOSE ------------------------------
*   The purpose of this function is to implement the event processor of the
*   xnl.
*
*---------------------------------- SYNOPSIS -----------------------------
*
*   PARAMETERS     event - The event associated with the data.
*                  data - Pointer to any event data.      
*
*   RETURN VALUE:  none.    
*
*---------------------------- DETAILED DESCRIPTION -----------------------
* 
*************************************************************************/


void  trigger_sm_event(sm_event_values_enum_t event, void * data)
{
    
    unsigned int i = 0;     // A counter used to step through events in a state 
                            // The current state of the module 
    sm_state_t          current_state = STATE_UNINITIALIZED;   
    sm_stateEventMatrix_entry_ptr_t  entry_ptr = 0;       // Pointer to the event entry 
    
    // CODE ------------------------------------

    // This is the main event processor for the xnl. 


       // Obtain the current state of the module 
       current_state = stateEventMatrixTable.current_state;

       // Obtain pointer to the state table (table of events) given the current state  
       entry_ptr = stateEventMatrixTable.state_table[current_state].event_table;      
       
       // Search through the state table looking for the event  
          
       // Start at the first event and compare the given event to all of the events in the table. If 
       //   a match is found, the table pointer will point to the event entry which consists of: 
       //   the event, the action routine, and the next state. If the event is not found, we will hit
       //   the end of the event table.  
       while (entry_ptr->event != event && i < stateEventMatrixTable.state_table[current_state].number_of_events)
       {
          ++entry_ptr;
          i++;
       }
     
       // Check to see if we hit the end of the event table 
       if (i != stateEventMatrixTable.state_table[current_state].number_of_events)
       { 
          // change to the next state based on the table entry for this event 
          stateEventMatrixTable.current_state = entry_ptr->next_state;
            
          // If an valid event was found in this state, run the action routine 
          if(entry_ptr->action)
          {
             (entry_ptr->action)(event,  data);
          }
          
   
            
       }
       else
       {

          // We hit the end of the event table. Therefore this was an unhandled event. 
          // Log an error and free the data, if any 
 
          // xnl_Error(xnl_ERR_EVENT_UNHANDLED, 0, event);
       }       
     
       
 
}





/*************************************************************************
*
*   FUNCTION NAME rfm_pro_event_parser:
*
*---------------------------------- PURPOSE ------------------------------
*   Reads the event and returns an enumerated value.
*  
*
*---------------------------------- SYNOPSIS -----------------------------
*                    
*
*   PARAMETERS:   void pointer pointing to the start of a message.      
*
*   RETURN VALUE: message opcode.   
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   This function is called by the ros task responsible for obtaining 
*   messages for rf modem.  Messages can come from VRIS (those rf modem 
*   has subscribed to, or from TCP (Command Terminal messages).  The IP
*   detection service will send a notification to this task, when such a
*   TCP message is received.  Before calling rfm_pro_event_parser(), the
*   task must have first called rfm_pro_Get_Msg() in order to determine
*   message source, set the Get_Msg_type, and save the data.
*   eventdata to event_enum_id is done in two seperate switch statements
*   because there is no guarantee of VRIS and rf modem protocol opcode
*   uniqueness.  
*************************************************************************/
sm_event_values_enum_t  event_parser( void * msg_ptr )
{
  unsigned int eventdata = 0;
  sm_event_values_enum_t event_enum_id = SM_EVENT_UNKNOWN;
  
//  if ( rfm_pro_private_data.Get_Msg_type == RFM_RIF_MSG_RADIO )
//  {
//    eventdata = ((vris_msg_t *)msg_ptr)->vris_hdr.all;
    
       /* determine event_id */
//    switch(eventdata)
//    {
      /* timer expiration */
//      case VR_COMBINE (OP_NORM_TIMEOUT, ID_SYS_CONTROL, ST_RTC): 
//         event_enum_id = RFM_SM_EVENT_TIMEOUT_MSG;                
//      break; 
      

//      default:            
//         event_enum_id = RFM_SM_EVENT_IGNORE;
         
//      break;              
        
//    }
    
    
//  }
//  else
//  {
 
    /* if a CT message then return the rf modem protocol message opcode */
//    eventdata = ((rfm_pro_msg_inrosbuf_t *)msg_ptr)->rfmodem_hdr.opcode;
    
    /* CT to rfmodem message events */
//    switch(eventdata)
//    {
      /* CT to radio rf modem protocol channel init */
//      case RFM_CHANNEL_INIT:
      
//         event_enum_id = RFM_SM_EVENT_CTtoRFM_CHAN_INIT;
         
//      break;  
      
 
            
//      default: /* drop here if the opcode read from CT message is not recognized */
         
//         event_enum_id = RFM_SM_EVENT_CT_ERROR; /* unknown opcode from CT */
         
         /* populate the error fields in preparation for the sending of an */
         /* error message to the command terminal that will be triggered by */
         /* the statemachine upon recognition of the RFM_SM_EVENT_CT_ERROR event */
         /* the action handler for that event will send these values to the CT */
         /* in the message payload */ 
         
//         rfm_pro_private_data.error_category = RFM_PROTO_ERR_UNKNOWNMSG; 
         
//         rfm_pro_private_data.error_code = RFM_SM_EVENT_CT_ERROR;  
         
//         rfm_pro_private_data.error_parameter = eventdata; 
      
//      break;
        
//    }
    
//  }
  
  
  
  return event_enum_id;
}                


/*************************************************************************
*
*   FUNCTION NAME   rfm_sm_get_currentstate
*
*---------------------------------- PURPOSE ------------------------------
*   Returns the statemachine state value.
*  
*
*---------------------------------- SYNOPSIS -----------------------------
*
*   PARAMETERS     none      
*
*   RETURN VALUE:  statemachine state.    
*
*---------------------------- DETAILED DESCRIPTION -----------------------
* 
*************************************************************************/

sm_state_t  stateMachine::getState(void)
{
  return stateEventMatrixTable.current_state; 
}

/*************************************************************************
*
*   FUNCTION NAME   rfm_sm_set_currentstate
*
*---------------------------------- PURPOSE ------------------------------
*   Overrides the statemachine currentstate value with a new state.
*---------------------------------- SYNOPSIS -----------------------------
*
*   PARAMETERS     rfm_sm_state_t newstate      
*
*   RETURN VALUE:  rfm_sm_state_t previous statemachine state.    
*
*---------------------------- DETAILED DESCRIPTION -----------------------
* This routine should be used very carefully. It is intended primarily for
* use in forcing rfmodem into the error state when certain errors occur 
* which require intervention by the Command Terminal. The old state is
* returned just in case the caller needs to know this. 
*************************************************************************/

sm_state_t  stateMachine::setState( sm_state_t newstate )
{
  sm_state_t oldstate;

  oldstate = stateEventMatrixTable.current_state;
  
  stateEventMatrixTable.current_state = newstate;
      
  return oldstate; 
}



/*******************************************************************************
*
*                     C L U S T E R    F U N C T I O N
*
*            COPYRIGHT 2003 MOTOROLA, INC. ALL RIGHTS RESERVED.
*
********************************************************************************
*
*   FUNCTION NAME   : xnl_task 
*
*---------------------------------- PURPOSE ------------------------------------
* Implements the ROS32 task.
*---------------------------------- SYNOPSIS -----------------------------------
*   ASSUMPTIONS/PRECONDITIONS: 
*
*   POSTCONDITIONS:
*
*   PARAMETER DESCRIPTION:
*       INPUT : void
*       OUTPUT: void
*
*--------------------------- DETAILED DESCRIPTION ------------------------------
* This task functions as the main message loop for rf modem.  It opens the
* serial transport, waits for a connection, initializes the rf modem, then
* begins getting messages. Messages can be those subscribed to from VRIS, or
* an IP detect TCP rxdata notification message.  All of the above are vris
* messages. If a TCP IP detect notification message is received, the socket
* will be read and the data will be saved.
*
* Messages are parsed to determine the event that they indicate, and the
* state machine will be called with the event id and a message pointer.
* The state machine then processes the event.
*
* If the rf modem is not allowed to run (codeplug check), then this task will
* wait forever on a ros message.  If a message arrives (should not happen) then
* the message will simply be freed without being used.
********************************************************************************
*/
/*--------------------------- FUNCTION DEFINITION ----------------------------

/*

void xnl_xnl_task(void)
{
    //------------------------- LOCAL VARIABLES ------------------------------ 
    boolean ergAppOn = FALSE;
    
    // generic pointer to a message. Use void and let functions cast as needed     
    void * xnl_msg_ptr = NULL;

    // event enumeration, -1 denotes error, 0 is ignore, positive value = valid event         
    xnl_sm_event_values_enum_t event_id = 0;
    
    extern xnl_pro_private_data_t xnl_pro_private_data;
    
    //------------------------------ CODE ------------------------------------

   if( xnl_rif_is_rf_modem_enabled() == TRUE )
   { 
      // initialize the TCP server provided by the RF Modem so that the external
      // PC client plugged into the serial port of the radio can connect.
      // this is the listening socket, it should never be closed 
      xnl_rif_serial_transport_open( );
   }
     
   // outer for loop, used to restart everything if a connection is closed     
   for(;;)
   {
        // check if the RF Modem is allowed to run 
        if( xnl_rif_is_rf_modem_enabled() == TRUE )
        {
     
            for(;;)
	    {
	    
               // wait for serial connection- a blocking call is used so that other tasks 
               // can execute during the wait. When the xnl is not being used, this task 
               // will be forever inside this function. 
               xnl_rif_serial_transport_waiton_connection();
	    
               // We can't enter xnl from a trunking channel (PLAso24993), so keep looping
	          //until the user changes to a conventional channel. 
	       if (dsi_util_get_current_sig_type() == SIG_CONV)
	       {
                  break;
	       }
	       
	       // Declare a buffer for the error message. Send the error message. Free up the buffer. 
               xnl_pro_private_data.CT_txdBuffer = xnl_Malloc( xnl_pro_msg_inrosbuf_t );
	           xnl_pro_error_sendto_CT( xnl_PROTO_ERR_NOTREADY, xnl_NON_CONV, 0 );
               xnl_Free( xnl_pro_private_data.CT_txdBuffer );

	       // Close the current connection.  We'll repeat the loop and wait for a new one 
               xnl_rif_serial_transport_close();
	       
	    }
            
            // since a connection has been made, the user wants to execute rf modem - start ergo 
            // start the ergo app and wait for an acknowledgement 
            if( ergAppOn == FALSE )
            {  
              xnl_rif_start_ergo_app();
              ergAppOn = TRUE;
            }
        
            // The PC has been connected! 
            // call xnl_proto_open to initialize the xnl private data and subscribe to 
            // the vris messages that are handled 

            //=======================================
            //  Initialize the xnl_radioif.c     
            //  module private attribute variables   
            //  and set the radio to a known state.   
            //=======================================
            xnl_rif_open();
                    
            xnl_pro_open(); // initialize the protocol module 
            
        } 
                   
        for(;;)
        {       
          // Get an input message. Messages come from either the radio (VRIS) or TCP. 
          // Messages read from the ros message queue will be freed after use. 
          // since messages come from different transports, the parser must know the 
          // type of message in order to extract the content properly. 
          // a private message type flag (xnl_rif_private_data.Get_Msg_type) is set 
          // by xnl_rif_Get_Msg and used by xnl_rif_event_parser 
         
          // wait for a message and block this task until one arrives 
          xnl_msg_ptr = xnl_pro_Get_Msg();

            // check if the RF Modem is allowed to run 
          if( xnl_rif_is_rf_modem_enabled() == TRUE )
          {
              if((xnl_msg_ptr != NULL) && (xnl_rif_getConnectionState() == TRUE))
              {
                // read the event contained in the message 
                // this function extracts event codes from TCP packets as well as ros/vris 
                // valid events to be acted upon all have positive integer values 
                event_id = (xnl_sm_event_values_enum_t)xnl_pro_event_parser(xnl_msg_ptr);
            
                // an event value less than 1 is to be ignored 
                // it could be an error, already reported by the parser, or a don't care event 
                if( event_id > 0)
                {                
                  // Call pass the event and data pointer into the state machine.  
                  xnl_sm_event(event_id, xnl_msg_ptr);
                }
              } 

              // check to verify the TCP socket connection is still active, the user could 
              // close it at any time 
              if( xnl_rif_getConnectionState() == FALSE)
              {

                // shut down protocol engine and free all memory 
                xnl_pro_close();
              
                // shut down the serial transport 
                xnl_rif_close();
                
                if( xnl_msg_ptr != NULL )
                {            
                  xnl_Free(xnl_msg_ptr);
                }
              
                // break out of inner for loop 
                break;  
              }
            
          }

          // free the memory allocated for this event if a ros message 
          // IP detection messages are freed in a separate portion of the code 
          // buffer memory allocated on startup is freed at close time 
          if( xnl_pro_GetMsgType() == xnl_RIF_MSG_RADIO )
          {
              if( xnl_msg_ptr != NULL )
              {            
                xnl_Free(xnl_msg_ptr);
              }
          }
          
        } // end inner for 
    
   } // end outer for 
            
}

*/