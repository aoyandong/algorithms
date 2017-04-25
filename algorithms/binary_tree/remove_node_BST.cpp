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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if (root==NULL)  return NULL;
        
        TreeNode *node;
        if (value<root->val) root->left = removeNode(root->left, value);
        else if (value>root->val) root->right = removeNode(root->right, value);
        else{
            if (root->left == NULL) {
                node = root->right;
                delete root;
                return node;
            }
            if (root->right == NULL){
                node = root->left;
                delete root;
                return node;
            }
            
            TreeNode* minNode = findminNode(root->right);
            root->val = minNode->val;
            root->right = removeNode(root->right, minNode->val);
        }
        return root;
    }

private :
    TreeNode* findminNode(TreeNode *root){
        TreeNode* cur=root;
        while (cur->left!=NULL){
            cur = cur->left;
        }
        return cur;
    }
};