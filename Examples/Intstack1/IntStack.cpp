//------------------------------------------------------------------------
// Class IntStack
// Implement the methods of the class
//------------------------------------------------------------------------	
#include "IntStack.h"
#include <iomanip>
using namespace std;
//------------------------------------------------------------------------
// Constructor: allocates an array of the capacity desired by the user.
// If the user does not supply a value, create the stack to hold
// 100 items by default.
//------------------------------------------------------------------------
IntStack::IntStack(int capacity=100) {
	m_capacity = capacity;
	m_items = new int[m_capacity];
	m_top = 0;                              // top not only tells us how many items are in the stack, 
											// but also the index of the next open slot in the stack.

	for (int i=0; i < m_capacity; i++) 
		m_items[i] = 0;  // lets fill with zeros so easy to view in debugging
}
//------------------------------------------------------------------------
// Destructor: deletes the allocated array
//------------------------------------------------------------------------
IntStack::~IntStack( ) {
	if (m_items) delete[] m_items;
}

//------------------------------------------------------------------------
// isFull: return true if stack is full
//-------------------------------------------------------------------------
bool IntStack::isFull() {
	return m_top == m_capacity;
}

//------------------------------------------------------------------------
// isFull: return true if stack is empty
//-------------------------------------------------------------------------
bool IntStack::isEmpty() {
	return m_top == 0;
}

//------------------------------------------------------------------------
// push(item): return true if item can be copied to stack
// Put a copy of item on top of stack
//-------------------------------------------------------------------------
bool IntStack::push(int item) {
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
bool IntStack::pop(int &item) {  // pass item by reference so can copy something back to caller
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
void IntStack::show(ostream &out) {
	for (int i = m_capacity-1; i >= 0; i--) // print stack top down
	{
		out << "[" << setw(3) << i << "]  "<< m_items[i];
		if (i == m_top) 
			out << "       <----- top    the next open index is [" << i << "]    ";
		out << endl << "--------------\n";
	}
}