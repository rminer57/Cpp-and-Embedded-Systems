// {{{RME classifier 'Logical View::HAL Instantiation::RF Deck::Deployment::tomahawk::SpiImageMgr'

#ifndef SpiImageMgr_H
#define SpiImageMgr_H

#ifdef PRAGMA
#pragma interface "SpiImageMgr.h"
#endif

#include <HALtestLib_win32.h>
class SpiSnippetMgr;
class rf_audio_std_types;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class SpiImageMgr
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
	// {{{RME classAttribute 'ImageModified'
	bool ImageModified;
	// }}}RME
	// {{{RME classAttribute 'ImageReset'
	bool ImageReset;
	// }}}RME
	// {{{RME classAttribute 'SnippetMgr'
	SpiSnippetMgr * * SnippetMgr;
	// }}}RME
	// {{{RME operation 'SpiImageMgr(int)'
	SpiImageMgr( int NumberOfSnippets );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SpiImageMgr_H */

// }}}RME
