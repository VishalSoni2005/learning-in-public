#include <bits/stdc++.h>
using namespace std;

class Graph {
  int v;
  vector<vector<int>> adj;

 public:
  Graph(int v) {
    this->v = v;
    adj.resize(v);
  }

  void addEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= this->v || v >= this->v) {
      cout << "Invalid edge! Vertices out of range.\n";
      return;
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void addDirectedEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= this->v || v >= this->v) {
      cout << "Invalid edge! Vertices out of range.\n";
      return;
    }
    adj[u].push_back(v);
  }

  void printGraph() {
    for (int i = 0; i < v; i++) {
      cout << i << " => ";
      for (int j : adj[i]) cout << j << " ";
      cout << '\n';
    }
  }
};

int main() {
  int n;
  cout << "Enter No. of vertices: ";
  cin >> n;

  Graph g(n);
  int choice, u, v;

  do {
    cout << "\n--- Graph Menu ---\n";
    cout << "1. Add Undirected Edge\n";
    cout << "2. Add Directed Edge\n";
    cout << "3. Display Graph\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter source and destination: ";
        cin >> u >> v;
        g.addEdge(u, v);
        break;

      case 2:
        cout << "Enter source and destination: ";
        cin >> u >> v;
        g.addDirectedEdge(u, v);
        break;

      case 3:
        cout << "Displaying the Graph:\n";
        g.printGraph();
        break;

      case 4:
        cout << "Exiting...\n";
        break;

      default:
        cout << "Invalid choice!\n";
    }
  } while (choice != 4);
}
