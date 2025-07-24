#include <iostream>
using namespace std;
int powerNormal(int a,int b){
    if(a==0) return 0;
    if(b==0) return 1;
    int ans = a*powerNormal(a,b-1);
    return ans;
}
int powerUltimate(int a,int b){ //formula : power(x,n) = power(x,n/2) * power(x,n/2) 
    if(a==0) return 0;
    if(b==1) return a;
    if(b==0) return 1;
    if(b%2==0){
        int ans = powerUltimate(a,b/2);
        return ans*ans;
    }
    if(b%2!=0){
        int ans = powerUltimate(a,b/2);
        return ans*ans*a;
    }
}
int main(){
    int n,m;
    cout<<"BASE > ";
    cin>>n;
    cout<<"EXPONENT > ";
    cin>>m;
    cout<<"ANSWER > "<<powerUltimate(n,m);
}