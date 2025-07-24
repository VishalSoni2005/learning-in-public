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

stack<int> atIdx(stack<int>original, int k, int idx) {
    stack<int>helper;
    for(int i=0; i<idx +1; i++) {
        helper.push(original.top());
        original.pop();
    }

    original.push(k);

    while(helper.size() != 0) {
        original.push(helper.top());
        helper.pop();
    }
    return original;

}

int main() {
    stack<int>original;
    

    for(int i=1; i<=5; i++) original.push(i*10);
    cout << "Your Original Stack Sir -> ";
    display(original);

    stack<int>helper = atIdx(original, 25, 2);
    display(helper);
    

}