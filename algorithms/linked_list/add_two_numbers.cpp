/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//For KK: you might want to try O(1) space algorithm, which is much longer...
class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        int sum=0;
        ListNode *head = new ListNode();
        ListNode *cur = head;
        
        while (l1!=NULL || l2!=NULL){
            sum/=10;
            if (l1!=NULL){
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if (l2!=NULL){
                sum = sum + l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(sum%10);
            cur = cur->next;
        }
        
        if (sum>=10) cur->next = new ListNode(1);
        return head->next;
    }
};
