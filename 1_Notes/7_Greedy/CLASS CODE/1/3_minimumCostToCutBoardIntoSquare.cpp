#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= len; j++) {
                if (i == j) {
                    dp[i][j] = 0;
                } else {    
                    for (int k = i; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cuts[j] - cuts[i - 1]);
                    }
            
}