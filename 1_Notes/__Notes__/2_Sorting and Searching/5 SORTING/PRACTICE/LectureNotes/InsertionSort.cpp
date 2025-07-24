#include <bits\stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    cout<<"Fill the array"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    //INSERTION SORT
    for(int i=1;i<n;i++){
        int j=i;
        while(j>=1 && v[j]<v[j-1]){
            swap(v[j],v[j-1]);
            j--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}