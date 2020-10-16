//------------------------------------------------------------------------
// Class IntStack
// Implement a stack to hold integers, using a dynamically allocated
// array of integers to hold the items.
// If the user does not specify a capacity, the default size will be 100.
//------------------------------------------------------------------------
#include <iostream>
using namespace std;
class IntStack {
	int m_capacity;  // max capacity of the stack
	int m_top;       // index of next available slot at the top of the stack
    int *m_items;    // an array to hold the items on the stack
public:
	IntStack(int);    // create a stack of any size
	~IntStack();      // because I use dynamic memory in my Stack class, I need to free it
	bool isFull();
	bool isEmpty();
	bool push(int item);
	bool pop (int &item);

	void show(ostream &);  // show the contents of the stack
};