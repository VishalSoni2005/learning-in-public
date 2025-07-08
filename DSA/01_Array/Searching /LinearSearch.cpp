#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int size, int key) {
  for(int i = 0; i < size; i++) {
    if(arr[i] == key) return true;
  }
  return false;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 50;

  cout << "is Key is present ? " << linearSearch(arr, n, key);
}