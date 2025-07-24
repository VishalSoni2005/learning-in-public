//Formula -> stair{n} = stair{n-1} + stair{n-2} + stair{n-3} + .....(no of ways)
//SAME AS OF FIBONACCI
#include<iostream>
using namespace std;
int stair(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    return stair(n-1) + stair(n-2) + stair(n-3);

}
int main(){
    int n;
    cout<<"Enter no of stairs : ";
    cin>>n;
    cout<<"No of ways are -> "<<stair(n);
}