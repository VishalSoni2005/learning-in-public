class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int k) {

        int m = nums.size();    // rows
        int n = nums[0].size(); // coln

        int lo = 0;
        int hi = m * n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int r = mid / n;
            int c = mid % n;
            if (nums[r][c] == k)
                return 1;
            else if (nums[r][c] > k)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return false;
    }
};