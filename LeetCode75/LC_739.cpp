// version 1: using <temperature, index> pair (slower)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> answer(temperatures.size(), 0);

        for(int i=0; i<temperatures.size(); i++) {
            // decreasing monotonic stack
            while(!st.empty() && st.top().first < temperatures[i]) {
                auto [t, idx] = st.top();
                st.pop();
                answer[idx] = i-idx;
            }
            st.push(pair<int,int>(temperatures[i], i));
        }

        return answer;
    }
};

// version 2: using just the index (faster)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> answer(temperatures.size(), 0);

        for(int i=0; i<temperatures.size(); i++) {
            // decreasing monotonic stack
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int idx = st.top();
                st.pop();
                answer[idx] = i-idx;
            }
            st.push(i);
        }

        return answer;
    }
};
