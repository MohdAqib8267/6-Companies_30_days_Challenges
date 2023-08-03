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
  
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int len = 0,pos;
        ListNode *node = head,*prev = NULL;
        while(node!=NULL){
            len++;
            node = node->next;
        }
        pos = len-n;
        node = head;
        
        if(pos==0){
            return head->next;
        }
        int cnt=0;
        node=head;
        while(cnt!=pos-1){
            node=node->next;
            cnt++;
        }
        node->next=node->next->next;
        return head;
        
        
        
        
    }
};