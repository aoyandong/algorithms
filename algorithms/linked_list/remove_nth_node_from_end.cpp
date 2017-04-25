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
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode *cur=head, *end=head;
        for (int i=0; i<n; i++){
            end = end->next;
        }
        if (end==NULL) return head->next;
        while (true){
            end = end->next;
            if (end==NULL){
                cur->next = cur->next->next;
                break;
            }
            cur = cur->next;
        }
        return head;
    }
};


