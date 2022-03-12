// {{{RME classifier 'Logical View::HAL Instantiation::IO Devices::Logical::KeypadScanner::KeypadScanner'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "KeypadScanner.h"
#endif

#include <iodev_comp.h>
#include <KeypadScanner.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME operation 'KeypadScanner(unsigned int,unsigned int,IOVirtual**,IOVirtual**)'
KeypadScanner::KeypadScanner( unsigned int numRows, unsigned int numCols, IOVirtual * * rowArrayPtr, IOVirtual * * colArrayPtr )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR
	: m_numRows(numRows), m_numCols(numCols), m_rowArray(rowArrayPtr), m_colArray(colArrayPtr)
	// }}}USR
	// }}}RME
{
	// {{{USR
	unsigned int i;

	// Need to register with the row objects first

	for (i=0;i < numRows;i++)
	{
		m_rowArray[i]->registerListener(this, IOVirtual::Event::EVENT_IO_LEVEL_CHANGE);
	}

	// Activate the keypad columns now that we are ready to receive events

	for (i=0;i < numCols;i++)
	{
		m_colArray[i]->send(1);
	}


	// }}}USR
}
// }}}RME

// {{{RME operation 'receive()'
KeypadVirtual::RowColumn & KeypadScanner::receive( void )
{
	// {{{USR
	unsigned int keysPressed = 0;
	unsigned int i;
	unsigned int j;

	// Don't want to receive any events during scanning
	for (i=0;i < m_numRows;i++)
	{
		m_rowArray[i]->unregisterListener(this, IOVirtual::Event::IO_EVENT);
	}

	// Ensure no columns are activated before scanning

	for (i=0;i < m_numCols;i++)
	{
		m_colArray[i]->receive();
	}

	// Start the scan.  A key is pressed when the value returned
	// by receive() on a row equals the value passed to send() on
	// the active column, e.g. if send(1) activates column Y and
	// receive() on row X returns 1, then the key at (X,Y) is pressed.

	for (i=0;i < m_numCols;i++)
	{
		m_colArray[i]->send(1);

		for (j=0;j < m_numRows;j++)
		{	
			if (m_rowArray[j]->receive() == 1)
			{
				m_rowCol.m_row = j;
				m_rowCol.m_column = i;
				keysPressed++;
			}
		}

		m_colArray[i]->receive();
	}

	m_rowCol.m_flag = (keysPressed == 1);

	// Re-activate the columns
	for (i=0;i < m_numCols;i++)
	{
		m_colArray[i]->send(1);
	}

	// OK to receive events now.
	for (i=0;i < m_numRows;i++)
	{
		m_rowArray[i]->registerListener(this, IOVirtual::Event::IO_EVENT);
	}

	return m_rowCol;
	// }}}USR
}
// }}}RME

// {{{RME operation '~KeypadScanner()'
KeypadScanner::~KeypadScanner( void )
{
	// {{{USR
	unsigned int i;

	// Need to de-register from the IOVirtuals and delete them

	for (i=0;i < m_numRows;i++)
	{
		m_rowArray[i]->unregisterListener(this, IOVirtual::Event::EVENT_IO_LEVEL_CHANGE);
		delete m_rowArray[i];
		m_rowArray[i] = 0;
	}

	// De-activate and delete the columns
	for (i=0;i < m_numCols;i++)
	{
		m_colArray[i]->send(0);
		delete m_colArray[i];
		m_colArray[i] = 0;
	}

	delete[] m_rowArray;
	delete[] m_colArray;

	// }}}USR
}
// }}}RME

// {{{RME operation 'eventOccurred(const EventBase* const)'
void KeypadScanner::eventOccurred( const EventBase * const event )
{
	// {{{USR
	informListeners(&m_eventPtr);
	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
