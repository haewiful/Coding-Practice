// Couldn't solve this alone, will try next time again
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
int max_length=0;
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return max_length;
    }

    // int dfs(TreeNode* node, vector<vector<int>>& dp, int index, bool left_direction) {
    void dfs(TreeNode* node, bool left_direction, int current) { 
        // base case: no node
        if(!node) {
            return;
        }
        
        // recursive case
        max_length=max(max_length, current);
        if(left_direction) {
            dfs(node->left, true, 1);
            dfs(node->right, false, current+1);
        } else {
            dfs(node->left, true, current+1);
            dfs(node->right, false, 1);
        }
    }
};
