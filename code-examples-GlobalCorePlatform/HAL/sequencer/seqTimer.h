#ifndef SEQ_TIMER_H
#define SEQ_TIMER_H

#include "rfTimer.h"

class seqTimer : public rfTimer
{
public:
  seqTimer(){};
  ~seqTimer(){};
  void delay(Integer time){};
  
protected:
  
private:
};

#endif // SEQ_TIMER_H