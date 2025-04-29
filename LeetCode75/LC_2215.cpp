class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        for(int elem : set1) {
            if(set2.find(elem)==set2.end()) {
                result[0].push_back(elem);
            }
        }
        for(int elem : set2) {
            if(set1.find(elem)==set1.end()) {
                result[1].push_back(elem);
            }
        }

        return result;
    }
};
