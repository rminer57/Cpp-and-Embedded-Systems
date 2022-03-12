// {{{RME classifier 'Logical View::SubscriberSystem::Interfaces::Connections::OptionQuantizationUnit'

#ifndef OptionQuantizationUnit_H
#define OptionQuantizationUnit_H

#ifdef PRAGMA
#pragma interface "OptionQuantizationUnit.h"
#endif

#include <conn.h>
#include <Connection.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class OptionQuantizationUnit : public Connection::ConnectionOption
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR
	SERIAL_CLASS_CONFIG();
	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classAttribute 'CONNECTION_OPTION_QUANT'
	static const unsigned int CONNECTION_OPTION_QUANT;
	// }}}RME

private:
	// {{{RME classAttribute 'm_quantizationUnit'
	unsigned int m_quantizationUnit;
	// }}}RME
	// {{{RME classAttribute 'm_adjust'
	bool m_adjust;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~OptionQuantizationUnit( void );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'getQuantizationUnit()'
	virtual unsigned int getQuantizationUnit( void ) const;
	// }}}RME
	// {{{RME operation 'setQuantizationUnit(unsigned int)'
	virtual void setQuantizationUnit( unsigned int thresh );
	// }}}RME
	// {{{RME operation 'OptionQuantizationUnit(unsigned int,bool)'
	OptionQuantizationUnit( unsigned int quantizationUnit = 0, bool adjust = false );
	// }}}RME

protected:
	// {{{RME operation 'deserialize(SerialObject*)'
	virtual void deserialize( SerialObject * so );
	// }}}RME
	// {{{RME operation 'serialize(SerialObject*)'
	virtual void serialize( SerialObject * so );
	// }}}RME

public:
	// {{{RME operation 'OptionQuantizationUnit(SerialObject*)'
	OptionQuantizationUnit( SerialObject * so );
	// }}}RME
	// {{{RME operation 'isAdjust()'
	bool isAdjust( void );
	// }}}RME
	// {{{RME operation 'setAdjust(bool)'
	void setAdjust( bool adjust );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* OptionQuantizationUnit_H */

// }}}RME
