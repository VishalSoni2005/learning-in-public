class Solution {
  // TLE
  int rec_soln(int idx, int sum, vector<int>& nums, int size) {
    if (sum == 0)
      return 1;

    if (sum < 0 or idx >= size)
      return 0;

    int include = rec_soln(idx, sum - nums[idx], nums, size);
    int exclude = rec_soln(idx + 1, sum, nums, size);

    return include + exclude;
  }

  int rec_soln2(int lidx, vector<int>& nums, int amt) {
    if (amt == 0)
      return 1;
    if (lidx < 0)
      return 0;

    if (nums[lidx] > amt)  // skip this lidx
      return rec_soln2(lidx - 1, nums, amt);

    return rec_soln2(lidx, nums, amt - nums[lidx]) +  // take
           rec_soln2(lidx - 1, nums, amt);            // no take
  }

  int TD(int lidx, vector<int>& nums, int amt, vector<vector<int>>& dp) {
    if (lidx < 0)
      return 0;
    if (amt == 0)
      return 1;

    if (dp[lidx][amt] != -1)
      return dp[lidx][amt];

    if (nums[lidx] > amt) {
      return TD(lidx - 1, nums, amt, dp);
    }

    return dp[lidx][amt] = TD(lidx - 1, nums, amt, dp) +
                           TD(lidx, nums, amt - nums[lidx], dp);
  }

  int BU(vector<int>& nums, int size, vector<vector<int>>& dp, int amt) {
    for (int i = 0; i <= size; i++)
      dp[i][0] = 1;

    for (int i = 1; i <= size; i++) {
      for (int j = 1; j <= amt; j++) {
        if (nums[i - 1] > j)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i][j - nums[i - 1]] + dp[i - 1][j];
      }
    }
    return dp[size][amt];
  }

 public:
  int change(int amount, vector<int>& coins) {
    int n = coins.size();

    // return rec_soln(0, amount, coins, n);
    // return rec_soln2(n - 1, coins, amount);

    // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    // return TD(n - 1, coins, amount, dp);

    // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    // return BU(coins, n, dp, amount);

    //  vector<int> dp(amount + 1, 0);
    //   dp[0] = 1;

    //   for (int i = 0; i < n; i++) {
    //       for (int j = coins[i]; j <= amount; j++) {
    //           dp[j] += dp[j - coins[i]];
    //       }
    //   }
    //   return dp[amount];

    // space optimization
    vector<unsigned long long> dp(amount + 1, 0);
    dp[0] = 1;

    for (int c : coins) {
      for (int a = c; a <= amount; a++) {
        dp[a] += dp[a - c];
      }
    }

    return dp[amount];
  }
};