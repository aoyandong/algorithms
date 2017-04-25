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
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> inorder = inorder_traversal(root);
        vector<int> result;
        for (int i=0; i<inorder.size(); i++){
            if (inorder[i]>=k1 && inorder[i]<=k2) result.push_back(inorder[i]);
        }
        return result;
    }
    
    vector<int> inorder_traversal(TreeNode *root){
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> Q;
        TreeNode *tmp = root;
        while (tmp!=NULL || !Q.empty()){
            if (tmp!=NULL){
                Q.push(tmp);
                tmp = tmp->left;
            }
            else{
                tmp = Q.top();
                Q.pop();
                result.push_back(tmp->val);
                tmp = tmp->right;
            }
        }
        return result;
    }
};