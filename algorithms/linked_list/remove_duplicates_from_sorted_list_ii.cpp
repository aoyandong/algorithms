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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if (!head) return head;
        
        ListNode *newhead = new ListNode();
        newhead->next = head;
        ListNode *p1=head, *p2=head->next, *cur=newhead, *tmp;
        while (p2!=NULL){
            if (p2->val==p1->val){
                while (p2!=NULL && p2->val==p1->val){
                    tmp = p2;
                    p2 = p2->next;
                    delete tmp;
                }
                cur->next = p2;
                delete p1;
                if (p2!=NULL){
                    p1 = p2;
                    p2 = p2->next;
                }
                else return newhead->next;
            }
            else{
                cur->next = p1;
                cur = cur->next;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return newhead->next;
    }
};
