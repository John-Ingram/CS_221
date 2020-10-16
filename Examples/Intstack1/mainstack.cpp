// Main program to test drive the IntStack
//-----------------------------------------------------------------------------
#include "IntStack.h"
using namespace std;
//-----------------------------------------------------------------------------
void pressreturn(void);
void doBraceMatch();

int main(void)
{
	IntStack s1(5);      // create a stack that can hold up to 5 elements
	int   temp;			 // temporary storage for values popped off the stack

	cout << "The stack has been declared and is empty:\n";
	s1.show(cout);
	pressreturn();

	s1.push(3);
	s1.push(7);
	s1.push(15);

	cout << "\nAfter pushing 3 then 7 then 15:\n";
	s1.show(cout);
	pressreturn();

	s1.pop(temp);  cout << "\nYou popped: " << temp << endl;
	cout << "After first pop:\n";
	s1.show(cout);
	pressreturn();


	s1.pop(temp);  cout << "\nYou popped: " << temp << endl;
	s1.pop(temp);  cout << "\nYou popped: " << temp << endl;

	cout << "After last pop:\n";
	s1.show(cout);
	pressreturn();

	s1.push(2);
	s1.push(14);
	cout << "\nAfter pushing 2 then 14:\n";
	s1.show(cout);
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

