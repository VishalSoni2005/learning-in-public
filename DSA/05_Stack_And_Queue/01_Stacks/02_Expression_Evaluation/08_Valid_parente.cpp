class Solution {
 public:
  bool isOpen(char c) {
    if (c == '(' or c == '{' or c == '[')
      return true;
    return 0;
  }

  bool isClose(char c, char d) {
    if (c == ')' and d == '(')
      return 1;
    if (c == ']' and d == '[')
      return 1;
    if (c == '}' and d == '{')
      return 1;
    return 0;
  }

  bool isValid(string s) {
    if (s.length() == 1)
      return 0;
    stack<char> st;

    for (char c : s) {
      if (isOpen(c))
        st.push(c);
      else if (st.empty())
        return false;
      else {
        if (isClose(c, st.top()))
          st.pop();
        else
          return 0;
      }
    }

    return st.empty();
  }
};