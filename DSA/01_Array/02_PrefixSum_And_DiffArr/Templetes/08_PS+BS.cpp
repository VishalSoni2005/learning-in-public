// Example: minimal length subarray sum >= target (positive nums only)
int minSubArrayLen(int target, vector<int>& nums) {
  int n = nums.size();
  vector<int> pref(n + 1, 0);
  for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + nums[i];
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    int need = target + pref[i];
    auto it = lower_bound(pref.begin(), pref.end(), need);
    if (it != pref.end()) ans = min(ans, (int)(it - (pref.begin() + i)));
  }
  return ans == INT_MAX ? 0 : ans;
}
