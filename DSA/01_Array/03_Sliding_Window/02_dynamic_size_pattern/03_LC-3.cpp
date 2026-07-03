class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    // int n = s.length();

    // int ml = 0;
    // int count = 0;
    // string str = "";
    // for (int i = 0; i < n; i++) {
    //     str.push_back(s[i]);
    //     // count++;
    //     for (int j = 0; j < str.length() - 1; j++) {
    //         if (str[j] == s[i]) {
    //             // count = 0;
    //             str.erase(str.begin());
    //             break;
    //         }
    //     }
    //     cout << str << endl;
    //     ml = max(ml, (int)str.length());
    // }
    // return ml;

    unordered_set<char> st;  // store chars in current window
    int left = 0, ml = 0;

    for (int right = 0; right < s.size(); right++) {
      if (st.find(s[right]) != st.end()) {  // if duplicate found
        st.erase(s[left]);                  // remove left char
        left++;                             // shrink window
      }

      st.insert(s[right]);             // add current char
      ml = max(ml, right - left + 1);  // update max length
    }
    return ml;
  }
};