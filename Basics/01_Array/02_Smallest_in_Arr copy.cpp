#include <bits/stdc++.h>
using namespace std;

int largest(int* arr, int size) {
  if(size == 0) throw  runtime_error("size can not be 0");
  int ml = INT_MAX;
  
  for (int i = 0; i < size; i++) {
    if (arr[i] < ml) {
      ml = arr[i];
    }
  }

  return ml;
}

int main() {
  int arr[] = {8, 3, 0, 9, 1, 2, 3, 4, 5, 7, -1};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Largest element in array is : " << largest(arr, size);
}