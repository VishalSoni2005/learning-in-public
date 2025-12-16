//! just little bit optimization used changes flag 
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
    const int INF = 1e8;
    vector<int> dist(V, INF);
    dist[S] = 0;

    // Relax edges up to V-1 times
    for (int i = 0; i < V - 1; i++) {
      bool changed = false;
      for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          changed = true;
        }
      }
      if (!changed) break;  // ✅ early exit
    }

    // Check for negative weight cycle
    for (auto &e : edges) {
      int u = e[0], v = e[1], w = e[2];
      if (dist[u] != INF && dist[u] + w < dist[v]) {
        return {-1};  // negative cycle
      }
    }

    return dist;
  }
};
