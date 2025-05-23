class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, -1);
        dp[0]=0;
        if(n>0) dp[1]=1;
        int range=1;
        for(int i=2; i<=n; i++) {
            if(i%2==0) {
                if(pow(2, range+1)==i) {
                    dp[i] = 1;
                    range++;
                } else
                    dp[i] = 1 + dp[i-pow(2, range)];
            } else {
                dp[i] = dp[i-1]+1;
            }
        }
        return dp;
    }
};


// Better Solution: let's use bit operators
