// Main program to test drive the IntStack
//-----------------------------------------------------------------------------
#include "IntStack.cpp"
using namespace std;
//-----------------------------------------------------------------------------
void pressreturn(void);
void doBraceMatch();

int main(void)
{
	IntStack s1(8);      // create a stack that can hold up to 5 elements
	int   temp;			 // temporary storage for values popped off the stack

	cout << "The stack has been declared and is empty:\n";
	s1.show(cout);
	pressreturn();

	s1.push(8);
	s1.push(9);
	s1.push(12);
	s1.push(11);
	s1.push(7);
	
	s1.show(cout);
	pressreturn();
	int v1;
	for (int j = 1; j <=5; j++)
	{
		s1.pop(v1);
		if (v1 % 2 == 1) s1.push(v1);
	} 

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

