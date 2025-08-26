
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    // Step 1: Calculate in-degree of every node
    for (int i = 0; i < V; i++) {
      for (auto it : adj[i]) {
        indegree[it]++;
      }
    }

    // Step 2: Push all nodes with indegree 0 into queue
    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    // Step 3: BFS process
    vector<int> topo;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      topo.push_back(node);

      // Decrease indegree of neighbors
      for (auto it : adj[node]) {
        indegree[it]--;
        if (indegree[it] == 0) {
          q.push(it);
        }
      }
    }

    return topo;
  }
};

int main() {
  int V = 6;
  vector<int> adj[V];

  // Example graph (DAG)
  adj[5].push_back(0);
  adj[5].push_back(2);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

  Solution obj;
  vector<int> ans = obj.topoSort(V, adj);

  cout << "Topological Sort using Kahn's Algorithm (BFS): ";
  for (auto it : ans) cout << it << " ";
}
