#include<iostream>
#include<stack>
using namespace std;
void display(stack<int>&st) {
    if(st.size() == 0) return ;
    cout << st.top() << " " ;
    st.pop();
    display(st);
}
void pushAtBottomRec( stack<int>& st, int x) {
    if(st.size() == 0) {
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    pushAtBottomRec(st,x);
    st.push(y);

}
int main() {
    stack<int> st;
    for(int i=1; i<=10; i++) st.push(i*10);
    pushAtBottomRec(st, 0);
    display(st);
}