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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        ListNode *p1=head, *p2=head, *h2=NULL, *cur=NULL, *tmp;
        if (!head) return;
        
        while (p2->next && p2->next->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        p2 = p1->next;
        p1->next = NULL;

        cur = p2;
        while (cur){
            tmp = cur->next;
            cur->next = h2;
            h2 = cur;
            cur = tmp;
        }

        p1 = head;
        p2 = h2;
        while (p2){
            cur = p1->next;
            p1->next = p2;
            h2 = p2->next;
            p2->next = cur;
            p1 = cur;
            p2 = h2;
        }
    }
};


