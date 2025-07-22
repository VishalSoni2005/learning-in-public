class Solution {
 public:
  int solve(int idx, vector<int>& nums, vector<int>& dp, int n) {
    if (idx >= n)
      return 0;
    if (dp[idx] != -1)
      return dp[idx];

    return dp[idx] = max(nums[idx] + solve(idx + 2, nums, dp, n),
                         solve(idx + 1, nums, dp, n));
  }

  // int rob(vector<int>& nums) {

  //     int n = nums.size();
  //     if (n == 1)
  //         return nums[0];
  //     vector<int> dp1(n + 2, -1); // first array for robing 0 to n-1
  //     vector<int> dp2(n + 2, -1); // second array to rob 1 to last(n)

  //     return max(solve(0, nums, dp1, n - 1), solve(1, nums, dp2, n));
  // }

  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    vector<int> dp1(n + 2, -1);  // first array for robing 0 to n-1
    vector<int> dp2(n + 2, -1);  // second array to rob 1 to last(n)

    dp1[n - 1] = dp1[n] = dp2[n + 1] = dp2[n] = 0;

    for (int i = n - 2; i > -1; i--) {
      dp1[i] = max(nums[i] + dp1[i + 2], dp1[i + 1]);
    }

    for (int i = n - 1; i > 0; i--) {
      dp2[i] = max(nums[i] + dp2[i + 2], dp2[i + 1]);
    }

    return max(dp1[0], dp2[0]);
  }
};