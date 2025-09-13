//! LC : 402

class Solution {
 public:
  string removeKdigits(string num, int k) {
    // USING STRING AS MONOTONIC STACK
    string stack = "";

    for (int i = 0; i < num.size(); i++) {
      while (!stack.empty() and k > 0 and stack.back() > num[i]) {
        k--;
        stack.pop_back();
      }

      stack.push_back(num[i]);
    }

    // if k != 0
    while (k > 0) {
      stack.pop_back();
      k--;
    }

    // remove leading zeors
    int i = 0;

    while (i < stack.size() and stack[i] == '0') {
      i++;
    }

    string ans = stack.substr(i);

    return ans.empty() ? "0" : ans;
  }
};