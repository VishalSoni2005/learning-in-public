#include <bits/stdc++.h>
using namespace std;

/**
 * ! Time Complexity: O(4^(N^2))
 * * Space Complexity: O(N^2)
 */

void solve(int x, int y, vector<vector<int>> &maze, int n, vector<string> &ans, string path, vector<vector<bool>> &visited)
{
  // If out of bounds, cell is 0 or already visited, return
  if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0 || visited[x][y])
    return;

  // If reached destination
  if (x == n - 1 && y == n - 1)
  {
    ans.push_back(path);
    return;
  }

  // Mark current cell visited
  visited[x][y] = true;

  // Move in all 4 directions (Lexicographical Order: D, L, R, U)
  solve(x + 1, y, maze, n, ans, path + 'D', visited); // Down
  solve(x, y - 1, maze, n, ans, path + 'L', visited); // Left
  solve(x, y + 1, maze, n, ans, path + 'R', visited); // Right
  solve(x - 1, y, maze, n, ans, path + 'U', visited); // Up

  // Backtrack
  visited[x][y] = false;
  return; // aise hi dediyea
}

vector<string> findPath(vector<vector<int>> &maze, int n)
{
  vector<string> ans;

  if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
    return ans;

  vector<vector<bool>> visited(n, vector<bool>(n, false));
  solve(0, 0, maze, n, ans, "", visited);
  sort(ans.begin(), ans.end());
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

  vector<string> paths = findPath(maze, n);

  cout << endl;

  if (paths.empty())
  {
    cout << "No path found.\n";
  }
  else
  {
    cout << "Paths found:\n";
    int count = 0;
    for (string path : paths)
    {
      count = count + 1;
      cout << path << " -> Path : " << count << endl;
    }
  }
  cout << endl;

  return 0;
}
