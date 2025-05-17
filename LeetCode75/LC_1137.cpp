class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        vector<int> dp(n+1, 0);
        dp[1]=1;
        dp[2]=1;
        return tri(dp, n);
    }

    int tri(vector<int>& dp, int n) {
        // base case
        if(n==0) return 0;
        if(n==1 || n==2) return 1;

        // in dp
        if(dp[n]!=0) return dp[n];

        // recursive case
        int n_1 = tri(dp, n-1);
        int n_2 = tri(dp, n-2);
        int n_3 = tri(dp, n-3);

        dp[n] = n_1 + n_2 + n_3;
        return dp[n];
    }
};
