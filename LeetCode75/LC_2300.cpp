class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // sort potions
        sort(potions.begin(), potions.end());

        // find the first potion that for a successful pair & add that to the result
        vector<int> result;
        int potion_size = potions.size();
        for(int i=0; i<spells.size(); i++) {
            long long spell = spells[i];
            int idx = potion_size/2;
            long long strength;
            int left=-1, right=potion_size;

            while(left<right) {
                strength = spell * potions[idx];
                if(strength >= success) {
                    right = idx;
                    idx = (left+right)/2;
                } else {
                    left = idx;
                    idx = (left+right)/2;
                }
                if(left+1==right) {
                    result.push_back(potion_size-right);
                    break;
                }
            }
        }
        return result;
    }
};
