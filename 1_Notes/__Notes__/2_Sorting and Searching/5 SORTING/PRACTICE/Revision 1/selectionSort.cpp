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

    //Sorting
    for(int i=0;i<n-1;i++){   //treat array as 2D array as i shows row no {after each pass}. n-1 bar me toh array sorted hi ho jayega 
        int min = INT_MAX;
        int mindx = -1;
        for(int j=i;j<n;j++){  //form content in this loop we can find the min ele in array
            if(v[j] < min){
            min = v[j];
            mindx = j;
            }            
        }
        swap(v[i],v[mindx]);
    }


    //printing
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
