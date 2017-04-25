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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string cur;
        helper(root, cur, res);
        return res;
    }
private:
    void helper(TreeNode* root, string &cur, vector<string> &res){
        if (root==nullptr) return;
        if (root->left==nullptr && root->right==nullptr){
            res.push_back(cur+to_string(root->val));
            return;
        }
        string tmp = to_string(root->val) + "->";
        cur = cur + tmp;
        helper(root->left, cur, res);
        helper(root->right, cur, res);
        cur.erase(cur.end()-tmp.length(), cur.end());
    }
};
