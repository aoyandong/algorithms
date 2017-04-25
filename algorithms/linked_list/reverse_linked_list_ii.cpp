/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre=dummy;
        for (int i=1; i<m; i++) pre = pre->next;

        ListNode *cur = pre->next;
        for (int i=0; i<n-m; i++){
            ListNode *tmp1 = cur->next;
            cur->next = tmp1->next;
            tmp1->next = pre->next;
            pre->next = tmp1;
        }
        return dummy->next;
    }
};
