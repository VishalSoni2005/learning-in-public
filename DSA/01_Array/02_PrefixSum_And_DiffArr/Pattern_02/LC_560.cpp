class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    unordered_map<int, int> mp;  // prefix sum -> freq
    mp[0] = 1;
    int ps = ` 0;

    for (int i : nums) {
      ps += i;

      if (mp.find(ps - k) != mp.end())
        count += mp[ps - k];

      mp[ps]++;
    }
    return count;
  }
  // typically this sum is sliding window -> variable length -> count;(atmostk)
};

