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
    void flatten(TreeNode* root) {
        if (root==nullptr) return;
        if (root->left==nullptr && root->right==nullptr) return;
        else if (root->left!=nullptr && root->right!=nullptr){
            TreeNode* cur=root->left;
            while(cur->right!=nullptr) cur = cur->right;
            cur->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        else if (root->left!=nullptr){
            root->right = root->left;
            root->left = nullptr;
        }
        flatten(root->right);
    }
};
