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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
//For KK: I don't see anything new between I and II, so do the leetcode discussion. 

    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        queue<TreeNode *> Q;
        vector<vector<int> > res;
        stack<vector<int> >S;
        vector<int> res_one;
        
        if (!root) return res;
        Q.push(root);
        TreeNode *cur;
        while (!Q.empty()){
            int n = Q.size();
            for (int i=0; i<n; i++){
                cur = Q.front();
                Q.pop();
                res_one.push_back(cur->val);
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
            }
            S.push(res_one);
            res_one.clear();
        }
        
        while (!S.empty()){
            res_one = S.top();
            S.pop();
            res.push_back(res_one);
        }
        return res;
    }
};
