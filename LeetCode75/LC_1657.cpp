class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // all char must exist
        // the number of each char must match

        unordered_map<char, int> map1, map2;
        for(char c : word1) {
            map1[c]++;
        }
        for(char c : word2) {
            map2[c]++;
        }
        vector<int> value_num;
        for(auto pair : map1) {
            if(map2.find(pair.first)==map2.end()) return false;
            value_num.push_back(pair.second);
        }
        for(auto pair: map2) {
            if(value_num.size()==0) return false;
            vector<int>::iterator it = find(value_num.begin(), value_num.end(), pair.second);
            if(it==value_num.end())
                return false;
            else {
                value_num.erase(it);
            }
        }
        if(value_num.size()>0) return false;
        return true;
    }
};
