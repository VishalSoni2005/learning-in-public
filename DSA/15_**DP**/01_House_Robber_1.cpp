class Solution {
 public:
  int rec_solve(vector<int>& nums, int size, int idx) {
    if (idx >= size)
      return 0;

    return max(nums[idx] + rec_solve(nums, size, idx + 2),
               rec_solve(nums, size, idx + 1));
  }
  int TD(vector<int>& nums, int size, int idx, vector<int>& dp) {
    if (idx >= size)
      return 0;

    if (dp[idx] != -1)
      return dp[idx];

    return dp[idx] = max(nums[idx] + TD(nums, size, idx + 2, dp),
                         TD(nums, size, idx + 1, dp));
  }

  int BU(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 2, -1);

    dp[n] = dp[n + 1] = 0;

    for (int i = n - 1; i > -1; i--) {
      int last = dp[i + 2];
      int prev = dp[i + 1];
      int curr = nums[i];
      dp[i] = max(last + curr, prev);
    }

    return dp[0];
  }

  int TAB(vector<int>& nums) {
    int n = nums.size();

    int ans;
    int first = 0;
    int second = 0;

    for (int i = n - 1; i > -1; i--) {
      int curr = nums[i];

      ans = max(curr + second, first);
      second = first;
      first = ans;
    }

    return ans;
  }

  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    // return max(rec_solve(nums, n, 0), rec_solve(nums, n, 1));

    // vector<int>dp(n+2, -1);
    // return max(TD(nums, n, 0, dp), TD(nums, n, 1, dp));

    // return BU(nums);

    return TAB(nums);
  }
};