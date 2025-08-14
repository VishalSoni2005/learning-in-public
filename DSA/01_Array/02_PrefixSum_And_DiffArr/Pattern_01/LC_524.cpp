class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> ps(n + 1, 0);

    for (int i = 0; i < n; i++)
      ps[i + 1] = nums[i] + ps[i];
    // ps is ready

    for (int i = 0; i < n; i++) {
      int ls = ps[i];
      int rs = ps[n] - ps[i + 1];
      if (ls == rs) return i;
    }
    return -1;
  }
};