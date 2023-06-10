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
    ListNode* merge(ListNode* head1,ListNode* head2){
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        if(head1==NULL and head2==NULL) return NULL;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* temp1=head1;
        ListNode* temp2=head2;
        while(temp1!=NULL and temp2!=NULL){
            if(temp1->val<=temp2->val){
                temp->next=temp1;
                temp=temp->next;
                temp1=temp1->next;
            }
            else{
                temp->next=temp2;
                temp=temp->next;
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
             temp->next=temp1;
                temp=temp->next;
                temp1=temp1->next;
        }
        while(temp2!=NULL){
             temp->next=temp2;
                temp=temp->next;
                temp2=temp2->next;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0){
            return NULL;
        }
        if(n==1){
            return lists[0];
        }
        
        int j=1;
        while(j<n){
            lists[0]=merge(lists[0],lists[j++]);
        }
        return lists[0];
    }
};