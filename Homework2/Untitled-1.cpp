#include <iostream>
#include <string>
using namespace std;

int main() {
  int *myArray1 = new int[5];
  int *myArray2 = new int[5];
  for (int j = 0; j<5; j++) {
    myArray1[j] = j;
  }

  myArray2 = myArray1;

  for (size_t i = 0; i < 5; i++)
  {
    cout << myArray2[i] << endl;
    cout << myArray1[i] << endl;
  }
  
  return 0;
}