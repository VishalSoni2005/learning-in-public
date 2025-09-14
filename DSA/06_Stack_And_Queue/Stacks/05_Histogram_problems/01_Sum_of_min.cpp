//! lc: 907. Sum of Subarray Minimums
//? BRUTE FORCE :
class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    // brute forc : find all subarray and then find min on all

    // monotonic stack:
    int mod = 1e9 + 7;
    int ans = 0;

    int n = arr.size();

    for (int i = 0; i < n; i++) {
      int mini = arr[i];

      for (int j = i; j < n; j++) {
        mini = min(arr[j], mini);
        ans = (ans + mini) % mod;
      }
    }
    return ans;
  }
};

//! OPTIMIZATION:
