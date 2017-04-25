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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        //return method1(root);
        return method2(root);
    }
    
    bool method2(TreeNode *root){
        return (DFS2(root) != -1);
    }
    
    int DFS2(TreeNode *root){
        if (root == NULL) return 0;
        
        int depth_l = DFS2(root->left);
        if (depth_l == -1) return -1;
        int depth_r = DFS2(root->right);
        if (depth_r == -1) return -1;
        
        if (abs(depth_l - depth_r) > 1)  return -1;
        return max(depth_l, depth_r) + 1;      
    }
    
    bool method1(TreeNode *root){
        if (!root) return true;
        int depth_l, depth_r;
        depth_l = DFS(root->left);
        depth_r = DFS(root->right);
        if (abs(depth_l-depth_r)<=1) return method1(root->left)&method1(root->right);
        else return false;
    }
    
    int DFS(TreeNode *root){
        if (root==NULL) return 0;
        int depth, depth_left, depth_right;
        depth_left = DFS(root->left);
        depth_right = DFS(root->right);
        if (depth_left<depth_right) depth=depth_right;
        else depth=depth_left;
        
        return depth+1;
    }
};