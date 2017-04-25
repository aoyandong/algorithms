/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr) return true;
        return helper(root->left, root->right);
    }
private:
    bool helper(TreeNode *l, TreeNode *r){
        if (l==nullptr && r==nullptr) return true;
        if (l==nullptr || r==nullptr) return false;
        if (l->val!=r->val) return false;
        return helper(l->left, r->right) && helper(l->right, r->left);
    }
};

