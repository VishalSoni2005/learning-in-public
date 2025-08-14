#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = nums.size();

  vector<int> prefix(n + 1, 0); // always start with 0 at fisrt index

  for (size_t i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + nums[i];
  }

  for(auto i : prefix) cout << i << " ";

  return 0;
}