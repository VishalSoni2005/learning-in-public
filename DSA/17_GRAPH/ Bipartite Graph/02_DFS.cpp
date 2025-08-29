class Solution {
 public:
  bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &adj) {
    color[node] = col;  // assign color
    for (auto it : adj[node]) {
      if (color[it] == -1) {
        // assign alternate color recursively
        if (!dfs(it, 1 - col, color, adj)) return false;
      } else if (color[it] == col) {
        // conflict found
        return false;
      }
    }
    return true;
  }

  bool isBipartite(int v, vector<vector<int>> &edges) {
    // Step 1: Build adjacency list
    vector<vector<int>> adj(v);
    for (auto &i : edges) {
      int m = i[0];
      int n = i[1];
      adj[m].push_back(n);
      adj[n].push_back(m);
    }
    // Step 2: Initialize color array
    vector<int> color(v, -1);
    // Step 3: Run DFS for each component
    for (int i = 0; i < v; i++) {
      if (color[i] == -1) {
        if (!dfs(i, 0, color, adj)) return false;
      }
    }
    return true;  // no conflicts
  }
};
