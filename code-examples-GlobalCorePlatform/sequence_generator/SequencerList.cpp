#include "SequencerList.h"
#include "SequenceExecuteClass.h"
#include "SequenceJumpClass.h"
#include "SequenceManipulate.h"
#include "SequenceMiscClass.h"



//**Add the implementation for serialization
//IMPLEMENT_SERIAL(SequencerList, CObject, VERSIONABLE_SCHEMA )


SequencerList::SequencerList()
{
  head = NULL;
  tail = NULL;
  size = 0;
};

SequencerList::~SequencerList()
{
	int tempSize = size;
  for (int i = 0; i < tempSize; i++)
  {
    removeFromTail();
  }
  
  head = NULL;
  tail = NULL;
};

bool SequencerList::isEmpty()
{
  return (size == 0);
}

int SequencerList::getSize()
{
  return size;
}

SequenceCommandBaseClass * SequencerList::getAt(int location)
{
  SequenceCommandBaseClass *returnVal = NULL;
  
  if ((location <= size)  && (location > 0))
  {
    ListNodePtr tempNode = getNode(location);
    returnVal = tempNode->data;
  }
  
  return returnVal;
}

void SequencerList::setAt(int location, SequenceCommandBaseClass *newData)
{
  if ((location <= size)  && (location > 0))
  {
    ListNodePtr temp = getNode(location);
	temp->data = newData;
  }
}

void SequencerList::insertAt(int location, SequenceCommandBaseClass *newData)
{
  if (location  == 1)
  {
    addToHead(newData);
  }
  else if ((location <= size) && (location > 0))
  {
    ListNodePtr nNode = getNode(location);
    ListNodePtr pNode = nNode->previous;
    ListNodePtr newNode = new ListNode;
    
    pNode->next = newNode;
    nNode->previous = newNode;
    
    newNode->next = nNode;
    newNode->previous = pNode;
    newNode->data = newData;
    
    size++;
  }
  else if (location == (size+1))
  {
    addToTail(newData);
  }
}

void SequencerList::removeFrom(int location)
{
  if (location == 1)
  {
    removeFromHead();
  }
  else if (location == size)
  {
    removeFromTail();
  }
  else if ((location < size) && (location > 0))
  {
    ListNodePtr oldNode = getNode(location);
    ListNodePtr pNode = oldNode->previous;
    ListNodePtr nNode = oldNode->next;
    
    pNode->next = nNode;
    nNode->previous = pNode;
   // delete oldNode;
	oldNode = NULL;
    
    size--;
  }
}

void SequencerList::addToTail(SequenceCommandBaseClass *newData)
{
  ListNodePtr newNode = new ListNode;
  
  if (tail != NULL)
  {
    tail->next = newNode;
    newNode->previous = tail;
  }
  else
  {
    newNode->previous = NULL;
    head = newNode;
  }
  
  newNode->next = NULL;
  newNode->data = newData;
  tail = newNode;
  
  size++;
}

void SequencerList::addToHead(SequenceCommandBaseClass *newData)
{
  ListNodePtr newNode = new ListNode;
  
  if (head != NULL)
  {
    head->previous = newNode;
    newNode->next = head;
  }
  else
  {
    newNode->next = NULL;
    tail = newNode;
  }
  
  newNode->previous = NULL;
  newNode->data = newData;
  head = newNode;
  
  size++;
}

void SequencerList::removeFromTail()
{
  if (!isEmpty())
  {
    if (size == 1)
    {
	  //if(tail != NULL)
	//	delete tail;
      tail = NULL;
      head = NULL;
    }
    else
    {
      tail = tail->previous;
      
      //destroy tail->next object
     // delete tail->next;
      
      tail->next = NULL;
    }
    
    size--;
  }
}

void SequencerList::removeFromHead()
{
  if (!isEmpty())
  {
    if (size == 1)
    {
	  //if(head != NULL)
	//	delete head;
      tail = NULL;
      head = NULL;
    }
    else
    {
      head = head->next;
      
      //destroy head->previous object
     // delete head->previous;
      
      head->previous = NULL;
    }
    
    size--;
  }
}

void SequencerList::swap(int location1, int location2)
{
  if ((location1 > 0) && (location1 <= size) && (location2 > 0) && (location2 <= size))
  {
    SequenceCommandBaseClass *temp1 = getAt(location1);
    setAt(location1, getAt(location2));
    setAt(location2, temp1);
  }
}

ListNode::ListNode()
{
  next = NULL;
  previous = NULL;
  data = new SequenceCommandBaseClass;
}

ListNode::~ListNode()
{
  next = NULL;
  previous = NULL;
  
  if(data != NULL)
	delete data;
  
  data = NULL;
}

ListNodePtr SequencerList::getNode(int location)
{
  ListNodePtr  tempNode = head;
  for (int i=1; i < location; i++)
  {
    tempNode = tempNode->next;
	
  }
  
  return tempNode;
}

//Serialize Method
void SequencerList::Serialize(CArchive &ar)
{
	int tempSize = size;
//	CObject::Serialize(ar);
	if(ar.IsStoring())
	{
	//	ar << head;
		ar << size;
	//	ar << tail;

		//ar << 1 << 2 << 3 << 4;
		
		for(int i = 1; i <= size; i++)
		{
			getAt(i)->Serialize(ar);
		}
	}
	else
	{	
	
		
		//ar >> head;
		ar >> tempSize;
		//ar >> tail;

		//tempSize = size;
		SequenceCommandBaseClass *tempObject;
		int tempOpcode;
		

		for(int i = 0; i < tempSize; i++)
		{
			ar >> tempOpcode;


			switch(tempOpcode)
			{
			case 0:
				{
					tempObject = new SequenceExecuteClass;
				}
				break;
			case 1:
				{
					tempObject = new SequenceManipulate;
				}
				break;
			case 2:
				{
					tempObject = new SequenceJumpClass;
				}
				break;
			case 3:
				{
					tempObject = new SequenceMiscClass;
				}
					break;
			default:
				{
					tempObject = new SequenceCommandBaseClass;
				}
				break;
			}
			tempObject->setOpcode(tempOpcode);
			tempObject->Serialize(ar);
			addToTail(tempObject);
		}
	}
}