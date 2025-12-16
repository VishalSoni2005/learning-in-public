#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
  int left = 0, right = numbers.size() - 1;

  while (left < right) {
    int sum = numbers[left] + numbers[right];

    if (sum == target) {
      // +1 because the problem expects 1-based indices
      return {left + 1, right + 1};
    } else if (sum < target) {
      left++;  // need a larger sum
    } else {
      right--;  // need a smaller sum
    }
  }

  return {};  // problem guarantees one solution, so this won't happen
}

int main() {
  vector<int> numbers = {2, 7, 11, 15};
  int target = 9;
  vector<int> ans = twoSum(numbers, target);

  cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
}
