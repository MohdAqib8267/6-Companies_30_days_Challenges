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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* last = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=head;
        ListNode* l1=reverse(slow);
        while(l1!=NULL){
            if(fast->val != l1->val){
                return false;
            }
            fast=fast->next;
            l1=l1->next;
        }
        return true;
    }
};