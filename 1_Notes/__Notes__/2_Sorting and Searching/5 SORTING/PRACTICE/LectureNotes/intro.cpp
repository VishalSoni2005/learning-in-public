#include<bits\stdc++.h>
using namespace std;
int main(){
    int n;                //  [ITS TIME COMPLEXITY IS O(nlogn)]
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    cout<<endl;

    sort(v.begin(),v.end()); //through we can only sort in accending order 
    //reverse(v.begin(),v.end()); //if we want to sort array in decending order then follow this

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}