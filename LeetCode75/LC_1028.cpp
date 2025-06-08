/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        return traverse(traversal, 0);
    }

    TreeNode* traverse(string& traversal, int depth) {
        // base case: no value
        if(traversal.size()==0) return nullptr;

        size_t first_dash = traversal.find_first_of('-');

        // base case: last value
        if(first_dash == string::npos) {
            int val = stoi(traversal);
            TreeNode* node = new TreeNode(val);
            return node;
        }

        // recursive case
        // get value
        int val = stoi(traversal.substr(0, first_dash));
        TreeNode* node = new TreeNode(val);

        // get # of dash for next value
        traversal = traversal.substr(first_dash);
        size_t dash = traversal.find_first_not_of('-');

        if(dash == depth+1) {
            traversal = traversal.substr(dash);
            node->left = traverse(traversal, depth+1);
        }
        dash = traversal.find_first_not_of('-');
        
        if(dash!=string::npos && dash == depth+1) {
            traversal = traversal.substr(dash);
            node->right = traverse(traversal, depth+1);
        }
        return node;
    }
};
