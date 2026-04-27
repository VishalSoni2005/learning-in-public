//! Time complexty : O(n * n!);
//! space complexty: O(n);

#include <bits/stdc++.h>
using namespace std;

void permutation(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited)
{
  if (temp.size() == nums.size())
  {
    ans.push_back(temp);
    return;
  }

  for (int i = 0; i < nums.size(); i++) //? Try every element from current index onward
  {                                     //* the nums.size() will be constant in every call
    if (visited[i] == 0)
    {
      visited[i] = 1;
      temp.push_back(nums[i]);
      permutation(nums, ans, temp, visited);
      visited[i] = 0;
      temp.pop_back();
    }
  }
}

//! solution without using visited array and vector<int> temp
void permutation_without_extra_arr(vector<int> &nums, vector<vector<int>> &ans, int idx = 0)
{

  if (idx == nums.size())
  {
    ans.push_back(nums);
    return;
  }

  for (int i = idx; i < nums.size(); i++)
  {
    swap(nums[i], nums[idx]);
    permutation_without_extra_arr(nums, ans, idx + 1);
    swap(nums[i], nums[idx]);
  }
}

int main()
{
  vector<int> nums = {1, 3, 2};
  vector<vector<int>> ans;

  vector<bool> visited = {0, 0, 0};
  vector<int> helper;
  // permutation(nums, ans, helper, visited);

  // cout << "All possible permutations are n! : " << endl;
  // for (auto i : ans)
  // {
  //   for (int j : i)
  //     cout << j << " ";
  //   cout << endl;
  // }

  cout << endl;
  permutation_without_extra_arr(nums, ans);

  cout << "All possible permutations Using Space optimised tech : " << endl;
  for (auto i : ans)
  {
    for (int j : i)
      cout << j << " ";
    cout << endl;
  }
}
