/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//For KK: this is reservoir sampling for special case k=1
// https://en.wikipedia.org/wiki/Reservoir_sampling
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res;
        int count=1;
        ListNode *cur = head;
        while (cur!=NULL){
            int seed = rand()%count;
            if (seed==0) res = cur->val;
            count++;
            cur = cur->next;
        }
        return res;
    }
    
private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
