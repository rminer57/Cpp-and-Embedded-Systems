// {{{RME classifier 'Logical View::SerializationBase::Serializable'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Serializable.h"
#endif

#include <serialbase.h>
#include <Serializable.h>
#include <AbstractSerialSizer.h>
#include <AbstractSerialSizerFactory.h>
#include <SerialObjectFactory.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'SERIALIZABLE'
const unsigned int Serializable::SERIALIZABLE( 1 );
// }}}RME

// {{{RME associationEnd 'm_sizer'
AbstractSerialSizerFactory * Serializable::m_sizer;
// }}}RME

// {{{RME associationEnd 'm_store'
SerialObjectFactory * Serializable::m_store;
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Serializable::~Serializable( void )
{
}
// }}}RME

// {{{RME operation 'deserialize(SerialObject*)'
void Serializable::deserialize( SerialObject * so )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'setClassSize(unsigned int)'
void Serializable::setClassSize( unsigned int s )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'getClassSize()'
unsigned int Serializable::getClassSize( void ) const
{
	// {{{USR
	return 0;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getSerialized()'
Array * Serializable::getSerialized( void )
{
	// {{{USR
	unsigned int cs = getClassSize();

	//first time execution (size currently unknown)
	if (cs == 0xFFFF)
	{
		unsigned int storeSize = getStoreFactory()->getBaseSize();			//get base size of store	
		AbstractSerialSizer *sz = getSizerFactory()->getSizer();
		serialize(sz);
		cs = (sz->getLength() + storeSize  - 1)/storeSize + 1; 				//round to nearest size, + 1 for type
		setClassSize(cs);
		delete sz;
	}

	SerialObject* so = getStoreFactory()->getStore(cs);
	so->setType(getType());
	serialize(so);									//store in serial store

	return getStoreFactory()->getArray(so);
	// }}}USR
}
// }}}RME

// {{{RME operation 'serialize(SerialObject*)'
void Serializable::serialize( SerialObject * so )
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType Serializable::getType( void ) const
{
	// {{{USR
	return SERIALIZABLE;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool Serializable::isType( ClassType type ) const
{
	// {{{USR
	return (type == SERIALIZABLE?true:TypedBaseClass::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator Array*()'
Serializable::operator Array*( void )
{
	// {{{USR
	return getSerialized();
	// }}}USR
}
// }}}RME

// {{{RME operation 'getStoreFactory()'
SerialObjectFactory * Serializable::getStoreFactory( void ) const
{
	// {{{USR
	return m_store;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getSizerFactory()'
AbstractSerialSizerFactory * Serializable::getSizerFactory( void ) const
{
	// {{{USR
	return m_sizer;
	// }}}USR
}
// }}}RME

// {{{RME operation 'init(SerialObjectFactory*,AbstractSerialSizerFactory*)'
void Serializable::init( SerialObjectFactory * store, AbstractSerialSizerFactory * sizer )
{
	// {{{USR
	m_store = store;
	m_sizer = sizer;
	// }}}USR
}
// }}}RME

// {{{RME operation 'Serializable()'
Serializable::Serializable( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR

	// }}}USR
}
// }}}RME

// {{{RME operation 'Serializable(Array*)'
Serializable::Serializable( Array * data )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	SerialObject *so = getStoreFactory()->getStore(data);
	deserialize(so);
	delete so;
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR
SerialObject &operator<<(SerialObject &so,Serializable *t)
{
	t->serialize(&so);
	return so;
}	

SerialObject &operator<<(SerialObject &so,Serializable &t)
{
	t.serialize(&so);
	return so;
}	

// }}}USR
// }}}RME

// }}}RME
