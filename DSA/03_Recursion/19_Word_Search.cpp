#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool solve(vector<vector<char>> &board, vector<vector<bool>> &visited,
             int row, int col, string &word, int idx)
  {

    if (idx == word.length())
      return true; // Word completely matched

    int m = board.size();
    int n = board[0].size();

    if (row < 0 || col < 0 || row >= m || col >= n || visited[row][col] || board[row][col] != word[idx])
      return false;

    visited[row][col] = true;

    bool found = solve(board, visited, row + 1, col, word, idx + 1) || //* only one condition will run  not all of them
                 solve(board, visited, row - 1, col, word, idx + 1) ||
                 solve(board, visited, row, col + 1, word, idx + 1) ||
                 solve(board, visited, row, col - 1, word, idx + 1);

    visited[row][col] = false; // Backtrack
    return found;
  }



  bool exist(vector<vector<char>> &board, string word)
  {
    int row = board.size();
    int col = board[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    //? this loop will check and help to find first word of sequence from which our word start
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        if (solve(board, visited, i, j, word, 0))
          return true;

    return false;
  }
};

int main()
{
  Solution s;

  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}};

  string word;
  cout << "Enter word to search: ";
  cin >> word;

  if (s.exist(board, word))
  {
    cout << "Word \"" << word << "\" exists in the board.\n";
  }
  else
  {
    cout << "Word \"" << word << "\" does NOT exist in the board.\n";
  }

  return 0;
}
