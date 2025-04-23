class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        int planted=0;
        bool possible = true;
        while(i<flowerbed.size()) {
            if(flowerbed[i] == 0) {
                if(possible) {
                    if(i+1 == flowerbed.size()) {
                        planted++;
                        break;
                    }
                    if(flowerbed[i+1]==0) {
                        planted++;
                        i++; // don't need to check next, pass the next one
                    }
                } else {
                    possible = true;
                }
            } else {
                possible = false;
            }
            i++;
        }
        cout << planted << endl;
        if(planted >= n) return true;
        return false;
    }
};
