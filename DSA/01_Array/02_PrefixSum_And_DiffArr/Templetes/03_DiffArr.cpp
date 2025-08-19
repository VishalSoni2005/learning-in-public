#include <bits/stdc++.h>
using namespace std;

// Apply range updates using 1D difference array
void applyUpdates(vector<int>& arr, vector<tuple<int, int, int>>& queries) {
  int n = arr.size();
  vector<int> diff(n + 1, 0);  // n+1 to avoid overflow on r+1

  // Step 1: Build difference array from original arr
  diff[0] = arr[0];
  for (int i = 1; i < n; i++) {
    diff[i] = arr[i] - arr[i - 1];
  }

  // Step 2: Apply all queries (l, r, val)
  for (auto [l, r, val] : queries) {
    diff[l] += val;
    if (r + 1 < n) diff[r + 1] -= val;
  }

  // Step 3: Rebuild the array
  arr[0] = diff[0];
  for (int i = 1; i < n; i++) {
    arr[i] = arr[i - 1] + diff[i];
  }
}

int main() {
  vector<int> arr = {0, 0, 0, 0, 0};
  vector<tuple<int, int, int>> queries = {
      {1, 3, 2},  // Add 2 to range [1,3]
      {2, 4, 3},  // Add 3 to range [2,4]
      {0, 2, -1}  // Subtract 1 from range [0,2]
  };

  applyUpdates(arr, queries);

  for (int x : arr) cout << x << " ";
  return 0;
}
