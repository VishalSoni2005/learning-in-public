#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>&v){
    cout<<"You Array Is : ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    display(v);
}
void input(vector<int>&v){
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    display(v);
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the array : ";
    input(v);
}