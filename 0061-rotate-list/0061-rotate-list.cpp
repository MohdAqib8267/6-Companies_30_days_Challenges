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
    ListNode* rotateRight(ListNode* head, int k) {
       if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        int len=1;
        ListNode* temp=head;
    
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        temp->next=head;
        //resize k
        k=k%len;
        int size=len-k;  //let suppose len=5 and k=2 then humey last ke 2 element aage dalne honge to uske liye peechey ke 3 elements k last element per phuchna hoga
        while(size--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};