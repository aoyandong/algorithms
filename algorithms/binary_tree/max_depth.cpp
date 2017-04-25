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
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root==NULL) return 0;
        //return BFS(root);
        return DFS(root);
    }
    
    int BFS(TreeNode *root){
        queue<TreeNode *> Q;
        int depth=0;
        Q.push(root);
        while (!Q.empty()){
            depth++;
            for (int i=0, n=Q.size(); i<n; i++){
                TreeNode *tmp = Q.front();
                Q.pop();
                if (tmp->left!=NULL) Q.push(tmp->left);
                if (tmp->right!=NULL) Q.push(tmp->right);
            }
        }
        return depth;
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