class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int idx = nums.size()/2;
        int left=0, right=nums.size();
        int n = nums.size();

        while(left<=right) {
            bool g_left = idx==0 || (idx>0 && nums[idx]>nums[idx-1]); // greater than left
            bool g_right = idx==n-1 || (idx<n-1 && nums[idx]>nums[idx+1]); // greater than right
            if(g_left && g_right) {
                return idx;
            } else if(g_left) {
                left = idx+1;
            } else {
                right = idx-1;
            }
            idx = (left+right)/2;
        }
        return -1;
    }
};
