#include <bits/stdc++.h>
using namespace std;

// 🔹 Steps (Infix → Prefix)

// Reverse the infix expression
// While reversing:
// Chage every ( to ) and ) to (.
// Convert the reversed infix → postfix (using our corrected function).
// Reverse the postfix result → final prefix.

int priority(char c) {
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

bool isRightAssociative(char c) {
  return c == '^';
}

// Infix to Postfix (helper function)
string inToPost(string str) {
  stack<char> st;
  string ans;

  for (auto c : str) {
    if (isalnum(c)) {
      ans += c;  // Operand
    } else if (c == '(') {
      st.push(c);
    } else if (c == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      if (!st.empty()) st.pop();  // remove '('
    } else {                      // Operator
      while (!st.empty() && st.top() != '(' &&
             (priority(st.top()) > priority(c) ||
              (priority(st.top()) == priority(c) && !isRightAssociative(c)))) {
        ans += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  return ans;
}

// Infix to Prefix
string inToPre(string expr) {
  // 1. Reverse the expression
  reverse(expr.begin(), expr.end());
  for (char &c : expr) {
    if (c == '(')
      c = ')';
    else if (c == ')')
      c = '(';
  }

  // 2. Get postfix of reversed expr
  string postfix = inToPost(expr);

  // 3. Reverse postfix → prefix
  reverse(postfix.begin(), postfix.end());
  return postfix;
}

int main() {
  string expr = "(A+B)*(C-D)";
  cout << "Infix:   " << expr << endl;
  cout << "Prefix:  " << inToPre(expr) << endl;
  return 0;
}
