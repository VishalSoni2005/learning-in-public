//* sorting unsorted array using merge sort algo

#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int>&v1, vector<int>&v2, vector<int>&container) {
  int n = v1.size();
  int m = v2.size();
  int i = 0;
  int j = 0; 
  int k = 0;
  while( i < n and j < m) {
    if(v1[i] <= v2[j]) {
      container[k++] = v1[i++];
    }
    else {
      container[k++] = v2[j++];
    }
  }

  if (i == n)
    while (j < m)
      container[k++] = v2[j++];
  if (j == m)
    while (i < n)
      container[k++] = v1[i++];
  return;
}

void divideAndConquer(vector<int>&v) {
  int n = v.size();
  int n1 = n/2;
  int n2 = n-n1;
  vector<int>v1(n1);
  vector<int>v2(n2);
  for(int i=0; i<n1; i++) v1[i] = v[i];
  for(int i=0; i<n2; i++) v2[i] = v[i + n1];

  divideAndConquer(v1);
  divideAndConquer(v2);

  mergeArray(v1, v2, v);
  
  v1.clear();
  v2.clear();
}


int main() {

  vector<int> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  cout << "Before Sorting : ";
  for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
  divideAndConquer(arr);

  cout << "After Sorting : ";
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
}