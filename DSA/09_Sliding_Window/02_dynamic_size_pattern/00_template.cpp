// Variable-size Sliding Window Template
#include <bits/stdc++.h>
using namespace std;

void variableWindow(vector<int>& arr, int target) {
  int n = arr.size();
  int left = 0, sum = 0, minLen = INT_MAX;

  for (int right = 0; right < n; right++) {
    sum += arr[right];  // expand window

    while (sum >= target) {  // contract window based on condition
      minLen = min(minLen, right - left + 1);
      sum -= arr[left++];
    }
  }
  cout << "Minimum length: " << minLen << endl;
}

int main() {
  vector<int> arr = {2, 3, 1, 2, 4, 3};
  int target = 7;
  variableWindow(arr, target);
}
