class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            for (int i = 1; i * i <= j; i++) {
                int sqnum = i * i;
                dp[j] = min(dp[j], 1 + dp[j - sqnum]);
            }
        }

        return dp[n];
    }
};