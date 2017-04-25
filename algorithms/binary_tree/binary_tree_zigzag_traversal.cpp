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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // write your code here
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        vector<vector<int> > res;
        vector<int> res_one;
        
        if (!root) return res;
        s1.push(root);
        TreeNode *cur;
        int zigzag = 1;
        while (!s1.empty() || !s2.empty()){
            if (zigzag==1) {
                while (!s1.empty()){
                    cur = s1.top();
                    s1.pop();
                    res_one.push_back(cur->val);
                    if (cur->left) s2.push(cur->left);
                    if (cur->right) s2.push(cur->right);
                }
                res.push_back(res_one);
                res_one.clear();
                zigzag = 0;
            }
            else{
                while (!s2.empty()){
                    cur = s2.top();
                    s2.pop();
                    res_one.push_back(cur->val);
                    if (cur->right) s1.push(cur->right);
                    if (cur->left) s1.push(cur->left);
                }
                res.push_back(res_one);
                res_one.clear();
                zigzag = 1;
            }
        }
        return res;
    }
};
