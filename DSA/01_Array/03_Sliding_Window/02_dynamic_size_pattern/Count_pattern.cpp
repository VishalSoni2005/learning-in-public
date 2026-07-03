#include <bits/stdc++.h>
using namespace std;

int main() {
  //? Find no of sub array having k distinck element;
  vector<int> nums = {1, 2, 1, 2, 3};
  int n = 5;
  int k = 2;

  int count = 0;

  for (int i = 0; i < n; i++) {
    unordered_map<int, int> mp;

    for (int j = i; j < n; j++) {
      mp[nums[j]]++;
      if (mp.size() == k)
        count++;
      else if (mp.size() > k)
        break;
    }
  }
  cout << "Brute force approach solution : " << count << '\n';
}