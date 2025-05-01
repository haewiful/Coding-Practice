class Solution {
public:
    string removeStars(string s) {
        int index=0;
        for(int i=0; i<s.size(); i++) {
            char c=s[i];
            if(c=='*') {
                index--;
            } else {
                s[index++]=s[i];
            }
        }

        return s.substr(0, index);
    }
};
