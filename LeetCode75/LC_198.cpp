class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return money(nums, dp, 0);
    }

    int money(vector<int>& nums, vector<int>& dp, int house) {
        // base case
        if(house>=nums.size()) return 0;

        // dp
        if(dp[house] >= 0) return dp[house];

        // recursive case
        dp[house] = max(money(nums, dp, house+1), money(nums, dp, house+2) + nums[house]);

        return dp[house];
    }
};
