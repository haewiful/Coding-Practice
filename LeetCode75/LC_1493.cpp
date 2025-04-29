class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0, right=0;
        int max=0, cur=0;
        int zeros=0;
        while(right<nums.size()) {
            if(nums[right]==1) {
                cur++;
                right++;
            } else {
                if(zeros<1) {
                    zeros++;
                    right++;
                } else {
                    if(nums[left++]==0) {
                        zeros--;
                    } else {
                        cur--;
                    }
                }
            }
            if(cur>max) max = cur;
        }
        if(max==nums.size()) return max-1;
        return max;
    }
};
