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
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* root) {
        // base case: root is nullptr
        if(root==nullptr) return 0;
        // base case: leaf node
        if(root->left==nullptr && root->right==nullptr) return 1;
        return 1 + max(dfs(root->left), dfs(root->right));
    }
};
