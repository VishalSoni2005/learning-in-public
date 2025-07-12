#include <iostream>
using namespace std;

int main() {
  int i;
  int j;
  cout << "Enter First NO : x = ";
  cin >> i;
  cout << "Enter second no : y = ";
  cin >> j;

  i = i ^ j;
  j = i ^ j;
  i = i ^ j;
  cout << "Swap no are : x = " << i << " and y = " << j;
  return 0;
}