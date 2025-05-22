class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(),-1));
        return distance(word1, word2, dp, word1.size()-1, word2.size()-1);
    }

    int distance(string& w1, string& w2, vector<vector<int>>& dp, int i, int j) {
        // base case
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]>=0) return dp[i][j];

        // recursive
        if(w1[i]==w2[j]) {
            dp[i][j] = distance(w1, w2, dp, i-1, j-1);
        } else {
            dp[i][j] = min(distance(w1, w2, dp, i-1, j), distance(w1, w2, dp, i, j-1)) + 1;
            dp[i][j] = min(dp[i][j], distance(w1, w2, dp, i-1, j-1)+1);
        }
        return dp[i][j];
    }
};
