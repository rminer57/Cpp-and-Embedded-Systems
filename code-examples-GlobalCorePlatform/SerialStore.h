// {{{RME classifier 'Logical View::Serialization::SerialStore'

#ifndef SerialStore_H
#define SerialStore_H

#ifdef PRAGMA
#pragma interface "SerialStore.h"
#endif

#include <serialize_comp.h>
#include <SIntArray.h>
#include <SerialObject.h>
class SerialBits;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdint.h>
// }}}USR
// }}}RME

class SerialStore : public SIntArray, public SerialObject
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
	// {{{RME classAttribute 'm_index'
	unsigned int m_index;
	// }}}RME
	// {{{RME classAttribute 'm_bitOffset'
	unsigned int m_bitOffset;
	// }}}RME

public:
	// {{{RME classAttribute 'STORESIZE'
	static const unsigned int STORESIZE;
	// }}}RME
	// {{{RME classAttribute 'SERIAL_STORE'
	static const unsigned int SERIAL_STORE;
	// }}}RME
	// {{{RME operation 'SerialStore(SIntArray*)'
	SerialStore( SIntArray * buffer );
	// }}}RME
	// {{{RME operation 'operator <<(int)'
	virtual SerialObject & operator <<( int i );
	// }}}RME
	// {{{RME operation 'operator <<(unsigned int)'
	virtual SerialObject & operator <<( unsigned int i );
	// }}}RME
	// {{{RME operation 'operator <<(char)'
	virtual SerialObject & operator <<( char i );
	// }}}RME
	// {{{RME operation 'operator <<(unsigned char)'
	virtual SerialObject & operator <<( unsigned char i );
	// }}}RME
	// {{{RME operation 'operator <<(bool)'
	virtual SerialObject & operator <<( bool i );
	// }}}RME
	// {{{RME operation 'operator >>(int&)'
	SerialObject & operator >>( int & i );
	// }}}RME
	// {{{RME operation 'operator >>(unsigned int&)'
	SerialObject & operator >>( unsigned int & i );
	// }}}RME
	// {{{RME operation 'operator >>(char&)'
	SerialObject & operator >>( char & i );
	// }}}RME
	// {{{RME operation 'operator >>(unsigned char&)'
	SerialObject & operator >>( unsigned char & i );
	// }}}RME
	// {{{RME operation 'operator >>(bool&)'
	SerialObject & operator >>( bool & i );
	// }}}RME
	// {{{RME operation 'setType(ClassType)'
	void setType( ClassType t );
	// }}}RME

private:
	// {{{RME operation 'put(unsigned int,unsigned int)'
	void put( unsigned int data, unsigned int loc = 0 );
	// }}}RME
	// {{{RME operation 'get(unsigned int)'
	unsigned int get( unsigned int loc = 0 ) const;
	// }}}RME
	// {{{RME operation 'storeData(unsigned int,unsigned int)'
	void storeData( unsigned int data, unsigned int size );
	// }}}RME
	// {{{RME operation 'getData(unsigned int)'
	unsigned int getData( unsigned int size );
	// }}}RME

public:
	// {{{RME operation 'getSerialType()'
	virtual ClassType getSerialType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'SerialStore(unsigned int)'
	SerialStore( unsigned int s );
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'reset()'
	virtual void reset( void );
	// }}}RME
	// {{{RME operation 'operator <<(SerialBits&)'
	virtual SerialObject & operator <<( SerialBits & i );
	// }}}RME
	// {{{RME operation 'operator >>(SerialBits&)'
	virtual SerialObject & operator >>( SerialBits & i );
	// }}}RME
	// {{{RME operation 'operator <<(long)'
	virtual SerialObject & operator <<( long i );
	// }}}RME
	// {{{RME operation 'operator >>(long&)'
	virtual SerialObject & operator >>( long & i );
	// }}}RME
	// {{{RME operation 'operator <<(unsigned long)'
	virtual SerialObject & operator <<( unsigned long i );
	// }}}RME
	// {{{RME operation 'operator >>(unsigned long&)'
	virtual SerialObject & operator >>( unsigned long & i );
	// }}}RME
	// {{{RME operation 'SerialStore(unsigned int,int16_t*)'
	SerialStore( unsigned int s, int16_t * buffer );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SerialStore_H */

// }}}RME
