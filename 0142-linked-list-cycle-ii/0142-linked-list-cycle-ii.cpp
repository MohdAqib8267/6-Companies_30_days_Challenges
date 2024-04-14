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
        ListNode* s=head;
        ListNode* f=head;
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        do{
            s=s->next;
            f=f->next->next;
            if(f==NULL || f->next==NULL){
                return NULL;
            }
        }while(s != f);
        if(s==head){
            return head;
        }
        s=head;
        while(s->next != f->next){
            s=s->next;
            f=f->next;
        }
        return s->next;
    }
};