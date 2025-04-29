class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occur;
        for(int elem : arr) {
            occur[elem]++;
        }

        unordered_set<int> values;
        for(auto elem : occur) {
            if(values.find(elem.second)!=values.end()) return false;
            values.insert(elem.second);
        }

        return true;
    }
};
