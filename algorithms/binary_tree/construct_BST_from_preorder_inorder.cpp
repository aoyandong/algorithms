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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int ps, int pe, int is, int ie){
        if (ps>pe) return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
        int sep;
        for (int i=is; i<=ie; i++){
            if (inorder[i]==root->val){
                sep = i;
                break;
            }
        }
        root->left = helper(preorder,inorder,ps+1,ps+sep-is, is, sep-1);
        root->right = helper(preorder, inorder,ps+sep-is+1,pe, sep+1, ie);
        return root;
    }
};