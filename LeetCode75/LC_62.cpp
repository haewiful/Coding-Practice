class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return paths(dp, 0, 0);
    }

    int paths(vector<vector<int>>& dp, int m, int n) {
        // dp
        if(m>=dp.size() || n>=dp[0].size()) return 0;
        if(dp[m][n]>0) return dp[m][n];

        // base case
        if(m==dp.size()-1 && n==dp[0].size()-1) {
            dp[m][n]=1;
            return 1;
        }

        dp[m][n] = paths(dp, m+1, n) + paths(dp, m, n+1);
        return dp[m][n];
    }
};
