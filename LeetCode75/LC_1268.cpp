// trie version (there are faster solutions not using trie)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie(products);
        vector<vector<string>> result;
        for(int i=0; i<searchWord.size(); i++) {
            vector<string> sug;
            string word = searchWord.substr(0,i+1);
            Trie* node = trie;
            bool noSuggest = false;
            for(char c : word) {
                if(node->children[c-'a']==nullptr) {
                    noSuggest = true;
                    break;
                }
                node = node->children[c-'a'];
            }
            if(!noSuggest)
                trie->suggest(node, sug, word);
            result.push_back(sug);
        }
        return result;
    }

    class Trie {
        public:
            bool isLeaf;
            Trie* children[26];

            Trie() {
                isLeaf=false;
                for(int i=0; i<26; i++)
                    children[i] = nullptr;
            }

            Trie(vector<string> products) {
                isLeaf=false;
                for(int i=0; i<26; i++)
                    children[i] = nullptr;
                
                for(string word : products) {
                    this->insert(word);
                }
            }

            void insert(string word) {
                Trie* node = this;
                for(char c : word) {
                    if(node->children[c-'a'] == nullptr) {
                        node->children[c-'a'] = new Trie();
                    }
                    node = node->children[c-'a'];
                }
                node->isLeaf = true;
            }

            void suggest(Trie* node, vector<string>& suggested, string word) {
                // base case
                if(suggested.size()>=3) return;

                // base case
                if(node->isLeaf==true) {
                    suggested.push_back(word);
                }

                // recursive
                for(int i=0; i<26; i++) {
                    if(node->children[i] != nullptr) {
                        suggest(node->children[i], suggested, word+((char) ('a'+i)));
                    }
                    if(suggested.size()>=3) return;
                }
            }
    };
};
