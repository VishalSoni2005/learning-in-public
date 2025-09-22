class Solution {
 public:
  int reverseBits(int n) {
    int rev = 0;
    for (int i = 0; i < 32; i++) {
      rev <<= 1;
      int LSB = n & 1;
      rev = rev | LSB; //! adding lsb to end of rev
      n >>= 1;
    }
    return rev;
  }
};