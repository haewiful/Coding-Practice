/*
// no stack version
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // only +, - will collide
        int index=0, last, cur;
        for(int i=0; i<asteroids.size(); i++) {
            if(index==0) {
                asteroids[index++] = asteroids[i];
            } else {
                // only check +, -
                last = asteroids[index-1];
                cur = asteroids[i];
                if(last*cur<0 && last>0) {
                    if(last==abs(cur)) {
                        index--;
                    } else if(last<abs(cur)) {
                        index--;
                        asteroids[index] = cur;
                        i--;
                    }
                } else {
                    asteroids[index++] = cur;
                }
            }
        }
        return vector<int>(asteroids.begin(), asteroids.begin()+index);
    }
};
*/

// stack version
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int last, cur;
        for(int i=0; i<asteroids.size(); i++) {
            if(st.empty()) {
                st.push(asteroids[i]);
            } else {
                // only check +, -
                last = st.top();
                cur = asteroids[i];
                if(last*cur<0 && last>0) {
                    if(last==abs(cur)) {
                        st.pop();
                    } else if(last<abs(cur)) {
                        st.pop();
                        i--;
                    }
                } else {
                    st.push(cur);
                }
            }
        }
        vector<int> result;
        while(!st.empty()) {
            result.insert(result.begin(), st.top());
            st.pop();
        }
        return result;
    }
};
