#include<iostream>
using namespace std;

class Solution {
 public:

  bool isCyclic(int v, vector<vector<int>>& edges) {
    // code here
    vector<vector<int>> adj(v);
    for (const auto& e : edges) {
      int i = e[0];
      int j = e[1];
      adj[i].push_back(j);
    }
    // edge list to adj list for easy traversal
    
    //! to detect cycle in directed graph using bfs kahn algo, make the count if count != V THEN RETURN FALSE;

    // step 1 : inorder
    vector<int>in(v, 0);
    for(int i = 0; i < v; i++) {
      for(auto j : adj[i]) in[j]++;
    }

    // step 2 : queue and push
    queue<int>q;
    for(int i = 0; i < v; i++) {
      if(in[i] == 0) q.push(i)
    }

    // step 3 : BFS stuff
    int count = 0;
    while(not q.empty()) {
      int temp = q.front();
      q.pop();
      count++;

      // decrement the neighbour
      for(auto it : adj[temp]) {
        in[it]--;
        if(in[it] == 0) q.push(it);
      }
    }

    return count == v;
  }
};