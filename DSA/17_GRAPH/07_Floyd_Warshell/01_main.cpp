// User function template for C++

//! adj matrix will be given and in adj mat distance b/w to node is given if one is infinite the there is no way to reach that node

//* tc : o(n^3) sc: o(1)

//? if any -ve element is present in diagonal element then graph contain -ve cycle
class Solution {
 public:
  void floydWarshall(vector<vector<int>> &dist) {
    // Code here
    int n = dist.size();

    // Floyd Warshall
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (dist[i][k] != 1e8 && dist[k][j] != 1e8) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }
  }
};