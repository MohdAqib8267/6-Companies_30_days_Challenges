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
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next_ptr;
        while(curr!=NULL){
            next_ptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_ptr;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // long long num1=0;
        // long long num2=0;
        // ListNode* temp1=l1;
        // while(temp1!=NULL){
        //     num1=num1*10+(temp1->val);
        //     temp1=temp1->next;
        // }
        //  ListNode* temp2=l2;
        // while(temp2!=NULL){
        //     num2=num2*10+(temp2->val);
        //     temp2=temp2->next;
        // }
        // long long res=num1+num2;
        // if(res==0){
        //     return new ListNode(0);
        // }
        // ListNode* dummy=new ListNode(-1);
        // ListNode* temp=dummy;
        // while(res>0){
        //     temp->next=new ListNode(res%10);
        //     res=res/10;
        //     temp=temp->next;
        // }
        // return reverse(dummy->next);
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry ){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
              if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
             sum += carry;
             carry = sum/10;
             ListNode *node = new ListNode(sum%10);
             temp->next = node;
             temp = temp->next;
        }
        return reverse(dummy->next);
        
    }
};