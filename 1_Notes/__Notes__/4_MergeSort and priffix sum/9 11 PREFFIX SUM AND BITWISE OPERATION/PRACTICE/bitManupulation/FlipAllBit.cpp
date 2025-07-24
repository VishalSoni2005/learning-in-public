#include<iostream>
using namespace std;
string d2b(int x , string &ans){
    while(x>0){
        if(x%2==0) ans = "0" + ans;
        else ans = "1" + ans;
        x /= 2;
    }
    return ans;
}
int main(){
    int x;
    cout<<"Enter a number : ";
    cin>>x;
    string ans = "";
    cout<<"Its binary is -> "<<d2b(x , ans);
}