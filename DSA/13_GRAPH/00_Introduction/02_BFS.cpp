class Solution {
 public:
  // Function to return Breadth First Traversal of given graph.
  vector<int> bfs(vector<vector<int>> &adj) {
    // Code here
    int V = adj.size();  // derive V
    vector<int> bfs;
    vector<int> vis(V, 0);

    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      bfs.push_back(node);

      for (int it : adj[node]) {
        if (!vis[it]) {
          vis[it] = 1;
          q.push(it);
        }
      }
    }
    return bfs;
  }
};