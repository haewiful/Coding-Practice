class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator start = nums.end();
        int k=0;
        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i]==val) {
                k++;
                start = nums.begin()+i;
            }
        }
        nums.erase(start, start+k);
        return nums.size();
    }
};
