#include<iostream>
using namespace std;

int fibo(int n) {
  if(n == 0 or n == 1) return n;
  return fibo(n-1) + fibo(n-2);
}

//! note : only one call can be made at once during code execution

int main() {
  cout << fibo(5);
}