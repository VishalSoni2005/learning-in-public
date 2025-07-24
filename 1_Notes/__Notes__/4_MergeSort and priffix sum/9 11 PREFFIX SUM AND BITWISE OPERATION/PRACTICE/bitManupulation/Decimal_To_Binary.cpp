#include<iostream>
#include<string>
using namespace std;
string D2B(int num){
    string ans = "";
    while(num>0){
        if(num%2==0){//even
            ans = "0" + ans;
        }
        else{//odd
            ans = "1" + ans;
        }
        num /= 2;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of which you want to find binary : ";
    cin>>n;
    cout<<"Binary of given Decimal is : "<<D2B(n);
}