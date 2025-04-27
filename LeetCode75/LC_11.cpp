class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_vol = 0;
        int left=0, right=height.size()-1;
        while(left<right) {
            int h = min(height[left], height[right]);
            int vol = h*(right-left);
            max_vol = max(vol, max_vol);
            if(height[left]<height[right]) left++;
            else right--;
        }
        return max_vol;
    }
};
