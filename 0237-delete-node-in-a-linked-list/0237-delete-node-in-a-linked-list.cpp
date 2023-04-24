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
    void deleteNode(ListNode* node) {
        // ListNode* temp=node->next;
        // if(node->next==NULL){
        //     return;
        // }
        // swap(node->val,temp->val);
        // node->next=temp->next;
        ListNode* temp=node->next;
        if(temp==NULL){
            return;
        }
       
            node->val = temp->val;
            node->next=temp->next;
        
    }
};