class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max=0, cur=0;
        for(int i=0; i<nums.size(); i++) {
            if(i<k) {
                cur+=nums[i];
                max = cur;
            } else {
                cur = cur - nums[i-k] + nums[i];
                if(cur>max) max = cur;
            }
        }
        return double(max)/k;
    }
};
