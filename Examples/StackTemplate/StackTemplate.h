//------------------------------------------------------------------------
// Class StackTemplate
// Implement a stack to hold any type of values.
// This uses a template.  A template acts as a blueprint to immplement
// logic that is the same except for the actual type of data stored
// in the collection.
//
// The stack template can be used to create a concrete Stack containing
// any given object data type.
//
// NOTE : Because templates cannot be fully compile until you actually use them
// it can be difficult and confusing to set up the project to recognize them.
// One solution is to put the implementation of the template in the .h file and include
// it in the code where you wish to use it.  The #ifndef directive section is used to
// prevent a .h file from being included more than one time.
//------------------------------------------------------------------------
#ifndef _STACKTEMPLATE_H_
#define _STACKTEMPLATE_H_
#include <iostream>
using namespace std;

template <class MYTYPE> // my type is a placeholder to plug in the data type you wish to use
class Stack {
	int m_capacity;  // max capacity of the stack
	int m_top;       // index of next available slot at the top of the stack
    MYTYPE  *m_items;    // an array to hold the items of (MYTYPE) on the stack
public:
	Stack(int capacity=100) {    // create a stack of any size
		if (capacity <= 0) capacity = 100;
		m_capacity = capacity;				    
		m_items = new MYTYPE[m_capacity];
		m_top = 0;                              // top not only tells us how many items are in the stack, 
												// but also the index of the next open slot in the stack.
	}
	~Stack() {                                  // because I use dynamic memory in my Stack class, I need to free it
		if (m_items) delete[] m_items;
	}

	//------------------------------------------------------------------------
	// isFull: return true if stack is full
	//-------------------------------------------------------------------------
	bool isFull() {
		return m_top == m_capacity;
	}

	//------------------------------------------------------------------------
	// isEmpty: return true if stack is empty
	//-------------------------------------------------------------------------
	bool isEmpty() {
		return m_top == 0;
	}

	//------------------------------------------------------------------------
	// push(item): return true if item can be copied to stack
	// Put a copy of item on top of stack
	//-------------------------------------------------------------------------
	bool push(MYTYPE item) {
		if (isFull()) // fail due to no room
			return false;
		else {
			m_items[m_top++] = item;  // copy the item to the top of the stack, and move top index up
			return true;
		}
	}

	//------------------------------------------------------------------------
	// pop(item): return true if item can be retrieved
	// retrieve a copy of item from top of stack
	//-------------------------------------------------------------------------
	bool pop(MYTYPE& item) {  // pass item by reference so can copy something back to caller
		if (isEmpty()) // fail due to no data in the stack
			return false;
		else {
			item = m_items[--m_top];  // copy the item from top of the stack, and move top index down
			return true;
		}
	}


	//------------------------------------------------------------------------
	// show - used to display/print the current state of the stack for illustration
	// or debugging purposes
	//-------------------------------------------------------------------------
	void show(ostream& out) {
		for (int i = m_capacity - 1; i >= 0; i--) // print stack top down
		{
			out << "[" << i << "]  " << m_items[i];        // NOTE this STACK WILL ONLY WORK FOR OBJS that have << defined!
			if (i == m_top)
				out << "       <----- top    the next open index is [" << i << "]    ";
			out << endl << "--------------\n";
		}
	}
};
#endif