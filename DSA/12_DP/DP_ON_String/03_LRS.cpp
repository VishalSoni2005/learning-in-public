// longest repeating subsequence

class Solution {
 public:
  int rec(string& s, string& t, int i, int j) {
    if (i == 0 or j == 0) return 0;

    if (i == j) return max(rec(s, t, i - 1, j), rec(s, t, i, j - 1));

    if (s[i - 1] == t[j - 1])
      return 1 + rec(s, t, i - 1, j - 1);
    else
      return max(rec(s, t, i - 1, j), rec(s, t, i, j - 1));
  }

  int TD(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
    if (i == 0 || j == 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (i == j) {
      return max(TD(s, t, i - 1, j, dp), TD(s, t, i, j - 1, dp));
    }

    if (s[i - 1] == t[j - 1])
      return dp[i][j] = 1 + TD(s, t, i - 1, j - 1, dp);

    return dp[i][j] = max(TD(s, t, i - 1, j, dp), TD(s, t, i, j - 1, dp));
  }

  int LongestRepeatingSubsequence(string& s) {
    // Code here

    // string t = s;
    // int n = s.length();
    // return rec(s, t, n, n);

    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // return TD(s, t, n, n, dp);

    int n = s.length();
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == s[j - 1] and i != j) {
          curr[j] = 1 + prev[j - 1];
        } else {
          curr[j] = max(curr[j - 1], prev[j]);
        }
      }
      prev = curr;
    }
    return prev[n];
  }
};