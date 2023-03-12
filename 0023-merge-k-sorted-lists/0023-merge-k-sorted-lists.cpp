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
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        if(head1==NULL and head2==NULL){
            return NULL;
        }
       ListNode* result=NULL;
        if(head1->val<=head2->val){
            result=head1;
            result->next=merge(head1->next,head2);
        }
        else{
            result=head2;
            result->next=merge(head1,head2->next);
        }
        return result;
       
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       int n= lists.size();
         if(n==0){
         return NULL; 
      }
        int last=n-1;
        while(last!=0){
            int i=0;int j=last;
            while(i<j){
                lists[i]=merge(lists[i],lists[j]);
                i++;
                j--;
                if(i>=j){
                    last=j;
                }
            }
        }
        return lists[0];
    }
};