#include <bits/stdc++.h>
using namespace std;

int priority(char op) {
  if (op == '^') return 3;
  if (op == '*' || op == '/') return 2;
  if (op == '+' || op == '-') return 1;
  return -1;
}

// Function to check associativity
bool isRightAssociative(char op) {
  return op == '^';  // only ^ is right-associative
}

//! steps to convert infix to postfix
//* step 1: check for operand
//* step 2: check for bracket
//* step 3: if ( bracket exist push to stack
//* step 4 : if ) bracket is there pop unitl (
//* step 5 : check for operator case
//* step 6: at last pop all element and put it to string;
string infixToPostfix(string& str) {
  stack<char> st;
  string ans = "";

  for (auto c : str) {
    // If operand, add to output
    if (isalnum(c)) {
      ans += c;
    }
    // If '(', push to stack
    else if (c == '(') {
      st.push(c);
    }
    // If ')', pop until '(' is found
    else if (c == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      if (!st.empty() && st.top() == '(') {
        st.pop();  // Remove '(' from stack
      }
    }
    // If operator
    else {
      while (!st.empty() && st.top() != '(' &&
             (priority(st.top()) > priority(c) ||
              (priority(st.top()) == priority(c) && !isRightAssociative(c)))) {
        ans += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  // Pop all remaining operators from stack
  while (!st.empty()) {
    if (st.top() == '(') {
      // Invalid expression - unmatched parentheses
      st.pop();
    } else {
      ans += st.top();
      st.pop();
    }
  }

  return ans;
}
