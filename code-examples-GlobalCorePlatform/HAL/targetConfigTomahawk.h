// {{{RME classifier 'Logical View::Tests::HALTestSupport::HALTestSupportClasses::targetConfigObjects::configMotorola_ICs::targetConfigTomahawk'

#ifndef targetConfigTomahawk_H
#define targetConfigTomahawk_H

#ifdef PRAGMA
#pragma interface "targetConfigTomahawk.h"
#endif

#include <HALtestLib_win32.h>
#include <targetConfigBase.h>
class IOVirtualSerial;
class connectionBufferFactory;
class rfSpiBuffer;
class rfSpiManager;
class tomahawk;
class tomahawkDefault;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class targetConfigTomahawk : public targetConfigBase
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
	// {{{RME classAttribute 'm_tomahawk'
	tomahawk * m_tomahawk;
	// }}}RME
	// {{{RME classAttribute 'm_tomahawkRxDefaultImage'
	uint32_t * m_tomahawkRxDefaultImage;
	// }}}RME
	// {{{RME classAttribute 'm_tomahawkTxDefaultImage'
	uint32_t * m_tomahawkTxDefaultImage;
	// }}}RME
	// {{{RME classAttribute 'm_defaultTomahawkImages'
	uint32_t * * m_defaultTomahawkImages;
	// }}}RME
	// {{{RME classAttribute 'm_tomahawkDefDataObj'
	tomahawkDefault * m_tomahawkDefDataObj;
	// }}}RME
	// {{{RME classAttribute 'm_spiBuffers'
	rfSpiBuffer * * m_spiBuffers;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	targetConfigTomahawk( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~targetConfigTomahawk( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	targetConfigTomahawk( const targetConfigTomahawk & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	targetConfigTomahawk & operator=( const targetConfigTomahawk & rtg_arg );
	// }}}RME
	// {{{RME operation 'init()'
	void init( void );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* targetConfigTomahawk_H */

// }}}RME
