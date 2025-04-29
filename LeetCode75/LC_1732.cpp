class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max=0, cur=0;
        for(int i=0; i<gain.size(); i++) {
            cur+=gain[i];
            if(max<cur) max=cur;
        }
        return max;
    }
};
