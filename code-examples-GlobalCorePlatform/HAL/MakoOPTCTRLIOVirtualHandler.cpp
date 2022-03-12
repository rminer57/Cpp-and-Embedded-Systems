// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::mako::MakoOPTCTRLSubsystem::MakoOPTCTRLIOVirtualHandler'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "MakoOPTCTRLIOVirtualHandler.h"
#endif

#include <rf_sequencer_comp.h>
#include <MakoOPTCTRLIOVirtualHandler.h>
#include <Mako.h>
#include <MakoOPTCTRL.h>
#include <MakoPrivateBitfieldsReg4.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
MakoOPTCTRLIOVirtualHandler::~MakoOPTCTRLIOVirtualHandler( void )
{
}
// }}}RME

// {{{RME operation 'MakoOPTCTRLIOVirtualHandler(unsigned int,MakoOPTCTRL *)'
MakoOPTCTRLIOVirtualHandler::MakoOPTCTRLIOVirtualHandler( unsigned int whichIOVirtual, MakoOPTCTRL * parent )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_whichIOVirtual(whichIOVirtual),m_MakoOPTCTRL_parent(parent)
	// }}}USR
	// }}}RME
{
	// {{{USR
	              // note: This constructor won't be called unless the whichIOVirtual argument first
	              // passes the validation test. Thus, there is no need to provide a default case to
	              // the switch statement.

			      // **********************************************************************      
			      // Initialize the m_which_OPT_CTRL_reg attribute so that each time a
			      // send or receive occurs, a little time can be saved by not having to
			      // determine this information again.
			      // **********************************************************************
			      switch (m_whichIOVirtual)
			      {
			        // *********************************
		            //            opt_ctrl1
		            // *********************************
			        case MAKOOPTCTL_IOVGRP_PIN_STATEB:
			        case MAKOOPTCTL_IOVGRP_PIN_STATEA:
			        case MAKOOPTCTL_IOV_OPTB_INTEN:
			        case MAKOOPTCTL_IOV_OPTB_INTFLAG:
			        case MAKOOPTCTL_IOVGRP_OPT_STATEB:
			        case MAKOOPTCTL_IOV_OPTA_INTEN:
			        case MAKOOPTCTL_IOV_OPTA_INTFLAG:
			        case MAKOOPTCTL_IOVGRP_OPT_STATEA:  
		        
			           m_which_OPT_CTRL_reg = 1;
			        	                
			        break;

			        // *********************************
		            //            opt_ctrl2
		            // *********************************
			        case MAKOOPTCTL_IOVGRP_GPIO_DIR:
			        case MAKOOPTCTL_IOVGRP_OPT_CONFIGB:
			        case MAKOOPTCTL_IOVGRP_OPT_CONFIGA:      

			           m_which_OPT_CTRL_reg = 2;
			        		        	                                
			        break;

			        // *********************************
		            //            opt_ctrl3
		            // *********************************
			        case MAKOOPTCTL_IOVGRP_PIN_MASKB:
			        case MAKOOPTCTL_IOVGRP_OPT_MASKB:
			        case MAKOOPTCTL_IOVGRP_PIN_MASKA:
			        case MAKOOPTCTL_IOVGRP_OPT_MASKA:         

			           m_which_OPT_CTRL_reg = 3;
			        	                                
			        break;



			      }

	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
unsigned int MakoOPTCTRLIOVirtualHandler::receive( void )
{
	// {{{USR
		unsigned int retval = 0;
		uint32_t rdData = 0;


		          // **********************************************************************      
		          //  read the IC
		          // **********************************************************************

	              switch ( m_which_OPT_CTRL_reg )
	              {
			        case 1:
			        
		               rdData = m_MakoOPTCTRL_parent->m_MakoParent->rdRegister(OPT_CTRL_REGISTER_ADDR, m_MakoOPTCTRL_parent->opt_ctrl1_image);
		               
		            break;              

			        case 2:
			        
		               rdData = m_MakoOPTCTRL_parent->m_MakoParent->rdRegister(OPT_CTRL_REGISTER_ADDR, m_MakoOPTCTRL_parent->opt_ctrl2_image);
		               
		            break;
		                          
			        case 3:
			        
		               rdData = m_MakoOPTCTRL_parent->m_MakoParent->rdRegister(OPT_CTRL_REGISTER_ADDR, m_MakoOPTCTRL_parent->opt_ctrl3_image);
		               
		            break;              	                          
	              };     
	              	 
		          // get current register contents. the image already has the correct register address.


	              // extract the desired bit.  Note: write only bit settings will be obtained from the saved
	              // image while read only or read/write bit(s) are obtained directly from the Mako IC.
	              	 
			      switch (m_whichIOVirtual)
			      {

			        // *********************************
		            //            opt_ctrl1 fields
		            // *********************************
			        case MAKOOPTCTL_IOVGRP_PIN_STATEB:  // read only
			        
		               retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_PIN_STATEB_BITFIELD);
		               
		            break;
			        
			        case MAKOOPTCTL_IOVGRP_PIN_STATEA:  // read only
			        
		               retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_PIN_STATEA_BITFIELD);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOV_OPTB_INTEN:  // write only

	                   rdData = m_MakoOPTCTRL_parent->opt_ctrl1_image;		        
		               retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_OPTB_INTEN_BITFIELD);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOV_OPTB_INTFLAG:  // read/write
			        
		               retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_OPTB_INTFLAG_BITFIELD);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOVGRP_OPT_STATEB:  // read only
			        
			        
		               retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_OPT_STATEB_BITFIELD);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOV_OPTA_INTEN:  // write only

	                   rdData = m_MakoOPTCTRL_parent->opt_ctrl1_image;		        
		               retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_OPTA_INTEN_BITFIELD);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOV_OPTA_INTFLAG:  // read/write
			        
		               retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_OPTA_INTFLG_BITFIELD);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOVGRP_OPT_STATEA:  // read only
			         
		               retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_OPT_STATEA_BITFIELD);
		               
		            break;
			        
			        // *********************************
		            //            opt_ctrl2 fields
		            // *********************************
			        case MAKOOPTCTL_IOVGRP_GPIO_DIR:  // write only

	                   rdData = m_MakoOPTCTRL_parent->opt_ctrl2_image;		        
		               retval = (unsigned int)getBitField( &rdData, MAKO_GPIO_DIR_BITFIELD);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOVGRP_OPT_CONFIGB:  // write only

	                   rdData = m_MakoOPTCTRL_parent->opt_ctrl2_image;		        		        
		               retval = (unsigned int)getBitField( &rdData, MAKO_OPT_CONFIGB_BITFIELD);
		               
		            break;
			         	        
			        case MAKOOPTCTL_IOVGRP_OPT_CONFIGA:  // write only

	                   rdData = m_MakoOPTCTRL_parent->opt_ctrl2_image;		        		             
		               retval = (unsigned int)getBitField( &rdData, MAKO_OPT_CONFIGA_BITFIELD);
		               
		            break;
			        
			        // *********************************
		            //            opt_ctrl3 fields
		            // *********************************
			        case MAKOOPTCTL_IOVGRP_PIN_MASKB:  // write only

	                   rdData = m_MakoOPTCTRL_parent->opt_ctrl3_image;		        		        
		               retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_PIN_MASKB_BITFIELD);
		               
		            break;
			         	        
			        case MAKOOPTCTL_IOVGRP_OPT_MASKB:  // write only

	                   rdData = m_MakoOPTCTRL_parent->opt_ctrl3_image;			        
		               retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_OPT_MASKB_BITFIELD);
		               
		            break;         
			        
			        case MAKOOPTCTL_IOVGRP_PIN_MASKA:  // write only

	                   rdData = m_MakoOPTCTRL_parent->opt_ctrl3_image;			        
		              retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_PIN_MASKA_BITFIELD);
		              
		            break;
			         	        
			        case MAKOOPTCTL_IOVGRP_OPT_MASKA:  // write only

	                   rdData = m_MakoOPTCTRL_parent->opt_ctrl3_image;			                
		              retval = (unsigned int)getBitField( &rdData, MAKOOPTCTL_OPT_MASKA_BITFIELD); 
		              
		            break;
			        

			      };

		    
		          return retval;    


	// }}}USR
}
// }}}RME

// {{{RME operation 'send(unsigned int)'
void MakoOPTCTRLIOVirtualHandler::send( unsigned int data )
{
	// {{{USR
	  // sending to a read only bit is invalid so attempting to do
	  // so will be ignored.

	              bool writable = true; // default to true, if user tries to write to a read only bit
	                                    // then it will be set to false.
	              uint32_t wrData = 0;
	              
	              
	              // read previously written image
	              switch ( m_which_OPT_CTRL_reg )
	              {
			        case 1:
			        
		               wrData = m_MakoOPTCTRL_parent->opt_ctrl1_image;
		               
		            break;              

			        case 2:
			        
		               wrData = m_MakoOPTCTRL_parent->opt_ctrl2_image;
		               
		            break;
		                          
			        case 3:
			        
		               wrData = m_MakoOPTCTRL_parent->opt_ctrl3_image;
		               
		            break;              	                          
	              };     
		  
			      switch (m_whichIOVirtual)
			      {


			        // *********************************
		            //            opt_ctrl1 fields
		            // *********************************
			        case MAKOOPTCTL_IOVGRP_PIN_STATEB:  // read only
			        
		               setBitField( &wrData, MAKOOPTCTL_PIN_STATEB_BITFIELD,data);
		               
		               
		            break;
			        
			        case MAKOOPTCTL_IOVGRP_PIN_STATEA:  // read only
			        
		               // don't perform a write for a read only
	                   writable = false;
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOV_OPTB_INTEN:  // write only
			        
		               setBitField( &wrData, MAKOOPTCTL_OPTB_INTEN_BITFIELD,data);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOV_OPTB_INTFLAG:  // read/write
			        
		               setBitField( &wrData, MAKOOPTCTL_OPTB_INTFLAG_BITFIELD,data);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOVGRP_OPT_STATEB:  // read only
			        
		               // don't perform a write for a read only
	                   writable = false;
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOV_OPTA_INTEN:  // write only
			        
		               setBitField( &wrData, MAKOOPTCTL_OPTA_INTEN_BITFIELD,data);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOV_OPTA_INTFLAG:  // read/write
			        
		               setBitField( &wrData, MAKOOPTCTL_OPTA_INTFLG_BITFIELD,data);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOVGRP_OPT_STATEA:  // read only
			        
		               // don't perform a write for a read only
	                   writable = false;	            

	                break;
			        
			        // *********************************
		            //            opt_ctrl2 fields
		            // *********************************
			        case MAKOOPTCTL_IOVGRP_GPIO_DIR:  // write only
			        
		               setBitField( &wrData, MAKO_GPIO_DIR_BITFIELD,data);
		               
		            break;
			        	        
			        case MAKOOPTCTL_IOVGRP_OPT_CONFIGB:  // write only
			        
		               setBitField( &wrData, MAKO_OPT_CONFIGB_BITFIELD,data);
		               
		            break;
			         	        
			        case MAKOOPTCTL_IOVGRP_OPT_CONFIGA:  // write only 
			             
		               setBitField( &wrData, MAKO_OPT_CONFIGA_BITFIELD,data);
		               
		            break;
			        
			        // *********************************
		            //            opt_ctrl3 fields
		            // *********************************
			        case MAKOOPTCTL_IOVGRP_PIN_MASKB:  // write only
			        
		               setBitField( &wrData, MAKOOPTCTL_PIN_MASKB_BITFIELD,data);
		               
		            break;
			         	        
			        case MAKOOPTCTL_IOVGRP_OPT_MASKB:  // write only
			        
		               setBitField( &wrData, MAKOOPTCTL_OPT_MASKB_BITFIELD,data);
		               
		            break;         
			        
			        case MAKOOPTCTL_IOVGRP_PIN_MASKA:  // write only
			        
		              setBitField( &wrData, MAKOOPTCTL_PIN_MASKA_BITFIELD,data);
		              
		            break;
			         	        
			        case MAKOOPTCTL_IOVGRP_OPT_MASKA:  // write only
			                 
		              setBitField( &wrData, MAKOOPTCTL_OPT_MASKA_BITFIELD,data); 
		              
		            break;
			        

			      };

	              // if client attempted to send to a read only bit or group of bits then do nothing
	              // because that is invalid.

	              if( writable == true )
	              {	 
		              // write new data to the Mako IC using the spi connection provided to Mako class.
		              m_MakoOPTCTRL_parent->m_MakoParent->wrRegister(OPT_CTRL_REGISTER_ADDR, wrData);

	                  // update image with new value
	                  switch ( m_which_OPT_CTRL_reg )
	                  {
			            case 1:
			        
		                   m_MakoOPTCTRL_parent->opt_ctrl1_image = wrData;
		               
		                break;              

			            case 2:
			        
		                   m_MakoOPTCTRL_parent->opt_ctrl2_image = wrData;
		               
		                break;
		                          
			            case 3:
			        
		                   m_MakoOPTCTRL_parent->opt_ctrl3_image = wrData;
		               
		                break;              	                          
	                  };     
	              }
		      
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
