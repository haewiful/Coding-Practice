class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        int mini=prices[0];
        for(int i=0; i<prices.size(); i++) {
            if(prices[i]<mini) mini=prices[i];
            else {
                result = max(result, prices[i]-mini);
            }
        }
        return result;
    }
};
