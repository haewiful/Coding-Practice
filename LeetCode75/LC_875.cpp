class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(), piles.end());
        int idx, result=right;

        while(left<=right) {
            idx=(left+right)/2;
            if(canEat(piles, idx, h)) {
                right=idx-1;
                result=idx;
            } else {
                left=idx+1;
            }
        }
        return result;
    }

    bool canEat(vector<int>&piles, int k, int h) {
        long count=0;
        for(int i=0; i<piles.size(); i++) {
            count+=piles[i]/k;
            if(piles[i]%k!=0) count++;
        }
        return h>=count;
    }
};
