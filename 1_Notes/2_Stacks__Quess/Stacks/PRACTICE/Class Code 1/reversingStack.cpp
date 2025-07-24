#include<bits/stdc++.h>
using namespace std;
int main () {
    stack<int>original;
    stack<int>temp;
    stack<int>helper;
    for(int i=1; i<=10; i++) original.push(i);
    while(original.size() > 0) {
        cout << original.top() << " ";
        temp.push(original.top());
        original.pop();
    }
    cout << endl;
    while(temp.size() > 0){
        helper.push(temp.top());
        temp.pop();
    } 
    while(helper.size() > 0) {
        original.push(helper.top());
        // cout << helper.top() << " ";
        helper.pop();
    }
    while(original.size() > 0) {
        cout << original.top() << " ";
        // temp.push(original.top());
        original.pop();
    }
}