#include<iostream>
using namespace std;
int main(){
    string x = "101010101010";
    int ans = 0;
    for(int i=0;i<12;i++){
        char ch = x[i];
        int num = ch + '0';
        ans = ans + num*(i<<(12-i-1));
    }
    cout<<ans;
}