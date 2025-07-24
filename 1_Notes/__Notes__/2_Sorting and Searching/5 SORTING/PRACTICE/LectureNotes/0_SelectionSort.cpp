#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {3,5,8,6,3,1,9,5};
    int n = sizeof(arr)/ sizeof(arr[0]);

    for(int i=0; i<n; i++) {
        int min = INT_MAX;
        int mindx = -1;
        for(int j=i; j<n; j++) {    //TO FIND MINIMUM ELEMENT
            if(arr[j] < min) {
                min = arr[j];
                mindx = j;
            }
        }
            swap(arr[i], arr[mindx]);
    }
    for(int i=0; i<n; i++ ) cout << arr[i] << " ";
}