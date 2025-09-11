#include <bits/stdc++.h>
using namespace std;

class InfixEvaluator {
  int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
  }

  int applyOp(int a, int b, char op) {
    switch (op) {
      case '+':
        return a + b;
      case '-':
        return a - b;
      case '*':
        return a * b;
      case '/':
        return a / b;
    }
    return 0;
  }

 public:
  int evaluate(string expr) {
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < expr.length(); i++) {
      if (expr[i] == ' ') continue;  // skip spaces

      // If number (can be multi-digit)
      if (isdigit(expr[i])) {
        int val = 0;
        while (i < expr.length() && isdigit(expr[i])) {
          val = (val * 10) + (expr[i] - '0');
          i++;
        }
        values.push(val);
        i--;  // step back
      }

      // If opening parenthesis
      else if (expr[i] == '(') {
        ops.push(expr[i]);
      }

      // If closing parenthesis
      else if (expr[i] == ')') {
        while (!ops.empty() && ops.top() != '(') {
          int b = values.top();
          values.pop();
          int a = values.top();
          values.pop();
          char op = ops.top();
          ops.pop();
          values.push(applyOp(a, b, op));
        }
        ops.pop();  // remove '('
      }

      // Operator
      else {
        while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
          int b = values.top();
          values.pop();
          int a = values.top();
          values.pop();
          char op = ops.top();
          ops.pop();
          values.push(applyOp(a, b, op));
        }
        ops.push(expr[i]);
      }
    }

    // Process remaining operators
    while (!ops.empty()) {
      int b = values.top();
      values.pop();
      int a = values.top();
      values.pop();
      char op = ops.top();
      ops.pop();
      values.push(applyOp(a, b, op));
    }

    return values.top();
  }
};

int main() {
  InfixEvaluator eval;
  string expr = "3+(2*5)-9";
  cout << eval.evaluate(expr) << endl;
  // Output: 4
}
