//* length of longest subarray with sum <= k
#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr[] = {2, 5, 1, 7, 10};
  int k = 14;

  int len = 0;
  int sum = 0;

  int l = 0;
  int r = 0;
  while (r < 5) {
    sum += arr[r];

    while (sum >= k) {
      len = max(len, r - l + 1);
      sum -= arr[l];
      l++;
    }

    r++;
  }

  cout << len << '\n';
}