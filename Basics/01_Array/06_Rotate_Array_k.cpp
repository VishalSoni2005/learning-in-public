#include <bits/stdc++.h>
using namespace std;

class Solution {
  void swap(int& i, int& j) {
    int temp = i;
    i = j;
    j = temp;
  }

  void rotateByIdx(vector<int>& nums, int idx1, int idx2) {
    while (idx2 > idx1) {
      swap(nums[idx2], nums[idx1]);
      idx1++;
      idx2--;
    }
  }

 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    rotateByIdx(nums, n - k, n - 1);

    rotateByIdx(nums, 0, n - k - 1);

    rotateByIdx(nums, 0, n - 1);
  }
};