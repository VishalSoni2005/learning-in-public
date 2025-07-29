//* longest arithmatics sequestion
class Solution {
public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return n;

        vector<unordered_map<int, int>> dp(n);
        int ans = 2;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = arr[i] - arr[j];

                // Check if this difference already exists in dp[j]
                if (dp[j].count(diff)) {
                    dp[i][diff] = dp[j][diff] + 1;
                } else {
                    dp[i][diff] = 2; // Start a new AP
                }

                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};
