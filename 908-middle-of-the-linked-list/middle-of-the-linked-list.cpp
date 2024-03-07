/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode* helper(ListNode* head){
        ListNode *prev=head,*curr=head;
        while(curr && curr->next){
            curr=curr->next;
            if(curr && curr->next) curr=curr->next;
            if(prev->next) prev=prev->next;
        }
        return prev;
    }
    ListNode* middleNode(ListNode* head) {
        return helper(head);
    }
};