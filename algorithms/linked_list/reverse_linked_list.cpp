/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if (head==nullptr) return nullptr;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head;

        while (cur->next!=nullptr){
            ListNode *tmp1 = cur->next;
            cur->next = tmp1->next;
            tmp1->next = dummy->next;
            dummy->next = tmp1;
        }
        return dummy->next;
    }
};
