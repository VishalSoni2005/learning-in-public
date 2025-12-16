//! this question is most similar to histogram problem

class Solution {
  vector<int> getNSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n,
                    n);  // for index out of bound showing the -1 for exceed
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
      while (not st.empty() and arr[i] <= arr[st.top()])
        st.pop();
      if (!st.empty())
        ans[i] = st.top();
      st.push(i);
    }
    return ans;
  }

  vector<int> getPSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n,
                    -1);  // for index out of bound showing the -1 for exceed
    stack<int> st;

    for (int i = 0; i < n; i++) {
      while (not st.empty() and arr[i] <= arr[st.top()])
        st.pop();
      if (!st.empty())
        ans[i] = st.top();
      st.push(i);
    }
    return ans;
  }

  int histogramArea(vector<int>& nums) {
    int n = nums.size();

    vector<int> nse = getNSE(nums);
    vector<int> pse = getPSE(nums);

    int ma = INT_MIN;

    for (int i = 0; i < n; i++) {
      int height = nums[i];
      int width = nse[i] - pse[i] - 1;
      int area = height * width;

      ma = max(ma, area);
    }
    return ma;
  }

 public:
  int maximalRectangle(vector<vector<char>>& nums) {
    int row = nums.size();
    int col = nums[0].size();

    vector<int> height(col, 0);
    int ma = 0;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (nums[i][j] == '1')
          height[j] += 1;
        else
          height[j] = 0;
      }

      ma = max(ma, histogramArea(height));
    }
    return ma;
  }
};