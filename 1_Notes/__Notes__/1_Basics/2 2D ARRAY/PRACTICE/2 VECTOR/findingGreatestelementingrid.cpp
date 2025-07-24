#include<bits\stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>v;

    vector<int>v1;
    // int n;
    // cout<<"Enter the size of v1 : ";
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int l;
    //     cin>>l;
    //     v1.push_back(l);
    // }
    v1.push_back(5);
    v1.push_back(4);
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(1);

    // vector<int>v2;
    // int m;
    // cout<<"Enter the size of v2 : ";
    // cin>>m;
    // for(int i=0;i<m;i++){
    //     int l;
    //     cin>>l;
    //     v2.push_back(l);
    // }

    vector<int>v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    // vector<int>v3;
    // int o;
    // cout<<"Enter the size of v3 : ";
    // cin>>o;
    // for(int i=0;i<o;i++){
    //     int l;
    //     cin>>l;
    //     v3.push_back(l);
    // }

    vector<int>v3;
    v3.push_back(9);
    v3.push_back(4);
    v3.push_back(9);
    v3.push_back(5);

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(int i=0;i<3;i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
     cout<<endl;

    //finding greatest in a row
    int w=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] < v[i][j+1]){
                w += v[i][j+1];
                cout<<v[i][j+1]<<" ";
            }
        }
    }
}