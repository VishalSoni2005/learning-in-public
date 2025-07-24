#include <iostream>
using namespace std;
bool two(int n){
    if(n==1){
        return true;
    }
    if(n%2==0){
       return two(n/2);
    }
     return false;
}
int main(){
    int n;
    cout<<"Given Number : ";
    cin>>n;
    if(two(n)){
        cout<<"Yes";
    }
    else{
        cout<<"NO";
    }
}