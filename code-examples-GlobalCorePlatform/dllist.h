
//Description : header file declaring Node object and dllist object
//              with associated functions

#ifndef __DLLIST_HPP__
#define __DLLIST_HPP__

#include <iostream.h>

typedef int ItemType;

class Node {                  // This is a node in the list
private:
   ItemType item;                    // The data itsef
   Node *next;                 // Pointer to the next list node
   Node *prev;                 // Pointer to the previous list node
   Node(int i = 0);                     // Default constructor
   Node(const Node &);            // Copy constructor
   Node &operator=(const Node &);   // Assignment operator
   ~Node();                           // Destructor

   friend ostream &operator<<(ostream &, const Node &);
   friend class dllist;

};

class dllist {                // This is the list header
private:
   Node *front;              //   Pointer to the first list node
   Node *rear;               // Pointer to the rear list node
   Node *current;            // Pointer to the current list node
   int nodecount;
   int outofmem;
   void Error(const char *) const;      // Error handler
   void deepCopy(const dllist &);
   friend ostream &operator<<(ostream &, const dllist &);
						// Output operator
public:
   dllist();                                 // Default constructor
   dllist(const dllist &);               // Copy constructor
   dllist &operator=(const dllist &);   // Assignment operator
   ~dllist();                                 // Destructor

   int isEmpty() const;
   int atFront() const;
   int atRear() const;
   int locate(int i = 0);
   void retrieve(int &) const;
   void next();
   void prev();
   void removeCurrent();
   void insertFront(int i = 0);
   void insertRear(int i = 0);
   void insertBefore(int i = 0);
   void insertAfter(int i = 0);
   void orderInsert(int i = 0);
   void goFront();
   void goRear();
   void destroyList();
   void purge();
   void print();
   int  getcount();
   int  isoutofmem();
};

#endif
