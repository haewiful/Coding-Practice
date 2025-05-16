class Solution {
public:
    vector<vector<string>> numPad = {{}, {}, {"a", "b", "c"}, {"d", "e", "f"},
                                {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"},
                                {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}};

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()==0) return result;
        
        queue<string> q;
        q.push("");

        for(char c : digits) {
            vector<string> letters = numPad[c-'0'];
            int n = q.size();
            for(int i=0; i<n; i++) {
                string s = q.front();
                q.pop();
                for(string ch : letters)
                    q.push(s+ch);
            }
        }
        while(!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
