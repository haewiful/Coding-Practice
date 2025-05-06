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
// version 1
/*
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int num_per_level=1, next_num=0;
        int level_max=INT_MIN, level_sum=0, depth=1, index=0;

        q.push(root);
        TreeNode* node;
        while(!q.empty()) {
            level_sum=0;
            while(num_per_level>0) {
                node = q.front();
                q.pop();
                level_sum+=node->val;
                num_per_level--;
                if(node->left) {
                    q.push(node->left);
                    next_num++;
                }
                if(node->right) {
                    q.push(node->right);
                    next_num++;
                }
            }
            if(level_max<level_sum) {
                level_max = level_sum;
                index=depth;
            }
            level_max = max(level_max, level_sum);
            num_per_level=next_num;
            next_num=0;
            depth++;
        }
        return index;
    }
};
*/

// version 2
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level_max=INT_MIN, level_sum=0, depth=1, result=0;

        q.push(root);
        TreeNode* node;
        while(!q.empty()) {
            int n = q.size();
            for(int i=0; i<n; i++) {
                node = q.front();
                q.pop();
                level_sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level_max<level_sum) {
                level_max = level_sum;
                result = depth;
            }
            depth++;
            level_sum=0;
        }
        return result;
    }
};
