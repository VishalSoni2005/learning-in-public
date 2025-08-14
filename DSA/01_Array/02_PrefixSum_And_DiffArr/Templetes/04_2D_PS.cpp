// Build 2D prefix sum
vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
for (int i = 1; i <= m; i++) {
  for (int j = 1; j <= n; j++) {
    pref[i][j] = matrix[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
  }
}

// Query sum of rectangle (x1,y1) to (x2,y2), inclusive, 0-indexed
int sumRect(int x1, int y1, int x2, int y2) {
  return pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1] - pref[x2 + 1][y1] + pref[x1][y1];
}
