// DLLIST.CPP

#include <iostream.h>
#include <stdlib.h>
#include "dllist.h"


/*
Function name : Node::Node(int i)
Description   : default constructor
Inputs        : int i - data value of the node
Outputs       : the initialized object (implied by the code - not returned
		explicitly)
*/
Node::Node(int i)
{
item=i;  next=0; prev=0;
}


/*
Function name : Node::Node(const Node &node)
Description   : copy constructor
Inputs        : const Node &node - reference to the constant Node
				       to be copied from
Outputs       : the initialized object (implied by the code - not returned
		explicitly)
*/

Node::Node(const Node &node)
: item(node.item), next(0), prev(0)
{ }


/*
Function name : Node &Node::operator=(const Node &node)
Description   : assignment operator
Inputs        : const Node &node - reference to the constant Node
				       to be assigned from
Outputs       : Node &           - reference to a Node object
*/

Node &Node::operator=(const Node &node)
{
   if(this == &node)                        // self assignment
      return (*this);
   item = node.item;                        // as integer only just copy
   next = prev = 0;
   return (*this);
}


/*
Function name : Node::~Node()
Description   : destructor
Inputs        : none
Outputs       : none
*/

Node::~Node()
{ }


/*
Function name : ostream &operator<<(ostream &os, const Node &node)
Description   : overloaded << operator
Inputs        : ostream &os          - reference to an ostream type
		const Node &node - reference to a constant
				       Node object
Outputs       : ostream &              - reference to an ostream type
*/

ostream &operator<<(ostream &os, const Node &node)
{
   cout << node.item;
   return (os);
}


/*
Function name : dllist::dllist()
Description   : default constructor
Inputs        : none
Outputs       : the initialized object (implied by the code - not returned
		explicitly)
*/

dllist::dllist()
{
  rear = 0;
  current = 0;
  front = 0;
  nodecount = 0;
  outofmem = 0;
}


/*
Function name : dllist::~dllist()
Description   : destructor
Inputs        : none
Outputs       : none
*/

dllist::~dllist()
{
   destroyList();
}


/*
Function name : dllist::dllist(const dllist &list)
Description   : copy constructor
Inputs        : const dllist &list - reference to the constant dllist
					 to be copied from
Outputs       : the initialized object (implied by the code - not returned
		explicitly)
*/

dllist::dllist(const dllist &list)
   : front(0), current(0), rear(0)
{
   deepCopy(list);
}


/*
Function name : dllist &dllist::operator=(const dllist &list)
Description   : assignment operator
Inputs        : const dllist &list - reference to the constant dllist
					 to be assigned from
Outputs       : dllist &             - reference to the dllist to be
					 assigned to
*/

dllist &dllist::operator=(const dllist &list)
{
   if (this==&list)                        // self assignment
      return (*this);
   destroyList();
   deepCopy(list);
   return (*this);
}


/*
Function name : void  dllist::deepCopy(const dllist &list)
Description   : deep copies one dllist object to another
Inputs        : const dllist &list - reference to the constant dllist
					 to be copied from
Outputs       : none                   - reference to the dllist to be
					 copied to
UpDates         : 'this' object now contains a copy of the list
*/

void dllist::deepCopy(const dllist &list)
{
   Node *NodePtr;

   if (list.isEmpty()) {                  // don't copy an empty list
     return;
   }

   // copy nodes one at a time
   // remember where current is pointing!!
   NodePtr = list.front;
   int count = 0;        // used to keep current!
   int seenCurrent = 0;
   while (NodePtr) {
      insertRear(NodePtr->item);
      if (NodePtr == list.current)
	 seenCurrent = 1;
      if (!seenCurrent && NodePtr != list.current)
	 count++;
      NodePtr = NodePtr->next;
   }

   // now fix up this object's current pointer
   // to match the copy from object
   current = front;
   while (count--)
      current = current->next;
}


/*
Function name : int dllist::atFront() const
Description   : constant function - tests if you are at the front of the list
Inputs        : none
Outputs       : int - return value 1 at front, 0 not at front
*/

int dllist::atFront() const
{
   if (isEmpty() || current != front)
      return (0);
   else
      return (1);
}


/*
Function name : int dllist::atRear() const
Description   : constant function - tests if you are at the rear of the list
Inputs        : none
Outputs       : int - return value 1 at rear, 0 not at rear
*/

int dllist::atRear() const
{
   if (isEmpty() || current != rear)
      return 0;
   else
      return 1;
}


/*
Function name : void dllist::insertFront(int item)
Description   : inserts a node at the front of the list
Inputs        : int item - data value of the node
Outputs       : updated list
*/

void dllist::insertFront(int item)
{
   if (!isEmpty())
      goFront();
      insertBefore(item);
}


/*
Function name : void dllist::insertRear(int item)
Description   : inserts a node at the rear of the list
Inputs        : int item - data value of the node
Outputs       : updated list
*/

void dllist::insertRear(int item)
{
   if (!isEmpty())
      goRear();
   insertAfter(item);
}


/*
Function name : void dllist::insertBefore(int item)
Description   : inserts a node before the current position
Inputs        : int item - data value of the node
Outputs       : updated list
*/

void dllist::insertBefore(int item)
{
   Node *p;
   p = new Node(item);
   if (p == 0)
     {
      outofmem=1;
      Error("Memory Error\nProgram Aborting ...\n");
     }
   if (isEmpty()) {                        // first node in list
      front = current = rear = p;
      p->next = p->prev = 0;
   } else {                               // insert before current position
      p->next = current;
      p->prev = current->prev;
      if (current->prev)
	 current->prev->next = p;
	 current->prev = p;
	    if (front == current)
	       front = p;
	 current = p;
      }
      nodecount++;

}

/*
Function name : void dllist::insertAfter(int item)
Description   : inserts a node after the current position
Inputs        : int item - data value of the node
Outputs       : updated list
*/

void dllist::insertAfter(int item)
{
   Node *p;
   if (isEmpty())                          // first node in list
      insertBefore(item);
   else {
      p = new Node(item);
      if (p == 0)
       {
	outofmem=1;
	Error("Memory Error\nProgram Aborting ...\n");
       }
      nodecount++;
      p->prev = current;                  // insert after current position
      p->next = current->next;
      if (current->next)
	 current->next->prev = p;
	 current->next = p;
	 if (rear == current)
	    rear = p;
	    current = p;
   }
}


/*
Function name : void dllist::removeCurrent()
Description   : removes the current node from the list
Inputs        : none
Outputs       : updated list
*/

void dllist::removeCurrent()
{
   Node *p;
   if (isEmpty())
      Error("Can't remove an element when the list is empty");
   p = current;
   if (p->next)
      p->next->prev = p->prev;
   if (p->prev)
      p->prev->next = p->next;
   if (p == front)
      front = p->next;
   if (p == rear)
      rear = p->prev;
   if (p->next == 0)
      current = rear;
   else
      current = p->next;
   delete p;
      nodecount--;

}


/*
Function name : void dllist::next()
Description   : move up one position in the list
Inputs        : none
Outputs       : updated list
*/

void dllist::next()
{
   if (isEmpty())
      Error("Can't next : list is empty");
   else
      current = current->next;
}


/*
Function name : void dllist::prev()
Description   : move back one position in the list
Inputs        : none
Outputs       : updated list
*/

void dllist::prev()
{
   if (isEmpty())
      Error("Can't prev : list is empty");
   else
      current = current->prev;
}

/*
Function name : int dllist::isEmpty() const
Description   : constant function - test for an empty list
Inputs        : none
Outputs       : int - return value 1 if empty, 0 if not
*/

int dllist::isEmpty() const
{
   return ( front == 0 ? 1 : 0 );
}


/*
Function name : void dllist::goFront()
Description   : sets current to the front of the list
Inputs        : none
Outputs       : updated list
*/

void dllist::goFront()
{
   if (isEmpty())
      Error("An empty list doesn't have a front");
   current = front;
}


/*
Function name : void dllist::goRear()
Description   : sets current to the rear of the list
Inputs        : none
Outputs       : updated list
*/

void dllist::goRear()
{
   if (isEmpty())
      Error("An empty list doesn't have a rear");
   current = rear;
}


/*
Function name : int dllist::locate(int it)
Description   : locates a specified node in the list
Inputs        : int it - item to be located
Outputs       : int - returns 1 if found, 0 if not found
*/

int dllist::locate(int it)
{
   int currItem;
   if (isEmpty())
      Error("Can't locate an element in an empty list");
   while (!atRear()) {
      retrieve(currItem);
      if (it == currItem)
	 return 1;
      else
	 next();
      }
      retrieve(currItem);
      if (it == currItem)                // check rear
	 return 1;
      return 0;
}


/*
Function name : void dllist::retrieve(int &item) const
Description   : constant function - retrieves the data value
		of the current item
Inputs        : int &item - data value to be retrieved
Outputs       : returns - value of the data to be retrieved
*/

void dllist::retrieve(int &item) const
{
   if (isEmpty())
      Error("Can't retrieve from an empty list");
   item = current->item;
}


/*
Function name : void dllist::Error(const char *s) const
Description   : prints an error message then terminates program
Inputs        : const char *s - error message to be printed
Outputs       : prints error message to stderr
*/

void dllist::Error(const char *s) const
{
   cerr << "DLList Error : " <<  s << endl;
   exit(1);
}


/*
Function name : ostream &operator<<(ostream &os, const dllist &list)
Description   : overloaded << operator
Inputs        : ostream &os      - reference to an ostream type
		const dllist &list - reference to the dllist to be
				   sent to the ostream
Outputs       : ostream &        - reference to an ostream type
*/

ostream &operator<<(ostream &os, const dllist &list)
{
   dllist tempList(list);
   int info;

   if (tempList.isEmpty()){
      cout << "{ }" << endl;
   } else {
      cout << "{ ";
      while (!tempList.atRear()) {
	 tempList.retrieve(info);
	 cout << info << " ";
	 tempList.next();
      }
      tempList.retrieve(info);
      cout << info << " }" << endl;
   }
   return (os);
}


/*
Function name : void dllist::destroyList()
Description   : unallocates previously allocated memory
Inputs        : none
Outputs       : none
*/

void dllist::destroyList()
{
   if (!isEmpty()) {
      goFront();
      while (!atRear())
	 removeCurrent();
      removeCurrent();                    // don't forget the rear cell
   }
   nodecount=0;
}


/*
Function name : void dllist::purge()
Description   : removes duplicates from the list
Inputs        : none
Outputs       : updated list
*/

void dllist::purge()
{
   int j;
   int k = 0;
   int item1;
   if (isEmpty())
      return;
   goFront();
   while (1) {
      if (atRear())
	 break;
      retrieve(item1);
      next();
      while (locate(item1))
	 removeCurrent();
      goFront();
      k++;
      for (j=1; j<=k; j++)
	 next();
   }
   goFront();
}


/*
Function name : void dllist::orderInsert(int item)
Description   : inserts a node into the list in ascending order
Inputs        : int item - data to be inserted into the list
Outputs       : updated list
*/

void dllist::orderInsert(int item)
{
   int currItem;

   if (isEmpty()) {
      insertBefore(item);
      return;
   }
   goFront();
   while (!atRear()) {
      retrieve(currItem);
      if (item <= currItem) {
	 insertBefore(item);
	 return;
      } else
	 next();
      }
      retrieve(currItem);
      if (item <= currItem)               // handle at rear condition
	 insertBefore(item);
      else
	 insertAfter(item);
}

void dllist::print()
{
	ItemType item;
	Node *temp;
	if (isEmpty())
		cout << endl << "emptylist { }" << endl;
	else {
		temp = current;      /*save initial current pointer */
		cout << "cnt=" << nodecount << " ";
		cout << "{";
		while (!atRear()) {    /* do all but rear item */
			retrieve(item);
			cout << " " << item;
			next();
		}
		retrieve(item);   /*do rear item */
		cout << " " << item << "}" << endl;
		current = temp;
	}
}

int dllist::getcount()
{
  return nodecount;
}
int dllist::isoutofmem()
{
 return(outofmem);
}