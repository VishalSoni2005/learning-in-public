#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(vector<int>& arr) {
  int f = INT_MAX;
  int s = INT_MAX;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] < f) {
      s = f;
      f = arr[i];
    }

    else if (arr[i] < s and arr[i] != f)
      s = arr[i];
  }

  if (f == INT_MAX or s == INT_MAX) return {-1};

  return {f, s};
}