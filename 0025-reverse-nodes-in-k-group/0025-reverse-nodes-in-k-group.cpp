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
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        int len = length(head);
        if(len<k) return head;
        ListNode* prev=NULL, *curr=head,*nextptr;
        ListNode* temp=head;
        while(cnt<k && temp!=NULL){
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
            cnt++;
        }
        if(nextptr!=NULL){
            head->next = reverseKGroup(nextptr,k);
        }
        return prev;
    }
};