#include <bits/stdc++.h>
using namespace std;

int findSum(int a, int b) {
    if(a > b) return 0;
    if(a % 2 == 0) return findSum(a+1, b);
    return a + findSum(a+2, b);
}
int main() {
    int a, b; //'a' se 'b'tak
    cin >> a >> b;
    cout << findSum(a, b) << endl;

}















// void simplyprint(int a,int b){
//     if(a>b){
//         for(int i=b;i<=a;i++){
//              if(i%2!=0) cout<<i<<" ";
//         }
//     }
//     else{
//         for(int i=a;i<=b;i++){
//             if(i%2!=0) cout<<i<<" ";
//         }
//     }
// }