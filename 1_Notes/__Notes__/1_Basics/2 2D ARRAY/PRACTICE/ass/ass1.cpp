#include <iostream>
#include <vector>
using namespace std;
int main(){
    // vector<int>a(5,10);
    // vector<int>b(5,10);

    // vector<vector<int>>v(a.size());
    // v.push_back(b);
    // v.push_back(b);
    // v.push_back(b);
    // v.push_back(b);
    // v.push_back(b);
    

    // for(int i=0;i<v.size();i++){
    //     for(int j=0;j<v[0].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int a[5] = {10,10,10,10,10};
    int b[5] = {10,10,10,10,10};

    int v[][5] = {10,10,10,10,10,10,10,10,10,10};
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
}