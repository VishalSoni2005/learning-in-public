#include <bits/stdc++.h>
using namespace std;

/**
 * * Time => O(4^(N×N)) ->	4 directions from each cell, max depth N^2
 * * Space =>	O(N^2) ->	visited matrix + recursion stack
 */

vector<int> row = {1, 0, 0, -1}; // D, L, R, U
vector<int> col = {0, -1, 1, 0};
string dir = "DLRU"; // Keep this order for lexicographical sorting

bool valid(int x, int y, int n)
{
  return x >= 0 && y >= 0 && x < n && y < n;
}

void Total(vector<vector<int>> &matrix, int i, int j, int n, string &path, vector<string> &ans, vector<vector<int>> &visited)
{
  if (i == n - 1 && j == n - 1)
  {
    ans.push_back(path);
    return;
  }

  visited[i][j] = 1;

  for (int k = 0; k < 4; k++)
  {
    int ni = i + row[k];
    int nj = j + col[k];

    if (valid(ni, nj, n) && matrix[ni][nj] == 1 && !visited[ni][nj])
    {
      path.push_back(dir[k]);
      Total(matrix, ni, nj, n, path, ans, visited);
      path.pop_back();
    }
  }

  visited[i][j] = 0; // Backtrack
}

vector<string> findPath(vector<vector<int>> &matrix, int n)
{
  vector<string> ans;
  if (matrix[0][0] == 0 || matrix[n - 1][n - 1] == 0)
    return ans;

  vector<vector<int>> visited(n, vector<int>(n, 0));
  string path;
  Total(matrix, 0, 0, n, path, ans, visited);
  sort(ans.begin(), ans.end()); // Optional for lexicographical output
  return ans;
}

int main()
{
  int n = 4;
  vector<vector<int>> maze = {
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 1, 1},
      {1, 1, 0, 1}};

  vector<string> res = findPath(maze, n);
  cout << endl;
  if (res.empty())
  {
    cout << "No paths found.\n";
  }
  else
  {
    for (int i = 0; i < res.size(); i++)
    {
      cout << "Path " << i + 1 << ": " << res[i] << endl;
    }
  }
  cout << endl;

  return 0;
}
