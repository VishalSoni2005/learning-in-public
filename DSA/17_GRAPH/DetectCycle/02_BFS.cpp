//! DRY RUN THIS CODE ITS PREFECT
class Solution {
 public:
  bool bfs(vector<vector<int>>& adj, vector<bool>& vis, int node) {
    vis[node] = 1;

    queue<pair<int, int>> q;
    q.push({node, -1});  // node, parent;

    while (!q.empty()) {
      auto [u, v] = q.front(); //* new technique
      q.pop();

      for (auto i : adj[u]) {
        if (i == v) continue;
        if (vis[i]) return true;
        vis[i] = 1;
        q.push({i, u});
      }
    }
    return 0;
  }

  bool isCycle(int v, vector<vector<int>>& edges) {
    // Build adjacency list
    vector<vector<int>> adj(v);
    for (auto& e : edges) {
      int a = e[0], b = e[1];
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    vector<bool> vis(v, false);

    for (int i = 0; i < v; i++) {
      if (!vis[i] and bfs(adj, vis, i)) {  // just change bfs to dfs
        return true;
      }
    }
    return false;
  }
};
