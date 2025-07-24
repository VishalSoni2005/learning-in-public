#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&original,int startIdx,int endIdx){ //THIS FUNCTION WILL FIND PIVOT ELEMENT AND SWAP SMALL ELEMENT TO LEFT AND LARGER ELEMENT TO RIGHT TO PARTITION INDEX
    //FINDING PIVOT INDEX
    int pivotElement = original[startIdx];
    int count = 0;
    for(int i = startIdx+1;i<=endIdx;i++){
        if(original[i] <= pivotElement) count++; 
    }
    int pivotIdx = count + startIdx;
    swap(original[startIdx] , original[pivotIdx]);
    ///////////////////////////////////////////////
    int i = startIdx;
    int j = endIdx;
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
void quickSort(vector<int>&original, int startIdx, int endIdx){
    if(startIdx>=endIdx) return;
    ////TO FIND PARTITION INDEX
    int partitionIdx = partition(original,startIdx,endIdx); 
    //////////ONCE PARTITION INDEX IS CALCULATED
    quickSort(original,startIdx,partitionIdx-1);
    quickSort(original,partitionIdx+1,endIdx);
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
    ////////////////////////
    quickSort(original,0,n-1);
    ////////////////////////
    cout<<"Quickly Sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<original[i]<<" ";
    }
}