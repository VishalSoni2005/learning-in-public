//KIND OF REVERSE BUBBLE SORT 
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vectors : ";
    cin>>n;
    cout<<"Fill the array"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    //SORTING
    for(int i=1;i<n;i++){
        int j=i;
        while(j>=1){
            if(v[j]>=v[j-1]) break;
            if(v[j]<v[j-1]) 
            swap(v[j],v[j-1]);
            j--;
        }
    }
    //print
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}