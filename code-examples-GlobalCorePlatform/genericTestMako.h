// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::genericTests::genericTestsMOTICs::genericTestsMako::genericTestMako'

#ifndef genericTestMako_H
#define genericTestMako_H

#ifdef PRAGMA
#pragma interface "genericTestMako.h"
#endif

#include <HALtestLib_win32.h>
#include <MakoAudioInputCtrl.h>
#include <MakoAudioOutputCtrl.h>
#include <genericTestBase.h>
class IOVirtualSerial;
class Mako;
class Mako1WireCtrl;
class MakoADC;
class MakoDCPwrCtrl;
class MakoFrontEndFilter;
class MakoIGNSenseCtrl;
class MakoIntrCtrl;
class MakoOPTCTRL;
class MakoRFPA;
class MakoRFPowerControl;
class MakoUSBConstants;
class MakoUSBCtrl;
class MakoUSBEvents;
class MakoWatchdogCtrl;
class PowerConfiguration;
class SCharArray;
class USBIOVirtualHandler;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#ifndef PASS
#define PASS true
#endif

#ifndef FAIL
#define FAIL false
#endif

#ifdef _WIN32

#include <IOVirtualSerialSimSPI.h>

#endif
// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestADC' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestAudio' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestOPTCTRL' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestDCPwrCtrl' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestIGNSense' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestWatchdogCtrl' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestIntrCtrl' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestOneWire' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestDAC' tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class genericTestMako : public genericTestBase
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classifier 'MakoTestADC'
	class MakoTestADC
	{
	public:
		// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	protected:
		// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	private:
		// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME
		// {{{RME classAttribute 'm_MakoADCArray'
		MakoADC * * m_MakoADCArray;
		// }}}RME

	public:
		// {{{RME classAttribute 'ADC_0'
		static const int ADC_0;
		// }}}RME
		// {{{RME classAttribute 'ADC_11_INVALID'
		static const int ADC_11_INVALID;
		// }}}RME

	private:
		// {{{RME classAttribute 'm_theMakoIC'
		Mako * m_theMakoIC;
		// }}}RME

	public:
		// {{{RME operation 'MakoTestADC(Mako *)'
		MakoTestADC( Mako * makoIC );
		// }}}RME
		// {{{RME operation 'execute()'
		int execute( void );
		// }}}RME
		// {{{RME operation 'testisConversionDone(int)'
		bool testisConversionDone( int device );
		// }}}RME
		// {{{RME operation 'testRead(int)'
		bool testRead( int device = 0 );
		// }}}RME
		// {{{RME operation 'testsetState(int)'
		bool testsetState( int device );
		// }}}RME
		// {{{RME operation 'testStartConversion(int)'
		bool testStartConversion( int device );
		// }}}RME
		// {{{RME operation 'testAllocation(unsigned int,unsigned int)'
		bool testAllocation( unsigned int adcSelect = 0, unsigned int adcDataDefault = 0 );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'MakoTestAudio'
	class MakoTestAudio
	{
	public:
		// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	protected:
		// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	private:
		// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME
		// {{{RME classAttribute 'm_MakoAudioInputCtrl'
		MakoAudioInputCtrl * m_MakoAudioInputCtrl;
		// }}}RME
		// {{{RME classAttribute 'm_MakoAudioOutputCtrl'
		MakoAudioOutputCtrl * m_MakoAudioOutputCtrl;
		// }}}RME

	public:
		// {{{RME operation 'MakoTestAudio()'
		MakoTestAudio( void );
		// }}}RME
		// {{{RME operation 'execute()'
		int execute( void );
		// }}}RME
		// {{{RME operation 'testSpkrInterfaces()'
		bool testSpkrInterfaces( void );
		// }}}RME
		// {{{RME operation 'testAllocation(unsigned int,unsigned int,unsigned int)'
		bool testAllocation( unsigned int sreg123init = 0, unsigned int sreg45init = 0, unsigned int sregPAinit = 0 );
		// }}}RME
		// {{{RME operation 'testMicInterfaces()'
		bool testMicInterfaces( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'MakoTestOPTCTRL'
	class MakoTestOPTCTRL
	{
	public:
		// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	protected:
		// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	private:
		// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME
		// {{{RME classAttribute 'm_MakoOPTCTRL'
		MakoOPTCTRL * m_MakoOPTCTRL;
		// }}}RME

	public:
		// {{{RME operation 'MakoTestOPTCTRL()'
		MakoTestOPTCTRL( void );
		// }}}RME
		// {{{RME operation 'execute()'
		int execute( void );
		// }}}RME
		// {{{RME operation 'testgpioSetMethods(unsigned int,unsigned int,unsigned int)'
		bool testgpioSetMethods( unsigned int configA = 0, unsigned int configB = 0, unsigned int dir = 0 );
		// }}}RME
		// {{{RME operation 'testAllocation(unsigned int,unsigned int,unsigned int)'
		bool testAllocation( unsigned int opt1init = 0, unsigned int opt2init = 0, unsigned int opt3init = 0 );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'MakoTestDCPwrCtrl'
	class MakoTestDCPwrCtrl
	{
	public:
		// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	protected:
		// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	private:
		// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME
		// {{{RME classAttribute 'm_MakoResourceObject'
		MakoDCPwrCtrl * m_MakoResourceObject;
		// }}}RME

	public:
		// {{{RME operation 'MakoTestDCPwrCtrl()'
		MakoTestDCPwrCtrl( void );
		// }}}RME
		// {{{RME operation 'execute()'
		int execute( void );
		// }}}RME
		// {{{RME operation 'testAllocation()'
		bool testAllocation( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'MakoTestIGNSense'
	class MakoTestIGNSense
	{
	public:
		// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	protected:
		// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	private:
		// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME
		// {{{RME classAttribute 'm_MakoResourceObject'
		MakoIGNSenseCtrl * m_MakoResourceObject;
		// }}}RME

	public:
		// {{{RME operation 'MakoTestIGNSense()'
		MakoTestIGNSense( void );
		// }}}RME
		// {{{RME operation 'execute()'
		int execute( void );
		// }}}RME
		// {{{RME operation 'testAllocation()'
		bool testAllocation( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'MakoTestWatchdogCtrl'
	class MakoTestWatchdogCtrl
	{
	public:
		// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	protected:
		// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	private:
		// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME
		// {{{RME classAttribute 'm_MakoResourceObject'
		MakoWatchdogCtrl * m_MakoResourceObject;
		// }}}RME

	public:
		// {{{RME operation 'MakoTestWatchdogCtrl()'
		MakoTestWatchdogCtrl( void );
		// }}}RME
		// {{{RME operation 'execute()'
		int execute( void );
		// }}}RME
		// {{{RME operation 'testAllocation()'
		bool testAllocation( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'MakoTestIntrCtrl'
	class MakoTestIntrCtrl
	{
	public:
		// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	protected:
		// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	private:
		// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME
		// {{{RME classAttribute 'm_MakoResourceObject'
		MakoIntrCtrl * m_MakoResourceObject;
		// }}}RME

	public:
		// {{{RME operation 'MakoTestIntrCtrl()'
		MakoTestIntrCtrl( void );
		// }}}RME
		// {{{RME operation 'execute()'
		int execute( void );
		// }}}RME
		// {{{RME operation 'testAllocation()'
		bool testAllocation( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'MakoTestOneWire'
	class MakoTestOneWire
	{
	public:
		// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	protected:
		// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	private:
		// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME
		// {{{RME classAttribute 'm_MakoResourceObject'
		Mako1WireCtrl * m_MakoResourceObject;
		// }}}RME

	public:
		// {{{RME operation 'MakoTestOneWire()'
		MakoTestOneWire( void );
		// }}}RME
		// {{{RME operation 'execute()'
		int execute( void );
		// }}}RME
		// {{{RME operation 'testAllocation()'
		bool testAllocation( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME classifier 'MakoTestDAC'
	class MakoTestDAC
	{
	public:
		// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	protected:
		// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	private:
		// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
		// {{{USR

		// }}}USR
		// }}}RME

	public:
		// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
		virtual ~MakoTestDAC( void );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
		MakoTestDAC( const MakoTestDAC & rtg_arg );
		// }}}RME
		// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
		MakoTestDAC & operator=( const MakoTestDAC & rtg_arg );
		// }}}RME
		// {{{RME operation 'MakoTestDAC()'
		MakoTestDAC( void );
		// }}}RME
		// {{{RME operation 'execute()'
		void execute( void );
		// }}}RME
	};
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	genericTestMako( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~genericTestMako( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	genericTestMako( const genericTestMako & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	genericTestMako & operator=( const genericTestMako & rtg_arg );
	// }}}RME
	// {{{RME operation 'init(genericTestBase::initConfig *)'
	genericTestBase::initResult * init( genericTestBase::initConfig * config = 0 );
	// }}}RME
	// {{{RME operation 'execute(genericTestBase::testConfig *)'
	genericTestBase::testResult * execute( genericTestBase::testConfig * config = 0 );
	// }}}RME
	// {{{RME operation 'genericTestMako(targetConfigBase *)'
	genericTestMako( targetConfigBase * hwPlatformConfig );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestADC' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestAudio' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestOPTCTRL' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestDCPwrCtrl' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestIGNSense' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestWatchdogCtrl' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestIntrCtrl' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestOneWire' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME
// {{{RME classifier 'MakoTestDAC' tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* genericTestMako_H */

// }}}RME
