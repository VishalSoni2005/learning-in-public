#include <iostream>
using namespace std;

int main() {
  //! Left shift -> shift bit to left -> add 0 bit to right
  //* effect: Multiply no by 2 for each shift

  int n = 1;

  for (int i = 0; i < 5; i++) {
    n = n << 1;  // or n <<= 1;
  }
  cout << "n: " << n << endl;

  int m = -1;
  for (int i = 0; i < 5; i++) {
    m = m << 1;  // or m <<= 1;
  }
  cout << "m: " << m << endl;

  int bin = 0b0110101;
  cout << "Int Value of bin : " << bin << endl;
  cout << "Left Shift Value : " << (bin << 2) << endl;  //! multiple of 2^2 = 4

  return 0;
}
