#include <bits/stdc++.h>
using namespace std;

class GraphMatrix {
  int V;
  vector<vector<int>> matrix;  // adjacency matrix
 public:
  GraphMatrix(int V) {
    this->V = V;
    matrix.resize(V, vector<int>(V, 0));
  }

  // Add edge (undirected)
  void addEdge(int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;  // remove for directed graph
  }

  // Print adjacency matrix
  void printGraph() {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << "\n";
    }
  }
};

int main() {
  GraphMatrix g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  g.printGraph();
  //     | Feature                  | Adjacency List  | Adjacency Matrix |
  //     | Space Complexity         | O(V + E)        | O(V²) |
  //     | Add Edge                 | O(1)            | O(1) |
  //     | Check Edge Exists        |  O(deg(u))      | O(1) |
  //     | Iterate Neighbors of u   | O(deg(u))       | O(V) |
  //     | Best For                 | Sparse Graphs   | Dense Graphs |
}
