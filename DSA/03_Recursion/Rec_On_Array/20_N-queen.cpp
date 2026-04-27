class Solution {
 public:
  bool check(int row, int col, vector<string>& board, int n) {
    // Check vertical column
    for (int i = 0; i < row; ++i) {
      if (board[i][col] == 'Q')
        return false;
    }

    // Check left upper diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (board[i][j] == 'Q')
        return false;
    }

    // Check right upper diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (board[i][j] == 'Q')
        return false;
    }

    return true;
  }

  void solve(int row, int n, vector<string>& board, vector<vector<string>>& result) {
    if (row == n) {
      result.push_back(board);  // All rows are filled with valid placements
      return;
    }

    for (int col = 0; col < n; ++col) {
      if (check(row, col, board, n)) {
        board[row][col] = 'Q';             // Place queen
        solve(row + 1, n, board, result);  // Recurse for next row
        board[row][col] = '.';             // Backtrack (remove queen)
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));  // no need to make an 2d arr string is vector already
    solve(0, n, board, result);
    return result;
  }
};
