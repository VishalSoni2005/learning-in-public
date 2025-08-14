/**
 ** Idea: Store seen prefix sums to find/count subarrays matching a target sum in O(n).
 ** Usage:Works with positive/negative numbers (sliding window fails for negatives).
            Count subarrays meeting sum conditions.
 ** Variants:
            Find length of such subarray (longest/shortest).
            Count frequency of prefix sums.
 */

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
  unordered_map<int, int> freq;
  freq[0] = 1;  // empty prefix
  int sum = 0, count = 0;
  for (int x : nums) {
    sum += x;
    if (freq.count(sum - k)) count += freq[sum - k];
    freq[sum]++;
  }
  return count;
}
int subarraysDivByK(vector<int>& nums, int k) {
  unordered_map<int, int> freq;
  freq[0] = 1;
  int sum = 0, count = 0;
  for (int x : nums) {
    sum += x;
    int mod = ((sum % k) + k) % k;  // handle negatives
    if (freq.count(mod)) count += freq[mod];
    freq[mod]++;
  }
  return count;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = nums.size();

  cout << subarraySum(nums, 4);
  return 0;
}