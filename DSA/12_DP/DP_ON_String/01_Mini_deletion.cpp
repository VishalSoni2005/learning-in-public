//* gfg
//*Given a string s. The task is to remove or delete the minimum number of characters from the string s, so that the resultant string forms a palindrome. Find the minimum number of characters we need to remove.
//  Note : The order of characters should be maintained.

       class Solution {
 public:
  int rec(int i, int j, string& s1, string& s2) {
    if (i == 0 or j == 0) return 0;

    if (s1[i - 1] == s2[j - 1]) return 1 + rec(i - 1, j - 1, s1, s2);

    int left = rec(i - 1, j, s1, s2);
    int right = rec(i, j - 1, s1, s2);

    return max(left, right);
  }

  int TD(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
    if (i == 0 or j == 0) {
      return 0;
    }

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i - 1] == s2[j - 1]) return dp[i][j] = 1 + TD(i - 1, j - 1, s1, s2, dp);

    int left = TD(i - 1, j, s1, s2, dp);
    int right = TD(i, j - 1, s1, s2, dp);

    return dp[i][j] = max(left, right);
  }

  int minDeletions(string& s) {
    // code here
    string s1 = s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int i = s1.length();
    int j = s2.length();
    // int lcs =  rec(i, j, s1, s2);
    // return i - lcs;

    vector<vector<int>> dp(i + 1, vector<int>(i + 1, -1));
    int lcs = TD(i, j, s1, s2, dp);
    return i - lcs;
  }
};