#include<bits/stdc++.h>
using namespace std;
void display(stack<int>original) {
    stack<int>helper;

    while(original.size() != 0) {
        helper.push(original.top());
        original.pop();
    }

    while(helper.size() != 0) {
        cout << helper.top() << " ";
        original.push(helper.top());
        helper.pop();
    }
    cout << endl;
}

int main() {
    stack<int>original;
    stack<int>helper;
    int k;
    cout << "Enter the value you wanna push at bottom : ";
    cin>>k;

    for(int i=1; i<=5; i++) original.push(i*10);
    cout << "Your Original Stack Sir -> ";
    display(original);

    //emptying the stack
    while(original.size() != 0) {
        helper.push(original.top());
        original.pop();
    }

    //pushing the k;
    original.push(k);

    while(helper.size() != 0) {
        original.push(helper.top());
        helper.pop();
    }

    cout << "Your New Stack Sir : ";
    display(original);


}