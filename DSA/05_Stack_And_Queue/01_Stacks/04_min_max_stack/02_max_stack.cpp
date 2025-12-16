class Solution {
  stack<int> st, ms;

 public:
  Solution() {
    // code here
  }

  // Add an element to the top of Stack
  void push(int x) {
    st.push(x);
    if (ms.empty() or ms.top() < x) ms.push(x);

    // code here
  }

  // Remove the top element from the Stack

  void pop() {
    if (st.empty()) return;
    if (ms.top() == st.top()) ms.pop();
    st.pop();

    // code here
  }

  // Returns top element of the Stack
  int peek() {
    // code here
    if (st.empty()) return -1;
    return st.top();
  }

  // Finds maximum element of Stack
  int getMax() {
    if (st.empty()) return -1;
    return ms.top();
    // code here
  }
};