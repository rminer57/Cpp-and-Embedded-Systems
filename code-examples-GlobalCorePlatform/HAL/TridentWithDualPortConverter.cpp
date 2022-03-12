// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::Trident::TridentWithDualPortConverter'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TridentWithDualPortConverter.h"
#endif

#include <rf_sequencer_comp.h>
#include <TridentWithDualPortConverter.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'TridentDualPortConfig' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tridentDualPortSettingsEnum_t' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'TridentDualPortDefines' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'TridentDualPortConfig'

// {{{RME classAttribute 'TRIDENT_DUALPORTCONFIG_OPTION'
const unsigned int TridentWithDualPortConverter::TridentDualPortConfig::TRIDENT_DUALPORTCONFIG_OPTION = 5678;
// }}}RME

// {{{RME operation 'TridentDualPortConfig(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int)'
TridentWithDualPortConverter::TridentDualPortConfig::TridentDualPortConfig( unsigned int TxDeviation, unsigned int nominalInputLevel, unsigned int lowPortScalingFactor, unsigned int lowPortPhaseOffset, unsigned int lowPortRoundedSSIdataSize, unsigned int hiPortScalingFactor, unsigned int hiPortPhaseOffset, unsigned int hiPortRoundedSSIdataSize, unsigned int modulationBalanceAtten, unsigned int modulationLimit, unsigned int fosc )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_TxDeviation(TxDeviation), m_nominalInputLevel(nominalInputLevel ), m_lowPortScalingFactor(lowPortScalingFactor), m_lowPortPhaseOffset( lowPortPhaseOffset ),m_lowPortRoundedSSIdataSize(lowPortRoundedSSIdataSize) ,m_hiPortPhaseOffset(hiPortPhaseOffset), m_hiPortRoundedSSIdataSize(hiPortRoundedSSIdataSize), m_modulationBalanceAtten(modulationBalanceAtten), m_modulationLimit(modulationLimit), m_fosc(fosc)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// Initializations are in the C++ tab
	// }}}USR
}
// }}}RME

// {{{RME operation 'TridentDualPortConfig(const TridentDualPortConfig &)'
TridentWithDualPortConverter::TridentDualPortConfig::TridentDualPortConfig( const TridentDualPortConfig & rtg_arg )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_TxDeviation(rtg_arg.m_TxDeviation)
	, m_nominalInputLevel(rtg_arg.m_nominalInputLevel)
	, m_lowPortScalingFactor( rtg_arg.m_lowPortScalingFactor )
	, m_lowPortPhaseOffset( rtg_arg.m_lowPortPhaseOffset )
	, m_lowPortRoundedSSIdataSize(rtg_arg.m_lowPortRoundedSSIdataSize)
	, m_hiPortScalingFactor( rtg_arg.m_hiPortScalingFactor)
	, m_hiPortPhaseOffset( rtg_arg.m_hiPortPhaseOffset )
	, m_hiPortRoundedSSIdataSize(rtg_arg.m_lowPortRoundedSSIdataSize)
	, m_modulationBalanceAtten( rtg_arg.m_modulationBalanceAtten )
	, m_modulationLimit( rtg_arg.m_modulationLimit )
	, m_fosc( rtg_arg.m_fosc )


	// }}}USR
	// }}}RME
{
	// {{{USR

	// Initializations are in the C++ tab


	// }}}USR
}
// }}}RME

// {{{RME operation 'operator!=(const TridentDualPortConfig &)'
bool TridentWithDualPortConverter::TridentDualPortConfig::operator!=( const TridentDualPortConfig & rtg_arg )
{
	// {{{USR
	bool isnotequal = false; 


	if( *this == rtg_arg )
	{
	  isnotequal = false;
	}
	else
	{
	  isnotequal = true; 
	}

	return isnotequal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator==(const TridentDualPortConfig &)'
bool TridentWithDualPortConverter::TridentDualPortConfig::operator==( const TridentDualPortConfig & rtg_arg )
{
	// {{{USR
	bool isequal = false; 


	if
	(
	  (m_TxDeviation == rtg_arg.m_TxDeviation) && 
	  (m_nominalInputLevel == rtg_arg.m_nominalInputLevel) &&  
	  (m_lowPortScalingFactor == rtg_arg.m_lowPortScalingFactor) &&
	  (m_lowPortPhaseOffset == rtg_arg.m_lowPortPhaseOffset) && 
	  (m_lowPortRoundedSSIdataSize == rtg_arg.m_lowPortRoundedSSIdataSize) &&
	  (m_hiPortScalingFactor == rtg_arg.m_hiPortScalingFactor) && 
	  (m_hiPortPhaseOffset == rtg_arg.m_hiPortPhaseOffset) && 
	  (m_hiPortRoundedSSIdataSize == rtg_arg.m_hiPortRoundedSSIdataSize) &&
	  (m_modulationBalanceAtten == rtg_arg.m_modulationBalanceAtten) &&  
	  (m_modulationLimit == rtg_arg.m_modulationLimit) &&  
	  (m_fosc == rtg_arg.m_fosc) 
	)
	{
	  isequal = true;
	}
	else
	{
	  isequal = false; 
	}

	return isequal;
	// }}}USR
}
// }}}RME

// {{{RME operation '~TridentDualPortConfig()'
TridentWithDualPortConverter::TridentDualPortConfig::~TridentDualPortConfig( void )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool TridentWithDualPortConverter::TridentDualPortConfig::isType( ClassType type ) const
{
	// {{{USR

	return (type == TridentDualPortConfig::TRIDENT_DUALPORTCONFIG_OPTION)?true:Option::isType(type);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType TridentWithDualPortConverter::TridentDualPortConfig::getType( void ) const
{
	// {{{USR

	return TridentDualPortConfig::TRIDENT_DUALPORTCONFIG_OPTION;
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator=(const TridentDualPortConfig &)'
TridentWithDualPortConverter::TridentDualPortConfig & TridentWithDualPortConverter::TridentDualPortConfig::operator=( const TridentDualPortConfig & rtg_arg )
{
	// {{{USR
		if( this != &rtg_arg )
		{
		    // assignments 
	        m_TxDeviation = rtg_arg.m_TxDeviation;
	        m_nominalInputLevel = rtg_arg.m_nominalInputLevel;
			m_lowPortScalingFactor = rtg_arg.m_lowPortScalingFactor;
			m_lowPortPhaseOffset = rtg_arg.m_lowPortPhaseOffset;
			m_lowPortRoundedSSIdataSize = rtg_arg.m_lowPortRoundedSSIdataSize;
			m_hiPortScalingFactor = rtg_arg.m_hiPortScalingFactor;
			m_hiPortPhaseOffset = rtg_arg.m_hiPortPhaseOffset;
			m_hiPortRoundedSSIdataSize = rtg_arg.m_hiPortRoundedSSIdataSize;
			m_modulationBalanceAtten = rtg_arg.m_modulationBalanceAtten;
			m_modulationLimit = rtg_arg.m_modulationLimit;
			m_fosc = rtg_arg.m_fosc;


		}  
		return *this;
		
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME operation 'send(Array *)'
bool TridentWithDualPortConverter::send( Array * buffer )
{
	// {{{USR
	int n,j=0;
	bool retvalue = true;

	int16_t scaler = 0;
	int16_t sample = 0;
	int16_t ans = 0;
	int32_t ansLong = 0;
	int inputBufSize = 0;
	int outputBufSize = 0;

	if( buffer !=0 )
	{

	 
	  if (buffer->isType(SIntArray::SIGNED_INT_ARRAY)) // check if the buffer is, in fact, pointing to an SIntArray
	  {

	  	// Obtain SIntArray pointer to the input samples 
		SIntArray * sIntArrayPtr = (SIntArray*) buffer;
		
		inputBufSize = buffer->getLength(); 

	    // first, determine which delay is bigger, hi port or low port. In the past, only the
	    // low port samples were delayed. Once the larger is known, an output array can be allocated
	    // ssi Data will be interleaved lo-hi and the send method will be called on the m_ssiConnection
	    // getLength to know how many samples to process
	    if( m_dualPortActiveConfig->m_lowPortPhaseOffset >= m_dualPortActiveConfig->m_hiPortPhaseOffset)
	    {
	      outputBufSize = m_dualPortActiveConfig->m_lowPortPhaseOffset + 2 * inputBufSize; // low port delay is largest or same
	    }
	    else
	    {
	      outputBufSize = m_dualPortActiveConfig->m_hiPortPhaseOffset + 2 * inputBufSize; // hi port delay is largest
	    }

		//Create new output to ssiData pointer that holds twice the size of the input buffer
		// this buffer will be passed to the ssi connection.  Its size is twice that of the
		// input because low and hi port interleaved data must be produced from the input data.  
		// Thus, for each input sample, two output samples will result.
	    SIntArray * ssiDataOutputPtr = new SIntArray( outputBufSize,(int16_t)0 );

		//for loop count will be twice as long as input buffer
		//because interleaving of the lo and hi port data will occur.
	    for(n=0; n < outputBufSize ;n++)
	    {
			  // determine even or odd value for n. even samples (0,2,4...) should be processed as low port data
			  bool even = false;
			  if( n % 2 == 0 ) even = true;

	          // check to see if current sample n is low port
			  // low port samples are even samples greater than or equal to the delay value
			  // tomahawk applied a scaler to the low port samples but no delay
			  // algorithm is the same for trident
			  if( (n >= m_dualPortActiveConfig->m_lowPortPhaseOffset) && even )
			  {
			    // low port sample, scale output
	    		scaler = (int16_t)(m_dualPortActiveConfig->m_lowPortScalingFactor >> 16);
				sample = (*sIntArrayPtr)[n];
	    		ansLong = (((int32_t)scaler * sample) << 1);
	    		ans =	(int16_t)ansLong;

	            // if size is not equal to the default of 16 bits, then perform rounding to 12 bit.
				// only hi port samples needed to be rounded in the original algorithm
				if(  m_dualPortActiveConfig->m_lowPortRoundedSSIdataSize != TDPC_LOWPORTSSIDATASIZE_DEFAULT )
				{
				  // only hi port samples needed to be rounded in the original algorithm
			      // convert 16 bit output to rounded 12 bit
	               ans &= MASKB3;
				   				
	               if( (ans & BIT3) == BIT3 ) {  ans |= BIT4; }
	              
				}

	    		(*ssiDataOutputPtr)[n] = ans;

			  }
			  else
			  {
			    // hi port sample
				// tomahawk applied a delay to the hi port samples but no scaler
				// tomahawk also rounded the hi port samples
				// algorithm is the same for trident
				if( n >= m_dualPortActiveConfig->m_lowPortPhaseOffset )
				{
			      // low port sample, scale output
	    		  scaler = (int16_t)(m_dualPortActiveConfig->m_hiPortScalingFactor >> 16);
				  sample = (*sIntArrayPtr)[n];
	    		  ansLong = (((int32_t)scaler * sample) << 1);
	    		  ans =	(int16_t)ansLong;

	              // if size is not equal to the default of 16 bits, then perform rounding to 12 bit.
				  // only hi port samples needed to be rounded in the original algorithm
				  if(  m_dualPortActiveConfig->m_hiPortRoundedSSIdataSize != TDPC_LOWPORTSSIDATASIZE_DEFAULT )
				  {
				   // only hi port samples needed to be rounded in the original algorithm
			       // convert 16 bit output to rounded 12 bit
	               ans &= MASKB3;
				   				
	               if( (ans & BIT3) == BIT3 ) {  ans |= BIT4; }
	              
				  }
	    		  (*ssiDataOutputPtr)[n] = ans;


				}

			  }

	    } // end for(n=0; n < outputBufSize ;n++)

	    bool txstatus = m_ssiConnection->send( ssiDataOutputPtr );


	    if( txstatus == true ) // consume input buffer if ssi send was successful
		{
	    	  delete sIntArrayPtr;
			  retvalue = true;
		      m_error = TRIDENT_ERRCODE_NOERR;
	    }
		else
		{     // ssi send failed
			  retvalue = false;
		      m_error = TRIDENT_ERRCODE_CONNSSI;
		}


	  }
	  else
	  {
		retvalue = false; // buffer passed in was not of required type SIntArray
		m_error = TRIDENT_ERRCODE_BADARG_BUFFER;
	  }
	}
	else
	{
		retvalue = false;  // buffer passed in was null
		m_error = TRIDENT_ERRCODE_BADARG_BUFFER;
	}

	return retvalue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
Array * TridentWithDualPortConverter::receive( void )
{
	// {{{USR
	return m_ssiConnection->receive();
	// }}}USR
}
// }}}RME

// {{{RME operation 'setOption(Configurable::Option *)'
bool TridentWithDualPortConverter::setOption( Configurable::Option * option )
{
	// {{{USR
	bool retvalue = false;


	if ( option->getType() == TridentDualPortConfig::TRIDENT_DUALPORTCONFIG_OPTION)
	{
	    // copy attributes
	    m_dualPortRFStateArray[Trident::m_currentRfState]->m_TxDeviation = ((TridentDualPortConfig *)option)->m_TxDeviation;
	    m_dualPortRFStateArray[Trident::m_currentRfState]->m_nominalInputLevel = ((TridentDualPortConfig *)option)->m_nominalInputLevel;
		m_dualPortRFStateArray[Trident::m_currentRfState]->m_lowPortScalingFactor = ((TridentDualPortConfig *)option)->m_lowPortScalingFactor;
		m_dualPortRFStateArray[Trident::m_currentRfState]->m_lowPortPhaseOffset = ((TridentDualPortConfig *)option)->m_lowPortPhaseOffset;
		m_dualPortRFStateArray[Trident::m_currentRfState]->m_lowPortRoundedSSIdataSize = ((TridentDualPortConfig *)option)->m_lowPortRoundedSSIdataSize;
		m_dualPortRFStateArray[Trident::m_currentRfState]->m_hiPortScalingFactor = ((TridentDualPortConfig *)option)->m_hiPortScalingFactor;
		m_dualPortRFStateArray[Trident::m_currentRfState]->m_hiPortPhaseOffset = ((TridentDualPortConfig *)option)->m_hiPortPhaseOffset;
		m_dualPortRFStateArray[Trident::m_currentRfState]->m_hiPortRoundedSSIdataSize = ((TridentDualPortConfig *)option)->m_hiPortRoundedSSIdataSize;
		m_dualPortRFStateArray[Trident::m_currentRfState]->m_modulationBalanceAtten = ((TridentDualPortConfig *)option)->m_modulationBalanceAtten;
		m_dualPortRFStateArray[Trident::m_currentRfState]->m_modulationLimit = ((TridentDualPortConfig *)option)->m_modulationLimit;
		m_dualPortRFStateArray[Trident::m_currentRfState]->m_fosc = ((TridentDualPortConfig *)option)->m_fosc;
			
		delete option;

		retvalue = true;

	}

	else
	{
		retvalue = m_ssiConnection->setOption(option);
	}

	return retvalue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus()'
Connection::Status * TridentWithDualPortConverter::getStatus( void )
{
	// {{{USR
	return m_ssiConnection->getStatus();
	// }}}USR
}
// }}}RME

// {{{RME operation 'setRFState(int32_t)'
int32_t TridentWithDualPortConverter::setRFState( int32_t rfState )
{
	// {{{USR
	// return value is supposed to be the previous rfState but if the
	// argument is invalid then the argument will be returned.
	int32_t prevState = rfState;

	// validate rfState argument
	if( (rfState >= 0) && ( rfState <= m_numberOfRfStates) )
	{

	  // add code to compare settings in m_dualPortActiveConfig to
	  // m_dualPortRFStateArray[rfState] and overwrite if necessary 
	  if( m_dualPortRFStateArray[rfState] != m_dualPortActiveConfig )
	  {
	     // create new active config.
	     m_dualPortActiveConfig = m_dualPortRFStateArray[rfState];
	  }

	 
	  // set the new RF state and return the previous Rf state
	  prevState = Trident::setRFState(rfState);

	  m_error = TRIDENT_ERRCODE_NOERR; 

	} // end if( (rfState >= 0) && ( rfState <= m_numberOfRfStates) )
	else
	{
	  // rfState is out of range
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;    
	}

	return prevState;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'TridentWithDualPortConverter(TridentDefaultImages*,rfSpiBuffer_int16 **,int,int,int,int,Connection *,TridentDualPortConfig **)'
TridentWithDualPortConverter::TridentWithDualPortConverter( TridentDefaultImages * init, rfSpiBuffer_int16 * * spiBuffers, int numberOfRfStates, int numberOfDiscretes, int numberOfGPOs, int numberOfGains, Connection * ssiConnection, TridentDualPortConfig * * configArrayPtr )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:Trident(init, spiBuffers, numberOfRfStates, numberOfDiscretes, numberOfGPOs, numberOfGains),
	 modulationBalanceAttenuator(numberOfRfStates),
	 m_ssiConnection(ssiConnection)

	// }}}USR
	// }}}RME
{
	// {{{USR


	cmnTridentWithDualPortConverterConstructor(configArrayPtr,numberOfRfStates);
	// }}}USR
}
// }}}RME

// {{{RME operation 'TridentWithDualPortConverter(TridentDefaultImages*,rfSpiBuffer_int16 **,int,Connection *,TridentDualPortConfig **)'
TridentWithDualPortConverter::TridentWithDualPortConverter( TridentDefaultImages * init, rfSpiBuffer_int16 * * spiBuffers, int numberOfRfStates, Connection * ssiConnection, TridentDualPortConfig * * configArrayPtr )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:Trident(init, spiBuffers, numberOfRfStates),  
	 modulationBalanceAttenuator(numberOfRfStates),
	 m_ssiConnection(ssiConnection)
	 
	// }}}USR
	// }}}RME
{
	// {{{USR


	cmnTridentWithDualPortConverterConstructor(configArrayPtr,numberOfRfStates);
	// }}}USR
}
// }}}RME

// {{{RME operation 'getOption(ClassType)'
Configurable::Option * TridentWithDualPortConverter::getOption( ClassType optionType ) const
{
	// {{{USR
	Configurable::Option *option;

	if (optionType == TridentDualPortConfig::TRIDENT_DUALPORTCONFIG_OPTION)
	{
	    TridentDualPortConfig * config;

		config = m_dualPortRFStateArray[Trident::m_currentRfState];

		//then produce an option object via copy constructor
	    option = new TridentDualPortConfig( *config );
	  
	}
	else
	{
		//passthrough to SSI data connection
	    option = m_ssiConnection->getOption(optionType);
	}

	return option;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setModBalance(Integer,Integer)'
Integer TridentWithDualPortConverter::setModBalance( Integer attenuation, Integer rfState )
{
	// {{{USR

	m_dualPortRFStateArray[rfState]->m_modulationBalanceAtten = attenuation;

	return modulationBalanceAttenuator::setModBalance(attenuation,rfState);
	// }}}USR
}
// }}}RME

// {{{RME operation '~TridentWithDualPortConverter()'
TridentWithDualPortConverter::~TridentWithDualPortConverter( void )
{
	// {{{USR
	if( m_dualPortRFStateArray != 0)
	{
	  delete [] m_dualPortRFStateArray;
	}

	if( m_dualPortActiveConfig != 0)
	{
	  delete m_dualPortActiveConfig;
	}

	m_dualPortRFStateArray = 0;
	m_dualPortActiveConfig  = 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setDeviceState(int,int,int)'
int TridentWithDualPortConverter::setDeviceState( int setting, int deviceId, int rfState )
{
	// {{{USR


	  //----------------------------- LOCAL VARIABLES ------------------------------

	Integer returnvalue = 0;
	 
	  //---------------------------------- CODE ------------------------------------  
	// validate rfState argument
	if( (rfState >= 0) && ( rfState <= m_numberOfRfStates) )
	{
	 
	  switch(deviceId)
	  {

	    m_error = TRIDENT_ERRCODE_NOERR;

	    case TridentWithDualPortConverter::TDPC_FOSC:  
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_fosc;

	       m_dualPortRFStateArray[rfState]->m_fosc = setting; 

		   break;
		}
	    case TridentWithDualPortConverter::TDPC_HIPORTPHASEOFFSET:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_hiPortPhaseOffset;

	       m_dualPortRFStateArray[rfState]->m_hiPortPhaseOffset = setting; 

		   break;
		}

	    case TridentWithDualPortConverter::TDPC_HIPORTROUNDEDSSIDATASIZE:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_hiPortRoundedSSIdataSize;

	       m_dualPortRFStateArray[rfState]->m_hiPortRoundedSSIdataSize = setting; 

		   break;
		}

	    case TridentWithDualPortConverter::TDPC_HIPORTSCALINGFACTOR:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_hiPortScalingFactor;

	       m_dualPortRFStateArray[rfState]->m_hiPortScalingFactor = setting; 

		   break;
		}

	    case TridentWithDualPortConverter::TDPC_LOWPORTPHASEOFFSET:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_lowPortPhaseOffset;

	       m_dualPortRFStateArray[rfState]->m_lowPortPhaseOffset = setting; 

		   break;
		}

	    case TridentWithDualPortConverter::TDPC_LOWPORTROUNDEDSSIDATASIZE:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_lowPortRoundedSSIdataSize;

	       m_dualPortRFStateArray[rfState]->m_lowPortRoundedSSIdataSize = setting; 

		   break;
		}

	    case TridentWithDualPortConverter::TDPC_LOWPORTSCALINGFACTOR:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_lowPortScalingFactor;

	       m_dualPortRFStateArray[rfState]->m_lowPortScalingFactor = setting; 

		   break;
		}

	    case TridentWithDualPortConverter::TDPC_MODBALANCEATTEN:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_modulationBalanceAtten;

	       m_dualPortRFStateArray[rfState]->m_modulationBalanceAtten = setting; 

		   break;
		}
	    case TridentWithDualPortConverter::TDPC_MODLIMIT:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_modulationLimit;

	       m_dualPortRFStateArray[rfState]->m_modulationLimit = setting; 

		   break;
		}
	    case TridentWithDualPortConverter::TDPC_NOMINALINPUTLVL:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_nominalInputLevel;

	       m_dualPortRFStateArray[rfState]->m_nominalInputLevel = setting; 

		   break;
		}
	    case TridentWithDualPortConverter::TDPC_TXDEVIATION:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_TxDeviation;

	       m_dualPortRFStateArray[rfState]->m_TxDeviation = setting; 

		   break;
		}

	    // if not dual port converter then invoke base class method.
	    default:
		{
	      
	      returnvalue = Trident::setDeviceState(setting,deviceId, rfState);

	      break;
		}

	  }  // END - switch

	} // end if( (rfState >= 0) && ( rfState <= m_numberOfRfStates) )
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}

	  return returnvalue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStatus(Integer,Integer)'
Integer TridentWithDualPortConverter::getStatus( Integer deviceId, Integer rfState )
{
	// {{{USR



	  //----------------------------- LOCAL VARIABLES ------------------------------

	Integer returnvalue = 0;
	 
	  //---------------------------------- CODE ------------------------------------  
	// validate rfState argument
	if( (rfState >= 0) && ( rfState <= m_numberOfRfStates) )
	{
	  m_error = TRIDENT_ERRCODE_NOERR;

	  switch(deviceId)
	  {

	   case TridentWithDualPortConverter::TDPC_FOSC:  
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_fosc;

		   break;
		}
	    case TridentWithDualPortConverter::TDPC_HIPORTPHASEOFFSET:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_hiPortPhaseOffset;

		   break;
		}

	    case TridentWithDualPortConverter::TDPC_HIPORTROUNDEDSSIDATASIZE:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_hiPortRoundedSSIdataSize;

	 	   break;
		}

	    case TridentWithDualPortConverter::TDPC_HIPORTSCALINGFACTOR:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_hiPortScalingFactor;

		   break;
		}

	    case TridentWithDualPortConverter::TDPC_LOWPORTPHASEOFFSET:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_lowPortPhaseOffset;

		   break;
		}

	    case TridentWithDualPortConverter::TDPC_LOWPORTROUNDEDSSIDATASIZE:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_lowPortRoundedSSIdataSize;

		   break;
		}

	    case TridentWithDualPortConverter::TDPC_LOWPORTSCALINGFACTOR:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_lowPortScalingFactor;

		   break;
		}

	    case TridentWithDualPortConverter::TDPC_MODBALANCEATTEN:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_modulationBalanceAtten;

		   break;
		}
	    case TridentWithDualPortConverter::TDPC_MODLIMIT:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_modulationLimit;

		   break;
		}
	    case TridentWithDualPortConverter::TDPC_NOMINALINPUTLVL:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_nominalInputLevel;

		   break;
		}
	    case TridentWithDualPortConverter::TDPC_TXDEVIATION:
	 	{ 
	       returnvalue = m_dualPortRFStateArray[rfState]->m_TxDeviation;

		   break;
		}  

	    // if not dual port converter then invoke base class method.
	    default:
		{
	      
	      returnvalue = Trident::getStatus(deviceId, rfState);

	      break;
		}

	  }  // END - switch

	} // end if( (rfState >= 0) && ( rfState <= m_numberOfRfStates) )
	else
	{
	  m_error = TRIDENT_ERRCODE_BADARG_RFSTATE;
	}



	  return returnvalue;
	// }}}USR
}
// }}}RME

// {{{RME operation 'cmnTridentWithDualPortConverterConstructor(TridentDualPortConfig **,int)'
void TridentWithDualPortConverter::cmnTridentWithDualPortConverterConstructor( TridentDualPortConfig * * configArrayPtr, int numberOfRfStates )
{
	// {{{USR
	int i;

	m_dualPortRFStateArray = new TridentDualPortConfig *[numberOfRfStates];

	if( configArrayPtr == 0 )
	{  

	  // initialize all rfState configurations.
	  // use default config since client did not supply one.
	 for(i = 0; i < numberOfRfStates; i++)
	 {
	   m_dualPortRFStateArray[i] = new TridentDualPortConfig();
	 }

	}
	else
	{
	 // initialize all rfState configurations.
	 // clients can change later. used to store changes...these are analogous
	 // to the Trident register image buffers.
	 // use client supplied config for all rf states.
	 // use default config since client did not supply one.
	 for(i = 0; i < numberOfRfStates; i++)
	 {
	   m_dualPortRFStateArray[i] = configArrayPtr[i];
	 }

	}

	// setup active config to default values.
	// active config is analogous to actual IC registers in a chip
	m_dualPortActiveConfig = new TridentDualPortConfig();

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'TridentDualPortConfig' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'tridentDualPortSettingsEnum_t' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'TridentDualPortDefines' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
