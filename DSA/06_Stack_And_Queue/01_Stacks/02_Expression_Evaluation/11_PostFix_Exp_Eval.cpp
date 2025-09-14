#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool isOperator(const string& s) {
    return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
  }

 public:
  int evaluatePostfix(vector<string>& tokens) {
    // code here
    stack<long long> st;

    for (auto i : tokens) {
      if (!isOperator(i))
        st.push(stoll(i));

      else {  // operation

        long long t1 = st.top();
        st.pop();
        long long t2 = st.top();
        st.pop();

        long long ans;

        if (i == "+")
          ans = t1 + t2;
        else if (i == "-")
          ans = t2 - t1;
        else if (i == "*")
          ans = t2 * t1;

        else if (i == "^")
          ans = pow(t2, t1);

        else if (i == "/") {
          //! special case in division => for -8 3 / => floor value when this negative post exp present
          // floor division
          ans = t2 / t1;
          if ((t2 ^ t1) < 0 && t2 % t1 != 0) ans--;
          //todo: IMP CONCEPT
          //* t2 XOR t1 -> (t2 ^ t1) < 0 means t2 and t1 have opposite signs. 
          //* a % b != 0 (non-exact division)
        }

        st.push(ans);
      }
    }
    return (int)st.top();
  }
};