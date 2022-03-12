// {{{RME classifier 'Logical View::DataArray::DataBuffer'

#ifndef DataBuffer_H
#define DataBuffer_H

#ifdef PRAGMA
#pragma interface "DataBuffer.h"
#endif

#include <data_array.h>
#include <Array.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

class DataBuffer : public Array
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

protected:
	// {{{RME classAttribute 'MAX_SIZE'
	static const unsigned int MAX_SIZE;
	// }}}RME
	// {{{RME classAttribute 'm_buffer'
	unsigned char * m_buffer;
	// }}}RME
	// {{{RME classAttribute 'm_start'
	unsigned int m_start;
	// }}}RME
	// {{{RME classAttribute 'm_end'
	unsigned int m_end;
	// }}}RME
	// {{{RME classAttribute 'm_size'
	unsigned int m_size;
	// }}}RME
	// {{{RME classAttribute 'DEFAULT_BACK_PADDING'
	static const unsigned int DEFAULT_BACK_PADDING;
	// }}}RME
	// {{{RME classAttribute 'DEFAULT_FRONT_PADDING'
	static const unsigned int DEFAULT_FRONT_PADDING;
	// }}}RME
	// {{{RME classAttribute 'm_wasteCleanupThreshold'
	unsigned int m_wasteCleanupThreshold;
	// }}}RME

public:
	// {{{RME classAttribute 'DATA_BUFFER_ARRAY'
	static const unsigned int DATA_BUFFER_ARRAY;
	// }}}RME
	// {{{RME operation 'operator [](unsigned int)'
	virtual unsigned char operator []( unsigned int loc ) const;
	// }}}RME
	// {{{RME operation 'getType()'
	virtual ClassType getType( void ) const;
	// }}}RME
	// {{{RME operation 'isType(ClassType)'
	virtual bool isType( ClassType type ) const;
	// }}}RME
	// {{{RME operation 'DataBuffer(const DataBuffer &)'
	DataBuffer( const DataBuffer & buf );
	// }}}RME
	// {{{RME operation 'DataBuffer(const DataBuffer *)'
	DataBuffer( const DataBuffer * buf );
	// }}}RME
	// {{{RME operation 'DataBuffer(void *,unsigned int,bool,unsigned int,unsigned int,unsigned int)'
	DataBuffer( void * buffer, unsigned int length, bool consumeBuffer = false, unsigned int frontPadding = DEFAULT_FRONT_PADDING, unsigned int backPadding = DEFAULT_BACK_PADDING, unsigned int wasteCleanupThreshold = MAX_SIZE );
	// }}}RME
	// {{{RME operation 'add(const DataBuffer *,unsigned int)'
	virtual bool add( const DataBuffer * buffer, unsigned int location = 0 );
	// }}}RME
	// {{{RME operation 'add(const void *,unsigned int,unsigned int)'
	virtual bool add( const void * buffer, unsigned int length, unsigned int location = 0 );
	// }}}RME
	// {{{RME operation 'append(const DataBuffer *)'
	virtual bool append( const DataBuffer * buffer );
	// }}}RME
	// {{{RME operation 'append(const void *,unsigned int)'
	virtual bool append( const void * buffer, unsigned int length );
	// }}}RME
	// {{{RME operation 'extractToArray(unsigned int,unsigned int)'
	virtual void * extractToArray( unsigned int start = 0, unsigned int length = MAX_SIZE );
	// }}}RME
	// {{{RME operation 'copyToArray(unsigned int,unsigned int)'
	virtual void * copyToArray( unsigned int start = 0, unsigned int length = MAX_SIZE ) const;
	// }}}RME
	// {{{RME operation 'getSize()'
	inline virtual unsigned int getSize( void ) const
	{
		// {{{USR
		return m_end - m_start;
		// }}}USR
	}
	// }}}RME
	// {{{RME operation 'extractToDataBuffer(unsigned int,unsigned int)'
	virtual DataBuffer * extractToDataBuffer( unsigned int start = 0, unsigned int length = MAX_SIZE );
	// }}}RME
	// {{{RME operation 'copyToDataBuffer(unsigned int,unsigned int)'
	virtual DataBuffer * copyToDataBuffer( unsigned int start = 0, unsigned int length = MAX_SIZE ) const;
	// }}}RME
	// {{{RME operation '~DataBuffer()'
	virtual ~DataBuffer( void );
	// }}}RME
	// {{{RME operation 'operator =(const DataBuffer &)'
	virtual DataBuffer operator=( const DataBuffer & rhs );
	// }}}RME

protected:
	// {{{RME operation 'wasteRecovery()'
	void wasteRecovery( void );
	// }}}RME

public:
	// {{{RME operation 'erase(unsigned int,unsigned int)'
	virtual void erase( unsigned int start = 0, unsigned int length = MAX_SIZE );
	// }}}RME
	// {{{RME operation 'DataBuffer()'
	DataBuffer( void );
	// }}}RME

private:
	// {{{RME operation 'memcpy(void *,const void *,int)'
	inline static void memcpy( void * dest, const void * source, int size )
	{
		// {{{USR
		char *t_dest = (char *)dest;
		char *t_source = (char *)source;
		while(size-- > 0) *t_dest++ = *t_source++;
		// }}}USR
	}
	// }}}RME

public:
	// {{{RME operation 'clone()'
	virtual Array * clone( void ) const;
	// }}}RME
	// {{{RME operation 'getLength()'
	virtual unsigned int getLength( void ) const;
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DataBuffer_H */

// }}}RME
