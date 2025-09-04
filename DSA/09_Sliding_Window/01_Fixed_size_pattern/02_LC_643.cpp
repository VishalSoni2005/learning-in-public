//! first find max sum then type cast it with double and divide by k
class Solution {
 public:
  double findMaxAverage(vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n)
      return 0;

    int windowSum = 0;
    for (int i = 0; i < k; i++)
      windowSum += arr[i];

    int maxsum = windowSum;

    for (int i = k; i < n; i++) {
      windowSum = windowSum + arr[i] - arr[i - k];
      maxsum = max(windowSum, maxsum);
    }
    return double(maxsum) / k;
  }
};