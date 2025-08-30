
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int v = adj.size();

    vector<bool> vis(v, false);
    vector<int> dist(v, -1);

    queue<int> q;
    q.push(src);
    vis[src] = true;
    dist[src] = 0;

    while (!q.empty()) {
      int temp = q.front();
      q.pop();

      for (auto i : adj[temp]) {
        if (!vis[i]) {
          vis[i] = true;
          q.push(i);
          dist[i] = dist[temp] + 1;
        }
      }
    }

    return dist;
  }
};

int main() {
  int V = 9;

  // ✅ Correct adjacency list initialization
  vector<vector<int>> adj = {
      {1, 3},        // 0
      {0, 2},        // 1
      {1, 6},        // 2
      {0, 4},        // 3
      {3, 5},        // 4
      {4, 6},        // 5
      {2, 5, 7, 8},  // 6
      {6, 8},        // 7
      {7, 6}         // 8
  };

  int src = 1;
  Solution obj;
  vector<int> dist = obj.shortestPath(adj, src);

  cout << "Shortest distance from source " << src << " to all vertices:\n";
  for (int i = 0; i < V; i++) {
    cout << "Node " << i << " -> " << dist[i] << "\n";
  }

  return 0;
}