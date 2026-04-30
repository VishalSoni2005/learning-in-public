#include <bits/stdc++.h>
using namespace std;

int getSecondLargest(vector<int>& arr) {

  int f = INT_MIN;
  int s = INT_MIN;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > f) {
      s = f;
      f = arr[i];
    } else if (arr[i] > s and arr[i] != f) {
      s = arr[i];
    }
  }
  return s == INT_MIN ? -1 : s;
}