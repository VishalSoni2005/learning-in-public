#include<bits/stdc++.h>
using namespace std;
void display(stack<int>&original) {
    stack<int>helper;
    while(original.size() > 0) {
        cout << original.top() << " ";
        original.pop();
    }
}
void insert(stack<int>& original, int idx, int val) {
    stack<int>temp;
    while(original.size() > idx) {
        temp.push(original.top());
        original.pop();
    }
    original.push(val);
    while(temp.size() > 0) {
        original.push(temp.top());
        temp.pop();
    }
    display(original);
}
int main (){
    stack<int>first;
    for(int i=1; i<=10; i++) first.push(i*10);
    int val = 1'2'0;
    int idx = 5;
    insert(first, idx, val);

}
