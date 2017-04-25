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
    int countNodes(TreeNode* root) {
        if (root==nullptr) return 0;
        int left_height=0, right_height=0;
        TreeNode *cur = root;
        while(cur!=nullptr){
            left_height++;
            cur = cur->left;
        }
        cur = root;
        while(cur!=nullptr){
            right_height++;
            cur = cur->right;
        }
        if (left_height==right_height) return pow(2,left_height)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};