#include <iostream>
using namespace std;

int pow(int a, int b)
{
  if (b == 1)
    return a;

    int half = pow(a, b/2);
  if (b % 2 == 0)
    return half * half;
  else
    return a * half * half;
}

int main()
{
  cout << pow(2, 9);
}