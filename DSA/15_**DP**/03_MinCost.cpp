class Solution {
 public:
  int rec(int n, int idx, vector<int>& nums) {
    if (idx >= n)
      return 0;

    return nums[idx] + min(rec(n, idx + 1, nums), rec(n, idx + 2, nums));
  }

  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    return min(rec(n, 0, cost), rec(n, 1, cost));
  }
};