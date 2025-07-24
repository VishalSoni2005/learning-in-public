#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
    }
    
    void push(int x) {
        st1.push(x);
        return;
    }
    
    int pop() { //st2
        while(st1.size() != 0) {
            st2.push(st1.top());
            st1.pop();
        }
        int x = st2.top();
        st2.pop();
        while(st2.size() != 0) {
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }
    
    int peek() { // st2
        while(st1.size() != 0) {
            st2.push(st1.top());
            st1.pop();
        }
        int x = st2.top();
        while(st2.size() != 0) {
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }
    
    bool empty() {
        if(st1.size() != 0) return false;
        else return true;
    }
};