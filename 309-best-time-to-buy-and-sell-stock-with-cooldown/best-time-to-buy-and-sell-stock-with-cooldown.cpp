class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n <= 1) {
            return 0;
        }

        vector<int> hold(n);
        vector<int> sold(n);

        // Buy on day 0
        hold[0] = -prices[0];

        // Cannot sell on day 0
        sold[0] = 0;

        // Day 1
        hold[1] = max(-prices[0], -prices[1]);
        sold[1] = max(0, prices[1] - prices[0]);

        for (int i = 2; i < n; i++) {
            hold[i] = max(hold[i - 1],
                          sold[i - 2] - prices[i]);

            sold[i] = max(sold[i - 1],
                          hold[i - 1] + prices[i]);
        }

        return sold[n - 1];
    }
};