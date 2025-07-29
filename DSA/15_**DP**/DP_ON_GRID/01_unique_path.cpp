class Solution {
 public:
  // Function to find total number of unique paths.
  int NumberOfPath(int a, int b) {
    vector<vector<int>> grid(a, vector<int>(b, 1));

    // Fill the DP table from bottom-right to top-left
    for (int i = a - 2; i >= 0; i--) {
      for (int j = b - 2; j >= 0; j--) {
        grid[i][j] = grid[i][j + 1] + grid[i + 1][j];
      }
    }

    return grid[0][0];
  }
};
