#include <iostream>
using namespace std;
void print(int n){
    if(n==0) return; //BASE CASE
    print(n-1); //RECURSIVE CALL
    cout<<n<<endl; //WORK DONE
}
int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    print(n);
}