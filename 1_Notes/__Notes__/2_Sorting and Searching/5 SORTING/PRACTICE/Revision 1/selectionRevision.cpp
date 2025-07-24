#include<bits/stdc++.h>
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

    //sorting
    for(int i=0;i<n-1;i++){
        int min = INT_MAX;
        int mindx = -1;
        for(int j=i;j<n;j++){
            if(v[j]<min){
                min = v[j];
                mindx = j;
            }
        }
        swap(v[i],v[mindx]);
    }
    //PRINTING
    for(int i=0;i<n;i++){
        cout<<v[i];
    }
}