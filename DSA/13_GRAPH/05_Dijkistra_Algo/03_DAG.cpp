#include <bits/stdc++.h>
using namespace std;

//! DJ algo in DAG

const int INF = 1e9;

int main() {
  int n, m;  // n = number of nodes, m = number of edges
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n);  // adj[node] = {neighbor, weight}

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;  // edge from u -> v with weight w
    adj[u].push_back({v, w});
  }

  int src;
  cin >> src;  // source node

  vector<int> dist(n, INF);
  dist[src] = 0;

  // min-heap priority queue: {distance, node}
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, src});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (d > dist[u]) continue;

    for (auto [v, w] : adj[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  // print distances
  for (int i = 0; i < n; i++) {
    if (dist[i] == INF)
      cout << "INF ";
    else
      cout << dist[i] << " ";
  }
  cout << "\n";

  return 0;
}
