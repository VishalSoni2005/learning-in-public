#include <bits/stdc++.h>
using namespace std;

int largest(int* arr, int size) {
  int ml = INT_MIN;
  
  for (int i = 0; i < size; i++) {
    if (arr[i] > ml) {
      ml = arr[i];
    }
  }

  return ml;
}

int main() {
  int arr[] = {8, 3, 0, 9, 1, 2, 3, 4, 5, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Largest element in array is : " << largest(arr, size);
}