#include<bits/stdc++.h>
using namespace std;
void sumTriangle(vector<int>&v ){ 
    int n = v.size();
    if(n==0) return;
    for(int num : v){
        cout<<num<<" ";
    }
    cout<<endl;
      if (n == 1) { //base case
        return;
    }
    vector<int>temp;
    for(int i=0;i<n-1;i++){
        temp.push_back(v[i] + v[i+1]);
    }
    sumTriangle(temp);
}
int main(){
    int n;
    cout<<"Size of array : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sumTriangle(v);
}