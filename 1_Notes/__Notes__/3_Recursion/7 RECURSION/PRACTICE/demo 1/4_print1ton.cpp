#include<iostream>
using namespace std;
void print(int n){
    if(n==0) return ;//base condition
    print(n-1);//recusive calling
    cout<<n<<endl;//work to be done
}
int main(){
    int n;
    cout<<"Enter : ";
    cin>>n;
    print(n);
}