class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left=0, right=nums.size()-1;
        int result=0;
        while(left<right) {
            int addition = nums[left]+nums[right];
            if(addition==k) {
                result++;
                left++;
                right--;
            } else if(addition<k) left++;
            else right--;
        }
        return result;
    }
};
