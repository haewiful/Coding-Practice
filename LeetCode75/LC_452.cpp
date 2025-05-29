// using pairs and then sorting that will make the algorithm faster
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort using the x_end point
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {return a[1]<b[1];});

        int end = INT_MIN;
        int count=0;
        for(vector<int> inter : points) {
            if(end==INT_MIN || inter[0] > end) {
                end = inter[1];
                count++;
            }
        }
        return count;
    }
};
