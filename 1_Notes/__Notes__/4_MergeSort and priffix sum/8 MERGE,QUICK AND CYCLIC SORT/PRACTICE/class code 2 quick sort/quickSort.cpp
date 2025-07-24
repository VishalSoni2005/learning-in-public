#include<bits/stdc++.h>
using namespace std;
int pivotindex(vector<int>&v,int si,int ei){
    int pivotEle = v[si];
    int count = 0;
    for(int i=si+1;i<=ei;i++) {
        if(v[i] <= pivotEle) count++;
    }
    int pivotIdx = count + si;
    swap(v[si] , v[pivotIdx]);
    //NOW SWAPING
    int i = si;
    int j = ei;
    while(i < pivotIdx && j > pivotIdx){
        if(v[i] > pivotEle && v[j] <= pivotEle){
            swap(v[i] , v[j]);
            i++;
            j--;
        }
        if(v[i] <= pivotEle) i++;
        if(v[j] > pivotEle) j--;
    }
    return pivotIdx;
}


void quickSort(vector<int>&v,int si , int ei){
    if(si>=ei) return;

    int pi = pivotindex(v,si,ei);

    quickSort(v,si,pi-1);

    quickSort(v,pi+1,ei);
}

int main(){
    int n;
    cout<<"Size : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    //SORTING FUNCTION
    quickSort(v,0,n-1);
    //DISPLAY SORTED ARRAY 
    cout<<"Your Sorted Array sir -> ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}