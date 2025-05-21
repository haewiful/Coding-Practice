class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return lcs(dp, text1, text2, text1.size()-1, text2. size()-1);
    }

    int lcs(vector<vector<int>>& dp, string& t1, string& t2, int i, int j) {
        // base case
        if(i<0 || j<0) {
            return 0;
        }

        // dp
        if(dp[i][j]>=0) return dp[i][j];

        // base case
        if(t1[i] == t2[j]) {
            dp[i][j] = lcs(dp, t1, t2, i-1, j-1) + 1;
        } else {
            dp[i][j] = max(lcs(dp, t1, t2, i-1, j), lcs(dp, t1, t2, i, j-1));
        }
        
        return dp[i][j];
    }
};
