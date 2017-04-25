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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode *cur=head, *big, *small, *small_head, *big_head;
        if (!head) return NULL;
        small = new ListNode(0);
        big = new ListNode(0);
        small_head=small;
        big_head=big;
        
        while (cur){
            if (cur->val<x){
                small->next = cur;
                small = small->next;
                cur = cur->next;
            }
            else{
                big->next = cur;
                big = big->next;
                cur = cur->next;
                big->next = NULL;
            } 
        }
        small->next = big_head->next;
        return small_head->next;
    }
};


