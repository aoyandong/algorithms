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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(root, sum, res, cur);
        return res;
    }

private:
    void helper(TreeNode* root, int sum, vector<vector<int>> &res, vector<int> &cur){
        if (root==nullptr) return;
        if (root->left==nullptr && root->right==nullptr && root->val==sum){
            cur.push_back(root->val);
            res.push_back(cur);
            cur.pop_back();
            return;
        }
        cur.push_back(root->val);
        helper(root->left, sum-root->val, res, cur);
        helper(root->right, sum-root->val, res, cur);
        cur.pop_back();
    }
};