// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::Trident::TridentPrivate::TridentIOVirtualSerial'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TridentIOVirtualSerial.h"
#endif

#include <rf_sequencer_comp.h>
#include <TridentIOVirtualSerial.h>
#include <SIntArray.h>
#include <Trident.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'activate()'
bool TridentIOVirtualSerial::activate( void )
{
	// {{{USR


	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'deactivate()'
bool TridentIOVirtualSerial::deactivate( void )
{
	// {{{USR


	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus()'
Connection::Status * TridentIOVirtualSerial::getStatus( void )
{
	// {{{USR


	Connection::Status * statusobj = 0;


	return statusobj;
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
Array * TridentIOVirtualSerial::receive( void )
{
	// {{{USR

	Array * retdata = 0; 

	// if receive fails, a null is returned.
	retdata = m_tridentParent->sendAndReceiveSPI();

	return retdata;
	// }}}USR
}
// }}}RME

// {{{RME operation 'send(Array *)'
bool TridentIOVirtualSerial::send( Array * buf )
{
	// {{{USR

	SIntArray * theArray = 0;

	bool retstatus = false;


	// validate buffer object
	if( buf != 0 )
	{

	   if ( buf->isType(SIntArray::SIGNED_INT_ARRAY)  )
	   {

	        SIntArray * clientbuffer = (SIntArray*)buf;       //Type safe up cast

	        // if m_auxSpiBufferSizeNormal = true then we need to create a new SIntArray with space for the header
	        if( m_auxSpiBufferSizeNormal == true )
	        {
	           // must create new SIntArray of size one greater than client buffer
	           // to make space for header
	           unsigned int length = clientbuffer->getLength();
	           SIntArray * biggerBuf = new SIntArray(length + 1);

	           // copy payload starting at index 1, leaving index 0 undisturbed
	           for(int i = 0; i < length; i++) (* biggerBuf)[i + 1] = (*clientbuffer)[i];

	           // set theArray pointer to be equal to bifferBuf so that
	           // outside the if statement, a single line of code for send can be used
	           theArray = biggerBuf;

	           delete clientbuffer;  // done so delete the client buffer
	        }
	        else
	        {
	                
	           // set theArray pointer to be equal to bifferBuf so that
	           // outside the if statement, a single line of code for send can be used
	           theArray = clientbuffer;

	        }

	        // bits D0-D7 of the first index of the SIntArray must contain an 8 bit address header

	 
	        // write the 8 bit address/mode header required by all Trident SPI transactions.
	        (* theArray)[0] = m_headerAddress;


	        // send the data to the Trident aux port address.
	        // capture boolean result in the class attribute since cmnSendReceive
	        // returns an array. The overloaded send and receive methods of this class
	        // will return the contents of m_sendResult
	        SIntArray * p = m_tridentParent->sendAndReceiveSPI(theArray);
	                
	        // null pointer return on send indicates success.
	        if( p == 0 ) retstatus = true;

	   }

	}


	return retstatus;


	// }}}USR
}
// }}}RME

// {{{RME operation 'TridentIOVirtualSerial(int,Trident *,bool,bool)'
TridentIOVirtualSerial::TridentIOVirtualSerial( int whichIOVirtualSerial, Trident * tridentParent, bool auxSpiBufferSizeNormal, bool spiMode4wire )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_tridentParent(tridentParent), m_auxSpiBufferSizeNormal(auxSpiBufferSizeNormal), m_spiMode4wire(spiMode4wire)
	// }}}USR
	// }}}RME
{
	// {{{USR

	if( whichIOVirtualSerial == SPIAUX1 )
	{
	   m_headerAddress = TRIDENT_SPIAUX1_HEADER4WIRE;
	}
	else
	{
	   m_headerAddress = TRIDENT_SPIAUX2_HEADER4WIRE;
	}


	if( spiMode4wire == false )
	{
	   m_headerAddress += TRIDENT_SPIAUX_NON4WIREADDROFFSET;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation '~TridentIOVirtualSerial()'
TridentIOVirtualSerial::~TridentIOVirtualSerial( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
