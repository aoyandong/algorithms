/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if (!head) return head;
        RandomListNode *l1, *l2, *rhead;
        for (l1=head; l1!=NULL; l1=l1->next->next){
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
        }
        
        for (l1=head; l1!=NULL; l1=l1->next->next){
            if (l1->random!=NULL){
                l1->next->random = l1->random->next;
            }
        }
        
        rhead = head->next;
        for (l1=head; l1!=NULL; l1=l1->next){
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next!=NULL) l2->next = l1->next->next;
        }
        return rhead;
    }
};