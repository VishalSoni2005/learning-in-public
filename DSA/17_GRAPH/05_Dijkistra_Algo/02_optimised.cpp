// User Function Template
class Solution {
 public:
  vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    // Step 1: Build adjacency list
    vector<vector<pair<int, int>>> adj(V);
    for (auto &e : edges) {
      int u = e[0];
      int v = e[1];
      int wt = e[2];

      // Undirected graph => add both directions
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }

    // Step 2: Distance array
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 3: Min-heap (priority_queue with greater<> makes it a min-heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});  // {dist, node}

    // Step 4: Process the queue
    while (!pq.empty()) {
      auto [d, node] = pq.top();
      pq.pop();

      // If we already have a better distance, skip
      if (d > dist[node]) continue;

      // Relax neighbours
      for (auto [nbr, wt] : adj[node]) {
        if (dist[node] + wt < dist[nbr]) {
          dist[nbr] = dist[node] + wt;
          pq.push({dist[nbr], nbr});
        }
      }
    }

    return dist;
  }
};
