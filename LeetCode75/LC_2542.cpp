class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>> pq;
        priority_queue<int, vector<int>, greater<int>> storage;
        long long score = INT_MIN;
        long sum=0;
        int mul=INT_MAX;
        for(int i=0; i<nums1.size(); i++) {
            pq.push(pair<int,int>(nums2[i], nums1[i]));
        }

        while(!pq.empty()) {
            auto [g,h] = pq.top();
            if(storage.size()<k) {
                auto [n2, n1] = pq.top();
                storage.push(n1);
                pq.pop();
                mul = min(mul, n2);
                sum+=n1;

                if(storage.size() == k) {
                    long long tmp = mul*sum;
                    if(score < tmp) score = tmp;
                }
            } else {
                auto [n2, n1] = pq.top();
                storage.push(n1);
                pq.pop();
                mul = n2;
                sum+=n1;

                int m1 = storage.top();
                storage.pop();
                sum-=m1;

                long long tmp = mul*sum;
                if(score < tmp) score = tmp;
            }
        }
        
        return score;
    }
};
