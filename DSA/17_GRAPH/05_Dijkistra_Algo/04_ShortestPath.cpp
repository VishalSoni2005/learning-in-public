//! shortest "path" in undirected weghted graph ({PATH})

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    const int INF = 1e9;
    vector<vector<pair<int, int>>> adj(n + 1);  // 1-based indexing

    // Build adjacency list
    for (auto& e : edges) {
      int u = e[0], v = e[1], w = e[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    dist[1] = 0;  // source = 1

    // Min-heap: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d > dist[u]) continue;

      for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          parent[v] = u;  // track path
          pq.push({dist[v], v});
        }
      }
    }

    // If no path exists
    if (dist[n] == INF) return {-1};

    // Reconstruct path from 1 to n
    vector<int> path;
    int cur = n;
    while (cur != -1) {
      path.push_back(cur);
      cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    // Insert total weight at the beginning
    path.insert(path.begin(), dist[n]);
    return path;
  }
};
