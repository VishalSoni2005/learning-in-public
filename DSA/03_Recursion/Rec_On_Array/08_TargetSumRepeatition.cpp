/**
 * * key hint in this question is that i can use an element many time
 * ! TC: O(2^n)
 */

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
    if (arr[idx] == 0)
      targetSumRepetition(nums, helper, arr, size, sum, idx + 1);
    helper.push_back(arr[idx]);
    targetSumRepetition(nums, helper, arr, size, sum - arr[idx], idx);
    helper.pop_back(); // backtrack
  }

  // Exclude
  targetSumRepetition(nums, helper, arr, size, sum, idx + 1);
}

int main()
{
  int arr[] = {2, 3, 4, 5, 7, 8};
  int sum = 14;
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