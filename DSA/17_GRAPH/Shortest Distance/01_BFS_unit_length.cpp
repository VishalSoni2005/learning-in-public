

//! TC -> O(v + e) and space = o(v);

class Solution {
 public:
  // Function to find the shortest path from source to all other nodes
  vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    // code here
    int v = adj.size();

    // adj list is given
    vector<bool> vis(v, false);
    vector<int> dist(v, -1);

    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dist[src] = 0;

    while (!q.empty()) {
      int temp = q.front();
      q.pop();

      for (auto i : adj[temp]) {
        if (vis[i])
          continue;
        else {
          vis[i] = 1;
          q.push(i);
          dist[i] = 1 + dist[temp];
        }
      }
    }

    return dist;
  }
};