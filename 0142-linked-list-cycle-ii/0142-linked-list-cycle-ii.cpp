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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL or head->next==NULL){
            return NULL;
        }
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                break;
            }
        }
        
        if(fast==NULL or fast->next==NULL){
            return NULL;
        }
        if(slow==head){
            return head;
        }
        slow=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        return fast->next;
    }
};