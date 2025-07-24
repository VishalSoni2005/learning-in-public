#include<bits/stdc++.h>
using namespace std;
void combination(int n , vector<int>original , vector<int>ans , int target ,int idx){
    if(target == 0){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(target < 0) return;
    for(int i=idx;i<n;i++){
        ans.push_back(original[i]);
        combination(n,original,ans,target-original[i],i);
        ans.pop_back();
    }
}
int main(){
    int n;
    cout<<"Enter size of vector : ";
    cin>>n;
    vector<int>original(n);
    cout<<"Fill the vector : ";
    for(int i=0;i<n;i++){
        cin>>original[i];
    }
    int target ;
    cout<<"Enter the target : ";
    cin>>target;
    vector<int>ans;
    cout<<"All possible combinations are : "<<endl;
    combination(n,original,ans,target,0);

}