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
        if(head==NULL){
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        temp=head;
        int x=len/2;
        if(len%2==0){
            while(x--){
                temp=temp->next;
            }
        }
        else{
           while(x--){
                temp=temp->next;
            }
            temp=temp->next;
        }
        temp=reverse(temp);
        while(head && temp)
        {
            if(head->val!=temp->val)
                return false;
            head=head->next;
            temp=temp->next;
        }
        return true;
    }
};