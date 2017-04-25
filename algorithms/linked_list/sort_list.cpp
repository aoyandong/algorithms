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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
		//Using mergesort, quicksort will be in next round.
        if (head==NULL || head->next==NULL) return head;
        ListNode *head2, *walker=head, *runner=head;
        
        while(runner->next!=NULL && runner->next->next !=NULL){
            walker = walker->next;
            runner = runner->next->next;
        }
        
        head2 = walker->next;
        walker->next = NULL;
        
        head = sortList(head);
        head2 = sortList(head2);
        return merge(head,head2);
    }
    
    ListNode *merge(ListNode *h1, ListNode *h2){
        ListNode *cur1=h1, *cur2=h2;
        ListNode *new_head = new ListNode;
        ListNode *cur = new_head;
        while (cur1!=NULL && cur2!=NULL){
            if (cur1->val<cur2->val){
                cur->next = cur1;
                cur1 = cur1->next;
            }
            else{
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        if (cur1) cur->next = cur1;
        else cur->next = cur2;
        cur = new_head->next;
        delete new_head;
        return cur;
    }
};


