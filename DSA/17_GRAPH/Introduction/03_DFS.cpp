class Solution {
 public:
  vector<int> dfs(vector<vector<int>>& adj) {
    int v = adj.size();
    vector<bool> vis(v, 0);
    vector<int> ans;

    dfsHelper(0, adj, vis, ans);
    return ans;
  }

  void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ans) {
    vis[node] = 1;
    ans.push_back(node);

    for (int i = 0; i < adj[node].size(); i++) {
      if (!vis[adj[node][i]]) {
        dfsHelper(adj[node][i], adj, vis, ans);
      }
    }
  }
};
