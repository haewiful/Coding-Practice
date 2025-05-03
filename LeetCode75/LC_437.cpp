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
    int pathSum(TreeNode* root, int targetSum) {
        return dfs(root, vector<int>(), targetSum);
    }

    int dfs(TreeNode* node, vector<int> path, int target) {
        // base case: no node
        if(!node) return 0;

        int result=0;
        long sum=0;
        path.push_back(node->val);
        for(int i=path.size()-1 ;i>=0 ;i--) {
            sum+=path[i];
            if(sum==target) {
                result++;
            }
        }
        return result+dfs(node->left, path, target) + dfs(node->right, path, target);
    }
};
