#include<bits/stdc++.h>
using namespace std;
void display (stack<int>&original) {
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

void pushAtbottom(stack<int>&original, int k) {
    stack<int>helper;
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
}

void reverseElements(stack<int>&original) {
    if(original.size() == 1) return; 
    int s = original.top();
    original.pop();
    reverseElements(original);
    pushAtbottom(original, s);


}

int main () {
    stack<int>original;
    
    for(int i=1; i<=5; i++) original.push(i*10);
    cout << "Your Original Stack Sir -> ";
    display(original);

    reverseElements(original);
    cout << "After Reversing sir : ";
    display(original);
}