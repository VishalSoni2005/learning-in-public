#include <bits/stdc++.h>
using namespace std;

void subsetSum(int idx, vector<int> &nums, int sum)
{
  if (idx == nums.size())
  {
    cout << "sum is : " << sum << endl;
    return;
  }

  subsetSum(idx + 1, nums, sum);             //* not included
  subsetSum(idx + 1, nums, sum + nums[idx]); //* included
}
int main()
{
  vector<int> nums = {3, 4, 5};
  int sum = 0;
  subsetSum(0, nums, sum);
}
