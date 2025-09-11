//! LC : 921. Minimum Add to Make Parentheses Valid

class Solution {
  bool isMatch(char c, char d) {
    if (c == ')' and d == '(')
      return 1;
    return 0;
  }

 public:
  int minAddToMakeValid(string s) {
    stack<char> st;

    for (char c : s) {
      if (c == '(')
        st.push(c);

      else {
        if (!st.empty() and isMatch(c, st.top()))
          st.pop();
        else
          st.push(c);
      }
    }

    int count = 0;
    while (!st.empty()) {
      count++;
      st.pop();
    }
    return count;
  }
};