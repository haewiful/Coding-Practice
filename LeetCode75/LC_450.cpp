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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val == key) {
            return restructure(root);
        }
        dfs(root, key);
        return root;
    }

    void dfs(TreeNode* node, int key) {
        // base case: no node
        if(!node) return;

        // base case: found key
        if(node->left && node->left->val==key) {
            node->left = restructure(node->left);
            return;
        }
        if(node->right && node->right->val==key) {
            node->right = restructure(node->right);
            return;
        }

        // recursive case
        dfs(node->left, key);
        dfs(node->right, key);
    }

    TreeNode* restructure(TreeNode* node) {
        if(!node->left) return node->right;
        if(!node->right) return node->left;

        queue<TreeNode*> q;
        q.push(node->left);
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if(!tmp->right) {
                tmp->right = node->right;
            } else {
                q.push(tmp->right);
            }
        }
        return node->left;
    }
};
*/


// version 2
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val == key) {
            return restructure(root);
        }
        dfs(root, key);
        return root;
    }

    void dfs(TreeNode* node, int key) {
        // base case: no node
        if(!node) return;

        // base case: found key
        if(node->left && node->left->val==key) {
            node->left = restructure(node->left);
            return;
        }
        if(node->right && node->right->val==key) {
            node->right = restructure(node->right);
            return;
        }

        // recursive case
        dfs(node->left, key);
        dfs(node->right, key);
    }

    TreeNode* restructure(TreeNode* node) {
        if(!node->left) return node->right;
        if(!node->right) return node->left;

        TreeNode* rightmost = node->left;
        while(rightmost->right)
            rightmost = rightmost->right;
        rightmost->right = node->right;
        return node->left;
    }
};
