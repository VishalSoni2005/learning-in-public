#include<bits/stdc++.h>
using namespace std;
void parenthesis(string ans, int ob, int cb, int n){
    if(ans.length() == 2*n){
        cout<<ans<<endl;
        return;
    }
    if(ob<n) parenthesis(ans+'(',ob+1,cb,n);
    if(ob>cb) parenthesis(ans+')',ob,cb+1,n);
    
}
int main(){
    int n;
    cout<<"Enter a number : ";
    cin>> n;
    parenthesis("",0,0,n);

}
