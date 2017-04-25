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
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
/*        // Priority queue answer. O(knlog(k)) time, O(k) space
        priority_queue<ListNode*, vector<ListNode*>, compare> Q;
        for (int i=0; i<lists.size(); i++){
            if (lists[i]!=NULL) Q.push(lists[i]);
        }
        ListNode *head = new ListNode(0);
        ListNode *cur, *tmp;
        cur = head;
        while (!Q.empty()){
            tmp = Q.top();
            Q.pop();
            cur->next = tmp;
            cur = cur->next;
            if (tmp->next!=NULL) Q.push(tmp->next);
        }
        return head->next;
*/
        //Divide and Conquer answer. O(knlog(k)) time, O(1) sapce
        int n = lists.size();
        if (n==0) return NULL;
        while (n>1){
            for (int i=0; i<n/2; i++){
                if (i==(n-i-1)) continue;
                lists[i] = merge2Lists(lists[i], lists[n-i-1]);
            }
            n = (n+1)/2;
        }
        return lists[0];
    }
private:
    ListNode *merge2Lists(ListNode *p1, ListNode *p2){
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (p1!=NULL && p2!=NULL){
            if (p1->val < p2->val){
                cur->next = p1;
                p1 = p1->next;
            }
            else{
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        if (p1!=NULL) cur->next = p1;
        else cur->next = p2;
        return head->next;
    }

};



