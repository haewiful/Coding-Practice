class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count=0;

        map<vector<int>,int> map1;
        for(int i=0; i<n; i++) {
            map1[grid[i]]++;
        }
        for(int i=0; i<n; i++) {
            vector<int> column;
            for(int j=0; j<n; j++) column.push_back(grid[j][i]);
            count += map1[column];
        }
        return count;
    }
};
