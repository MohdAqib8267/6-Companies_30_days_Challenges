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
    ListNode* deleteDuplicates(ListNode* head) {
//         if(head==NULL){
//             return NULL;
//         }
//         ListNode* temp1=head;
//         ListNode* temp2=head->next;
        
//         while(temp2!=NULL){
//             if(temp1->val == temp2->val){
//                 temp2=temp2->next;
//                 temp1->next=temp2;
//             }
//             else{
//                 temp1=temp2;
//             temp2=temp2->next;
//             }
            
//         }
//         return head;
        
        //recursive
        if(head==NULL or head->next == NULL){
            return head;
        }
        if(head->val == head->next->val){
            ListNode* temp = head->next;
            head->next = head->next->next;
            delete(temp);
            deleteDuplicates(head);
            
        }
        deleteDuplicates(head->next);
        return head;
    }
};