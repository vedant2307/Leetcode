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
    ListNode *detectCycle(ListNode *head) {
        ListNode *prev=head,*curr=head;
        while(curr && curr->next){
            curr=curr->next->next; prev=prev->next;
            if(prev==curr) break;
        }
        if(!curr || (curr && !curr->next))  return NULL;
        prev=head;
        while(prev!=curr){
            prev=prev->next; curr=curr->next;
        }
        return prev;
    }
};