class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int n : nums) q.push(n);
        int n;
        while(k>0) {
            n=q.top();
            q.pop();
            k--;
        }
        return n;
    }
};
