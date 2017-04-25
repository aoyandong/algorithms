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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        ListNode *runner=head, *walker=head;
        if (!head) return false;
        while (runner->next && runner->next->next){
            walker = walker->next;
            runner = runner->next->next;
            if (walker==runner) return true;
        }
        return false;
    }
};


