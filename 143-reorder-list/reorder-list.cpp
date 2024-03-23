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
    ListNode* middle(ListNode* head){
        ListNode *slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next; fast=fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode *x=NULL,*y=head,*z=head;
        while(z){
            z=z->next;
            y->next=x;
            x=y; y=z;
        }
        return x;
    }

    void printList(ListNode* head){
        while(head){
            cout<<head->val<<" "; head=head->next;
        }
        cout<<endl;
        return;
    }

    void reorderList(ListNode* head) {
        if(!head->next) return;
        ListNode* mid = middle(head);
        ListNode* l2=mid->next;
        mid->next=NULL; 
        l2 = reverse(l2);
        ListNode* l1=head;
        printList(l1); printList(l2);
        ListNode* tt=l2;
        while(tt){
            ListNode* temp=l1->next;
            l1->next=l2;
            l2=tt->next;
            tt->next=temp;
            l1=temp;
            tt=l2;
        }
        return;
    }
};