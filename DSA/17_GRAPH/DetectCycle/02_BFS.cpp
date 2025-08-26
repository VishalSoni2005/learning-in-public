

//! DRY RUN THIS CODE ITS PREFECT
class Solution {
 public:
  bool bfs(int V, vector<vector<int>>& edges, vector<int>& vis) {
    vis[V] = 1;

    queue<pair<int, int>> q;
    q.push({V, -1});  // node, parent

    while (!q.empty()) {
      int node = q.front().first;
      int pnode = q.front().second;
      q.pop();

      for (int i = 0; i < edges[node].size(); i++) {
        int nbr = edges[node][i];

        if (nbr == pnode) continue;  // ignore parent
        if (vis[nbr]) return true;   // visited & not parent => cycle

        vis[nbr] = 1;
        q.push({nbr, node});
      }
    }
    return false;
  }

  bool isCycle(int V, vector<vector<int>>& edges) {
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
      if (!vis[i] && bfs(i, edges, vis))
        return true;
    }
    return false;
  }
};
