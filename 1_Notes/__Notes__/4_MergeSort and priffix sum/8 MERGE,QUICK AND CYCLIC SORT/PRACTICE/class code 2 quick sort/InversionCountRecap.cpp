#include<bits/stdc++.h>
using namespace std;
int noPair = 0;
int inversion(vector<int>&a,vector<int>&b){
    int count = 0;
    int i=0,j=0;
    while(){
        if(a[i] > )
    }
}
void mergeArray(vector<int>&a , vector<int>&b , vector<int>&ans){
    int n=a.size() , m=b.size();
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(a[i] > b[j]) ans[k++] = b[j++];
        if(a[i] < b[j]) ans[k++] = a[i++];
    }
    if(i==n) while(j<m) ans[k++] = b[j++];
    if(j==m) while(i<n) ans[k++] = a[i++];
}
void mergeSort(vector<int>&v){
    int n = v.size();
    if(n==1) return;
    int n1=n/2 , n2=n-n1;
    vector<int>a(n1) , b(n2);
    for(int i=0;i<n1;i++) a[i] = v[i];
    for(int i=0;i<n2;i++) b[i] = v[i+n1];
    ///////////////////////////////////////
    mergeSort(a);
    mergeSort(b);
    ////////////////////////////////////////
    noPair = inversion(a,b);
    ////////////////////////////////////////
    mergeArray(a,b,v);
    ////////////////////////////////////////
    a.clear();
    b.clear();
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
    mergeSort(v);
    //DISPLAY SORTED ARRAY 
    cout<<"Your Sorted Array sir -> ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}