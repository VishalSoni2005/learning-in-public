#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;                    // number of vertices
  vector<vector<int>> adj;  // adjacency list
 public:
  Graph(int V) {
    this->V = V;
    adj.resize(V);
  }

  // Add edge (undirected)
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // remove this for directed graph
  }

  // Print adjacency list
  void printGraph() {
    for (int i = 0; i < V; i++) {
      cout << i << " -> ";
      for (int v : adj[i]) cout << v << " ";
      cout << "\n";
    }
  }
};

int main() {
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  g.printGraph();
}
