class Solution {
 public:
  //! recursive solution
  // void paint(vector<vector<int>>& nums, int sr, int sc, int c, int oc) {
  //     if (sr < 0 || sr >= nums.size() || sc < 0 || sc >= nums[0].size())
  //         return;

  //     if (nums[sr][sc] != oc)
  //         return;

  //     nums[sr][sc] = c;

      // recurse in 4 directions
  //     paint(nums, sr + 1, sc, c, oc);
  //     paint(nums, sr - 1, sc, c, oc);
  //     paint(nums, sr, sc + 1, c, oc);
  //     paint(nums, sr, sc - 1, c, oc);
  // }

  vector<vector<int>> floodFill(vector<vector<int>>& nums, int sr, int sc,
                                int c) {
    // int oldColor = nums[sr][sc];
    // if (oldColor == c) return nums; // avoid infinite loop
    // paint(nums, sr, sc, c, oldColor);
    // return nums;
    
    //* graph bfs soln
    int row = nums.size();
    int col = nums[0].size();
    int oldColor = nums[sr][sc];
    nums[sr][sc] = c;

    if (oldColor == c) return nums;

    vector<vector<int>> vis(row, vector<int>(col, 0));
    vis[sr][sc] = 1;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    q.push({sr, sc});

    while (not q.empty()) {
      auto [r, cc] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = cc + dy[i];

        if (nr >= 0 and nc >= 0 and
            nr < row and nc < col and
            !vis[nr][nc] and nums[nr][nc] == oldColor) {
          vis[nr][nc] = 1;
          nums[nr][nc] = c;
          q.push({nr, nc});
        }
      }
    }

    return nums;
  }
};