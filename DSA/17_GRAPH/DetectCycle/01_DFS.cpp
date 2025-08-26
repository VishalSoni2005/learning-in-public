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
    cout << "Adjacency List : " << endl;
    for (int i = 0; i < v; i++) {
      cout << i << " => ";
      for (int j : adj[i]) cout << j << " ";
      cout << '\n';
    }
  }

  void dfs_helper(int node, vector<bool>& vis) {
    vis[node] = 1;
    cout << node << " ";

    for (auto i : adj[node]) {
      if (!vis[i]) dfs_helper(i, vis);
    }
  }

  void dfs() {
    vector<bool> visited(v, 0);

    // dfs_helper(node, visited, ans);
    for (int i = 0; i < v; i++) {
      if (!visited[i]) {
        cout << "component : ";
        dfs_helper(i, visited);
        cout << endl;
      }
    }
  }

  void bfs_with_start(int start) {
    vector<bool> vis(v, 0);
    vis[start] = 1;
    queue<int> q;
    q.push(start);

    cout << "BFS starting from " << start << ": ";
    while (not q.empty()) {
      int temp = q.front();
      q.pop();

      cout << temp << " ";

      for (int i : adj[temp]) {
        if (!vis[i]) {
          q.push(i);
          vis[i] = 1;
        }
      }
    }

    cout << endl;
  }

  void bfs() {
    vector<bool> vis(v, 0);

    cout << "BFS Traversal Component wise : \n";
    for (int start = 0; start < v; start++) {
      // for traversing to all index to visited array

      if (!vis[start]) {
        cout << "Component : ";
        vis[start] = 1;
        queue<int> q;
        q.push(start);

        while (not q.empty()) {
          int temp = q.front();
          q.pop();

          cout << temp << " ";  // perform operation

          for (auto i : adj[temp]) {
            if (not vis[i]) {
              vis[i] = 1;
              q.push(i);
            }
          }
        }
        cout << endl;
      }
    }
  }

  //* getter function for graph class
  //* coz it is private
  int vertices() const { return v; }
  const vector<vector<int>>& getList() const { return adj; }
};

class CycleDetector {
  const Graph& graph;

  

 public:
  CycleDetector(const Graph& g) : graph(g) {}  // initializer list

  bool isCycle() {
    int V = graph.vertices();
    const auto& adj = graph.getAdj();

    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (detectDFS(i, -1, vis, adj)) {
          cout << "Cycle Detected ✅" << endl;
          return true;
        }
      }
    }
    cout << "No Cycle ❌" << endl;
    return false;
  }
};

int main() {
  Graph g(8);

  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 0);  // cycle
  g.addEdge(5, 6);
  g.addEdge(6, 7);

  g.printGraph();

  cout << "\n--- Traversals ---\n";
  cout << "(i) DFS Graph Traversal " << endl;
  g.dfs();

  cout << "\n(ii) BFS Graph Traversal " << endl;
  g.bfs_with_start(0);
  g.bfs();
  cout << endl;

  cout << "\n--- Cycle Detection ---\n";
  CycleDetector detector(g);
  detector.isCycle();
}