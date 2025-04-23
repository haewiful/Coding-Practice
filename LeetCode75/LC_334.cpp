//version 1 (time limited exceeded)
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // dp?
        // max(왼편에 있는 것들 중에, 자기보다 작은 것들 중에, 제일 큰 숫자를 가진 자+1, mine)
        // 이게 3이상 되면 바로 리턴 true
        // 혹시라도 반복문 끝나면 false

        vector<int> dp(nums.size(), 1);
        for(int i=0 ;i<nums.size(); i++) {
            for(int j=0 ;j<i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            if(dp[i]>2) return true;
        }
        return false;
    }
};
*/



// version 2 (passed)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // dp[i]: num of sequence including nums[i]
        // smallest[j]: smallest nums[i] that is included in a (j+1) num of sequence
        /* Example
        nums    = [4,3,5,0,1,2]
        dp      = [1,1,2,1,2,3]
        smallest= [0,1,2]
        */

        int n = nums.size();
        int idx = 1; // The number of sequence found yet
        vector<int> dp(n, 1);
        vector<int> smallest(3, INT_MAX);
        smallest[0] = nums[0];
        for(int i=1 ;i<n; i++) {
            // calculate dp[i]
            for(int j=0 ;j<idx; j++) {
                if(smallest[j] < nums[i]) {
                    dp[i]=j+2;
                }
            }
            // if nums[i] is smaller than the one in smallest, update
            int cur_n = dp[i]-1;
            if(smallest[cur_n] > nums[i]) {
                smallest[cur_n] = nums[i];
            }
            if(cur_n >= idx) idx=cur_n+1;
            if(idx>2) return true;
        }
        return false;
    }
};

// answer
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < first) {
                first = nums[i];
            } else if(nums[i] < second) {
                second = nums[i];
            } else {
                // can only reach here if there is a number for first&second [a sequence of 2 numbers] & it's bigger than both
                return true;
            }
        }
    }
};
*/
