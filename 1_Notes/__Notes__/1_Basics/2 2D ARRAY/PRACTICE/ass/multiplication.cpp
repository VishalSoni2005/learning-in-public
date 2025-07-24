#include <iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a,b;
    cin>>a>>b;
    if(n==a){
    int arr[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
        }
    }
    int brr[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>brr[i][j];
        }
    }
    cout<<endl;

    //MULTIPLYING
    int res[m][b];
    for(int i=0;i<m;i++){
        for(int j=0;j<b;j++){
            res[i][j] = 0;
            for(int k=0;k<a;k++){
                res[i][j] += arr[i][k]*brr[k][j];
            }
        }
    }


    for(int i=0;i<m;i++){
        for(int j=0;j<b;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    }
    else cout<<"Santax error ";
}