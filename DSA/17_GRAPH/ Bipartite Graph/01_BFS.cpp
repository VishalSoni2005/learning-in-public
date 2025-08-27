class Solution {
 public:
  bool isBipartite(int v, vector<vector<int>> &edges) {
    // Code here
    vector<vector<int>> adj(v);

    for (auto i : edges) {
      int m = i[0];
      int n = i[1];
      adj[m].push_back(n);
      adj[n].push_back(m);
    }

    // step 1 : decelare the color array
    vector<int> color(v, -1);
    // Step 3: Check each component
    for (int start = 0; start < v; start++) {
      if (color[start] != -1) continue;  // already visited

      queue<int> q;
      q.push(start);
      color[start] = 0;  // assign first color

      while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
          if (color[it] == -1) {
            // Assign alternate color
            color[it] = (color[node] + 1) % 2;
            q.push(it);
          } else if (color[it] == color[node]) {
            // Conflict → not bipartite
            return false;
          }
        }
      }
    }
    return true;
  }
};