/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        ListNode *cur=head,*pos=head;
        if (!head) return NULL;
        for(int i=0; i<k; i++){
            pos = pos->next;
            if (!pos && i<k) pos=head;
        }
        while (true){
            if (pos->next){
                pos = pos->next;
                cur = cur->next;
            }
            else{
                pos->next = head;
                head = cur->next;
                cur->next = NULL;
                break;
            }
        }
        return head;
    }
};