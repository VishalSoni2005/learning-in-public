#include <bits/stdc++.h>
using namespace std;

int binarySearchRec(int *arr, int key, int low, int hi)
{
  if (low > hi)
    return -1;

  int mid = low + (hi - low) / 2;

  if (arr[mid] == key)
    return mid;
  else if (arr[mid] < key)
    return binarySearchRec(arr, key, mid + 1, hi);
  else
    return binarySearchRec(arr, key, low, mid - 1);
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 5;

  int index = binarySearchRec(arr, key, 0, n - 1);
  if (index != -1)
    cout << "Key is present at index " << index << endl;
  else
    cout << "Key not found" << endl;
}
