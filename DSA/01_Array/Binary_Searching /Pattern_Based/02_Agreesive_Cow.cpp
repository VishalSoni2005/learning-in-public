class Solution {
 public:
  bool isPossible(vector<int> &nums, int cows, int minDist) {
    int count = 1;
    int lastPosition = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - lastPosition >= minDist) {
        count++;
        lastPosition = nums[i];
      }

      if (count >= cows) return true;
    }
    return false;
  }

  int aggressiveCows(vector<int> &nums, int k) {
    // code here
    int n = nums.size();
    if (k > n) return -1;

    // step 1 sort
    sort(nums.begin(), nums.end());

    int lo = 1;                      // the minimum possible distance between two cows is at least 1 unit
    int hi = nums[n - 1] - nums[0];  // first element - last element
    int ans = 0;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      if (isPossible(nums, k, mid)) {
        ans = mid;
        lo = mid + 1;
      } else
        hi = mid - 1;
    }
    return ans;
  }
};