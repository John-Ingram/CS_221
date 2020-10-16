// Main program to test drive the Stack Template.
// THIS IS VERSION 2 of Stack examples, It uses the stack template instead
// of a stack that can only hold int values in it.
//-----------------------------------------------------------------------------
#include "StackTemplate.h"
#include <iostream>
using namespace std;
//-----------------------------------------------------------------------------
void pressreturn(void);

int main(void)
{
	Stack<int> s1(5);        // create a stack that can hold up to 5 elements (MYTYPE = int)
	Stack<char> s2(5);       // create a stack that can hold up to 5 character elements
	char   temp;		   	 // temporary storage for values popped off a stack

	cout << "The stack has been declared and is empty:\n";
	s1.show(cout);
	pressreturn();

	s1.push(3);
	s1.push(7);
	s1.push(15);

	cout << "\nAfter pushing 3 then 7 then 15:\n";
	s1.show(cout);
	pressreturn();

	cout << "\n\nNow let's work with a character stack instead.\n";
	s2.push('a');
	s2.push('b');
	cout << "\nAfter pushing a then b:\n";
	s2.show(cout);
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

