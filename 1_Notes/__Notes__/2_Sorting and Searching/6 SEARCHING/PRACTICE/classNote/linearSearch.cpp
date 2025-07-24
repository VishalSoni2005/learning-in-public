#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the vector"<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        if(i!=v[i]){
            cout<<i;
            break;
        }

    }
}