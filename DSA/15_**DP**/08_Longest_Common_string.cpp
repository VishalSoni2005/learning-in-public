//* longest commong string -> contineous -> diff from subsequence
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int find(string& s1, int m, string& s2, int n, int& ans) {
    if (m == 0 or n == 0) return 0;

    int len = 0;
    if (s1[m - 1] == s2[n - 1]) {
      len = 1 + find(s1, m - 1, s2, n - 1, ans);
      ans = max(len, ans);
    }

    find(s1, m - 1, s2, n, ans);
    find(s1, m, s2, n - 1, ans);

    return len;
  }

  int TD(string& s1, int m, string& s2, int n, int& ans, vector<vector<int>>& dp) {
    if (m == 0 || n == 0) return 0;

    if (dp[m][n] != -1) return dp[m][n];

    if (s1[m - 1] == s2[n - 1]) {
      dp[m][n] = 1 + TD(s1, m - 1, s2, n - 1, ans, dp);
      ans = max(ans, dp[m][n]);
    } else {
      dp[m][n] = 0;
    }

    // Recurse on other combinations to explore all end positions
    TD(s1, m - 1, s2, n, ans, dp);
    TD(s1, m, s2, n - 1, ans, dp);

    return dp[m][n];
  }

  int BU(string& s1, int m, string& s2, int n, int& ans) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          ans = max(ans, dp[i][j]);
        }
      }
    }
    return ans;
  }

  int longestCommonSubstr(string& s1, string& s2) {
    int m = s1.length();
    int n = s2.length();
    int ans = 0;

    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    // TD(s1, m, s2, n, ans, dp);

    // return ans;

    // BU(s1, m, s2, n, ans);

    // space optimization

    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          curr[j] = 1 + prev[j - 1];
          ans = max(ans, curr[j]);
        } else {
          curr[j] = 0;
        }
      }
      prev = curr;
    }

    return ans;
  }
};