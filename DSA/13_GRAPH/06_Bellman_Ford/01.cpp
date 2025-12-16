// User function Template for C++
//! directed weighted graph with negative weights
// todo: it works on principle of edges , till now we have studied based on vertiecs
//* it is used to  detect negative cycle => on vth iteration if any value change then it is negative cycle

// Time Complexity  Total = O(V·E) and sc : Total = O(V + E)

class Solution {
 public:
  vector<int> bellmanFord(int V, vector<vector<int>> &edges, int S) {
    // Code here
    const int INF = 1e8;
    vector<int> dist(V, INF);
    dist[S] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
      for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if (dist[u] != INF && dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
        }
      }
    }

    // Check for negative weight cycle
    //! vth iteration detect negative cycle
    for (auto &e : edges) {
      int u = e[0];
      int v = e[1];
      int w = e[2];

      if (dist[u] != INF && dist[u] + w < dist[v]) {
        return {-1};  // negative cycle found
      }
    }

    return dist;
  }
};
