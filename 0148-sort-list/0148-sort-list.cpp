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
    ListNode* findMid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* merge(ListNode* head1,ListNode* head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    ListNode* temp1=head1;
    ListNode* temp2=head2;
    ListNode* dummy=new ListNode(-1);
    ListNode* temp=dummy;
    while(temp1!=NULL and temp2!=NULL){
        if(temp1->val<=temp2->val){
            temp->next=temp1;
            temp=temp->next;
            temp1=temp1->next;
        }
        else{
             temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        temp->next=temp1;
         temp=temp->next;
            temp1=temp1->next;
    }
    while(temp2!=NULL){
         temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
    }
    return dummy->next;
}
    ListNode* sortList(ListNode* head) {
       if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* mid=findMid(head);
    ListNode* left=head;
    ListNode* right=mid->next;
    mid->next=NULL;

    left=sortList(left);
    right=sortList(right);

    ListNode* result = merge(left,right);
    return result;
    }
};