class Solution {
public:
    int maxVowels(string s, int k) {
        int max=0, cur=0;
        vector<bool> vol(s.size(), false);
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                vol[i]=true;
            }
            if(i<k) {
                cur += vol[i];
                max = cur;
            } else {
                cur+=vol[i]-vol[i-k];
                if(max<cur) max = cur;
            }
        }
        return max;
    }
};
