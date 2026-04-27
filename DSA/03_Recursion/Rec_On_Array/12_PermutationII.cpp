//! Time complexty : O(n * n!);
//! space complexty: O(n);

//* DUBLICATION OF ELEMENT CAN BE POSSIBLE

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
    if (i > 0 and nums[i] == nums[i - 1] and !visited[i - 1])
      continue;
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

//? space Efficient
void permute_Efficient(vector<int> &nums, vector<vector<int>> &ans, int idx = 0)
{
  if (idx == nums.size())
  {
    ans.push_back(nums);
    return;
  }

  vector<int> use(21, 0);
  for (int i = idx; i < nums.size(); i++)
  {
    if (use[nums[i] + 10] == 0) // meaning it is used first time
    {
      swap(nums[idx], nums[i]);
      permute_Efficient(nums, ans, idx + 1);
      swap(nums[i], nums[idx]);
      use[nums[i] + 10] = 1;
    }
  }
}

int main()
{
  vector<int> nums = {1, 1, 2};
  sort(nums.begin(), nums.end());

  vector<vector<int>> ans;

  // vector<bool> visited = {0, 0, 0};
  // vector<int> helper;
  // permutation(nums, ans, helper, visited);
  permute_Efficient(nums, ans);

  cout << "All unique possible permutations" << endl;
  for (auto i : ans)
  {
    for (int j : i)
      cout << j << " ";
    cout << endl;
  }
}