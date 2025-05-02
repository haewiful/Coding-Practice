// my solution - recursion version
/*
class Solution {
public:
    string decodeString(string s) {
        return decode_unit(s);
    }
    
    string decode_unit(string s) {
        // s will always start with a digit
        stack<char> st;
        int repeat=0;
        string result="", encoded="";
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if(isdigit(c)) {
                if(st.empty()) {
                    if(encoded.size()>0) { // base case1
                        result += encoded;
                        encoded="";
                    }
                    repeat = repeat*10 + (c-'0');
                } else {
                    encoded+=c;
                }
            } else if(c=='[') {
                st.push(c);
                encoded+=c;
            } else if(c==']') {
                st.pop();
                encoded+=c;
                if(st.empty()) {
                    string tmp = decode_unit(encoded.substr(1, encoded.size()-2));
                    for(int i=0; i<repeat; i++) {
                        result += tmp;
                    }
                    encoded="";
                    repeat=0;
                }
            } else {
                encoded+=c;
            }
        }
        // leftover letters -> also a base case for no decoding string
        if(encoded.size()>0) result += encoded;

        // recursive case: if decoding needed -> repeat decoding & repeat them FOR every encoding unit
        return result;
    }
};
*/

// fastest version learnt and applied
class Solution {
public:
    string decodeString(string s) {
        stack<string> prev; // contains already decoded string (stored only when another encoding starts)
        stack<int> iter; // contains the number that the current string has to be repeated
        string till_now=""; // contains only the letters that will be repeated(decoded)
        int iterate=0;
        for(char c : s) {
            if(isdigit(c)) {
                iterate = iterate*10 + (c-'0');
            } else if(c=='[') { // a new encoding starts (store previous done string and the iteration needed)
                prev.push(till_now);
                iter.push(iterate);
                till_now.clear();
                iterate=0;
            } else if(c==']') { // the string that needs to be decoded is done, decode it
                int repeat = iter.top();
                iter.pop();
                string tmp = "";
                for(int i=0; i<repeat; i++) {
                    tmp += till_now;
                }
                till_now = prev.top();
                prev.pop();
                till_now += tmp;
            } else { // add char to string
                till_now+=c;
            }
        }
        return till_now;
    }
};
