/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// version 1
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> p_anc, q_anc;
        p_anc = get_ancestor(root, p);
        q_anc = get_ancestor(root, q);
        int index=INT_MIN;
        for(int i=0; i<p_anc.size(); i++) {
            vector<int>::iterator it = find(q_anc.begin(), q_anc.end(), p_anc[i]);
            if(it!=q_anc.end()) {
                int tmp = distance(q_anc.begin(), it);
                if(tmp>index) index=tmp;
            }
        }
        return find_node(root, q_anc[index]);
    }

    vector<int> get_ancestor(TreeNode* node, TreeNode* target) {
        // base case: no node
        if(!node) return vector<int>();

        // base case: found target
        if(node->val==target->val) {
            return vector<int>(1, target->val);
        }

        // recursive case
        vector<int> result = get_ancestor(node->left, target);
        if(result.size()==0) result = get_ancestor(node->right, target);
        // if target not found from both subtrees
        if(result.size()==0) return vector<int>();

        // if found, insert this node
        result.insert(result.begin(), node->val);
        return result;
    }

    TreeNode* find_node(TreeNode* node, int target) {
        if(!node) return nullptr;
        if(node->val==target) return node;
        TreeNode* result;
        if(node->left) result = find_node(node->left, target);
        if(!result && node->right) result = find_node(node->right, target);
        return result;
    }
};


/*
// version 2 -> got help from another's answer
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case: no node
        if(!root) return nullptr;

        // base case: found target = even if the other one is beneath this node, this is the LCA
        if(root==p || root==q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // if left and right are both not null, this is the LCA
        if(left && right) return root;

        // if both are null, LCA is not in this subtree
        if(!left && !right) return nullptr;

        // if only one are not null, return that
        return left? left : right;
    }
};
*/
