#include<bits/stdc++.h>
using namespace std;
void display(stack<int>original) {
    while(original.size() != 0) {
        cout << original.top() << " ";
        original.pop();
    }
    cout << endl;
}
void rec(stack<int>&original) {
    if(original.size() == 0) return ;
    int x = original.top();
    original.pop();
    rec(original);
    cout << x << " ";
    original.push(x);
}
int main() {
    stack<int>original;

    for(int i=1; i<=10; i++) original.push(i*10);
    cout << "Your Original Stack Sir -> ";
    display(original);

    cout << "Your reversed Stack Sir -> ";
    rec(original);

    cout << endl;
    cout << "Original sir : ";
    display(original);
}