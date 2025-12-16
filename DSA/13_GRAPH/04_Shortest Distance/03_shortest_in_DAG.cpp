// User function Template for C++
class Solution {
 public:
  void topo(int node, stack<int>& st,
            vector<int>& vis,
            vector<vector<pair<int, int>>>& adj) {
    vis[node] = 1;

    for (auto [v, w] : adj[node]) {
      if (!vis[v]) topo(v, st, vis, adj);
    }
    st.push(node);
  }

  vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    // Step 1: Build weighted adjacency list
    vector<vector<pair<int, int>>> adj(V);
    for (auto& i : edges) {
      int from = i[0];
      int to = i[1];
      int wt = i[2];
      adj[from].push_back({to, wt});
    }

    // Step 2: Topo sort (DFS)
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++) {
      if (!vis[i]) topo(i, st, vis, adj);
    }

    // Step 3: Distance initialization
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;  // source = 0

    // Step 4: Relaxation in topo order
    while (!st.empty()) {
      int temp = st.top();
      st.pop();
      if (dist[temp] != INT_MAX) {
        for (auto [v, w] : adj[temp]) {
          if (dist[v] > dist[temp] + w) {
            dist[v] = dist[temp] + w;
          }
        }
      }
    }

    // Step 5: Replace INF with -1 (if unreachable)
    for (int i = 0; i < V; i++) {
      if (dist[i] == INT_MAX) dist[i] = -1;
    }

    return dist;
  }
};
