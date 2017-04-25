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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // write your code here
/*		// only 1 queue.
        queue<TreeNode*> Q;
        vector<vector<int> > result;
        vector<int> tmp;
        if (!root) return result;
        
        int n;
        Q.push(root);
        TreeNode *cur;
        while (!Q.empty()){
            n = Q.size();
            tmp.clear();
            for (int i=0; i<n; i++){
                cur = Q.front();
                Q.pop();
                tmp.push_back(cur->val);
                if (cur->left!=NULL) Q.push(cur->left);
                if (cur->right!=NULL) Q.push(cur->right);
            }
            result.push_back(tmp);
        }
        return result;
*/
		//DFS
        stack<TreeNode*> Q;
        stack<int> levels;
        vector<vector<int> > result;
        int level;
        TreeNode* cur;
        if (!root) return result;
        
        Q.push(root);
        levels.push(0);
        while (!Q.empty()){
            cur = Q.top();
            Q.pop();
            level = levels.top();
            levels.pop();
            if (result.size()<=level) result.resize(level+1);
            result[level].push_back(cur->val);
            
            if (cur->right!=NULL) {Q.push(cur->right); levels.push(level+1);}
            if (cur->left!=NULL) {Q.push(cur->left); levels.push(level+1);}
        }
        return result;
    }
};
