//? Number of subset possible to sum up to sum and also print the subsets

//! tc : O(2^n);
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void perfectSum(vector<int> &nums, vector<vector<int>> &ans, int sum, int idx, vector<int> helper)
{
  if (idx == nums.size())
  {
    if (sum == 0)
    {
      ans.push_back(helper);
    }
    return;
  }
  perfectSum(nums, ans, sum, idx + 1, helper); // exclude

  if (nums[idx] <= sum) // include only if nums[idx] is smaller than sum
  {
    helper.push_back(nums[idx]);
    perfectSum(nums, ans, sum - nums[idx], idx + 1, helper);
    helper.pop_back();
  }
}

int main()
{
  vector<int> nums = {-1, 0, 2, 3, 5, 6};
  int sum = 5;

  vector<vector<int>> ans;
  vector<int> helper;
  perfectSum(nums, ans, sum, 0, helper);
  // ans is : 3

  for (vector<int> i : ans)
  {
    for (int j : i)
      cout << j << " ";
    cout << endl;
  }
  return 0;
}