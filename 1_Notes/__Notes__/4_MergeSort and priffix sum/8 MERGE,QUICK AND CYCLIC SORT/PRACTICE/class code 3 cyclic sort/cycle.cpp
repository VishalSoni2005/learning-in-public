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
        int idx = ans[i] - 1;
        if(i==idx) i++; //BHAU EK BATT YADD RAKH INDEX SE MATCH KRNA H ELEMENT NA KI ELEMENT SE IDX
        else swap(ans[i] , ans[idx]);
    }
    cout<<"Sorted vector sir -> ";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}