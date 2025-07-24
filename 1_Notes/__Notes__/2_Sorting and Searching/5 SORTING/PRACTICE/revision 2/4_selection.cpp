#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&v){
    cout<<"Sorted array is : ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
vector<int> SelectionSort(vector<int>&v){
    int n = v.size();                                                                                           
    for(int i=0;i<n-1;i++){
        int min = INT_MAX;
        int mindx = -1;
        for(int j=i;j<n;j++){ //Loop for finding minimum element one by one
            if(v[j]<min){
                min = v[j];
                mindx = j;
            }
        }
        swap(v[i],v[mindx]);
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
    SelectionSort(v);
    display(v);
}