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
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        stack<TreeNode*> Q;
        TreeNode *tmp;
        tmp = root;
        while (tmp!=NULL){
            Q.push(tmp);
            tmp = tmp->left;
        }
        while (!Q.empty()){
            tmp = Q.top();
            Q.pop();
            result.push_back(tmp->val);
            if (tmp->right!=NULL){
                Q.push(tmp->right);
                tmp = tmp->right;
                while (tmp->left!=NULL){
                    Q.push(tmp->left);
                    tmp = tmp->left;
                }
            }
        }
        return result;
    }
};