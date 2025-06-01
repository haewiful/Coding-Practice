class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=nums[0];
        int cnt=1;
        int k=nums.size();
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]==prev) {
                cnt++;
                if(cnt>2) {
                    nums.erase(nums.begin()+i);
                    i--;
                    k--;
                }
            } else {
                prev = nums[i];
                cnt=1;
            }
        }
        return k;
    }
};
