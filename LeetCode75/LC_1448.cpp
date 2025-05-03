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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

    int dfs(TreeNode* root, int max) {
        // base case: not a node
        if(root==nullptr) return 0;
        
        // recursive case
        int left=0, right=0, result=0;
        if(root->val >= max) {
            max=root->val;
            result++;
        }
        left = dfs(root->left, max);
        right = dfs(root->right, max);

        return result+left+right;
    }
};
