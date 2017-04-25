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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class BSTIterator {
private:
    stack<TreeNode *> S;
    void pushleft(TreeNode *root){
        TreeNode *cur;
        for (cur=root; cur!=NULL; cur=cur->left) S.push(cur);
    }

public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        // write your code here
        pushleft(root);
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        if (!S.empty()) return true;
        else return false;
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode *cur = S.top();
        S.pop();
        pushleft(cur->right);
        return cur;
    }
};
