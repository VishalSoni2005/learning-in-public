//! gfg : Shortest Source to Destination Path nad flood fill
// User function Template for C++

// todo : ONE OF THE SIMPLEST PATTERN

/* *
 * * this is one of the most important pattern of question :
 * remember following steps;
 *  1-> make a martrix of possible direction
 *  2-> run look from k = 0 to 4 checking all posibililry of direction
 *  3-> consider boundary conditions of matrix
 */

// TC : o(e * v);

class Solution {
 public:
  int shortestDistance(int row, int col, vector<vector<int>> A, int x, int y) {
    // code here

    // adj matrix is given
    // find shortest path in adj matrix

    if (A[0][0] == 0) return -1;     // cannot start
    if (x == 0 && y == 0) return 0;  // already at destination

    // Visited matrix
    vector<vector<int>> vis(row, vector<int>(col, 0));
    vis[0][0] = 1;

    // Directions (up, down, left, right)
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // Queue: {steps, {x, y}}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();

      int steps = curr.first;
      int r = curr.second.first;
      int c = curr.second.second;

      // Check all 4 neighbors
      for (int k = 0; k < 4; k++) {
        int nr = r + dx[k];
        int nc = c + dy[k];

        // Check valid & not visited & walkable (==1)
        if (nr >= 0 && nr < row && nc >= 0 && nc < col && !vis[nr][nc] && A[nr][nc] == 1) {
          // If destination found
          if (nr == x && nc == y) return steps + 1;

          vis[nr][nc] = 1;
          q.push({steps + 1, {nr, nc}});
        }
      }
    }

    return -1;  // not reachable
  }
};