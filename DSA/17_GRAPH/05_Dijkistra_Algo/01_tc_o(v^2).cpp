//! undirected weighted graph
//* tc : O(V^2) and sc: o(v)

// User Function Template
class Solution {
 public:
  vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    // Step 1: Build adjacency list (undirected weighted graph)
    vector<vector<pair<int, int>>> adj(V);
    for (auto &i : edges) {
      int from = i[0];
      int to = i[1];
      int wt = i[2];
      adj[from].push_back({to, wt});
      adj[to].push_back({from, wt});  // because graph is undirected
    }

    // Step 2: Initialize
    vector<int> dist(V, INT_MAX);
    vector<bool> vis(V, false);
    dist[src] = 0;

    // Step 3: Standard O(V^2) Dijkstra
    int count = V;
    while (count--) {
      // Pick the unvisited node with minimum distance
      int node = -1, val = INT_MAX;
      for (int i = 0; i < V; i++) {
        if (!vis[i] && dist[i] < val) {
          node = i;
          val = dist[i];
        }
      }

      if (node == -1) break;  // no more reachable nodes
      vis[node] = true;

      // Step 4: Relax its neighbors
      for (auto &[neighbour, wt] : adj[node]) {
        if (!vis[neighbour] && dist[node] + wt < dist[neighbour]) {
          dist[neighbour] = dist[node] + wt;
        }
      }
    }

    return dist;
  }
};
