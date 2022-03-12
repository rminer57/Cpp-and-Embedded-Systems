// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsMOTICs::genericTestsMako::genericTestMako'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "genericTestMako.h"
#endif

#include <HALtestLib_win32.h>
#include <genericTestMako.h>
#include <IOVirtualSerial.h>
#include <Mako.h>
#include <Mako1WireCtrl.h>
#include <MakoADC.h>
#include <MakoDCPwrCtrl.h>
#include <MakoFrontEndFilter.h>
#include <MakoIGNSenseCtrl.h>
#include <MakoIntrCtrl.h>
#include <MakoOPTCTRL.h>
#include <MakoRFPA.h>
#include <MakoRFPowerControl.h>
#include <MakoUSBConstants.h>
#include <MakoUSBCtrl.h>
#include <MakoUSBEvents.h>
#include <MakoWatchdogCtrl.h>
#include <PowerConfiguration.h>
#include <SCharArray.h>
#include <USBIOVirtualHandler.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestADC' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestAudio' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestOPTCTRL' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestDCPwrCtrl' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestIGNSense' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestWatchdogCtrl' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestIntrCtrl' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestOneWire' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestDAC' tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classifier 'MakoTestADC'

// {{{RME classAttribute 'ADC_0'
const int genericTestMako::MakoTestADC::ADC_0( 0 );
// }}}RME

// {{{RME classAttribute 'ADC_11_INVALID'
const int genericTestMako::MakoTestADC::ADC_11_INVALID( 11 );
// }}}RME

// {{{RME operation 'MakoTestADC(Mako *)'
genericTestMako::MakoTestADC::MakoTestADC( Mako * makoIC )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	m_theMakoIC = makoIC;

	// create the array of devices
	m_MakoADCArray = new MakoADC * [ 11 ]; // 11 ADC devices, 0 - 10
	// }}}USR
}
// }}}RME

// {{{RME operation 'execute()'
int genericTestMako::MakoTestADC::execute( void )
{
	// {{{USR
	targetConfigBase::sendStringToStderr("MakoADC allocation tests\r\n");

	testAllocation();


	testStartConversion(0); // startConversion method not yet implemented in MakoADC

	testisConversionDone(0); // isConversionDone method not yet implemented in MakoADC

	targetConfigBase::sendStringToStderr("MakoADC setState tests\r\n");
	testsetState(ADC_0);

	targetConfigBase::sendStringToStderr("MakoADC read tests\r\n");
	testRead(ADC_0);


	return 1;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testisConversionDone(int)'
bool genericTestMako::MakoTestADC::testisConversionDone( int device )
{
	// {{{USR
	//unsigned int rxval;

	//m_parent->theSerialDebugObj->readValueUINT32 = 0;

	//rxval = m_MakoADCArray[device]->receive();

	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testRead(int)'
bool genericTestMako::MakoTestADC::testRead( int device )
{
	// {{{USR

	unsigned int rxval;

	//setReceiveReturnVal( 0x00000000 ); 

	rxval = m_MakoADCArray[device]->receive();

	//getBitField( &rxval, MAKO_AD_DATA_BITFIELD); 

	//targetConfigBase::sendStringToStderr("received");
	//targetConfigBase::sendStringToStderr(HEXOUTPUT);
	//targetConfigBase::sendStringToStderr(ENDL);
	//targetConfigBase::sendStringToStderr(FLUSH);


	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testsetState(int)'
bool genericTestMako::MakoTestADC::testsetState( int device )
{
	// {{{USR


	targetConfigBase::sendStringToStderr("     testsetState() enable, sets D23\r\n");

	m_MakoADCArray[device]->setState( MAKO_AD_ENABLE );

	targetConfigBase::sendStringToStderr("     testsetState() disable, clears D23\r\n");

	m_MakoADCArray[device]->setState( MAKO_AD_DISABLE );



	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testStartConversion(int)'
bool genericTestMako::MakoTestADC::testStartConversion( int device )
{
	// {{{USR

	//#define MAKO_ASC_STARTCONVERSION 1
	//#define MAKO_ASC_CONVERSION_DONE 0

	//m_parent->theSerialDebugObj->readValueUINT32 = 0;

	return true;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testAllocation(unsigned int,unsigned int)'
bool genericTestMako::MakoTestADC::testAllocation( unsigned int adcSelect, unsigned int adcDataDefault )
{
	// {{{USR
	   bool retval = PASS;
	   bool tempval = PASS;

	  // test case 1
	  // make sure all devices can be allocated
	  targetConfigBase::sendStringToStderr("MakoADC basic allocation test case 1, allocate all ADC's...");
	  for(int i = 0; i < NUMBER_OF_ADCS; i++) 
	  {
	    adcSelect = i;
	    adcDataDefault = 0; // set to zero so we can see the changes

	    m_MakoADCArray[i] = m_theMakoIC->getADC( adcSelect, adcDataDefault);

	    // if a zero is returned (null pointer) it means this device could not be allocated.
	    // thats BAD because they all should be unallocated
	    if( m_MakoADCArray[i] == 0 )
	    {
	      targetConfigBase::sendStringToStderr("FAILED\\n\r");
	      retval = FAIL;
	      tempval = FAIL;
	      break;
	    }

	  }
	  if( tempval != FAIL) targetConfigBase::sendStringToStderr("passed\n\r"); 

	  // test case 2
	  // make sure null pointer returned on all allocated devices

	  tempval = PASS;

	  targetConfigBase::sendStringToStderr("MakoADC double allocation test case 2...");

	  for(int j = 0; j < NUMBER_OF_ADCS; j++) 
	  {
	    adcSelect = j;
	    adcDataDefault = 0; // set to zero so we can see the changes

	    // since all devices are allocated following test case 1, they should all return
	    // a null pointer.  If they don't, then the allocation detection failed.
	    if( m_theMakoIC->getADC( adcSelect, adcDataDefault) != 0 )
	    {
	      targetConfigBase::sendStringToStderr("FAILED\n\r");
	      retval = FAIL; 
	      tempval = FAIL;
	      break;
	    }

	  }
	  if( tempval != FAIL) targetConfigBase::sendStringToStderr("passed\n\r"); 


	  // test case 3, out of bounds adc device allocation.
	  targetConfigBase::sendStringToStderr("MakoADC allocation test case 3, out of bounds device (0-10 valid) select...");

	 
	  if( m_theMakoIC->getADC( ADC_11_INVALID, adcDataDefault) != 0 )
	  {
	     targetConfigBase::sendStringToStderr("FAILED\n\r");
	     retval = FAIL;
	  }
	  else
	  {
	     targetConfigBase::sendStringToStderr("passed\n\r");
	  }


	return retval;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'MakoTestAudio'

// {{{RME operation 'MakoTestAudio()'
genericTestMako::MakoTestAudio::MakoTestAudio( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	m_MakoAudioInputCtrl = 0;
	m_MakoAudioOutputCtrl = 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'execute()'
int genericTestMako::MakoTestAudio::execute( void )
{
	// {{{USR
	//targetConfigBase::sendStringToStderr("Mako audio tests\r\n");

	//testAllocation();


	//targetConfigBase::sendStringToStderr(" --- Mic interface tests\r\n");
	//testMicInterfaces();


	//targetConfigBase::sendStringToStderr(" --- Spkr interface tests\r\n");
	//testSpkrInterfaces();


	return 1;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testSpkrInterfaces()'
bool genericTestMako::MakoTestAudio::testSpkrInterfaces( void )
{
	// {{{USR
	bool retval = PASS;
	bool tempval = PASS;

	bool boolwrsetting, boolrdsetting;

	int DigitalgainTable[] = { 0,1,2,3,4,5,6 } ; 
	int sizeofDigitalgainTable = sizeof(DigitalgainTable)/sizeof(int);

	int G3gainTable[] = { 0,2,4,6,8,10 } ;

	int sizeofG3gainTable = sizeof(G3gainTable)/sizeof(int);

	int G4gainTable[] = { 20,22,24,26 } ;

	int sizeofG4gainTable = sizeof(G4gainTable)/sizeof(int);

	int G5gainTable[] = { 0,-2,-4,-6,-8,-10,-12,-14,-16,-18,-20,-22,-24,-26,-28,-30,-32,-34,-36,-38,-40,-46,-52 } ;

	int sizeofG5gainTable = sizeof(G5gainTable)/sizeof(int);

	  // *************************************************
	  // case 1, Spkr set/get tests 
	  // *************************************************

	   targetConfigBase::sendStringToStderr("		   Spkr set/get test...");

	  tempval = PASS;
	 
	  m_MakoAudioOutputCtrl->setSpkrSelected(0);
	 
	  if(m_MakoAudioOutputCtrl->getSpkrSelected() != 0)
	  {
	    retval = FAIL; tempval = FAIL;
	  }

	  boolwrsetting = true;
	  m_MakoAudioOutputCtrl->setSpkrSelected(boolwrsetting);
	  boolrdsetting = m_MakoAudioOutputCtrl->getSpkrSelected();

	  if(boolrdsetting != boolwrsetting)
	  {
	    retval = FAIL; tempval = FAIL;
	  }

	  if( tempval == PASS)
	  {
	   targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	   targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }


	  // *************************************************
	  // case 2, setFilterType/getFilterType tests 
	  // *************************************************

	   targetConfigBase::sendStringToStderr("		filter set/get test....");

	  tempval = PASS;
	  boolwrsetting = false;

	  m_MakoAudioOutputCtrl->setFilterType(boolwrsetting);
	  boolrdsetting = m_MakoAudioOutputCtrl->getFilterType();

	  if( boolwrsetting != boolrdsetting)
	  {
	    retval = FAIL; tempval = FAIL;

	  }

	  if( tempval == PASS)
	  {
	   targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	   targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }

	  // *************************************************
	  // case 3, setStandbyMode/getStandbyMode tests 
	  // *************************************************
	   targetConfigBase::sendStringToStderr("  standbyMode set/get test....");

	  tempval = PASS;
	  boolwrsetting = false;

	  m_MakoAudioOutputCtrl->setFilterType(boolwrsetting);
	  boolrdsetting = m_MakoAudioOutputCtrl->getFilterType();

	  if( boolwrsetting != boolrdsetting)
	  {
	    retval = FAIL; tempval = FAIL;

	  }

	  if( tempval == PASS)
	  {
	   targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	   targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }
	  
	  // *************************************************
	  // case 4, setLoopbackMode/getLoopbackMode tests 
	  // *************************************************
	   targetConfigBase::sendStringToStderr("	LoopbackMode set/get test....");

	  tempval = PASS;
	  boolwrsetting = false;

	  m_MakoAudioOutputCtrl->setLoopbackMode(boolwrsetting);
	  boolrdsetting = m_MakoAudioOutputCtrl->getLoopbackMode();

	  if( boolwrsetting != boolrdsetting)
	  {
	    retval = FAIL; tempval = FAIL;

	  }

	  if( tempval == PASS)
	  {
	       targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	       targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }
	  
	  // *************************************************
	  // case 5, setMasterOnMode/getMasterOnMode tests 
	  // *************************************************
	    targetConfigBase::sendStringToStderr("	MasterOnMode set/get test....");

	  tempval = PASS;
	  boolwrsetting = false;

	  m_MakoAudioOutputCtrl->setMasterOnMode(boolwrsetting);
	  boolrdsetting = m_MakoAudioOutputCtrl->getMasterOnMode();

	  if( boolwrsetting != boolrdsetting)
	  {
	    retval = FAIL; tempval = FAIL;

	  }

	  if( tempval == PASS)
	  {
	       targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	       targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }
	  
	  // *************************************************
	  // case 6, setDeemphasisMode/getDeemphasisMode tests 
	  // *************************************************
	    targetConfigBase::sendStringToStderr("	DeemphasisMode set/get test....");

	  tempval = PASS;
	  boolwrsetting = false;

	  m_MakoAudioOutputCtrl->setDeemphasisMode(boolwrsetting);
	  boolrdsetting = m_MakoAudioOutputCtrl->getDeemphasisMode();

	  if( boolwrsetting != boolrdsetting)
	  {
	    retval = FAIL; tempval = FAIL;

	  }

	  if( tempval == PASS)
	  {
	       targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	       targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }

	  // *************************************************
	  // case 7, digital gain tests 
	  // *************************************************

	     targetConfigBase::sendStringToStderr("		digital gain test......");

	  tempval = PASS;

	  for(int i = 0; i < sizeofDigitalgainTable; i++)
	  {
	    
	    m_MakoAudioOutputCtrl->setDigitalGain(DigitalgainTable[i]);
	  
	    if( DigitalgainTable[i] != m_MakoAudioOutputCtrl->getDigitalGain() )
	    {
	      retval = FAIL; tempval = FAIL;
	    }
	   
	  }


	  if( tempval == PASS)
	  {
	       targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	       targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }


	  // *************************************************
	  // case 8, G3 Preamp gain tests 
	  // *************************************************
	     targetConfigBase::sendStringToStderr("		G3 gain tests..........");

	  tempval = PASS;

	  
	  for(int j = 0; j < sizeofG3gainTable; j++)
	  {
	 
	   m_MakoAudioOutputCtrl->setG3PreampGain( G3gainTable[j] );

	   if( G3gainTable[j] != m_MakoAudioOutputCtrl->getG3PreampGain() )
	   {
	     retval = FAIL; 
	     tempval = FAIL;
	   }
	  }

	  if( tempval == PASS)
	  {
	       targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	       targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }
	  
	 // *************************************************
	  // case 9, G4 PA gain tests 
	  // *************************************************
	     targetConfigBase::sendStringToStderr("		G4 gain tests..........");

	  tempval = PASS;

	  for(int k = 0; k < sizeofG4gainTable; k++)
	  {

	    m_MakoAudioOutputCtrl->setG4PAGain( G4gainTable[k] );

	    if( G4gainTable[k] != m_MakoAudioOutputCtrl->getG4PAGain() )
	    {
	     retval = FAIL; 
	     tempval = FAIL;
	    }
	  }

	  if( tempval == PASS)
	  {
	       targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	       targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }  

	  // *************************************************
	  // case 10, G5 gain tests 
	  // *************************************************
	     targetConfigBase::sendStringToStderr("		G5 gain tests..........");

	   tempval = PASS;

	  for(int m = 0; m < sizeofG5gainTable; m++)
	  {
	 
	   m_MakoAudioOutputCtrl->setG5AnalogGain( G5gainTable[m] );

	   if( G5gainTable[m] != m_MakoAudioOutputCtrl->getG5AnalogGain() )
	   {
	     retval = FAIL; 
	     tempval = FAIL;
	   }
	  }

	  if( tempval == PASS)
	  {
	       targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	       targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }

	  // *************************************************
	  // case 11, complete path output test 
	  // *************************************************
	  // TBD - This is the last test that I did not have time to due
	  // due to the imposed release date. This test will initialize

	return (bool)retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testAllocation(unsigned int,unsigned int,unsigned int)'
bool genericTestMako::MakoTestAudio::testAllocation( unsigned int sreg123init, unsigned int sreg45init, unsigned int sregPAinit )
{
	// {{{USR

	  bool retval = PASS;


	  // **************************************************
	  // test case 1 make sure audio input allocation works
	  // **************************************************
	  //targetConfigBase::sendStringToStderr("MakoAudioInputCtrl basic allocation test....");

	  // if a zero is returned (null pointer) it means this device could not be allocated.
	  // thats BAD because it should be unallocated

	//  m_MakoAudioInputCtrl = m_theMakoIC->getAudioInputCtrl(sreg123init ,sreg45init ,sregPAinit);

	 // if( m_MakoAudioInputCtrl == 0 )
	 // {
	 //   targetConfigBase::sendStringToStderr("FAILED\n\r");      
	    retval = FAIL;
	 // }
	 // else
	 // {
	 //   targetConfigBase::sendStringToStderr("passed\n\r");
	 // }

	  // **************************************************
	  // test case 2 make sure audio Output allocation works
	  // **************************************************
	  //targetConfigBase::sendStringToStderr("MakoAudioOutputCtrl basic allocation test...");


	  // if a zero is returned (null pointer) it means this device could not be allocated.
	  // thats BAD because it should be unallocated

	  //m_MakoAudioOutputCtrl = m_theMakoIC->getAudioOutputCtrl(sreg123init ,sreg45init ,sregPAinit);

	  //if( m_MakoAudioOutputCtrl == 0 )
	 // {
	 //   targetConfigBase::sendStringToStderr("FAILED\n\r");      
	 //   retval = FAIL;
	 // }
	 // else
	 // {
	//    targetConfigBase::sendStringToStderr("passed\n\r");
	//  }


	  // ***************************************************************
	  // test case 3 make sure null pointer returned on allocated input
	  // ***************************************************************
	//  targetConfigBase::sendStringToStderr("MakoAudio test case 3 - null pointer if Input already allocated...");


	  // if a zero is returned (null pointer) then allocation test passes because its already allocated.
	//  if( m_theMakoIC->getAudioInputCtrl(sreg123init ,sreg45init ,sregPAinit) == 0 )
	//  {
	//    targetConfigBase::sendStringToStderr("passed\n\r"); 
	//  }
	//  else
	//  {
	//    targetConfigBase::sendStringToStderr("FAILED\n\r");      
	    retval = FAIL;
	//  }

	  // ***************************************************************
	  // test case 4 make sure null pointer returned on allocated Output
	  // ***************************************************************
	  //targetConfigBase::sendStringToStderr("MakoAudio test case 4 - null pointer if Output already allocated...");


	  // if a zero is returned (null pointer) then allocation test passes because its already allocated.
	  //if( m_theMakoIC->getAudioOutputCtrl(sreg123init ,sreg45init ,sregPAinit) == 0 )
	  //{
	  //  targetConfigBase::sendStringToStderr("passed\n\r");
	  //}
	 // else
	 // {
	 //   targetConfigBase::sendStringToStderr("FAILED\n\r");
	 //   retval = FAIL;
	 // }

	return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testMicInterfaces()'
bool genericTestMako::MakoTestAudio::testMicInterfaces( void )
{
	// {{{USR
	  bool retval = PASS;
	  bool tempval = PASS;

	  int DigitalgainTable[] = { 0,1 };
	 
	  int sizeofDigitalgainTable = sizeof(DigitalgainTable)/sizeof(int);

	  int G1gainTable[] = { m_MakoAudioInputCtrl->G1G2_MUTE_CONSTANT, 0, 15, 30, 45 };

	  int sizeofG1gainTable = sizeof(G1gainTable)/sizeof(int);
	                                         
	  int G2gainTable[] = { m_MakoAudioInputCtrl->G1G2_MUTE_CONSTANT, -30, -28, -26, -24, -22, -20, -18, -16, -14, -12, -10, -8, -6, -4, -2, 0 };

	  int sizeofG2gainTable = sizeof(G2gainTable)/sizeof(int);

	  // *************************************************
	  // case 1, mic set/get tests 
	  // *************************************************

	  //targetConfigBase::sendStringToStderr("		   mic set/get test....");

	  tempval = PASS;

	  m_MakoAudioInputCtrl->setMicSelected(0);

	  if( m_MakoAudioInputCtrl->getMicSelected() != 0 )
	  {
	    retval = FAIL; 
	    tempval = FAIL;
	  }

	 
	  m_MakoAudioInputCtrl->setMicSelected(1);

	  if( m_MakoAudioInputCtrl->getMicSelected() != 1)
	  {
	    retval = FAIL; 
	    tempval = FAIL;
	  }

	  if( tempval == PASS)
	  {
	    //targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	    //targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }


	  // *************************************************
	  // case 2, filter set/get tests 
	  // *************************************************

	  //targetConfigBase::sendStringToStderr("		filter set/get test....");

	  tempval = PASS;

	  m_MakoAudioInputCtrl->setFilterType(0);

	  if( m_MakoAudioInputCtrl->getFilterType() != 0 )
	  {
	    retval = FAIL; 
	    tempval = FAIL;
	  }

	  m_MakoAudioInputCtrl->setFilterType(1);

	  if( m_MakoAudioInputCtrl->getFilterType() != 1 )
	  {
	    retval = FAIL; 
	    tempval = FAIL;
	  }

	  if( tempval == PASS)
	  {
	    //targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	    //targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }


	  // *************************************************
	  // case 3, digital gain tests 
	  // *************************************************

	  //targetConfigBase::sendStringToStderr("		digital gain test......");

	  tempval = PASS;

	  for(int i = 0; i < sizeofDigitalgainTable; i++)
	  {
	 
	    m_MakoAudioInputCtrl->setDigitalGain( DigitalgainTable[i] );

	    if( DigitalgainTable[i] != m_MakoAudioInputCtrl->getDigitalGain() )
	    {
	      retval = FAIL; tempval = FAIL;
	    }
	   
	  }


	  if( tempval == PASS)
	  {
	    //targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	    //targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }


	  // *************************************************
	  // case 4, G1 gain tests 
	  // *************************************************
	  //targetConfigBase::sendStringToStderr("		G1 gain tests..........");

	  tempval = PASS;

	  for(int j = 0; j < sizeofG1gainTable; j++)
	  {
	 
	   m_MakoAudioInputCtrl->setG1Gain( G1gainTable[j] );

	   if( G1gainTable[j] != m_MakoAudioInputCtrl->getG1Gain() )
	   {
	     retval = FAIL; 
	     tempval = FAIL;
	   }
	  }

	  if( tempval == PASS)
	  {
	    //targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	    //targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	    
	        ////targetConfigBase::sendStringToStderrCmd(ENDL);
	        ////targetConfigBase::sendStringToStderr("sizeofG1gainTable: ");
	        ////targetConfigBase::sendStringToStderr(sizeofG1gainTable);
	        ////targetConfigBase::sendStringToStderr(" should be 5");
	        ////targetConfigBase::sendStringToStderrCmd(ENDL);
	  }

	  // *************************************************
	  // case 5, G2 gain tests 
	  // *************************************************
	//  //targetConfigBase::sendStringToStderr("		G2 gain tests..........");

	  tempval = PASS;

	  for(int k = 0; k < sizeofG2gainTable; k++)
	  {
	 
	   m_MakoAudioInputCtrl->setG2Gain( G2gainTable[k] );

	   if( G2gainTable[k] != m_MakoAudioInputCtrl->getG2Gain() )
	   {
	     retval = FAIL; 
	     tempval = FAIL;

	     // prints garbage when displaying the G2gainTable[k] 

	   ////targetConfigBase::sendStringToStderrCmd( ENDL );
	   ////targetConfigBase::sendStringToStderr( "FAILED @ " );
	   ////targetConfigBase::sendStringToStderr( "G2gainTable[" );
	   ////targetConfigBase::sendStringToStderr( k );
	   ////targetConfigBase::sendStringToStderr( "]= " );
	   ////targetConfigBase::sendStringToStderr( G2gainTable[k] );
	   ////targetConfigBase::sendStringToStderr( " read back: " );
	   ////targetConfigBase::sendStringToStderr( m_MakoAudioInputCtrl->getG1Gain() );
	   ////targetConfigBase::sendStringToStderrCmd( ENDL );

	   }

	  }

	  if( tempval == PASS)
	  {
	    ////targetConfigBase::sendStringToStderr(" passed.\n\r");
	  }
	  else
	  {
	    ////targetConfigBase::sendStringToStderr(" FAILED.\n\r");
	  }

	return (bool)retval;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'MakoTestOPTCTRL'

// {{{RME operation 'MakoTestOPTCTRL()'
genericTestMako::MakoTestOPTCTRL::MakoTestOPTCTRL( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'execute()'
int genericTestMako::MakoTestOPTCTRL::execute( void )
{
	// {{{USR
	targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation tests\r\n");

	testAllocation();


	return 1;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testgpioSetMethods(unsigned int,unsigned int,unsigned int)'
bool genericTestMako::MakoTestOPTCTRL::testgpioSetMethods( unsigned int configA, unsigned int configB, unsigned int dir )
{
	// {{{USR

	  bool retval = PASS;
		
	  // **************************************************
	  // test case 1 gpioSetConfigA
	  // **************************************************
	  targetConfigBase::sendStringToStderr("MakoOPTCTRL test case 1 - gpioSetConfigA\n\r");

	  m_MakoOPTCTRL->gpioSetConfigA(configA);

	  // **************************************************
	  // test case 1 gpioSetConfigB
	  // **************************************************
	 targetConfigBase::sendStringToStderr("MakoOPTCTRL test case 1 - gpioSetConfigB\n\r");

	  m_MakoOPTCTRL->gpioSetConfigB(configB);

	  // **************************************************
	  // test case 1 gpioSetConfigA
	  // **************************************************
	 targetConfigBase::sendStringToStderr("MakoOPTCTRL test case 1 - gpioSetConfigA\n\r");

	  m_MakoOPTCTRL->gpioSetDir(dir);

	  

	  if(retval == PASS)
	  {
	    targetConfigBase::sendStringToStderr("MakoOPTCTRL set gpio method tests pass!\n\r");
	      
	  } 

	  return retval;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testAllocation(unsigned int,unsigned int,unsigned int)'
bool genericTestMako::MakoTestOPTCTRL::testAllocation( unsigned int opt1init, unsigned int opt2init, unsigned int opt3init )
{
	// {{{USR

		bool retval = PASS;
		
	  // **************************************************
	  // test case 1 make sure basic allocation works
	  // **************************************************
	  targetConfigBase::sendStringToStderr("MakoOPTCTRL test case 1 - basic allocation\n\r");


	  // if a zero is returned (null pointer) it means this device could not be allocated.
	  // thats BAD because it should be unallocated

	  //m_MakoOPTCTRL = m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init);

	//  if( m_MakoOPTCTRL == 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL basic allocation test case 1 failure");
	//      retval = FAIL;
	//  }

	  
	  // ***************************************************************
	  // test case 3 make sure null pointer returned on allocated input
	  // ***************************************************************
	  targetConfigBase::sendStringToStderr("MakoOPTCTRL test case 3 - null pointer if Input already allocated\n\r");


	  // if a zero is returned (null pointer) then allocation test passes because its already allocated.
	//   if( m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init) != 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation detection test case 3 failure");
	//      retval = FAIL;
	//  }

	 

	if(retval == PASS)
	{
	 targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation tests pass!\n\r");
	      
	} 

	return retval;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'MakoTestDCPwrCtrl'

// {{{RME operation 'MakoTestDCPwrCtrl()'
genericTestMako::MakoTestDCPwrCtrl::MakoTestDCPwrCtrl( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'execute()'
int genericTestMako::MakoTestDCPwrCtrl::execute( void )
{
	// {{{USR
	//targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation tests\r\n");

	testAllocation();


	return 1;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testAllocation()'
bool genericTestMako::MakoTestDCPwrCtrl::testAllocation( void )
{
	// {{{USR

		bool retval = PASS;
		
	  // **************************************************
	  // test case 1 make sure basic allocation works
	  // **************************************************
	//  targetConfigBase::sendStringToStderr("FIX ME test case 1 - basic allocation\n\r");


	  // if a zero is returned (null pointer) it means this device could not be allocated.
	  // thats BAD because it should be unallocated

	//  m_MakoOPTCTRL = m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init);

	//  if( m_MakoOPTCTRL == 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL basic allocation test case 1 failure");
	//      retval = FAIL;
	//  }

	  
	  // ***************************************************************
	  // test case 3 make sure null pointer returned on allocated input
	  // ***************************************************************
	//  targetConfigBase::sendStringToStderr("MakoOPTCTRL test case 3 - null pointer if Input already allocated\n\r");


	  // if a zero is returned (null pointer) then allocation test passes because its already allocated.
	//   if( m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init) != 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation detection test case 3 failure");
	//      retval = FAIL;
	//  }

	 

	//if(retval == PASS)
	//{
	// targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation tests pass!\n\r");
	      
	//} 

	return retval;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'MakoTestIGNSense'

// {{{RME operation 'MakoTestIGNSense()'
genericTestMako::MakoTestIGNSense::MakoTestIGNSense( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'execute()'
int genericTestMako::MakoTestIGNSense::execute( void )
{
	// {{{USR
	//targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation tests\r\n");

	testAllocation();


	return 1;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testAllocation()'
bool genericTestMako::MakoTestIGNSense::testAllocation( void )
{
	// {{{USR

		bool retval = PASS;
		
	  // **************************************************
	  // test case 1 make sure basic allocation works
	  // **************************************************
	//  targetConfigBase::sendStringToStderr("FIX ME test case 1 - basic allocation\n\r");


	  // if a zero is returned (null pointer) it means this device could not be allocated.
	  // thats BAD because it should be unallocated

	//  m_MakoOPTCTRL = m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init);

	//  if( m_MakoOPTCTRL == 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL basic allocation test case 1 failure");
	//      retval = FAIL;
	//  }

	  
	  // ***************************************************************
	  // test case 3 make sure null pointer returned on allocated input
	  // ***************************************************************
	//  targetConfigBase::sendStringToStderr("MakoOPTCTRL test case 3 - null pointer if Input already allocated\n\r");


	  // if a zero is returned (null pointer) then allocation test passes because its already allocated.
	//   if( m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init) != 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation detection test case 3 failure");
	//      retval = FAIL;
	//  }

	 

	//if(retval == PASS)
	//{
	// targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation tests pass!\n\r");
	      
	//} 

	return retval;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'MakoTestWatchdogCtrl'

// {{{RME operation 'MakoTestWatchdogCtrl()'
genericTestMako::MakoTestWatchdogCtrl::MakoTestWatchdogCtrl( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'execute()'
int genericTestMako::MakoTestWatchdogCtrl::execute( void )
{
	// {{{USR
	targetConfigBase::sendStringToStderr("Watchdog tests\r\n");

	testAllocation();


	return 1;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testAllocation()'
bool genericTestMako::MakoTestWatchdogCtrl::testAllocation( void )
{
	// {{{USR

		bool retval = PASS;
		
	  // **************************************************
	  // test case 1 make sure basic allocation works
	  // **************************************************
	//  targetConfigBase::sendStringToStderr("FIX ME test case 1 - basic allocation\n\r");


	  // if a zero is returned (null pointer) it means this device could not be allocated.
	  // thats BAD because it should be unallocated

	//  m_MakoOPTCTRL = m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init);

	//  if( m_MakoOPTCTRL == 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL basic allocation test case 1 failure");
	//      retval = FAIL;
	//  }

	  
	  // ***************************************************************
	  // test case 3 make sure null pointer returned on allocated input
	  // ***************************************************************
	//  targetConfigBase::sendStringToStderr("MakoOPTCTRL test case 3 - null pointer if Input already allocated\n\r");


	  // if a zero is returned (null pointer) then allocation test passes because its already allocated.
	//   if( m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init) != 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation detection test case 3 failure");
	//      retval = FAIL;
	//  }

	 

	//if(retval == PASS)
	//{
	// targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation tests pass!\n\r");
	      
	//} 

	return retval;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'MakoTestIntrCtrl'

// {{{RME operation 'MakoTestIntrCtrl()'
genericTestMako::MakoTestIntrCtrl::MakoTestIntrCtrl( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'execute()'
int genericTestMako::MakoTestIntrCtrl::execute( void )
{
	// {{{USR
	//targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation tests\r\n");

	testAllocation();


	return 1;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testAllocation()'
bool genericTestMako::MakoTestIntrCtrl::testAllocation( void )
{
	// {{{USR

		bool retval = PASS;
		
	  // **************************************************
	  // test case 1 make sure basic allocation works
	  // **************************************************
	//  targetConfigBase::sendStringToStderr("FIX ME test case 1 - basic allocation\n\r");


	  // if a zero is returned (null pointer) it means this device could not be allocated.
	  // thats BAD because it should be unallocated

	//  m_MakoOPTCTRL = m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init);

	//  if( m_MakoOPTCTRL == 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL basic allocation test case 1 failure");
	//      retval = FAIL;
	//  }

	  
	  // ***************************************************************
	  // test case 3 make sure null pointer returned on allocated input
	  // ***************************************************************
	//  targetConfigBase::sendStringToStderr("MakoOPTCTRL test case 3 - null pointer if Input already allocated\n\r");


	  // if a zero is returned (null pointer) then allocation test passes because its already allocated.
	//   if( m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init) != 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation detection test case 3 failure");
	//      retval = FAIL;
	//  }

	 

	//if(retval == PASS)
	//{
	// targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation tests pass!\n\r");
	      
	//} 

	return retval;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'MakoTestOneWire'

// {{{RME operation 'MakoTestOneWire()'
genericTestMako::MakoTestOneWire::MakoTestOneWire( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'execute()'
int genericTestMako::MakoTestOneWire::execute( void )
{
	// {{{USR
	//targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation tests\r\n");

	testAllocation();


	return 1;
	// }}}USR
}
// }}}RME

// {{{RME operation 'testAllocation()'
bool genericTestMako::MakoTestOneWire::testAllocation( void )
{
	// {{{USR

		bool retval = PASS;
		
	  // **************************************************
	  // test case 1 make sure basic allocation works
	  // **************************************************
	//  targetConfigBase::sendStringToStderr("FIX ME test case 1 - basic allocation\n\r");


	  // if a zero is returned (null pointer) it means this device could not be allocated.
	  // thats BAD because it should be unallocated

	//  m_MakoOPTCTRL = m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init);

	//  if( m_MakoOPTCTRL == 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL basic allocation test case 1 failure");
	//      retval = FAIL;
	//  }

	  
	  // ***************************************************************
	  // test case 3 make sure null pointer returned on allocated input
	  // ***************************************************************
	//  targetConfigBase::sendStringToStderr("MakoOPTCTRL test case 3 - null pointer if Input already allocated\n\r");


	  // if a zero is returned (null pointer) then allocation test passes because its already allocated.
	//   if( m_theMakoIC->getOPT(opt1init ,opt2init ,opt3init) != 0 )
	//  {
	//      targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation detection test case 3 failure");
	//      retval = FAIL;
	//  }

	 

	//if(retval == PASS)
	//{
	// targetConfigBase::sendStringToStderr("MakoOPTCTRL allocation tests pass!\n\r");
	      
	//} 

	return retval;
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME classifier 'MakoTestDAC'

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
genericTestMako::MakoTestDAC::~MakoTestDAC( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
genericTestMako::MakoTestDAC::MakoTestDAC( const MakoTestDAC & rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
genericTestMako::MakoTestDAC & genericTestMako::MakoTestDAC::operator=( const MakoTestDAC & rtg_arg )
{
	if( this != &rtg_arg )
	{
	}
	return *this;
}
// }}}RME

// {{{RME operation 'MakoTestDAC()'
genericTestMako::MakoTestDAC::MakoTestDAC( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'execute()'
void genericTestMako::MakoTestDAC::execute( void )
{
	// {{{USR
	// need to initialize these when completing the test
	//rfSpiBuffer ** m_commonDACBuffers = 0;
	//Connection * m_conn = 0;
	//rfSpiBuffer ** m_dac3Buffer = 0;

	//const unsigned int numRFStates=4;   // Number of RF states.
	//unsigned int i;


	// Create Mako's image buffer.
	//m_conn = new ConsoleConnection();
	//m_commonDACBuffers = new rfSpiBuffer*[numRFStates];

	//for (i=0; i<numRFStates; i++) { m_commonDACBuffers[i]=new ConnectionRFBuffer(4, m_conn);   }

	// Build Mako object.
	//Mako *mako = new Mako(m_commonDACBuffers, numRFStates);

	//Create default Front End Filter Data...
	//unsigned int defaultFEFData[numRFStates] = {128, 129, 130, 131};

	// Create the Mako Front End Filter:
	//MakoFrontEndFilter *filter = mako->getFrontEndFilter(Mako::MAKO_DAC_1, defaultFEFData, numRFStates);

	// Test1:
	// Verify the following: commonDACBuffer[0] = e1020000
	//                       commonDACBuffer[1] = e1020400
	//                       commonDACBuffer[2] = e1020800
	//                       commonDACBuffer[3] = e1020c00
	//Create default PA Bias Data...
	//unsigned int defaultPAData[numRFStates] = {80, 79, 78, 77};

	// Create the Mako PA
	//MakoRFPA *pa = mako->getRFPA(Mako::MAKO_DAC_2, defaultPAData, numRFStates);

	// Test2:
	// Verify the following: commonDACBuffer[0] = e3020050
	//                       commonDACBuffer[1] = e302044f
	//                       commonDACBuffer[2] = e302084e
	//                       commonDACBuffer[3] = e3020c4d

	// Create a power envelope....
	//uint16_t powerEnvelope[32] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};

	// Create the PowerConfiguration...
	//PowerConfiguration **powerConfig = new PowerConfiguration*[numRFStates];
	//powerConfig[0] = new PowerConfiguration(powerEnvelope, 1, false, false);
	//powerConfig[1] = new PowerConfiguration(powerEnvelope, 2, true,  true);   
	//powerConfig[2] = new PowerConfiguration(powerEnvelope, 3, false, false);
	//powerConfig[3] = new PowerConfiguration(powerEnvelope, 4, true,  false);

	// Create a dedicated SPI buffer...
	//m_dac3Buffer = new connectionRFBuffer(4, m_conn);

	// Now the RF power control object can be created.
	//MakoRFPowerControl *powerControl = mako->getRFPowerControl(Mako::MAKO_DAC_3, powerConfig, m_dac3Buffer, numRFStates);

	// Test3:
	// Verify the following: m_commonDACBuffer[0] = e3020050
	//                       m_commonDACBuffer[1] = e702044f
	//                       m_commonDACBuffer[2] = e302084e
	//                       m_commonDACBuffer[3] = e7020c4d

	//powerControl->setPowerLevel(1, 0);
	// Test4:
	// Verify the following: m_dac3Buffer         = e8a0781f

	//powerControl->setRFState(2);
	// }}}USR
}
// }}}RME
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
genericTestMako::genericTestMako( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
genericTestMako::~genericTestMako( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
genericTestMako::genericTestMako( const genericTestMako & rtg_arg )
	: genericTestBase( rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
genericTestMako & genericTestMako::operator=( const genericTestMako & rtg_arg )
{
	if( this != &rtg_arg )
		genericTestBase::operator=( rtg_arg );
	return *this;
}
// }}}RME

// {{{RME operation 'init(genericTestBase::initConfig *)'
genericTestBase::initResult * genericTestMako::init( genericTestBase::initConfig * config )
{
	// {{{USR

	if( config != 0)
	{
	  m_initConfig_ptr = config;

	  config->m_targetConfig->init();
	}

	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'execute(genericTestBase::testConfig *)'
genericTestBase::testResult * genericTestMako::execute( genericTestBase::testConfig * config )
{
	// {{{USR
	Mako * m_theMakoIC; 
	MakoUSBCtrl * m_makoUSBctrl;
	MakoAudioInputCtrl  * m_MakoAudioInputCtrl;
	MakoAudioOutputCtrl * m_MakoAudioOutputCtrl;

			unsigned int rxval;
			unsigned int mako_reg_addr = 0;
			volatile uint32_t reg_data = 0;
	        volatile uint32_t rdData = 0;
	        volatile uint32_t usb1_ctrl_stat;
	        volatile uint32_t usb2_ctrl_stat;

	        targetConfigBase::sendStringToStderr("genericTestMako execute() method!\n");

	        targetConfigBase::sendStringToStderr("\n\rInstantiating Mako, this will result in spi traffic\n\r");
			
			//Mako( rfSpiBuffer * * dacBuffers, unsigned int numDACBuffers, Connection * connection )
			//Mako * m_theMakoIC = new Mako( 0, 0, (Connection *)targetConfigBase::m_MakoSPI );

#ifdef TARGETCONFIGLTDMP2_1610

	        m_theMakoIC = (( targetConfigLTDmp2_1610)(genericThreadBase::m_targetConfig))->m_makoIC;
	        m_makoUSBctrl = (( targetConfigLTDmp2_1610)(genericThreadBase::m_targetConfig))->m_makoUSBctrl;

#endif

#ifdef TARGETCONFIGLTDMP3_1610

	        m_theMakoIC = (( targetConfigLTDmp3_1610)(genericThreadBase::m_targetConfig))->m_makoIC;
	        m_makoUSBctrl = (( targetConfigLTDmp3_1610)(genericThreadBase::m_targetConfig))->m_makoUSBctrl;

#endif

#ifdef TARGETCONFIGLTDMP3_1710

	        m_theMakoIC = (( targetConfigLTDmp3_1710)(genericThreadBase::m_targetConfig))->m_makoIC;
	        m_makoUSBctrl = (( targetConfigLTDmp3_1710)(genericThreadBase::m_targetConfig))->m_makoUSBctrl;
#endif
	    
	        // ******************************
	        // test wrRegister and rdRegister
	        // ******************************
#ifdef TARGETCONFIGWIN32

			//Mako( rfSpiBuffer * * dacBuffers, unsigned int numDACBuffers, Connection * connection )
			m_theMakoIC = new Mako( 0, 0, (Connection *)targetConfigBase::m_MakoSPI );

	        targetConfigBase::sendStringToStderr("\n\r****************************************\n\r");
	        mako_reg_addr = 4;  // usb
	        reg_data = 0x40002400;

	        targetConfigBase::sendStringToStderr("\n\rMako wrRegister test to USB1 ctrl_stat - should display 0xC0002400 in binary\n\r");
	        m_theMakoIC->wrRegister( mako_reg_addr, reg_data );

	        targetConfigBase::sendStringToStderr("\n\r****************************************\n\r");
			targetConfigBase::sendStringToStderr(" Mako rdRegister test - should read back 0x40654321\n\r");

	        mako_reg_addr = 4;  // usb
	        reg_data = 0x00654321;       
	        rdData = m_theMakoIC->rdRegister( mako_reg_addr, reg_data );

		    targetConfigBase::sendStringToStderr(" \n\rrdData returned ,should be 0x40654321 from rdRegister: ");
		    targetConfigBase::send_uint32_ToStderr(rdData);
		    targetConfigBase::sendStringToStderr("\n\r");

	        targetConfigBase::sendStringToStderr("\n\r****************************************\n\r");


	m_MakoAudioInputCtrl  = m_theMakoIC->getAudioInputCtrl(0xB2161010,0xB6130D00,0xBA309000);
	m_MakoAudioOutputCtrl = m_theMakoIC->getAudioOutputCtrl(0xB2161010,0xB6130D00,0xBA309000);

#else
	        // fix this to read from a specific Mako register which has a unique power up
	        // default value.
	        mako_reg_addr = 4;  // usb control group
	        reg_data = 0x40000000; // usb1 ctrl_status

	        // would expect to see ccs display a value of 0x40002400 as that will be the default
	        // power up contents of the register, especially the 24 digits. Some of the others
	        // like reading Vbus for a transceiver set to device mode, are unclear as to the expected
	        // result
	                                               // mako_reg_addr, reg_data
	        usb1_ctrl_stat = m_theMakoIC->rdRegister(             4, 0 );
	        usb2_ctrl_stat = m_theMakoIC->rdRegister(             4, 0x1000000 );

#endif 

	            // ************************************************************
	            // test mako fet manager - add more test cases for all 4 states
	            // ************************************************************
	            targetConfigBase::sendStringToStderr(" *********** Mako FET Manager tests **************\n\r\n\r");

	            // *********** test case 1  Sets transceiver 1 to host ***************
	            targetConfigBase::sendStringToStderr(" 	Test Case 1, Sets transceiver 1 to host\n\r\n\r");

	            m_makoUSBctrl->setMode(MakoUSBConstants::USB_MODE_HOST,MakoUSBConstants::USB1_TRANSCEIVER);


	                                              // mako_reg_addr, reg_data
	            usb1_ctrl_stat = m_theMakoIC->rdRegister(             4, 0 );
	            usb2_ctrl_stat = m_theMakoIC->rdRegister(             4, 0x1000000 );

	            targetConfigBase::sendStringToStderr(" 			usb1_ctrl_stat = ");	        
	            targetConfigBase::send_uint32_ToStderr(usb1_ctrl_stat);
	            targetConfigBase::sendStringToStderr("\n\r\n\r");

	            targetConfigBase::sendStringToStderr(" 			usb2_ctrl_stat = ");	        
	            targetConfigBase::send_uint32_ToStderr(usb2_ctrl_stat);
	            targetConfigBase::sendStringToStderr("\n\r");		

	            targetConfigBase::sendStringToStderr("\n\r *********** Mako FET Manager test complete ************\n\r");

	            // ***********************
	            // test syncAudio
	            // ***********************

				//targetConfigBase::sendStringToStderr(" Mako syncAudio test\n\r");

				//m_IOVirtualSerial_ptr->m_valueToBeReturnedByReceive = 0x12345678;

				//m_theMakoIC->syncAudio( );

				//m_parent->m_IOVirtualSerial_ptr->m_valueOfSendLastOutput
	           
	            // ***********************
	            // test ADC
	            // ***********************
	        	targetConfigBase::sendStringToStderr("executing adc test \r\n");

	            genericTestMako::MakoTestADC * adcTestObjPtr = new genericTestMako::MakoTestADC(m_theMakoIC);
	             
	        	adcTestObjPtr->execute();

	            // ***********************
	            // test Audio
	            // ***********************

	        	//targetConfigBase::sendStringToStderr("executing audio test \r\n");

	            //MakoTestAudio * audioTestObjPtr = new MakoTestAudio(this,m_theMakoIC);

	        	//audioTestObjPtr->execute();

	            // ***********************
	            // test MakoOPTCTRL
	            // ***********************

	        	//targetConfigBase::sendStringToStderr("executing option control test \r\n");
	 
	            //MakoTestOPTCTRL * optTestObjPtr = new MakoTestOPTCTRL(this, m_theMakoIC); 
				//optTestObjPtr->execute();

	            // ***********************
	            // test Watchdog
	            // ***********************

	        	//targetConfigBase::sendStringToStderr("executing watchdog test \r\n");
	 
				//MakoTestWatchdogCtrl * wdtest = new MakoTestWatchdogCtrl(this, m_theMakoIC);
				//wdtest->execute();

	            // ***********************
	            // test OneWire
	            // ***********************

	        	//targetConfigBase::sendStringToStderr("executing one wire test \r\n");
	 
				//MakoTestOneWire * onewiretest = new MakoTestOneWire(this, m_theMakoIC);
				//onewiretest->execute();

	            // ***********************
	            // test interrupt control
	            // ***********************

	        	//targetConfigBase::sendStringToStderr("executing interrupt control test \r\n");
	  
				//MakoTestIntrCtrl * intTest = new MakoTestIntrCtrl(this, m_theMakoIC);
				//intTest->execute();

	            // ***********************
	            // test ignition sense
	            // *********************** 

	        	//targetConfigBase::sendStringToStderr("executing ignition sense test \r\n");
	 
				//MakoTestIGNSense * igntest = new MakoTestIGNSense(this, m_theMakoIC);
				//igntest->execute();

	            // ***********************
	            // test DC regulator
	            // ***********************

	        	//targetConfigBase::sendStringToStderr("executing DC power test \r\n");
	 
				//MakoTestDCPwrCtrl * DCpwrTest = new MakoTestDCPwrCtrl(this, m_theMakoIC);
				//DCpwrTest->execute();

				//targetConfigBase::sendStringToStderr("Execution of all tests are complete.\r\n");  

	        return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'genericTestMako(targetConfigBase *)'
genericTestMako::genericTestMako( targetConfigBase * hwPlatformConfig )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	genericTestBase::initConfig * hwconf = new genericTestBase::initConfig(hwPlatformConfig);

	init(hwconf);

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestADC' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestAudio' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestOPTCTRL' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestDCPwrCtrl' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestIGNSense' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestWatchdogCtrl' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestIntrCtrl' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestOneWire' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestDAC' tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
