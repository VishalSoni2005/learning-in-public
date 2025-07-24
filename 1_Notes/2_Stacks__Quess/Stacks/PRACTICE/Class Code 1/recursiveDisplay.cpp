#include<bits/stdc++.h>
using namespace std;
void display1(stack<int>&original) {
    if(original.size() == 0) return ;
    int x = original.top();
    cout << x << " ";
    original.pop();
    display1(original);
    original.push(x);
}
// void display2(stack<int>&original) {
//      while(original.size() > 0) {
//         cout << original.top() << " ";
//         original.pop();
//     }
// }

int main (){
    stack<int>first;
    for(int i=1; i<=10; i++) first.push(i*10);
    display1(first);
    cout << endl;
    display1(first);
}
