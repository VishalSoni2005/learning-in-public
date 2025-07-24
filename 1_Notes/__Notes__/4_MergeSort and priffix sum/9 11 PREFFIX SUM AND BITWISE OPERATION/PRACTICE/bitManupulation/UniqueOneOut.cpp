#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cout<<"Size : ";
    cin>>x;
    vector<int>arr(x);
    cout<<"Fill the array : ";
    for(int i=0;i<x;i++) cin>>arr[i];
    sort(arr.begin() , arr.end());
    int res = 0;
    for(int i=0;i<x;i++){
        res = res ^ arr[i];
    }
    cout<<"Odd One Out is -> "<<res;
}
//      IMPORTANT PROPERTIES OF XOR
//1 xor is commutative ie a^b^c = a^c^b
//2 when bits are same the it gives [ 0 ]
//3 when bits are different it gives [ 1 ]