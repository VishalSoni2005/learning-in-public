#include<bits/stdc++.h>
using namespace std;


int partition(vector<int>&original,int lo,int hi){ //THIS FUNCTION WILL FIND PIVOT ELEMENT AND SWAP SMALL ELEMENT TO LEFT AND LARGER ELEMENT TO RIGHT TO PARTITION INDEX
    // FINDING PIVOT INDEX
    int n = (lo+hi)/2;
    int pivotElement = original[n];
    int count = 0;
    for(int i = lo; i<=hi; i++){
        if(i==n) continue;
        if(original[i] <= pivotElement) count++; 
    }
    int pivotIdx = count + lo;
    swap(original[lo] , original[pivotIdx]);
    /////////////////////////////////////////////// 
    int i = lo;
    int j = hi;
    while(i < pivotIdx && j > pivotIdx){
        if(original[i] > pivotElement && original[j] <= pivotElement) {
            swap(original[i] , original[j]);
            i++;
            j--;
        }
        if(original[i] <= pivotElement) i++;
        if(original[j] > pivotElement) j--;
    } 
    //////////////////////////////////////////////
    return pivotIdx;
}


void quickSort(vector<int>&original,int lo ,int hi){
    if(lo>=hi) return;
    ////TO FIND PARTITION INDEX
    int partitionIdx = partition(original,lo,hi); 
    //////////ONCE PARTITION INDEX IS CALCULATED
    quickSort(original,lo,partitionIdx-1);
    quickSort(original,partitionIdx+1,hi);
}
int main(){
    int n;
    cout<<"Enter the Size of Array  : ";
    cin>>n;
    vector<int>original(n);
    cout<<"Fill the array : ";
    for(int i=0;i<n;i++){
        cin>>original[i];
    }
    //////////////////////
    quickSort(original,0,n-1);
    ////////////////////////
    cout<<"Quickly Sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<original[i]<<" ";
    }
}