#include <iostream>
using namespace std;

int main()
{
  int a;
  a = 69;

  int *ptr = &a;

  int *pNum = NULL;
  pNum = new int;

  // pNum = ptr;

  *pNum = 1;

  cout << "the value of pNum is => " << pNum << endl;

  cout << "the value of *ptr is => " << *ptr << endl;

  cout << "the value of ptr is => " << ptr << endl;

  cout << "the value of a is => " << &a << endl;

  cout << "Size of a is (in bytes) => " << sizeof(a) << endl;

  //? it is suggest that when we use new keyword we have to use delete keyword to free the memory
  delete pNum;
}