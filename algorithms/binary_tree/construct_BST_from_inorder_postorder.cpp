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
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if (postorder.size()==0) return NULL;
        TreeNode *root = helper(inorder, postorder, 0, postorder.size()-1, postorder.size()-1);
        return root;
    }
    
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int left, int right, int root_loc){
        TreeNode *root = new TreeNode(postorder[root_loc]);
        if (left==right) return root;
        int i;
        for (i=left; i<=right; i++){
            if (inorder[i]==postorder[root_loc]) break;
        }
        if (i!=right) root->right = helper(inorder, postorder, (i+1), right, root_loc-1);
        if (i!=left) root->left = helper(inorder, postorder, left, (i-1), root_loc-(right-i)-1);
        
        return root;
    }
};