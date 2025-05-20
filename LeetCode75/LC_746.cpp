class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(price(cost, dp, 0), price(cost, dp, 1));
    }

    int price(vector<int>& cost, vector<int>& dp, int from) {
        // base case
        if(from>=cost.size()) return 0;

        // dp
        if(dp[from]>=0) return dp[from];

        // recursive
        dp[from] = min(price(cost, dp ,from+1), price(cost, dp, from+2)) + cost[from];

        return dp[from];
    }
};
