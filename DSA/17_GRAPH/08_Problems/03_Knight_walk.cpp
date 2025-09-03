//! same pattern as of flood fill and shortest 2d path

// 🔹 Complexity
//Time : O(n²)(each cell visited once at most) Space : O(n²)(visited matrix + BFS queue)

class Solution {
 public:
  int minStepToReachTarget(vector<int>& kp, vector<int>& tp, int n) {
    int pr = kp[0], pc = kp[1];
    int tr = tp[0], tc = tp[1];

    if (pr == tr && pc == tc) return 0;  // already at target

    vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));
    vis[pr][pc] = 1;

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {pr, pc}});  // {steps, {row, col}}

    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    while (!q.empty()) {
      auto [steps, cell] = q.front();
      q.pop();

      int r = cell.first, c = cell.second;

      for (int i = 0; i < 8; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if (nr >= 1 && nc >= 1 && nr <= n && nc <= n && !vis[nr][nc]) {
          if (nr == tr && nc == tc) return steps + 1;

          vis[nr][nc] = 1;
          q.push({steps + 1, {nr, nc}});
        }
      }
    }
    return -1;  // should never happen on a valid board
  }
};
