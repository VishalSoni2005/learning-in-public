#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void subset(int arr[], vector<int> &v, int n)
{
  if (n == 0)
  {
    for (int i = 0; i < v.size(); i++)
      cout << v[i] << " ";
    cout << endl;
    return;
  }

  subset(arr, v, n - 1);
  v.push_back(arr[n - 1]);
  subset(arr, v, n - 1);
  // v.pop_back();
}

int main()
{
  int arr[] = {1, 2, 3};
  vector<int> v;
  int n = sizeof(arr) / sizeof(arr[0]);
  subset(arr, v, n);

  return 0;
}