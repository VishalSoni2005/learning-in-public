class NumMatrix {
 public:
  vector<vector<int>> pref;

  NumMatrix(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    pref.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        pref[i][j] = mat[i][j];
        if (i > 0) pref[i][j] += pref[i - 1][j];
        if (j > 0) pref[i][j] += pref[i][j - 1];
        if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int x1, int y1, int x2, int y2) {
    int res = pref[x2][y2];
    if (x1 > 0) res -= pref[x1 - 1][y2];
    if (y1 > 0) res -= pref[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) res += pref[x1 - 1][y1 - 1];
    return res;
  }
};
