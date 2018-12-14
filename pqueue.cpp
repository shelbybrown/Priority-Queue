// CSCI 2530
// Assignment: 6
// Author:     Shelby Brown
// File:       pqueue.cpp
// Tab stops:  ***

/* The program is a module that implements priority queues,
with a header file called pqueue.h that describes what the 
this program will export.
*/


#include <cstdio>
#include "pqueue.h"
using namespace std;

/* An object of type PQCell holds an item and a pointer
to the next cell in the list.

The fields are: 
priority  holds an item.  
item      points to the next cell in the list.
*/

struct PQCell
{
  PriorityType priority;
  ItemType item;
  PQCell* next;

  PQCell(ItemType x, PriorityType p)
  {
    priority = p;
    item = x;
    next = NULL;
  }

};

//isEmpty() checks to see if PriorityQueue object 'q'
//is empty.
//If q is empty then it will return true, and if not
//then it will return false.

bool isEmpty(const PriorityQueue& q)
{
  return q.linkedList == NULL;
}

//insertCell() inserts a PQCell into the PriorityQueue
//in acsending order.

void insertCell(PQCell*& L, ItemType x, PriorityType p)
{
  if(L == NULL)
  {
    PQCell* newCell = new PQCell(x, p);
    /*newCell->item = x;
    newCell->priority = p;
    newCell->next = NULL;*/
    L = newCell;
  }
  else if(p <= L -> priority)
  {
    PQCell* newCell = new PQCell(x, p);
    /*newCell->item = x;
    newCell->priority = p;*/
    newCell->next = L;
    L = newCell;
  }
  else
  {
    insertCell(L -> next, x, p);
  }
}

//insert() inserts item 'x' with priority 'p' into
//PriorityQueue object 'q'.

void insert(PriorityQueue& q, ItemType x, PriorityType p)
{
  insertCell(q.linkedList, x, p);
}

//printPriorityQueue() writes the priority queue of 
//parameter 'q' to standard output.
//The function will display the PriorityQueue in
//acsending order.

void printPriorityQueue(const PriorityQueue& q, ItemPrinter pi, PriorityPrinter pp)
{
  PQCell* acsend = q.linkedList;
  while(acsend != NULL)
  {
    pi(acsend -> item);
    printf("\n");
    pp(acsend -> priority);
    printf("\n\n");
    acsend = acsend -> next;
  }
}

//remove() removes the smallest priority from 'q'.
//The function will store the smallest priority in
//out-parameters: 'x' and 'p'.

void remove(PriorityQueue& q, ItemType& x, PriorityType& p)
{
  if(!isEmpty(q))
  {
    x = q.linkedList->item;
    p = q.linkedList->priority;

    PQCell* empty;

    empty = q.linkedList->next;
    delete q.linkedList;
    q.linkedList = empty;
  }

}

