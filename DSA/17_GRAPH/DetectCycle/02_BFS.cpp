class Solution {
 public:
  bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here

    // using bfs

    vector<int> vis(V, 0);
    vis[0] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(0, -1));  // node, parent

    while (!q.empty()) {
      int node = q.front().first();
      int pnode = q.front().second();

      q.pop();

      for (int i = 0; i < edges[node].size(); i++) {
        if (pnode == edges[node][i]) continue;
        if (vis[edges[node][i]]) return 1;

        vis[edges[node][i]] = 1;
        q.push(make_pair(edges[node][i]), node);
      }
    }
    return 0;
  }
};