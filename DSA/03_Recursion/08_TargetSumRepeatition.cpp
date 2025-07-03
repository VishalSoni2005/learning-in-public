#include <bits/stdc++.h>
using namespace std;

void targetSumRepetition(vector<vector<int>> &nums, vector<int> &helper, int arr[], int size, int sum, int idx)
{
  if (sum == 0)
  {
    nums.push_back(helper);
    return;
  }

  if (idx == size || sum < 0)
    return;

  // Include reuse
  if (arr[idx] <= sum)
  {
    helper.push_back(arr[idx]);
    targetSumRepetition(nums, helper, arr, size, sum - arr[idx], idx);
    helper.pop_back(); // backtrack
  }

  // Exclude
  targetSumRepetition(nums, helper, arr, size, sum, idx + 1);
}

int main()
{
  int arr[] = {2, 3, 4};
  int sum = 6;
  vector<vector<int>> ans;
  vector<int> helper;
  int size = sizeof arr / sizeof arr[0];

  cout << "Pairs are as followed : " << endl;

  targetSumRepetition(ans, helper, arr, size, sum, 0);

  for (vector<int> i : ans)
  {
    for (int j : i)
      cout << j << " ";
    cout << endl;
  }

  return 0;
}