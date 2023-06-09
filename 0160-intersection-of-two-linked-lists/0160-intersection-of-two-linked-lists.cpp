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
    int length(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* head1=headA;
        ListNode* head2=headB;
        int len1=length(headA);
        int len2=length(headB);
        if(len1<len2){
            int diff=len2-len1;
            while(diff--){
                head2=head2->next;
            }
        }
        else{
            int diff=len1-len2;
             while(diff--){
                head1=head1->next;
            }
        }
        while(head1!=NULL and head2!=NULL){
            if(head1==head2){
                return head1;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return NULL;
    }
};