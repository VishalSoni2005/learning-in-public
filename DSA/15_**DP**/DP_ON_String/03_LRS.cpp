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

    string t = s;
    int n = s.length();

    // return rec(s, t, n, n);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return TD(s, t, n, n, dp);
  }
};