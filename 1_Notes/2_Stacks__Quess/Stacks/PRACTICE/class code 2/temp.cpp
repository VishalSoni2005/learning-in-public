#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<char>str;
        stack<char>st;
        st.push(s[0]);
        for(int i=1; i<s.length() - 1; i++) {
            if(st.top() == s[i]) {
                str.push_back(s[i]);
                st.push(s[i]);
            }
            if(st.top() != s[i]) {
                str.push_back(s[i]);
                st.pop();
            }
        }
        string ans = "";
        for(int i=0; i<str.size(); i++) ans[i] = str[i];
        return ans;
    }
};