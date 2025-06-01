// there is another version using only reversing
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size()-(k%nums.size());
        for(int i=0; i<n; i++) {
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(), nums.begin()+n);
    }
};
