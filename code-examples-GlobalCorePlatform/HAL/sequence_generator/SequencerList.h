#include "SequenceCommandBaseClass.h"
#ifndef SEQ_LIST_H
#define SEQ_LIST_H 1
#ifndef NULL
#define NULL 0
#endif

class ListNode 
{

	
	


public:
  SequenceCommandBaseClass *data;
  ListNode *next;
  ListNode *previous;
  
  ListNode();
  ~ListNode();
};

typedef ListNode *ListNodePtr;

class SequencerList //: public CObject
{

//**Include Serialization functions
//DECLARE_SERIAL(SequencerList);

public:
  SequencerList();
  ~SequencerList();
  bool isEmpty();
  int getSize();
  SequenceCommandBaseClass *getAt(int location);
  void setAt(int location, SequenceCommandBaseClass *newData);
  void insertAt(int location, SequenceCommandBaseClass *newData);
  void removeFrom(int location);
  void addToTail(SequenceCommandBaseClass *newData);
  void addToHead(SequenceCommandBaseClass *newData);
  void removeFromTail();
  void removeFromHead();
  void swap(int location1, int location2);  

  //Serialize method
  virtual void Serialize(CArchive &ar);
  
protected:
  
private:
  ListNodePtr getNode(int location);
  
  ListNodePtr head;
  ListNodePtr tail;
  int size;
};
#endif