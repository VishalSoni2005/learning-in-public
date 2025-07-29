//! longest increasing subsequence

class Solution {
 public:
  int lis(vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;

    vector<int> LIS(n);
    int size = 0;

    LIS[0] = a[0];

    for (int i = 1; i < n; i++) {
      int start = 0, end = size, idx = size + 1;

      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (LIS[mid] < a[i]) {
          start = mid + 1;
        } else {
          idx = mid;
          end = mid - 1;
        }
      }

      LIS[idx] = a[i];
      if (idx > size) size = idx;
    }

    return size + 1;
  }
};
