#include <iostream>
#include <vector>
using namespace std;

void combinationSum(vector<int> &arr, vector<int> &ans, int index, int target)
{
  if (target == 0)
  {
    for (int num : ans)
      cout << num << " ";
    cout << endl;
    return;
  }

  if (target < 0)
    return;

  for (int i = index; i < arr.size(); i++)
  {
    ans.push_back(arr[i]);
    combinationSum(arr, ans, i, target - arr[i]); // allow same element again
    ans.pop_back();                               // backtrack
  }
}

int main()
{
  vector<int> arr = { 2, 3, 5};
  vector<int> ans;
  int target = 8;
  combinationSum(arr, ans, 0, target);
  return 0;
}
