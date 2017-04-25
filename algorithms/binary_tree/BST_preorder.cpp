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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> Q;
        TreeNode *tmp;
        Q.push(root);
        while (!Q.empty()){
            tmp = Q.top();
            Q.pop();
            result.push_back(tmp->val);
            if (tmp->right!=NULL) Q.push(tmp->right);
            if (tmp->left!=NULL) Q.push(tmp->left);
        }
        return result;
    }
};
