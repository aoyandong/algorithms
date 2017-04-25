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
    int minDepth(TreeNode *root) {
        // write your code here
        if (!root) return 0;
        queue<TreeNode *> Q;
        Q.push(root);
        int level=0;
        TreeNode *cur;
        int n;
        while (!Q.empty()){
            level++;
            n = Q.size();
            for (int i=0; i<n; i++){
                cur = Q.front();
                Q.pop();
                if (cur->left!=NULL) Q.push(cur->left);
                if (cur->right!=NULL) Q.push(cur->right);
                if (cur->left==NULL && cur->right==NULL) return level;
            }
        }
        return level;
    }
};
