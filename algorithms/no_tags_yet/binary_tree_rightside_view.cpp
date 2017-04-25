/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root==nullptr) return res;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()){
            int n = Q.size();
            TreeNode* cur;
            for (int i=0; i<n; i++){
                cur = Q.front();
                Q.pop();
                if (cur->left!=nullptr) Q.push(cur->left);
                if (cur->right!=nullptr) Q.push(cur->right);
            }
            res.push_back(cur->val);
        }
        return res;
    }
};
