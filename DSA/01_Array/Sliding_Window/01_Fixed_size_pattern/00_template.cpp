// Fixed-size Sliding Window Template
#include <bits/stdc++.h>
using namespace std;

void fixedWindow(vector<int>& arr, int k) {
  int n = arr.size();
  int windowSum = 0;

  // First window
  for (int i = 0; i < k; i++) windowSum += arr[i];

  cout << windowSum << " ";  // do your operation here

  for (int i = k; i < n; i++) {
    windowSum += arr[i] - arr[i - k];  // slide window
    cout << windowSum << " ";          // operation
  }
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  fixedWindow(arr, k);
}
