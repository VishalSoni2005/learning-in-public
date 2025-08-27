#include<iostream>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class DFSSolution {
 public:
  bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node]) {
      if (!vis[it]) {
        if (dfs(it, adj, vis, pathVis)) return true;
      } else if (pathVis[it]) {
        // back edge → cycle
        return true;
      }
    }

    pathVis[node] = 0;  // backtrack
    return false;
  }

  bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V, 0), pathVis(V, 0);

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (dfs(i, adj, vis, pathVis)) return true;
      }
    }
    return false;
  }
};
