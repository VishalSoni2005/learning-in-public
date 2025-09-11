#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert Postfix → Infix
string postToInfix(string postfix) {
  stack<string> st;

  for (char c : postfix) {
    if (isalnum(c)) {
      // Operand → push as string
      st.push(string(1, c));
    } else if (isOperator(c)) {
      // Operator → pop two operands
      string op2 = st.top();
      st.pop();
      string op1 = st.top();
      st.pop();

      // Form new expression
      string exp = "(" + op1 + c + op2 + ")";
      st.push(exp);
    }
  }

  return st.top();
}

int main() {
  string postfix = "AB+CD-*";
  cout << "Postfix: " << postfix << endl;
  cout << "Infix:   " << postToInfix(postfix) << endl;
  return 0;
}
