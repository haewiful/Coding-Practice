class Solution {
public:
    string reverseWords(string s) {
        // trim s
        s = s.substr(s.find_first_not_of(' '));
        s = s.substr(0, s.find_last_not_of(' ')+1);

        string result = "";
        while(s.size()!=0) {
            size_t first_sp = s.find_first_of(' ');
            if(first_sp==string::npos) {
                result = s + " " + result;
                break;
            }
            string word = s.substr(0, first_sp);
            result = word + " " + result;
            s = s.substr(first_sp+1); // remove word
            s = s.substr(s.find_first_not_of(' ')); // remove any other spaces
        }
        return result.substr(0, result.size()-1);
    }
};
