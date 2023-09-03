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
   //1. stack me bhar lo and traverse kro list per and stack k top element se compare krte jao
    
    //2nd half list reverse
      ListNode* reverse(ListNode*head)
    {
        if(!head)return head;
        ListNode*prev=NULL,*temp=head;
        while(temp)
        {
            ListNode* curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) 
    {
//         ListNode*temp=head;
//         int l=0;
//         while(temp)
//         {
//             l++;
//             temp=temp->next;
//         }
//         temp=head;        
//         int x=l/2;
//         if(l%2==0)
//         {            
//             while(x--){
//                  temp=temp->next;
//             }
           
//         }       
//         else
//         {           
//             while(x--){
//                  temp=temp->next;
//             }
               
//             temp=temp->next;
//         }
        
//         temp=reverse(temp);
        
//         while(head && temp)
//         {
//             if(head->val!=temp->val)
//                 return false;
//             head=head->next;
//             temp=temp->next;
//         }
//         return true;
        int l=0;
        ListNode*temp=head;
        while(temp)
        {
            l++;
            temp=temp->next;
         }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(l%2==0){
            temp=reverse(slow); 
        }else{
            slow=slow->next;
            temp=reverse(slow);
        }
        ListNode* curr=head;
        while(temp!=NULL){
            if(curr->val!=temp->val){
                return false;
            }
            temp=temp->next;
            curr=curr->next;
        }
        return true;
       
        
    }
};