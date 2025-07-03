//! time complexty : O(2^n)

#include <bits/stdc++.h>
using namespace std;

void targetSum(vector<int> &nums, int target, int idx, vector<vector<int>> &ans, vector<int> helper)
{
  if (target == 0)
  {
    ans.push_back(helper);
    return;
  }

  if (idx == nums.size() || target < 0)
    return;

  targetSum(nums, target, idx + 1, ans, helper); //* Exclude current element

  helper.push_back(nums[idx]);
  targetSum(nums, target - nums[idx], idx + 1, ans, helper); //* include curr ele

  helper.pop_back();
}

int main()
{
  int target = 12;
  vector<int> nums = {3, 6, 4, 5};

  vector<vector<int>> ans;
  vector<int> helper;

  targetSum(nums, target, 0, ans, helper);

  for (vector<int> i : ans)
  {
    for (int j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}