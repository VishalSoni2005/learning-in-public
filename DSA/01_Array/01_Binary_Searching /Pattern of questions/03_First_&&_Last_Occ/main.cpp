

//! key is first find first element then last element
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    // catch we have to find first and last element of do bs twice
    int first = -1;
    int last = -1;

    int n = nums.size();
    int lo = 0;
    int hi = n - 1;

    // first
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (nums[mid] == target) {
        first = mid;
        hi = mid - 1;
      }

      if (nums[mid] >= target)
        hi = mid - 1;
      else
        lo = mid + 1;
    }

    // last
    lo = 0;
    hi = n - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (nums[mid] == target) {
        last = mid;
        lo = mid + 1;
      } else if (nums[mid] >= target)
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    if (first == last and first == -1)
      return {-1, -1};
    return {first, last};
  }
};