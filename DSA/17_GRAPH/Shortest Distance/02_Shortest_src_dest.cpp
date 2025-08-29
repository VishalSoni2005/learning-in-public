#include <bits/stdc++.h>
using namespace std;

int shortestPath(int V, vector<vector<int>>& edges, int src, int dest) {
  // Step 1: Build adjacency list
  vector<vector<int>> adj(V);
  for (auto e : edges) {
    int u = e[0], v = e[1];
    adj[u].push_back(v);
    adj[v].push_back(u);  // undirected
  }

  // Step 2: Distance + parent array
  vector<int> dist(V, INT_MAX);
  vector<int> parent(V, -1);

  dist[src] = 0;
  queue<int> q;
  q.push(src);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int nbr : adj[node]) {
      if (dist[nbr] == INT_MAX) {  // not visited
        dist[nbr] = dist[node] + 1;
        parent[nbr] = node;
        q.push(nbr);

        if (nbr == dest)  // we reached destination early
          break;
      }
    }
  }

  if (dist[dest] == INT_MAX) return -1;  // no path

  // If you only need distance:
  cout << "Shortest distance: " << dist[dest] << "\n";

  // If you also want the actual path:
  vector<int> path;
  for (int v = dest; v != -1; v = parent[v]) {
    path.push_back(v);
  }
  reverse(path.begin(), path.end());

  cout << "Path: ";
  for (int v : path) cout << v << " ";
  cout << "\n";

  return dist[dest];
}

int main() {
  int V = 6;
  vector<vector<int>> edges = {
      {0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 5}};

  int src = 0, dest = 5;
  shortestPath(V, edges, src, dest);

  return 0;
}
