class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() < 2) return nums[0];
        sort(nums.begin(), nums.end());
        int maj = nums.size()/2;
        int cnt=1, prev=nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]!=prev) {
                prev=nums[i];
                cnt=1;
            } else {
                cnt++;
                if(cnt>maj) return prev;
            }
        }
        return 0;
    }
};
