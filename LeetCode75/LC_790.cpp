/*
I should practice finding patterns using brute-force a little more
*/
class Solution {
public:
int mod = 1e9+7;
    int numTilings(int n) {
        vector<int> dp(n+1, -1);
        return num(dp, n);
    }

    int num(vector<int>& dp, int n) {
        // dp
        if(dp[n]>=0) return dp[n];

        // base case
        if(n==1) {
            dp[n]=1;
            return 1;
        } else if(n==2) {
            dp[n]=2;
            return 2;
        } else if(n==3) {
            dp[n]=5;
            return 5;
        }
        // 1, 2, 5, 11, 24, 53, 117, 258
        // 1  2  1  1   2   5   11   24

        // recursive case
        dp[n] = (num(dp, n-1)*2 % mod + num(dp, n-3)) % mod;

        return dp[n];
    }
};
