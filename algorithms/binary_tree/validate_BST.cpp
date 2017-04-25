/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        TreeNode *pre=NULL;
        return validate(root,pre);
    }
    
    bool validate(TreeNode *root, TreeNode *&pre){
        if (root==NULL) return true;
        if (!validate(root->left,pre)) return false;
        if (pre!=NULL && root->val<=pre->val) return false;
        pre = root;
        return validate(root->right,pre);
    }
};