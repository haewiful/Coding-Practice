class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max=0, cur=0, zeros=0;
        int left=0, right=0;
        while(right<nums.size()) {
            if(nums[right]==1) {
                cur++;
                right++;
            }
            else {
                if(zeros<k) {
                    zeros++;
                    cur++;
                    right++;
                } else {
                    if(nums[left++]==0) zeros--;
                    cur--;
                }
            }
            if(cur>max) {
                max=cur;
            }
        }
        return max;
    }
};
