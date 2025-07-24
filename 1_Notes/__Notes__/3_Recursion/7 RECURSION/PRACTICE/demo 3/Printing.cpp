#include <iostream>
#include <vector>
#include <string>
using namespace std;
void print(vector<int>&v , int n , int idx){
    if(idx == n) return;
    cout<<v[idx]<<" ";
    print(v,n,idx+1);
    
}
int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the array : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"Your Array sir : ";
    print(v,n,0);

}