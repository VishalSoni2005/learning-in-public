//TIME COMPLEXITIES -> best case : O(n)
//                     normal case : O(n^2)
//                     worst case : O(n^2)
// SELECTION SORTING is unstable sorting algorithm
#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&v){
    cout<<"Sorted array is : ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
void selectionSort(int n, vector<int>&v){
    for(int i=0;i<n-1;i++){ //outer loop n-1 times chal rah h
        int min = INT_MAX;
        int mindx = -1;
        for(int j=i;j<n;j++){ //Iner loop is only to find minimum element
            if(v[j]<min){
                min = v[j];
                mindx = j;
            }
        }
        swap(v[i],v[mindx]);
    }
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the vector : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    //////////////////////////////////////
    selectionSort(n,v);
    ///////////////////////////////////////
    display(v);
}