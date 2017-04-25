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
    int rob(TreeNode* root) {
        int left=0, right=0;
        int res = rob_helper(root, left, right);
        return res;
    }
    
private:
    int rob_helper(TreeNode *root, int &left, int &right){
        if (root==NULL) return 0;
        
        int l_left=0, l_right=0, r_left=0, r_right=0;
        left = rob_helper(root->left, l_left, l_right);
        right = rob_helper(root->right, r_left, r_right);
        
        return max(left+right, l_left+l_right+r_left+r_right+root->val);
    }
};
