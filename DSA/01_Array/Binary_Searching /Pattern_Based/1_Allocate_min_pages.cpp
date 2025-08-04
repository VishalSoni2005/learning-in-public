class Solution {
 public:
  int findPages(vector<int> &arr, int k) {
    // code here
    int n = arr.size();
    if (n < k) return -1;
    int lo = 0;
    int hi = 0;

    for (int i = 0; i < n; i++) {
      if (arr[i] > lo) lo = arr[i];
      hi += arr[i];
    }

    int ans;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int pages = 0;
      int count = 1;

      for (int i = 0; i < n; i++) {
        pages += arr[i];

        if (mid < pages) {
          count++;
          pages = arr[i];
        }
      }

      if (count <= k) {
        ans = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }

    return ans;
  }
};