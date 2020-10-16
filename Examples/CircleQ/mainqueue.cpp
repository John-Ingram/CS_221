// Main program to test drive the CircQueue
//-----------------------------------------------------------------------------
#include "CircQueue.h"
using namespace std;
//-----------------------------------------------------------------------------
void pressreturn(void);


int main(void)
{
	CircQueue q1(5);      // create a queue that can hold up to 5 elements
	char temp;            // temporary storage for a character

	cout << "The queue has been declared and is empty:\n";
	q1.show(cout);
	pressreturn();

	q1.enqueue('a');
	q1.enqueue('b');
	q1.enqueue('c');

	cout << "\nAfter enqueueing a then b then c:\n";
	q1.show(cout);
	pressreturn();

	q1.dequeue(temp);  cout << "\nYou dequeueed: " << temp << endl;
	cout << "After first dequeue:\n";
	q1.show(cout);
	pressreturn();


	q1.dequeue(temp);  cout << "\nYou dequeueed: " << temp << endl;
	q1.dequeue(temp);  cout << "\nYou dequeueed: " << temp << endl;

	cout << "After last dequeue:\n";
	q1.show(cout);
	pressreturn();

	q1.enqueue('x');
	q1.enqueue('y');
	cout << "\nAfter enqueueing x then y:\n";
	q1.show(cout);
	pressreturn();


	return 0;
}

//------------------------------------------------------------------------------------
// Some utilities used by the main function
//------------------------------------------------------------------------------------
void pressreturn(void)
{
	char ret;
	cout << "\n************ PRESS RETURN TO CONTINUE *********";
	cin.get(ret);
	cout << "\n";
}

