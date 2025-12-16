//* LC -> 150
//! RPN ==> postfix eval
//? solution : postfix eval -> direct expression evaluation {similar to postfix->infix}

class Solution {
  bool isOperator(const string& s) {
    return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
  }

 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (auto i : tokens) {
      if (!isOperator(i))
        st.push(stoi(i));

      else {  // operation

        int t1 = st.top();
        st.pop();
        int t2 = st.top();
        st.pop();

        int ans;

        if (i == "+")
          ans = t1 + t2;
        else if (i == "-")
          ans = t2 - t1;
        else if (i == "*")
          ans = t2 * t1;
        else if (i == "/")
          ans = t2 / t1;
        else if (i == "^")
          ans = pow(t2, t1);

        st.push(ans);
      }
    }
    return st.top();
  }
};
