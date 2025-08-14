#include <bits/stdc++.h>
using namespace std;
void subset(int *arr, int size, vector<int> &ans, int idx = 0) {
  if (idx == size) {
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return;
  }

  subset(arr, size, ans, idx + 1);
  ans.push_back(arr[idx]);
  subset(arr, size, ans, idx + 1);
  ans.pop_back();
}

int main() {
  // ?Given an integer array nums of unique elements,
  // return all possible subsets(the power set).

  int arr[] = {1, 2, 3};
  int n = 3;

  vector<int> ans;
  subset(arr, 3, ans);
}