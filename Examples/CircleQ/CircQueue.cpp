//------------------------------------------------------------------------
// Class CircQueue
// Implement the methods of the class
// This uses a CIRCULAR queue. 
//    m_front : is the index of the next item to read off the queue
//    m_rear  : is the index of the next slot to place an item
//    
//   if the front and rear are in the same place, that means the queue is empty
//   if the queue is full, then the rear index will be one slot behind the front
//        -- we will not place an item in there, it's a sacrifice slot
//------------------------------------------------------------------------	
#include "CircQueue.h"
#include <iomanip>
#include <sstream>
using namespace std;
//------------------------------------------------------------------------
// Constructor: allocates an array of the capacity desired by the user.
// If the user does not supply a value, create the queue to hold
// 100 items by default.
//------------------------------------------------------------------------
CircQueue::CircQueue(int capacity=100) {
	m_capacity = capacity+1;		// let's secretly add 1 slot for the buffer slot, so our queue can hold the full capacity desired by the user
	m_items = new char[m_capacity];
	m_front = 0;                    // front is the index of the next item to read if the queue is not empty
	m_rear = 0; 					// rear is the index of the next available slot to write into if the queue is not full

	for (int i=0; i < m_capacity; i++) 
		m_items[i] = ' ';  // lets fill with blanks so easy to view in debugging
}
//------------------------------------------------------------------------
// Destructor: free array used by this data structure
//------------------------------------------------------------------------
CircQueue::~CircQueue() {
	if (m_items != NULL) delete[] m_items;
}

//------------------------------------------------------------------------
// isFull: return true if queue is full
// The queue is full if rear is currently one slot before front. If moving the
// rear over by one will make it the same as front, we don't want to do that.
//-------------------------------------------------------------------------
bool CircQueue::isFull() {
	return m_front == (m_rear+1) % m_capacity; 
}

//------------------------------------------------------------------------
// isFull: return true if queue is empty
//-------------------------------------------------------------------------
bool CircQueue::isEmpty() {
	return  m_front == m_rear;
}

//------------------------------------------------------------------------
// push(item): return true if item can be copied to queue
// Put a copy of item on top of queue
//-------------------------------------------------------------------------
bool CircQueue::enqueue(char value) {
	if (isFull()) // fail due to no room
		return false;
	else {
		m_items[m_rear] = value;  // copy the value to the rear of the queue, and move rear over 1, rotate around to 0 if go off the end
		m_rear = (m_rear + 1) % m_capacity;
		return true;
	}
}

//------------------------------------------------------------------------
// pop(item): return true if item can be retrieved
// retrieve a copy of item from top of queue
//-------------------------------------------------------------------------
bool CircQueue::dequeue(char &value) {  // pass by reference so can copy something back to caller
	if (isEmpty()) // fail due to no data in the queue
		return false;
	else {
		value = m_items[m_front];  // copy the value from front of the queue, and move front over 1
		m_front = (m_front + 1) % m_capacity;
		return true;
	}
}


//------------------------------------------------------------------------
// show - used to display/print the current state of the queue for illustration
// or debugging purposes
// THIS WILL ONLY WORK FOR SMALL QUEUES AS I HARDCODE IN THE NUMBER OF STRINGS
// I AM USING TO FORMAT THE PRINT OUTPUT
// NOTE LEFTOVER DATA IS NOT CLEARED OUT OF REUSED CIRCULAR BUFFER ENTRIES
// THE ONES OUTSIDE OF FRONT/REAR RANGE HAVE NO MEANING!
//-------------------------------------------------------------------------
void CircQueue::show(ostream &out) {
    
	string buff1[20];
	string buff2[20];
	string buff3[20];
	string buff4[20];
	int i;

	for ( i = 0; i < 20; i++) {
		buff1[i] = "     ";
		buff2[i] = "     ";
		buff3[i] = "     ";
		buff4[i] = "     ";
	}

	for (int i=0; i < m_capacity; i++) {
		buff1[i][2] = m_items[i]; buff1[i][4] ='|';
		if (i == m_front) {
			buff2[i][2] = '^'; buff3[i][2] = 'F';
		}
		if (i == m_rear) {
			buff2[i][2] = '^'; buff4[i][2] = 'R';
		}
	}
	
	for (i = 0; i < 20; i++) out << buff1[i];
	out << endl;
	for (i = 0; i < 20; i++) out << buff2[i];
	out << endl;
	for (i = 0; i < 20; i++) out << buff3[i];
	out << endl;
	for (i = 0; i < 20; i++) out << buff4[i];
	out << endl;
	

}
