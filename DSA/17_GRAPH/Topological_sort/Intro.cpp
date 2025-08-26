#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
    vis[node] = 1;

    for (auto it : adj[node]) {
      if (!vis[it]) {
        dfs(it, adj, vis, st);
      }
    }

    st.push(node);  // push after visiting all neighbors
  }

  vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        dfs(i, adj, vis, st);
      }
    }

    while (!st.empty()) {
      result.push_back(st.top());
      st.pop();
    }
    return result;
  }
};

int main() {
  int V = 6;
  vector<int> adj[V];

  // Example edges
  adj[5].push_back(0);
  adj[5].push_back(2);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

  Solution obj;
  vector<int> ans = obj.topoSort(V, adj);

  cout << "Topological Sort (DFS): ";
  for (auto it : ans) cout << it << " ";
}
