#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert Prefix → Postfix
string preToPost(string prefix) {
  stack<string> st;

  // Traverse from right to left
  for (int i = prefix.size() - 1; i >= 0; i--) {
    char c = prefix[i];

    if (isalnum(c)) {
      // Operand → push as string
      st.push(string(1, c));
    } else if (isOperator(c)) {
      // Pop two operands
      string op1 = st.top();
      st.pop();
      string op2 = st.top();
      st.pop();

      // Form new postfix expression
      string exp = op1 + op2 + c;
      st.push(exp);
    }
  }

  return st.top();
}

int main() {
  string prefix = "*+AB-CD";
  cout << "Prefix:  " << prefix << endl;
  cout << "Postfix: " << preToPost(prefix) << endl;
  return 0;
}
