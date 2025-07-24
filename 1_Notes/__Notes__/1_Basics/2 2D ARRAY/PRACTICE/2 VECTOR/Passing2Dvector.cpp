#include <iostream>
#include <vector>
using namespace std;
void print(vector<vector<int> > &v){ // & because we want to use same vector  . pass by reference
    //printing size of column of all rows
    cout<<v[0].size()<<endl;
    cout<<v[1].size()<<endl;
    cout<<v[2].size()<<endl;
}
int main(){
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int>v2;
    v2.push_back(4);
    v2.push_back(5);
    
    vector<int>v3;
    v3.push_back(6);
    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);
    v3.push_back(0);

    vector< vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3); 

    print(v);
    






    // int n = numRows;
    // for(int i=1;i<=n;i++){
    //     vector<int>a(i);
    //     numRows.push_back(a); 
    // }
    // //generating pascal triangle
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         if(j==0 || j==i) v[i][j] = 1;
    //         else v[i][j] = v[i-1][j] + v[i-1][j-1];
    //     }
    // }
    // //PRINTING
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // return(v);
        
    

}