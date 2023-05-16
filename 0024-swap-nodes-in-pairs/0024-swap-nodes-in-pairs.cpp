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
    ListNode* swapping(ListNode* &head,int k){
           ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next;
      
        int count=0;
        while(curr!=NULL and count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next!=NULL){
            head->next=swapping(next,k);
        }
        return prev;
    }
    
    
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        return swapping(head,2);
     
    }
};