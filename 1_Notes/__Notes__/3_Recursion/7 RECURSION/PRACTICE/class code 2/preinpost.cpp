#include<iostream>
using namespace std;
void pip(int n){
    if(n==0) return;
    cout<<n<<" ";
    pip(n-1);
    cout<<n<<" ";
    pip(n-1);
    cout<<n<<" ";
    pip(n-1);
    cout<<n<<" ";
}
int main(){
    int n;
    cout<<"Enter number : ";
    cin>>n;
    pip(n);
}

// #include <iostream>
// using namespace std;


// void rec(int num) {
//     if(num == 0) return;
    
//     cout << num << " ";
//     rec(num - 1);
//     rec(num - 1);
// }


// int main() {
//     rec(3);
//     return 0;
// }