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
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        int res=INT_MIN;
        max_branch(root,res);
        return res;
    }

private:
    int max_branch(TreeNode *root, int &res){
        if (root==NULL) return 0;
        int left = max_branch(root->left, res);
        int right = max_branch(root->right, res);
        
        if (left<0) left = 0;
        if (right<0) right = 0;
        res = max(res, left+right+root->val);
        
        return max(left+root->val, right+root->val);
    }
};
