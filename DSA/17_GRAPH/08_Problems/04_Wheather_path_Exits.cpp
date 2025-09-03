//! gfg : Find whether path exist

class Solution {
 public:
  vector<int> findCord(vector<vector<int>>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (nums[i][j] == 1) return {i, j};
      }
    }
  }
  // Function to find whether a path exists from the source to destination.
  bool is_Possible(vector<vector<int>>& grid) {
    // code here
    int n = grid.size();

    vector<int> cord = findCord(grid);
    int sr = cord[0];
    int sc = cord[1];

    vector<vector<int>> vis(n, vector<int>(n, 0));

    vis[sr][sc] = 1;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;  // x, y
    q.push({sr, sc});

    while (not q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if (nr < n and nc < n and nc >= 0 and nr >= 0 and !vis[nr][nc] and grid[nr][nc] != 0) {
          if (grid[nr][nc] == 2) return true;

          vis[nr][nc] = 1;
          q.push({nr, nc});
        }
      }
    }
    return 0;
  }
};