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
