class Solution {
 public:
  bool isPossible(vector<int>& arr, int k, int mid) {
    int count = 1;
    int lp = 0;

    for (int i = 0; i < arr.size(); i++) {
      if (lp + arr[i] > mid) {
        count++;
        lp = arr[i];

        if (count > k)
          return false;
      } else
        lp += arr[i];
    }
    return true;
  }

  int splitArray(vector<int>& nums, int k) {
    int lo = *max_element(nums.begin(), nums.end());
    int hi = accumulate(nums.begin(), nums.end(), 0);

    int ans = hi;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      if (isPossible(nums, k, mid)) {
        ans = mid;
        hi = mid - 1;  // search if smaller exist
      } else
        lo = mid + 1;
    }

    return ans;
  }
};