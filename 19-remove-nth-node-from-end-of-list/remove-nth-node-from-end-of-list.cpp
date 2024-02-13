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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *slow=dummy,*fast=head;
        while(fast && n--) fast=fast->next; 
        while(fast) slow=slow->next,fast=fast->next;
        if(slow==dummy) return head->next;
        if(slow->next->next){
            ListNode* temp = slow->next;
            slow->next=temp->next;
            temp->next=NULL;
        }
        else slow->next=NULL;
        return head;
    }
};