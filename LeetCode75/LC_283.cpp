class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int zero=-1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                if(zero==-1)
                    zero = i;
            } else{
                if(zero!=-1 && zero<i) {
                    nums[zero++] = nums[i];
                    nums[i]=0;
                }
            }
        }
    }
};
