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
    bool isPalindrome(ListNode* head) {
        if (head==nullptr) return true;
        ListNode *mid=head, *runner=head, *tmp1, *tmp2, *cur;
        while (runner->next!=NULL && runner->next->next!=NULL){
            mid=mid->next;
            runner=runner->next->next;
        }
        cur = mid->next;
        tmp1 = mid;
        mid->next = NULL;
        while (cur!=NULL){
            tmp2 = cur->next;
            cur->next = tmp1;
            tmp1 = cur;
            cur = tmp2;
        }
        tmp2 = head;
        while (tmp1!=tmp2 && tmp2!=NULL){
            if (tmp1->val!=tmp2->val) return false;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return true;
    }
};
