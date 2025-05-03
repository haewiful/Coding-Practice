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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;
        seq1 = leaf_value_seq(root1, seq1);
        seq2 = leaf_value_seq(root2, seq2);
        if(seq1.size()!=seq2.size()) return false;
        for(int i=0; i<seq1.size(); i++) {
            if(seq1[i]!=seq2[i]) return false;
        }
        return true;
    }
    vector<int> leaf_value_seq(TreeNode* root, vector<int> seq) {
        // base case: root is nullptr
        if(root==nullptr) return seq;
        // base case: is leaf
        if(root->left==nullptr && root->right==nullptr) {
            seq.push_back(root->val);
            return seq;
        }
        // recursive case
        seq = leaf_value_seq(root->left, seq);
        seq = leaf_value_seq(root->right, seq);
        return seq;
    }
};
