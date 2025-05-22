class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return profit(dp, prices, fee, 0, 0);
    }

    int profit(vector<vector<int>>& dp, vector<int>& prices, int fee, int idx, int buy) {
        // base case
        if(idx >= dp.size()) return 0;

        // dp
        if(dp[idx][buy]>=0) return dp[idx][buy];

        // recursive
        if(buy) {
            dp[idx][buy] = max(profit(dp, prices, fee, idx+1, 0) + prices[idx], profit(dp, prices, fee, idx+1, 1));
        } else {
            dp[idx][buy] = max(profit(dp, prices, fee, idx+1, 1) - prices[idx] - fee, profit(dp, prices, fee, idx+1, 0));
        }

        return dp[idx][buy];
    }
};
