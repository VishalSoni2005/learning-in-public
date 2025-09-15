//* ((n >> i) & 1) means getting bit at ith position
//* looping through 21 because -> int (4 byte) -> 32 bits -> bit at each position (n >> i) & 1

#include <iostream>
using namespace std;

void printCompactBinary(int n) {
  bool started = false;
  for (int i = 31; i >= 0; i--) {
    if ((n >> i) & 1) started = true;
    if (started) cout << ((n >> i) & 1);
  }
  if (!started) cout << 0;
  cout << endl;
}

void int_to_binary(int n) {
  for (int i = 31; i >= 0; i--) {
    cout << ((n >> i) & 1);
  }
}

int main() {
  int n = 128;
  cout << "Binary is : ";
  int_to_binary(n);
  cout << endl;
  cout << "Without zero : ";
  printCompactBinary(n);
  return 0;
}