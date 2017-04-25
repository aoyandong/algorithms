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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if (head==NULL || head->next==NULL) return NULL;
        ListNode *walker=head, *runner=head, *entry=head;
        while (runner->next!=NULL && runner->next->next!=NULL){
            walker = walker->next;
            runner = runner->next->next;
            if (walker==runner){
                while (entry!=walker){
                    entry = entry->next;
                    walker = walker->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};

