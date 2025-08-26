#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void dfs(int node, vector<vector<int>>& adj, stack<int>& st,
           vector<bool>& vis) {
    vis[node] = 1;

    for (auto i : adj[node]) {
      if (!vis[i]) dfs(i, adj, st, vis);
    }

    st.push(node);
  }

  vector<int> topoSort(int v, vector<vector<int>>& edges) {
    // code here

    // given edge list: converting it into adj list
    vector<vector<int>> adj(v);
    //! Why & (reference)? Without &, the loop makes a copy of each element:
    // for (auto e : edges) { ... }   // e is a COPY of a vector<int>
    // That means for every iteration, a new vector<int> is created in memory → extra cost (slow + memory heavy).
    // With &, e becomes a reference to the original element in edges

    for (auto& e : edges) {
      int i = e[0];
      int j = e[1];
      adj[i].push_back(j);
    }

    // not topo sort

    stack<int> st;
    vector<bool> vis(v, 0);

    for (int i = 0; i < v; i++) {
      if (!vis[i]) {
        dfs(i, adj, st, vis);
      }
    }

    // dfs(ans, st, adj, 0);

    vector<int> ans;
    while (!st.empty()) {
      ans.push_back(st.top());
      st.pop();
    }

    return ans;
  }
};
// int main() {
//   int V = 7;
//   vector<int> adj[V];

//   // Example edges
//   adj[0].push_back(1);
//   adj[0].push_back(2);

//   adj[1].push_back(3);
//   adj[1].push_back(4);

//   adj[2].push_back(0);

//   adj[3].push_back(4);

//   // adj[4].push_back(3); // 4 dont direct to any

//   adj[5].push_back(3);
//   adj[5].push_back(6);

//   adj[6].push_back(3);

//   Solution obj;
//   vector<int> ans = obj.topoSort(V, adj);

//   cout << "Topological Sort (DFS): ";
//   for (auto it : ans) cout << it << " ";
// }
