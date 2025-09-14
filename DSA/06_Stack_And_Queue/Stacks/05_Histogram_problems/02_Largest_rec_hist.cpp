
//! Brute force tc : o(5N) 
class Solution {
  vector<int> getNSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, n);  //! note here we provided 6 sample because 6 will act as extra index if no nse is present
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] >= arr[i]) {
        st.pop();
      }
      if (!st.empty()) nse[i] = st.top();
      st.push(i);
    }
    return nse;
  }

  vector<int> getPSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
      while (!st.empty() && arr[st.top()] >= arr[i]) {
        st.pop();
      }
      if (!st.empty()) pse[i] = st.top();
      st.push(i);
    }
    return pse;
  }

 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    vector<int> nse = getNSE(heights);
    vector<int> pse = getPSE(heights);

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
      int width = nse[i] - pse[i] - 1;
      int area = heights[i] * width;
      maxArea = max(maxArea, area);
    }
    return maxArea;
  }
};
