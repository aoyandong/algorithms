/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        return sortedListToBST(head, NULL);
    }
    
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
        if (head==tail) return NULL;
        
        ListNode *walker=head, *runner=head;
        while (runner->next!=tail && runner->next->next!=tail){
            walker = walker->next;
            runner = runner->next->next;
        }
        
        TreeNode *root = new TreeNode(walker->val);
        root->left = sortedListToBST(head, walker);
        root->right = sortedListToBST(walker->next, tail);
        
        return root;
    }
};


