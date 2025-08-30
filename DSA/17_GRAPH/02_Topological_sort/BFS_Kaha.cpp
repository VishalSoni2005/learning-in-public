
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> topoSort(int v, vector<vector<int>>& edges) {
    // code here
    // using bfs kahn algo:

    // step 0
    // edgelist is convertedt to adj list
    vector<vector<int>> adj(v);
    for (const vector<int>& e : edges) {
      int i = e[0];
      int j = e[1];
      adj[i].push_back(j);
    }

    // now kahns:

    // step 1 : inorder
    vector<int> inorder(v, 0);
    for (int i = 0; i < v; i++) {
      for (auto j : adj[i]) inorder[j]++;
    }

    // step 2 : push to queue where inorder[i] == 0
    queue<int> q;
    for (int i = 0; i < v; i++) {
      if (inorder[i] == 0) q.push(i);
    }

    // step 3 : typical BFS
    vector<int> ans;
    while (!q.empty()) {
      int node = q.front();
      q.pop();

      ans.push_back(node);

      // reduce the inorder of adj elements
      for (auto i : adj[node]) {
        inorder[i]--;
        if (inorder[i] == 0) q.push(i);
      }
    }
    return ans;
  }
};