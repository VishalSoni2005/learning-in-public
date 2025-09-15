/*************  ✨ Windsurf Command ⭐  *************/
#include <iostream>
using namespace std;

int main() {
  // Right Shift(>>)
  //    Shifts bits to the right, discarding bits on the right.
  //     Effect : Divides the number by 2 ^ k(if shifted k times).

  int n = 1024;

  for (int i = 0; i < 5; i++) {
    n = n >> 1;  // or n <<= 1;
  }
  cout << "n: " << n << endl;

  int m = -512;
  for (int i = 0; i < 5; i++) {
    m = m >> 1;  // or m <<= 1;
  }
  cout << "m: " << m << endl;
}
