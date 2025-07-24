#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of Array : ";
    cin>>n;
    vector<int>ans(n);
    
    cout<<"Fill the vector : ";
    for(int i=0;i<n;i++) cin>>ans[i];
    //CYCLE SORT
    int i=0;
    while(i<n){
        int correctIdx = ans[i] - 1;
        if(i == correctIdx) i++;
        else swap(ans[i] , ans[correctIdx]);
    }
    cout<<"Sorted vector sir -> ";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}