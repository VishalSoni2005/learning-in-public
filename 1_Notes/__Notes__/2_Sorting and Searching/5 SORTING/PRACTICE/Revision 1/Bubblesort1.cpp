#include<bits/stdc++.h>
using namespace std;
void display(vector<int>& v){
    
}
int main(){
    int n;
    cout<<"Enter the size of vectors : ";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    //SORTING
    for(int i=0;i<n-1;i++){
        bool flag = true;
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]) swap(v[j],v[j+1]);
            flag = false;
        }
        if(flag == true) break;
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}