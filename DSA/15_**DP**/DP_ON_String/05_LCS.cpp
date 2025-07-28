//* questions -> two string will be given and you need to find the no of unique subset tha 
//* that are common in both string

class Solution {
 public:
  int rec(string& str1, int s1, string& str2, int s2) {
    if (s1 == 0 or s2 == 0)
      return 0;

    if (str1[s1 - 1] == str2[s2 - 1])
      return 1 + rec(str1, s1 - 1, str2, s2 - 1);

    return max(rec(str1, s1 - 1, str2, s2), rec(str1, s1, str2, s2 - 1));
  }

  int TD(string& str1, int s1, string& str2, int s2,
         vector<vector<int>>& dp) {
    if (s1 == 0 or s2 == 0)
      return 0;

    if (dp[s1][s2] != -1)
      return dp[s1][s2];

    if (str1[s1 - 1] == str2[s2 - 1])
      return dp[s1][s2] = 1 + TD(str1, s1 - 1, str2, s2 - 1, dp);

    return dp[s1][s2] = max(TD(str1, s1 - 1, str2, s2, dp),
                            TD(str1, s1, str2, s2 - 1, dp));
  }

  int BU(string& str1, string& str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (str1[i - 1] == str2[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    for (auto i : dp) {
      for (auto j : i) {
        cout << j << " ";
      }
      cout << endl;
    }
    return dp[m][n];
  }

  int longestCommonSubsequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    // return rec(str1, m, str2, n);

    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    // return TD(str1, m, str2, n, dp);

    // return BU(str1, str2);

    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (str1[i - 1] == str2[j - 1]) {
          curr[j] = 1 + prev[j - 1];
        } else {
          curr[j] = max(prev[j - 1], curr[j]);
        }
        prev = curr;
      }
    }
    return prev[n];
  }
};
