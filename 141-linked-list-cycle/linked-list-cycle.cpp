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
    bool hasCycle(ListNode *head) {
        ListNode *prev=head,*curr=head;
        while(curr && curr->next){
            curr=curr->next;
            if(curr){
                curr=curr->next; prev=prev->next;
            }
            if(prev==curr) return true;
        }
        return false;
    }
};