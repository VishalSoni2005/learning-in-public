//IT SAYS THAT TAKE A UNSORTED ARRAY AND IT WILL SORT IT
#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&ans){
    cout<<"Answer is : ";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
void mergeArr(vector<int>&v1, vector<int>&v2, vector<int>&original){
    int n = v1.size();
    int m = v2.size();
    int i=0, j=0, k=0;
    while(i<n && j<m){
        if(v1[i] > v2[j]) original[k++] = v2[j++];
        else original[k++] = v1[i++];
    }
    if(i == n) while(j<m) original[k++] = v2[j++];
    if(j==m) while(i<n) original[k++] = v1[i++];
}
void mergeSort(vector<int>&v){
    int n = v.size();
    if(n==1) return ;
    int n1 = n/2, n2 = n - n1;
    vector<int>v1(n1), v2(n2);
    for(int i=0; i<n1; i++) v1[i] = v[i];
    for(int i=0; i<n2; i++) v2[i] = v[i+n1];
    mergeSort(v1);
    mergeSort(v2);
    mergeArr(v1, v2, v);
}
int main() {
    vector<int> arr {9,5,8,6,33,-1,7,0,1,5};
    mergeSort(arr);
    display(arr);
}