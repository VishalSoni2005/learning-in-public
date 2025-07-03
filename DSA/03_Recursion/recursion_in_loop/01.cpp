#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> &nums , vector<int>temp, int idx) {

  if(idx == nums.size()) {
    for(auto i : temp) cout << i << " ";
    cout << endl;
    return ; 
  }

  for(int i = idx; i < nums.size(); i++) {
    temp.push_back(nums[i]);
    helper(nums, temp, i + 1);
  }
}


int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  helper(nums, {}, 0);
 
  return 0;
}