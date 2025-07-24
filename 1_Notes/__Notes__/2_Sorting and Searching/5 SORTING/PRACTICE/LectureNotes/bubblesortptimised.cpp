#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vectors : ";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    //bubble sort 
    for(int i=0;i<n-1;i++){
        //traversing
        bool flag = true; //sorted
        for(int j=0;j<n-1-i;j++){
            if(v[j]>v[j+1]){ 
                swap(v[j],v[j+1]);
                flag = false;
            }
        }
        if(flag == true){
            break;              //SWAPING DOESN'T HAPPENED
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    
    
}