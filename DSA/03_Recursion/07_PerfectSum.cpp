//! tc : O(2^n);
#include <iostream>
using namespace std;

int perfectSum(int arr[], int sum, int size, int idx)
{
  if (idx == size)
    return sum == 0;

  int leftAns = perfectSum(arr, sum, size, idx + 1);
  int rightAns = perfectSum(arr, sum - arr[idx], size, idx + 1);
  return leftAns + rightAns;
}

int main()
{
  int arr[] = {-1, 0, 2, 3, 5, 6};
  int sum = 5;
  int size = sizeof arr / sizeof arr[0];

  cout << "Possible number os pairs are : " << perfectSum(arr, sum, size, 0);
  return 0;
}