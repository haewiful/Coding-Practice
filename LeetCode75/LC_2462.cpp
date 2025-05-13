class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long total=0;
        if(costs.size() <= candidates*2) {
            sort(costs.begin(), costs.end());
            for(int i=0; i<k; i++) {
                total += costs[i];
            }
            return total;
        }

        priority_queue<int, vector<int>, greater<int>> left, right;
        int left_idx=candidates, right_idx=costs.size()-candidates-1;
        for(int i=0; i<candidates; i++) {
            left.push(costs[i]);
            right.push(costs[costs.size()-i-1]);
        }

        int count=0;
        while(count < k) {
            if(!left.empty() && (right.empty() || left.top() <= right.top())) {
                int cost = left.top();
                left.pop();
                total+=cost;
                if(left_idx<=right_idx) {
                    left.push(costs[left_idx]);
                }
                left_idx++;
            } else {
                int cost = right.top();
                right.pop();
                total+=cost;
                if(left_idx<=right_idx) {
                    right.push(costs[right_idx]);
                }
                right_idx--;
            }
            count++;
        }
        return total;
    }
};
