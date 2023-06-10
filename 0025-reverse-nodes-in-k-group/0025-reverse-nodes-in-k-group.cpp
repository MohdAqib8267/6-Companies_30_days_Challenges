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
    int length(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int len=length(head);
        if(len<k) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextptr;
        int cnt=0;
        while(curr!=NULL and cnt<k){
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
            cnt++;
        }
        
        if(nextptr!=NULL){
            head->next=reverseKGroup(nextptr,k);
        }
        return prev;
        
    }
};