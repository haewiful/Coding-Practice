class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int product = 1;
        int has_zero = -1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                if(has_zero!=-1) {
                    vector<int> final_result(nums.size(), 0);
                    return final_result;
                }
                has_zero = i;
            } else {
                product *= nums[i];
            }
        }
        for(int i=0; i<nums.size(); i++) {
            if(has_zero!=-1) {
                if(has_zero!=i) {
                    result.push_back(0);
                } else {
                    result.push_back(product);
                }
            } else {
                result.push_back(product/nums[i]);
            }
        }
        return result;
    }
};

