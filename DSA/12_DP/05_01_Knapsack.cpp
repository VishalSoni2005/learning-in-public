class Solution {
 public:
  int rec(int idx, vector<int>& val, vector<int>& wt, int W) {
    if (W == 0 || idx == 0) return 0;

    if (wt[idx - 1] > W) {
      return rec(idx - 1, val, wt, W);  // Only notTake
    }

    int take = val[idx - 1] + rec(idx - 1, val, wt, W - wt[idx - 1]);
    int notTake = rec(idx - 1, val, wt, W);

    return max(take, notTake);
  }

  int TD(int idx, int W, vector<vector<int>>& dp, vector<int>& val, vector<int>& wt) {
    if (W == 0) return 0;
    if (idx == 0) return 0;

    if (dp[idx][W] != -1) return dp[idx][W];

    if (wt[idx - 1] > W) {
      return dp[idx][W] = TD(idx - 1, W, dp, val, wt);
    }

    int take = val[idx - 1] + TD(idx - 1, W - wt[idx - 1], dp, val, wt);
    int nottake = TD(idx - 1, W, dp, val, wt);
    return dp[idx][W] = max(take, nottake);
  }

  int knapsackBU(int n, int W, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int w = wt[0]; w <= W; ++w)
      dp[0][w] = val[0];

    for (int i = 1; i < n; ++i) {
      for (int w = 0; w <= W; ++w) {
        int notTake = dp[i - 1][w];
        int take = INT_MIN;
        if (wt[i] <= w)
          take = val[i] + dp[i - 1][w - wt[i]];
        dp[i][w] = max(take, notTake);
      }
    }
    return dp[n - 1][W];
  }

  int knapsack(int W, vector<int>& val, vector<int>& wt) {
    // code here

    int n = val.size();
    // return rec(n, val, wt, W);

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    return TD(n, W, dp, val, wt);
  }
};