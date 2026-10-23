class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n<=0) return 0;

        if (dp[n] != -1) {
            return dp[n];
        }

        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            int sqnum = i*i;
            int count = 1 + solve(n-sqnum, dp);
            ans = min(ans, count);
        }
        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};