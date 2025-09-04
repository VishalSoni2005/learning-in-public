
class Solution {
 public:
  int isEulerian(int V, vector<int> adj[]) {
    // Step 1: Check connectivity (ignoring isolated vertices)
    vector<bool> visited(V, false);

    int start = -1;
    for (int i = 0; i < V; i++) {
      if (adj[i].size() > 0) {
        start = i;
        break;
      }
    }

    if (start == -1) return 2;  // no edges → Eulerian Circuit by definition

    dfs(start, visited, adj);

    for (int i = 0; i < V; i++) {
      if (!visited[i] && adj[i].size() > 0)
        return 0;  // graph not connected
    }

    // Step 2: Count odd degree vertices
    int odd = 0;
    for (int i = 0; i < V; i++) {
      if (adj[i].size() % 2 != 0) odd++;
    }

    // Step 3: Apply rules
    if (odd == 0)
      return 2;  // Eulerian Circuit
    else if (odd == 2)
      return 1;  // Eulerian Path
    else
      return 0;
  }

 private:
  void dfs(int u, vector<bool>& visited, vector<int> adj[]) {
    visited[u] = true;
    for (auto v : adj[u]) {
      if (!visited[v]) dfs(v, visited, adj);
    }
  }
};
