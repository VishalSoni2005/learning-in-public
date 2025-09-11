#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert Postfix → Prefix
string postToPre(string postfix) {
  stack<string> st;

  for (char c : postfix) {
    if (isalnum(c)) {
      // Operand → push as string
      st.push(string(1, c));
    } else if (isOperator(c)) {
      // Pop two operands
      string op2 = st.top();
      st.pop();
      string op1 = st.top();
      st.pop();

      // Form new prefix expression
      string exp = c + op1 + op2;
      st.push(exp);
    }
  }

  return st.top();
}

int main() {
  string postfix = "AB+CD-*";
  cout << "Postfix: " << postfix << endl;
  cout << "Prefix:  " << postToPre(postfix) << endl;
  return 0;
}
