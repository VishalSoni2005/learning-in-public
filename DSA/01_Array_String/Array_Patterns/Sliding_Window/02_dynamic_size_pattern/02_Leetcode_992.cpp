class Solution {
  int atmostk(vector<int>& nums, int k) {
    int left = 0;
    int count = 0;
    unordered_map<int, int> mp;

    for (int right = 0; right < nums.size(); right++) {
      mp[nums[right]]++;

      while (mp.size() > k) {  // THIS WHILE LOOP ENSURES THAT THE COMPLETE FIRST ELEMENT IS REMOVED FROM MAP
        mp[nums[left]]--;
        if (mp[nums[left]] == 0)
          mp.erase(nums[left]);
        left++;
      }

      count += (right - left + 1);
    }
    return count;
  }

 public:
  // count in subarray variation
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    // int n = nums.size();
    // int len = 0;

    // for (int i = 0; i < n; i++) {
    //     unordered_map<int, int> mp; // int -> freq

    //     for (int j = i; j < n; j++) {
    //         mp[nums[j]]++;
    //         if (mp.size() == k)
    //             len++;
    //         else if (mp.size() > k)
    //             break;
    //     }
    // }

    // return len; // TC -> O(n^2) SC-> O(n) map

    // optimised O(n);

    // formula : count(exactly(k)) = count(atmost(k)) - count(atmost(k - 1))

    return atmostk(nums, k) - atmostk(nums, k - 1);
  }
};