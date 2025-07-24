#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<int>st;
    // cout << st.size() << endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    // cout << st.size() << endl;
    cout << "Printing the stack element in reverse order : ";
    while(st.size() > 0) {
        cout << st.top() << " ";
        st.pop();
    }









}