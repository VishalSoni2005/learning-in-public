class Solution {
 public:
  // int find(vector<int>& nums, int size, int idx, vector<int>&dp) {

  //     if (idx >= size)
  //         return 0;

  //     if(dp[idx] != -1) return dp[idx];

  //     return dp[idx] =  max(nums[idx] + find(nums, size, idx + 2, dp),
  //                find(nums, size, idx + 1, dp));
  // }

  // int rob(vector<int>& nums) {
  //     int n = nums.size();
  //     vector<int>dp(n+2, -1);
  //     dp[n] = 0, dp[n + 1] = 0;
  //     // return find(nums, n, 0, dp);

  //     for(int i = n-1; i > -1; i--)
  //       dp[i] = max(dp[i+2] + nums[i], dp[i+1]);
  //     return dp[0];
  // }

  int rob(vector<int>& nums) {
    int n = nums.size();
    int ans;
    int first = 0;
    int second = 0;

    for (int i = n - 1; i > -1; i--) {
      ans = max(nums[i] + second, first);
      second = first;
      first = ans;
    }
    return ans;
  }
};