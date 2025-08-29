//! use topo sort tc o(v + e)
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> shortestPathInDAG(int V, vector<vector<pair<int, int>>>& adj, int src) {
    // Step 1: Topological Sort
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++) {
      for (auto [v, w] : adj[u]) {
        indegree[v]++;
      }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
      if (indegree[i] == 0) q.push(i);

    vector<int> topo;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      topo.push_back(u);

      for (auto [v, w] : adj[u]) {
        indegree[v]--;
        if (indegree[v] == 0) q.push(v);
      }
    }

    // Step 2: Relax edges in topo order
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int u : topo) {
      if (dist[u] != INT_MAX) {
        for (auto [v, w] : adj[u]) {
          if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
          }
        }
      }
    }

    return dist;
  }
};

int main() {
  int V = 6;
  vector<vector<pair<int, int>>> adj(V);

  // DAG edges (u -> v, weight)
  adj[0].push_back({1, 2});
  adj[0].push_back({4, 1});
  adj[1].push_back({2, 3});
  adj[4].push_back({2, 2});
  adj[4].push_back({5, 4});
  adj[2].push_back({3, 6});
  adj[5].push_back({3, 1});

  Solution obj;
  int src = 0;
  vector<int> dist = obj.shortestPathInDAG(V, adj, src);

  cout << "Shortest distances from source " << src << ":\n";
  for (int i = 0; i < V; i++) {
    if (dist[i] == INT_MAX)
      cout << "Node " << i << " -> INF\n";
    else
      cout << "Node " << i << " -> " << dist[i] << "\n";
  }
  return 0;
}
