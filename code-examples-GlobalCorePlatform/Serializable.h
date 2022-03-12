// {{{RME classifier 'Logical View::SerializationBase::Serializable'

#ifndef Serializable_H
#define Serializable_H

#ifdef PRAGMA
#pragma interface "Serializable.h"
#endif

#include <serialbase.h>
#include <Array.h>
#include <SerialObject.h>
#include <TypedBaseClass.h>
class AbstractSerialSizer;
class AbstractSerialSizerFactory;
class SerialObjectFactory;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#define SERIAL_CLASS_CONFIG() \
		static unsigned int classSize; \
		unsigned int getClassSize( void ) const {return classSize;}; \
		void setClassSize( unsigned int s ) {classSize = s;}

#define SERIAL_CLASS_CONFIG_RESIZE() \
		static unsigned int classSize; \
		unsigned int getClassSize( void ) const {return classSize;}; \
		void setClassSize( unsigned int s ) {}

#define SERIAL_CLASS_INITIALIZE(name) unsigned int name::classSize( 0xFFFF )
// }}}USR
// }}}RME

class Serializable : public TypedBaseClass
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR
	friend SerialObject &operator<<(SerialObject &so,Serializable *t);
	friend SerialObject &operator<<(SerialObject &so,Serializable &t);
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
	// {{{RME classAttribute 'SERIALIZABLE'
	static const unsigned int SERIALIZABLE;
	// }}}RME

private:
	// {{{RME associationEnd 'm_sizer'
	static AbstractSerialSizerFactory * m_sizer;
	// }}}RME
	// {{{RME associationEnd 'm_store'
	static SerialObjectFactory * m_store;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Serializable( void );
	// }}}RME

protected:
	// {{{RME operation 'deserialize(SerialObject*)'
	virtual void deserialize( SerialObject * so );
	// }}}RME
	// {{{RME operation 'setClassSize(unsigned int)'
	virtual void setClassSize( unsigned int s );
	// }}}RME
	// {{{RME operation 'getClassSize()'
	virtual unsigned int getClassSize( void ) const;
	// }}}RME
	// {{{RME operation 'getSerialized()'
	Array * getSerialized( void );
	// }}}RME
	// {{{RME operation 'serialize(SerialObject*)'
	virtual void serialize( SerialObject * so );
	// }}}RME

public:
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'operator Array*()'
	operator Array*( void );
	// }}}RME

protected:
	// {{{RME operation 'getStoreFactory()'
	virtual SerialObjectFactory * getStoreFactory( void ) const;
	// }}}RME
	// {{{RME operation 'getSizerFactory()'
	virtual AbstractSerialSizerFactory * getSizerFactory( void ) const;
	// }}}RME

public:
	// {{{RME operation 'init(SerialObjectFactory*,AbstractSerialSizerFactory*)'
	static void init( SerialObjectFactory * store, AbstractSerialSizerFactory * sizer );
	// }}}RME
	// {{{RME operation 'Serializable()'
	Serializable( void );
	// }}}RME
	// {{{RME operation 'Serializable(Array*)'
	Serializable( Array * data );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Serializable_H */

// }}}RME
