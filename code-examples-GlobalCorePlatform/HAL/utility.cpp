// {{{RME classifier 'Logical View::HAL Instantiation::Standard Includes::utility'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "utility.h"
#endif

#include <HALtestLib_win32.h>
#include <utility.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR
// used within sqrt calculation
#define INNER_SQRT(s)                                     \
  temp = (square_root_val << (s)) + (1 << ((s) * 2 - 2)); \
  if (val >= temp)                                        \
  {                                                       \
    square_root_val += 1 << ((s)-1);                      \
    val -= temp;                                          \
  }

// }}}USR
// }}}RME

// {{{RME operation 'rev_bits(uint32_t,uint32_t)'
uint32_t utility::rev_bits( uint32_t data_to_reverse, uint32_t number_of_bits )
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------
	  
	  uint32_t reversed_bits = 0;
	  uint32_t loop_counter;   
	  
	  //---------------------------------- CODE ------------------------------------   
	  
	  for (loop_counter = number_of_bits; loop_counter > 0; loop_counter--) 
	  {
	    reversed_bits = (reversed_bits << 1) + (data_to_reverse & 1);
	    
	    // shift next bit 
	    data_to_reverse = data_to_reverse >> 1;     
	  }
	  return reversed_bits;     

	// }}}USR
}
// }}}RME

// {{{RME operation 'minInt(Integer,Integer)'
Integer utility::minInt( Integer int1, Integer int2 )
{
	// {{{USR
	  return (int1 < int2)?int1:int2;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'maxInt(Integer,Integer)'
Integer utility::maxInt( Integer int1, Integer int2 )
{
	// {{{USR
	  return (int1 > int2)?int1:int2;  

	// }}}USR
}
// }}}RME

// {{{RME operation 'check_range(Integer,Integer,Integer)'
Boolean utility::check_range( Integer freq_value, Integer ref_freq_value, Integer percent )
{
	// {{{USR
	  //----------------------------- LOCAL VARIABLES ------------------------------

	  UInteger remainder;
	  UInteger low_2_percent;
	  UInteger high_2_percent;
	  Boolean  condition_ok;  
	  
	  //---------------------------------- CODE ------------------------------------
	  
	  remainder = (freq_value)%(ref_freq_value);
	  low_2_percent = (UInteger)((percent/100)*ref_freq_value);
	  high_2_percent = (UInteger)((1 - (percent/100))*ref_freq_value);
	  condition_ok = ((remainder > low_2_percent) && (remainder < high_2_percent));
	  return condition_ok;

	// }}}USR
}
// }}}RME

// {{{RME operation 'square_root(uint32_t)'
uint16_t utility::square_root( uint32_t val )
{
	// {{{USR
	  // this algorithm was found on http://www.azillionmonkeys.com/qed/sqroot.html
	  
	  uint32_t temp;
	  uint32_t square_root_val = 0;

	  if (val >= 0x40000000)
	  {
	    square_root_val = 0x8000; 
	    val -= 0x40000000;
	  }

	  INNER_SQRT (15)
	  INNER_SQRT (14)
	  INNER_SQRT (13)
	  INNER_SQRT (12)
	  INNER_SQRT (11)
	  INNER_SQRT (10)
	  INNER_SQRT ( 9)
	  INNER_SQRT ( 8)
	  INNER_SQRT ( 7)
	  INNER_SQRT ( 6)
	  INNER_SQRT ( 5)
	  INNER_SQRT ( 4)
	  INNER_SQRT ( 3)
	  INNER_SQRT ( 2)

	  temp = square_root_val+square_root_val+1;
	  if (val >= temp)
	  {
	     square_root_val++;
	  }
	   
	  return ( (uint16_t)square_root_val);

	// }}}USR
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
