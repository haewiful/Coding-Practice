class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        vector<int> vowel_idx;
        for(int i=0; i<s.length(); i++) {
            char c = s.at(i);
            if(vowels.find(c) != std::string::npos) {
                vowel_idx.push_back(i);
            }
        }

        int last_idx = vowel_idx.size()-1;
        for(int i=0; i<vowel_idx.size()/2; i++) {
            char c = s[vowel_idx[i]];
            s[vowel_idx[i]] = s[vowel_idx[last_idx-i]];
            s[vowel_idx[last_idx-i]] = c;
        }
        return s;
    }
};
