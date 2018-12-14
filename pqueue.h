// CSCI 2530
// Assignment: 6
// Author:     Shelby Brown
// File:       pqueue.h
// Tab stops:  ***

// These #ifndef and #define lines make it so that, if this file is
// read more than once by the compiler, its body is skipped on all
// but the first time it is read.

#ifndef pqueue_h
#define pqueue_h

#include <cstdio>
using namespace std;

//Type definitions.

typedef const char* ItemType;
typedef double      PriorityType;

typedef void (ItemPrinter)(ItemType);
typedef void (PriorityPrinter)(PriorityType);

struct PQCell;

// Structure PriorityQueue holds a pointer to the PQCell linked list.
// By default it sets the pointer to null.

struct PriorityQueue
{
  PQCell* linkedList;

  PriorityQueue()
  {
    linkedList == NULL;
  }
};

bool isEmpty(const PriorityQueue& q);
void insert(PriorityQueue& q, ItemType x, PriorityType p);
void remove(PriorityQueue& q, ItemType& x, PriorityType& p);
void printPriorityQueue(const PriorityQueue& q, ItemPrinter pi, PriorityPrinter pp);


#endif
