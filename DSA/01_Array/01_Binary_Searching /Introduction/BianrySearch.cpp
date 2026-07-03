#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
  int low = 0;
  int high = n - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
      return mid;

    else if (arr[mid] < key)
      low = mid + 1;

    else
      high = mid - 1;
  }
  return -1;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 5;

  cout << "Key is present at index " << binarySearch(arr, n, key);
  
}