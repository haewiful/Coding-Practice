class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(), false);
        int max = *max_element(candies.begin(), candies.end());
        for(int i=0; i<candies.size(); i++) {
            if(max <= candies[i] + extraCandies) {
                result[i] = true;
            }
        }
        return result;
    }
};
