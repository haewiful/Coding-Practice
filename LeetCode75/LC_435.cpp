// should memorize this greedy algorithm
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort by the end of intervals
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){ return a[1] < b[1];});

        int end = INT_MIN;
        int count=0;
        for(vector<int> inter : intervals) {
            if(inter[0] < end) count++;
            else {
                end = inter[1];
            }
        }
        return count;
    }
};
