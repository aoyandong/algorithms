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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = p->val, b=q->val;
        if (a>b) swap(a,b);
        while (true){
            if (root->val>a && root->val>b) root = root->left;
            else if (root->val<a && root->val<b) root = root->right;
            else return root;
        }
    }
};