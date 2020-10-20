// Main program to test drive the CircQueue
//-----------------------------------------------------------------------------
#include "CircQueue.cpp"
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

	q1.enqueue(NULL);
	q1.enqueue(NULL);
	q1.enqueue(NULL);
	q1.enqueue('7');
	q1.enqueue('4');
	q1.enqueue('4');
	char v1, v2, v3;
	q1.dequeue(v1);
	q1.dequeue(v2);
	v3 = 'e';
	q1.enqueue(v3);

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

