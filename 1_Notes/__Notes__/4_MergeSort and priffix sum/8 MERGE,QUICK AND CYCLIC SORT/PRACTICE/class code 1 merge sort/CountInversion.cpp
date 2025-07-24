#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of first array : ";
    cin>>n;
    vector<int>arr1(n);
    cout<<"Fill the array : ";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    //////// BRUTE FORCE or NAIVE APPROACH ///////
    int count = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr1[i] > arr1[j]) count++;
        }
    }
    cout<<"Number of possible Inversions are : "<<count;
}
