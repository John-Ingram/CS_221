//------------------------------------------------------------------------
// Class CircQueue
// Implement a queue to hold characters, using a dynamically allocated
// array of char to hold the items.  The items are maintained in a CIRCULAR
// queue with one slot in the queue used to represent the empty end slot 
// as our indices move around the queue.
// If the user does not specify a capacity, the default size will be 100.
//------------------------------------------------------------------------
#include <iostream>
using namespace std;
class CircQueue {
	int m_capacity;  // max capacity of the queue
	int m_front;     // index of next available item at the front of the queue
	int m_rear;      // index of next available slot at the rear of the queue
    char *m_items;   // an array to hold the items on the queue
public:
	CircQueue(int);    // create a queue of any size
	~CircQueue();
	bool isFull();
	bool isEmpty();
	bool enqueue(char value);
	bool dequeue (char &value);

	void show(ostream &);  // show the contents of the queue
};