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
    vector<int> result;

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 1);
        return result;
    }
    void dfs(TreeNode* node, int depth) {
        // base case: no node
        if(!node) return;

        // base case: most right part of the level
        if(result.size()<depth) result.push_back(node->val);

        // recursive case
        dfs(node->right, depth+1);
        dfs(node->left, depth+1);
    }
};
