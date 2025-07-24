#include<bits/stdc++.h>
using namespace std;
void display(stack<int>original) {
    while(original.size() != 0) {
        cout << original.top() << " ";
        original.pop();
    }
    cout << endl;
}
int main() {
    stack<int>original;
    stack<int>helper;
    stack<int>temp;

    for(int i=1; i<=10; i++) original.push(i*10);
    cout << "Your Original Stack Sir -> ";
    display(original);

    while(original.size() != 0) {
        helper.push(original.top());
        original.pop();
    }

    while(helper.size() != 0) {
        temp.push(helper.top());
        helper.pop();
    }

    while(temp.size() != 0) {
        original.push(temp.top());
        temp.pop();
    }

    cout << "Your Reversed Stack Sir -> ";
    display(original);

}