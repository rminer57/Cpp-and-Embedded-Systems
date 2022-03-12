// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::tomahawk::TomahawkWithDualPortConverter'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TomahawkWithDualPortConverter.h"
#endif

#include <HALtestLib_win32.h>
#include <TomahawkWithDualPortConverter.h>
#include <DelayBase.h>
#include <DesiredTxDevOption.h>
#include <INT32DivideBase.h>
#include <LongFract.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
TomahawkWithDualPortConverter::~TomahawkWithDualPortConverter( void )
{
}
// }}}RME

// {{{RME operation 'send(Array *)'
bool TomahawkWithDualPortConverter::send( Array * buffer )
{
	// {{{USR
	//ssi Data will be interleaved hi-lo and the send method will be called on the m_ssiConnection
	//getLength to know how many samples to process
	int ssiDataLength = (int16_t)buffer->getLength();

	if (buffer->isType(SIntArray::SIGNED_INT_ARRAY)) // check if the buffer is, in fact, pointing to an SIntArray
	{
		//Create new output to ssiData pointer that holds twice the size of the input buffer
		RealSignal * ssiDataOutputPtr = new RealSignal(2*ssiDataLength );

		//Create temporay output array for lo port 
		RealSignal * loPortssiDataOutTempPtr = new RealSignal(ssiDataLength );

		//Create temporay input array for lo port 
		SIntArray* sIntArrayPtr = (SIntArray*) buffer; // Cast the input array as SIntArrayPtr*
		RealSignal loPortssiDataInTempPtr(sIntArrayPtr );

		//delay lo port to create hi port output
		m_delay->delayBuffer(loPortssiDataInTempPtr,*loPortssiDataOutTempPtr);

		int i,j=0;
		Fract mul1,mul2,ans;
		LongFract ansLong;
		//for loop count will be twice as long as input buffer
		//because we will be interleaving the lo and hi port values
		for(i=0;i<2*ssiDataLength ;i++)
		{

			//scale output and interleave lo port
			mul2 = (int16_t)(m_lowPortScaler>>16);
			mul1 = loPortssiDataInTempPtr[j];
			ansLong.longFractMult(mul1,mul2);
			ans.x =	(int16_t)ansLong.x;
			(*ssiDataOutputPtr)[i] = ans;


			//interleave hi port with the delayed  data from buffer
			//convert 16 bit output to rounded 12 bit
			int16_t roundedHiPort=(*loPortssiDataOutTempPtr)[j].x&BIT3;
			(*loPortssiDataOutTempPtr)[j].x &= MASKB3;		
			if(roundedHiPort==BIT3)
			{
				(*loPortssiDataOutTempPtr)[j].x |= BIT4;
			}
			(*ssiDataOutputPtr)[i+1] = (*loPortssiDataOutTempPtr)[j];

			j++;
			i++;
		}

		m_ssiConnection->send(ssiDataOutputPtr->convertThis2SIntArrayPtr());

	    loPortssiDataOutTempPtr->delete_buffer();
		delete loPortssiDataOutTempPtr;
		loPortssiDataInTempPtr.delete_buffer();
	    delete ssiDataOutputPtr;
		return true;
	}
	else
	    {
		return false;
	    }

	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
Array * TomahawkWithDualPortConverter::receive( void )
{
	// {{{USR
	return m_ssiConnection->receive();
	// }}}USR
}
// }}}RME

// {{{RME operation 'setOption(Configurable::Option *)'
bool TomahawkWithDualPortConverter::setOption( Configurable::Option * option )
{
	// {{{USR
	if (option->getType() == DesiredTxDevOption::DESIRED_TX_DEV_OPTION)
	{
		//retrieve the dev and nominal values 
		m_desiredTxDeviation = ((DesiredTxDevOption *)option)->desiredTxDeviation;
		m_nominalInputLevel = ((DesiredTxDevOption *)option)->nominalInputLevel;
		delete option;

		int32_t mrefDiv = tomahawk::readImage(MREF_DIV,m_rfState);
		int32_t lpAdd = tomahawk::readImage(LP_ADD,m_rfState);
		//call function to do lo port scaler calculation
		//function checks dev calculation if does not fall in params return false
		return calculateLowPortScaler(mrefDiv,lpAdd);

	}
	else
	{
		return(m_ssiConnection->setOption(option));
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'getOption(ClassType)'
Configurable::Option * TomahawkWithDualPortConverter::getOption( ClassType optionType ) const
{
	// {{{USR
	Configurable::Option *option;

	if (optionType == DesiredTxDevOption::DESIRED_TX_DEV_OPTION)
	{
		//then produce DESIRED_TX_DEV_OPTION
	    option = new DesiredTxDevOption(m_desiredTxDeviation,m_nominalInputLevel);  
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

// {{{RME operation 'getStatus()'
Connection::Status * TomahawkWithDualPortConverter::getStatus( void )
{
	// {{{USR
	return m_ssiConnection->getStatus();
	// }}}USR
}
// }}}RME

// {{{RME operation 'setRFState(int32_t)'
int32_t TomahawkWithDualPortConverter::setRFState( int32_t rfState )
{
	// {{{USR
	m_rfState = rfState;

	//retrieving MREF_DIV and LP_ADD register values
	int32_t mrefDiv = tomahawk::readImage(MREF_DIV,m_rfState);
	int32_t lpAdd = tomahawk::readImage(LP_ADD,m_rfState);

	//calculates value of m_lowPortScaler by
	calculateLowPortScaler(mrefDiv,lpAdd);

	//call setRFState to send image to tomahawk ic
	return tomahawk::setRFState(rfState);

	// }}}USR
}
// }}}RME

// {{{RME operation 'TomahawkWithDualPortConverter(tomahawkDefault*,rfSpiBuffer**,int,int,int,int,DelayBase *,INT32DivideBase *,Connection *,signed int,signed int,int32_t)'
TomahawkWithDualPortConverter::TomahawkWithDualPortConverter( tomahawkDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates, int numberOfDiscretes, int numberOfGPOs, int numberOfGains, DelayBase * delayPtr, INT32DivideBase * divPtr, Connection * ssiConnection, signed int maxInputLevel, signed int nominalInputLevel, int32_t rfState )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:tomahawk(init, spiBuffers, numberOfRfStates, numberOfDiscretes, numberOfGPOs, numberOfGains),
	 m_delay(delayPtr),
	 dividePtr(divPtr),
	 m_ssiConnection(ssiConnection),
	 m_maxInputLevel(maxInputLevel),
	 m_nominalInputLevel(nominalInputLevel),
	 m_rfState(rfState),
	 m_desiredTxDeviation(0)

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'TomahawkWithDualPortConverter(tomahawkDefault*,rfSpiBuffer**,int,DelayBase *,INT32DivideBase *,Connection *,signed int,signed int,int32_t)'
TomahawkWithDualPortConverter::TomahawkWithDualPortConverter( tomahawkDefault * init, rfSpiBuffer * * spiBuffers, int numberOfRfStates, DelayBase * delayPtr, INT32DivideBase * divPtr, Connection * ssiConnection, signed int maxInputLevel, signed int nominalInputLevel, int32_t rfState )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	:tomahawk(init, spiBuffers, numberOfRfStates),
	 m_delay(delayPtr),
	 dividePtr(divPtr),
	 m_ssiConnection(ssiConnection),
	 m_maxInputLevel(maxInputLevel),
	 m_nominalInputLevel(nominalInputLevel),
	 m_rfState(rfState),
	 m_desiredTxDeviation(0)
	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'calculateLowPortScaler(int32_t,int32_t)'
bool TomahawkWithDualPortConverter::calculateLowPortScaler( int32_t mrefDiv, int32_t lpAdd )
{
	// {{{USR
	int32_t lpAddMultiplier=1;
	int i;
	for(i=0;i<lpAdd;i++)
		lpAddMultiplier*=2;

	if(mrefDiv>0 && mrefDiv<=5)
		m_maxDev = (TOMAHAWK_MULTIPLIER*lpAddMultiplier)/(mrefDiv);
	else
		m_maxDev = TOMAHAWK_MULTIPLIER*lpAddMultiplier;

	LongFract txDev(m_desiredTxDeviation),maxDev(m_maxDev),maxInput(m_maxInputLevel),nomInput(m_nominalInputLevel);
	LongFract quotient1,rem1,quotient2,rem2;
	LongFract ans;

	//if desired tx dev is less than max dev
	if(m_desiredTxDeviation<=m_maxDev)
	{	
		//(m_desiredTxDeviation/m_maxDev)
		dividePtr->divide(quotient1.x,rem1,txDev.x,maxDev.x);

		//(m_maxInputLevel/m_nominalInputLevel)
		dividePtr->divide(quotient2.x,rem2,maxInput.x,nomInput.x);
		
		ans.longFractMult32(rem2,rem1);
		m_lowPortScaler = quotient2.x*rem1.x;
		m_lowPortScaler += ans.x;

		//m_lowPortScaler= (m_desiredTxDeviation/m_maxDev)*(m_maxInputLevel/m_nominalInputLevel);
		return true;
	}
	else
	{
		m_lowPortScaler=0;
		return false;
	}
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
