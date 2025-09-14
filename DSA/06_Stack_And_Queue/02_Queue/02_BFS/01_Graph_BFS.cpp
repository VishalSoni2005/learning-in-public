#include <vector>
class Solution {
 public:
  // Function to return Breadth First Traversal of given graph.
  vector<int> bfs(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> vis(n, 0);
    vector<int> ans;

    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while (not q.empty()) {
      int temp = q.front();
      q.pop();
      ans.push_back(temp);

      for (auto i : adj[temp]) {
        if (not vis[i]) {
          vis[i] = 1;

          q.push(i);
        }
        A
      }
    }
    return ans;
  }
};