class Solution {
 public:
  vector<int> preSmallerEle(vector<int>& arr) {
    //  code here
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int idx = 0; idx < n; idx++) {
      // int idx = i % n;

      while (!st.empty() and arr[idx] <= st.top()) st.pop();

      if (!st.empty()) ans[idx] = st.top();

      st.push(arr[idx]);
    }
    return ans;
  }
};