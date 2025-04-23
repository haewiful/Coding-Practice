#include <iostream>
#include <string>
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int index = 0;
        string result = "";
        for(index=0 ;index<word1.length(); index++) {
            if(index>=word2.length()) {
                result.append(word1.substr(index, word1.length()-index));
                return result;
            break;
            }
            result.append(word1.substr(index, 1) + word2.substr(index, 1));
        }
        result.append(word2.substr(index, word2.length()-index));
        return result;
    }
};
