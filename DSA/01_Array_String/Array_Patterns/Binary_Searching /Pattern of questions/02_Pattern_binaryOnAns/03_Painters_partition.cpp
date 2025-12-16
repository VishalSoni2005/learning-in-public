class Solution {
 public:
  bool tellme(vector<int>& v, int k, int mid) {
    int count = 1;
    int lp = 0;  // assuming the first wall will be awarded to first worker

    for (int i = 0; i < v.size(); i++) {
      if (lp + v[i] > mid) {
        count++;        // need one more painter
        lp = v[i];      
        if (count > k)  // more than k painters needed
          return false;
      } else {
        lp += v[i];  // assign to current painter
      }
    }
    return true;
  }

  int minTime(vector<int>& arr, int k) {
    // code here

    int n = arr.size();
    if (n < k) return -1;

    int lo = *max_element(arr.begin(), arr.end());
    int hi = accumulate(arr.begin(), arr.end(), 0);

    int ans = hi;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      if (tellme(arr, k, mid)) {
        ans = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
    return ans;
  }
};