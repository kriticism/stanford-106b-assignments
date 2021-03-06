// This is a .h file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#ifndef _arraypriorityqueue_h
#define _arraypriorityqueue_h

#include <iostream>
#include <string>
#include "PQEntry.h"
using namespace std;

class ArrayPriorityQueue {
public:
    ArrayPriorityQueue();
    ~ArrayPriorityQueue();
    void changePriority(string value, int newPriority);
    void clear();
    string dequeue();
    void enqueue(string value, int priority);
    bool isEmpty() const;
    string peek() const;
    int peekPriority() const;
    int size() const;
    int len() const;
    string stringifyArrPQ() const;
    friend ostream& operator <<(ostream& out, const ArrayPriorityQueue& queue);

private:
    // TODO: add any other member functions/variables necessary
    PQEntry* ArrayPQarr; // Pointer to internal array of elements
    int ArrayPQcapacity; // Integer for array’s actual capacity
    int ArrayPQsize;

};


#endif
