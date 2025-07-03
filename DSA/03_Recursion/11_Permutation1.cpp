//! Time complexty : O(n * n!);
//! space complexty: O(n);

#include <bits/stdc++.h>
using namespace std;

void permutation(vector<int> &nums, vector<vector<int>> &ans, vector<int>& temp, vector<bool>& visited)
{
  if (temp.size() == nums.size()) {
    ans.push_back(temp);
    return;
  }

  for (int i = 0; i < nums.size(); i++) // Try every element from current index onward
  {
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

int main()
{
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans;

  vector<bool> visited = {0, 0, 0};
  vector<int> helper;
  permutation(nums, ans, helper, visited);

  cout << "All possible permutations are n! : " << endl;
  for (auto i : ans)
  {
    for (int j : i)
      cout << j << " ";
    cout << endl;
  }
}