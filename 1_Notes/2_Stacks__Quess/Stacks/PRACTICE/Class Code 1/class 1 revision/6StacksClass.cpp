#include<iostream>
#include<vector>
using namespace std;
class stack{
public:
    int idx;
    int size;
    vector<int> ans;

    stack() {
        idx = -1;
        size = 0;
    }

    void push(int val) {
        idx++;
        ans.push_back(val);
        size++;
    }

    void pop() {
        idx--;
        ans.pop_back();
        size--;
    }

    int top() {
        return ans[idx];
    }

    int atIdx(int idx) {
        return ans[idx];
    }

    void display() {
        for(int i=0; i<size; i++) cout << ans[i] << " ";
        cout << endl;
    }
};
int main() {
    stack st;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);

    st.display(); 
    cout << st.size << endl;

    cout << st.top() << endl;

}