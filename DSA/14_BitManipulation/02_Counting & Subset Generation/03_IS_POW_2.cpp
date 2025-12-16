class Solution {
 public:
  bool isPowerOfTwo(int n) {
    // my approach to count no of 1 bit
    if (n <= 0) return 0;
    int count = 0;
    while (n) {
      if (n & 1) count++;
      n >>= 1;
    }
    return count == 1;
  }
};

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return 0;
    return (n & (n - 1)) == 0;
  }
};