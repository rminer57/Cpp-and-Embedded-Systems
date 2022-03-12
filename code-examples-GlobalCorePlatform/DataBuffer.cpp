// {{{RME classifier 'Logical View::DataArray::DataBuffer'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DataBuffer.h"
#endif

#include <data_array.h>
#include <DataBuffer.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'MAX_SIZE'
const unsigned int DataBuffer::MAX_SIZE( 0xFFFFFFFF );
// }}}RME

// {{{RME classAttribute 'DEFAULT_BACK_PADDING'
const unsigned int DataBuffer::DEFAULT_BACK_PADDING( 16 );
// }}}RME

// {{{RME classAttribute 'DEFAULT_FRONT_PADDING'
const unsigned int DataBuffer::DEFAULT_FRONT_PADDING( 8 );
// }}}RME

// {{{RME classAttribute 'DATA_BUFFER_ARRAY'
const unsigned int DataBuffer::DATA_BUFFER_ARRAY( 5 );
// }}}RME

// {{{RME operation 'operator [](unsigned int)'
unsigned char DataBuffer::operator []( unsigned int loc ) const
{
	// {{{USR
	unsigned int index;

	// Figure out where the data is located in m_buffer.
	index = loc + m_start;
	if (index >= m_end)
	{
		index = m_end-1;
	}

	// If there is no user data return 0, otherwise return the
	// data at the appropriate location.
	return getSize() == 0 ? 0 : m_buffer[index];

	// }}}USR
}
// }}}RME

// {{{RME operation 'getType()'
ClassType DataBuffer::getType( void ) const
{
	// {{{USR
	return DATA_BUFFER_ARRAY;
	// }}}USR
}
// }}}RME

// {{{RME operation 'isType(ClassType)'
bool DataBuffer::isType( ClassType type ) const
{
	// {{{USR
	return (type == DATA_BUFFER_ARRAY?true:Array::isType(type));
	// }}}USR
}
// }}}RME

// {{{RME operation 'DataBuffer(const DataBuffer &)'
DataBuffer::DataBuffer( const DataBuffer & buf )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: Array(buf.m_size)
	// }}}USR
	// }}}RME
{
	// {{{USR
	m_size = buf.m_size;
	m_start = buf.m_start;
	m_end = buf.m_end;
	m_buffer = new unsigned char[m_size];
	m_wasteCleanupThreshold = buf.m_wasteCleanupThreshold ;

	if (m_end > m_start)
	{
		memcpy(m_buffer+m_start, buf.m_buffer+m_start, getSize());
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'DataBuffer(const DataBuffer *)'
DataBuffer::DataBuffer( const DataBuffer * buf )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: Array(buf->m_size)
	// }}}USR
	// }}}RME
{
	// {{{USR
	m_size = buf->m_size;
	m_start = buf->m_start;
	m_end = buf->m_end;
	m_buffer = new unsigned char[m_size];
	m_wasteCleanupThreshold = buf->m_wasteCleanupThreshold ;

	if (m_end > m_start)
	{
		memcpy(m_buffer+m_start, buf->m_buffer+m_start, getSize());
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'DataBuffer(void *,unsigned int,bool,unsigned int,unsigned int,unsigned int)'
DataBuffer::DataBuffer( void * buffer, unsigned int length, bool consumeBuffer, unsigned int frontPadding, unsigned int backPadding, unsigned int wasteCleanupThreshold )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: Array(length)
	// }}}USR
	// }}}RME
{
	// {{{USR
	// Initialize the waste cleanup threshold. The threshold must be larger than
	// the default padding in order to avoid thrashing.
	if (wasteCleanupThreshold < frontPadding + backPadding)
	{
		wasteCleanupThreshold = frontPadding + backPadding;
	}
	if (wasteCleanupThreshold < DEFAULT_FRONT_PADDING + DEFAULT_BACK_PADDING)
	{
		wasteCleanupThreshold = DEFAULT_FRONT_PADDING + DEFAULT_BACK_PADDING;
	}
	m_wasteCleanupThreshold = wasteCleanupThreshold;

	if ((buffer != 0) && consumeBuffer)
	{
		// The goal is to be efficient, so take over the buffer passed
		// in rather than doing a copy, and don't add any padding.
		m_size = length;
		m_start = 0;
		m_end = m_size;
		m_buffer = (unsigned char *) buffer;
	}
	else
	{
		// Create a new internal buffer
		m_size = frontPadding + length + backPadding;
		m_buffer = new unsigned char[m_size];
		m_start = frontPadding;
		if (buffer == 0)
		{
			length = 0;
		}
		m_end = m_start + length;
		if (length > 0)
		{
			memcpy(m_buffer+m_start, buffer, length);
		}
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'add(const DataBuffer *,unsigned int)'
bool DataBuffer::add( const DataBuffer * buffer, unsigned int location )
{
	// {{{USR
	return add(buffer->m_buffer + buffer->m_start, buffer->getSize(), location);

			
	// }}}USR
}
// }}}RME

// {{{RME operation 'add(const void *,unsigned int,unsigned int)'
bool DataBuffer::add( const void * buffer, unsigned int length, unsigned int location )
{
	// {{{USR
	bool retVal = true;
	int backPaddingToUse;
	int frontPaddingToUse;
	int i;
	unsigned int newSize;
	unsigned char *newBuffer;

	// If the location is beyond the end of the existing data, append the new data
	if (location > getSize())
	{
		location = getSize();
	}

	if (m_size - getSize() >= length)
	{
		// There is enough available space in m_buffer to fit the new data.
		// Padding space can exist at the front of m_buffer and at the back of m_buffer.
		// Decide which padding space to use, with the goal of minimizing the need to
		// perform an internal copy.
		// If the new data is being pre-pended to the front of the DataBuffer, we would
		// like to use the front padding.
		// If the new data is being appended to the back of the DataBuffer, we would
		// like to use the back padding.
		// If the new data is being inserted in the middle of the DataBuffer, then we prefer
		// to use front padding if the insertion point is close to the front, and we prefer
		// to use back padding if the insertion point is close to the back.

		if (location <= getSize() / 2)
		{
			// This is a pre-pend, or inserting in the middle with insertion point
			// closer to the front of the DataBuffer.
			// This means we prefer to use the front padding.
			if (length <= m_start)
			{
				// There is enough room in front for all of the new data.
				frontPaddingToUse = length;
				backPaddingToUse = 0;
			}
			else
			{
				// We need to use both front padding and back padding.
				frontPaddingToUse = m_start;
				backPaddingToUse = length - frontPaddingToUse;
			}
		}
		else
		{
			// This is a append, or inserting in the middle with insertion point
			// closer to the back of the DataBuffer.
			// This means we prefer to use the back padding.
			if (length <= (m_size - m_end))
			{
				// There is enough room in back for all of the new data.
				backPaddingToUse = length;
				frontPaddingToUse = 0;
			}
			else
			{
				// We need to use both front padding and back padding.
				backPaddingToUse = m_size - m_end;
				frontPaddingToUse = length - backPaddingToUse;
			}
		}

		// Shift some existing data to the front if necessary
		if (frontPaddingToUse > 0)
		{
			for(i=m_start; i<m_start+location; i++)
			{
				m_buffer[i-frontPaddingToUse] = m_buffer[i];
			}
		}

		// Shift some existing data to the back if necessary
		if (backPaddingToUse > 0)
		{
			// Defect CGISS00001781 - avoid letting i become negative
			// because of problems with signed vs. unsigned int comparison
			for(i=m_end; i>m_start+location; i--)
			{
				m_buffer[i-1+backPaddingToUse] = m_buffer[i-1];
			}
		}
		
		// Adjust parameters
		m_start -= frontPaddingToUse;
		m_end += backPaddingToUse;

		// Put the new data in the middle
		memcpy(m_buffer+m_start+location, buffer, length);

	} // Enough room in existing DataBuffer
	else
	{
		// We need to grow into a bigger buffer.
		newSize = getSize() + length + DEFAULT_FRONT_PADDING + DEFAULT_BACK_PADDING;
		newBuffer = new unsigned char[newSize];
		if (newBuffer == 0)
		{
			retVal = false;
		}
		else
		{
			// Copy the old data that came before the insertion point
			memcpy(newBuffer+DEFAULT_FRONT_PADDING, m_buffer+m_start, location);

			// Copy the new data
			memcpy(newBuffer+DEFAULT_FRONT_PADDING+location, buffer, length);

			// Copy the old data that came after the insertion point
			memcpy(newBuffer+DEFAULT_FRONT_PADDING+location+length, m_buffer+m_start+location, getSize()-location);

			// Adjust parameters
			m_size = newSize;
			m_start = DEFAULT_FRONT_PADDING;
			m_end = m_size - DEFAULT_BACK_PADDING;

			// Change to the new buffer
			delete [] m_buffer;
			m_buffer = newBuffer;
		}
	}

	return retVal;
	// }}}USR
}
// }}}RME

// {{{RME operation 'append(const DataBuffer *)'
bool DataBuffer::append( const DataBuffer * buffer )
{
	// {{{USR
	return add(buffer->m_buffer + buffer->m_start, buffer->getSize(), getSize());
	// }}}USR
}
// }}}RME

// {{{RME operation 'append(const void *,unsigned int)'
bool DataBuffer::append( const void * buffer, unsigned int length )
{
	// {{{USR
	return add(buffer, length, getSize());

	// }}}USR
}
// }}}RME

// {{{RME operation 'extractToArray(unsigned int,unsigned int)'
void * DataBuffer::extractToArray( unsigned int start, unsigned int length )
{
	// {{{USR
	unsigned int numBytes;
	unsigned char * returnPtr;
	int i;
	unsigned int size;

	size = getSize();

	// Decide if we should return data or not
	if ((size == 0) ||
		(start >= size) ||
		(length == 0))
	{
		// No valid data to return
		returnPtr = 0;
	}
	else
	{
		// Decide the number of bytes to remove.
		if ((length == MAX_SIZE) ||
		    (length + start > size))
		{
			numBytes = size - start;
		}
		else
		{
			numBytes = length;
		}
		returnPtr = new unsigned char[numBytes];

		// copy the data
		memcpy(returnPtr, m_buffer+m_start+start, numBytes);

		// fill in the gap if data was removed from the middle of the buffer
		for(i=m_start+start+numBytes; i<m_start+size; i++)
		{
			m_buffer[i-numBytes] = m_buffer[i];
		}

		// Adjust the end of data offset
		m_end -= numBytes;

		// Recover excessive memory if needed
		wasteRecovery();
	}

	return returnPtr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'copyToArray(unsigned int,unsigned int)'
void * DataBuffer::copyToArray( unsigned int start, unsigned int length ) const
{
	// {{{USR
	unsigned char * returnPtr;
	unsigned int count;
	unsigned int size;

	size = getSize();

	// The default value for length means copy the entire buffer
	if (length == MAX_SIZE)
	{
		length = size;
	}

	// Decide if we should return data or not
	if ((size  == 0) ||
		(start >= size) ||
		(length == 0))
	{
		// No valid data to return
		returnPtr = 0;
	}
	else
	{
		// Allocate a new buffer for the caller.
		// Even if the requested length goes beyond the end of the data
		// (start + length > m_length), allocate a buffer of the requested length
		// since the caller is likely to assume that much memory has been allocated.
		returnPtr = new unsigned char[length];

		// Figure out how many bytes to copy.	
		if (start + length > size)
		{
			// The requested amount of data goes beyond the end of the DataBuffer.
			count = size - start;
		}
		else
		{
			// The requested amount of data is in range.
			count = length;
		}

		// Copy the data
		memcpy(returnPtr, m_buffer + m_start + start, count);
	}

	return returnPtr;
	// }}}USR
}
// }}}RME

// {{{RME operation 'extractToDataBuffer(unsigned int,unsigned int)'
DataBuffer * DataBuffer::extractToDataBuffer( unsigned int start, unsigned int length )
{
	// {{{USR
	unsigned int size;
	unsigned int numBytes;
	unsigned char * buf;
	int i;

	if (length == MAX_SIZE)
	{
		length = getSize();
	}

	// Decide the number of bytes to extract.
	if (length + start > getSize())
	{
		numBytes = getSize() - start;
	}
	else
	{
		numBytes = length;
	}

	buf = (unsigned char *) extractToArray(start, numBytes);

	return new DataBuffer(buf, numBytes, true);

	// }}}USR
}
// }}}RME

// {{{RME operation 'copyToDataBuffer(unsigned int,unsigned int)'
DataBuffer * DataBuffer::copyToDataBuffer( unsigned int start, unsigned int length ) const
{
	// {{{USR
	unsigned int count;
	unsigned int size;

	size = getSize();

	// The default value for length means copy the entire buffer
	if (length == MAX_SIZE)
	{
		length = size;
	}

	// The starting point cannot be beyond the end of the data.
	if (start > size)
	{
		start = size;
	}

	// Figure out the amount of data to copy.
	if (start + length > size)
	{
		// The requested amount of data goes beyond the end of the DataBuffer.
		count = size - start;
	}
	else
	{
		// The requested amount of data is in range.
		count = length;
	}

	// Create the new DataBuffer
	return new DataBuffer(m_buffer + m_start + start, count);

	// }}}USR
}
// }}}RME

// {{{RME operation '~DataBuffer()'
DataBuffer::~DataBuffer( void )
{
	// {{{USR
	delete [] m_buffer;
	// }}}USR
}
// }}}RME

// {{{RME operation 'operator =(const DataBuffer &)'
DataBuffer DataBuffer::operator=( const DataBuffer & rhs )
{
	// {{{USR
	// Watch out for self assignment
	if (m_buffer != rhs.m_buffer)
	{
		m_size = rhs.m_size;
		m_start = rhs.m_start;
		m_end = rhs.m_end;
		m_wasteCleanupThreshold = rhs.m_wasteCleanupThreshold;

		delete m_buffer;

		m_buffer = new unsigned char[m_size];
		if (m_end > m_start)
		{
			memcpy(m_buffer+m_start, rhs.m_buffer+m_start, getSize());
		}
	}
	return *this;
	// }}}USR
}
// }}}RME

// {{{RME operation 'wasteRecovery()'
void DataBuffer::wasteRecovery( void )
{
	// {{{USR
	unsigned char * newBuffer;
	unsigned int newSize;

	if ( m_size - getSize() > m_wasteCleanupThreshold)
	{
		// The unused space is over the limit, allocate a smaller buffer
		newSize = getSize() + DEFAULT_FRONT_PADDING + DEFAULT_BACK_PADDING;
		newBuffer = new unsigned char[newSize];

		if (newBuffer != 0)
		{
			// Copy over the data
			memcpy(newBuffer+DEFAULT_FRONT_PADDING, m_buffer+m_start, getSize());

			// Adjust parameters
			m_size = newSize;
			m_start = DEFAULT_FRONT_PADDING;
			m_end = m_size - DEFAULT_BACK_PADDING;

			// Change to the new buffer
			delete [] m_buffer;
			m_buffer = newBuffer;
		}
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'erase(unsigned int,unsigned int)'
void DataBuffer::erase( unsigned int start, unsigned int length )
{
	// {{{USR
	unsigned int numBytes;
	int i;
	unsigned int size;
	bool eraseFromBack = false;

	size = getSize();

	// The start location must be within the actual data size,
	// otherwise there is no work to do
	if (start < size)
	{
		// Decide the number of bytes to remove.
		if(length >= size - start)
		{
			// The requested length of bytes to erase goes all the way to the end of
			// the existing bytes, and maybe even beyond.
			numBytes = size - start;
			eraseFromBack = true;
		}
		else
		{
			numBytes = length;
		}

		// Three possible uses are to erase bytes from the front of the DataBuffer,
		// erase bytes from the back of the DataBuffer, or erase from the middle.

		if (start == 0)
		{
			// Data removed from the front of the DataBuffer
			// Adjust the start of data offset
			m_start += numBytes;
		}
		else if (eraseFromBack)
		{
			// Data removed from the back of the DataBuffer
			// Adjust the end of data offset
			m_end -= numBytes;
		}
		else
		{
			// Data removed from the middle of the DataBuffer.
			// Fill in the gap where the data was removed.
			for(i=m_start+start+numBytes; i<m_start+size; i++)
			{
				m_buffer[i-numBytes] = m_buffer[i];
			}
			// Adjust the end of data offset
			m_end -= numBytes;
		}


		// Recover excessive memory if needed
		wasteRecovery();
	}

	// }}}USR
}
// }}}RME

// {{{RME operation 'DataBuffer()'
DataBuffer::DataBuffer( void )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	// By default,start with a buffer containing 0 bytes.

	m_size = DEFAULT_FRONT_PADDING + DEFAULT_BACK_PADDING;
	m_start = DEFAULT_FRONT_PADDING;
	m_end = DEFAULT_FRONT_PADDING;
	m_buffer = new unsigned char[m_size];
	m_wasteCleanupThreshold = MAX_SIZE;
	// }}}USR
}
// }}}RME

// {{{RME operation 'clone()'
Array * DataBuffer::clone( void ) const
{
	// {{{USR
	return copyToDataBuffer();     // return duplicate.
	// }}}USR
}
// }}}RME

// {{{RME operation 'getLength()'
unsigned int DataBuffer::getLength( void ) const
{
	// {{{USR
	return getSize();
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
