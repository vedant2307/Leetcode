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
    ListNode* reverse(ListNode* head){
        ListNode *x=NULL,*y=head,*z=head;
        while(z){
            z=z->next; y->next=x; x=y; y=z;
        }
        return x;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* head=new ListNode();
        ListNode* temp=head; 
        int carry=0;
        while(l1 || l2 || carry){
            int sum=0;
            if(l1){
                sum+=(l1->val); l1=l1->next;
            }
            if(l2){
                sum+=(l2->val); l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode *curr=new ListNode(sum%10);
            temp->next=curr;
            temp=temp->next;
        }
        head=head->next;
        head=reverse(head);
        return head;
    }
};