#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){ //Pushing all the zeros to right corner of array
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the vector : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    //Bubble sort optimised
    for(int i=0;i<n-1;i++){
        bool flag = true; //means array is sorted
        for(int j=0;j<n-1;j++){
            if(v[j]==0 && v[j+1] !=0){
                swap(v[j] , v[j+1]);
                flag = false;
            }
        }
        if(flag == true){
            cout<<"You Entered A Sorted Array";
            break;
        }

    }
    //Printing
        cout<<"Sorted array is : ";
        for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
        }


}