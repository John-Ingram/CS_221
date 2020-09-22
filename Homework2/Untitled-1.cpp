#include <iostream>
#include <string>
using namespace std;

int main() {
  double x, y, z, q;
	double *p1, *p2;
	x = 18.2;
	y = 2.6;
	z = 99.1;
	q = 0;
	
	p1 = &x;
	p2 = &y;
	*p1 = 2.0 * *p2;
	// What are x & y at this point?
    cout << "p1 = " << *p1 << endl;
    cout << "p2 = " << *p2 << endl;


	p1 = &z;
	p2 = &q;
	p1 = p2;
	*p1 = 88.8;
	// What are z & q at this point?
    cout << "p1 = " << *p1 << endl;
    cout << "p2 = " << *p2 << endl;

  return 0;
}