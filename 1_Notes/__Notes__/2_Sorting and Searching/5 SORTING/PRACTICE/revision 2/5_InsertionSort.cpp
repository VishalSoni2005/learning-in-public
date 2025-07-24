#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&v){
    cout<<"Sorted array is : ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
vector<int> InsertionSort(vector<int>&v){
    int n = v.size();                                                                                           
    for(int i=1;i<n;i++){
        int j = i;
        while(j>=1){
            if(v[j] >= v[j-1]) break;
            if(v[j] < v[j-1]) swap(v[j],v[j-1]);
            j--;
        }
    }
    return v;
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
    InsertionSort(v);
    display(v);
}