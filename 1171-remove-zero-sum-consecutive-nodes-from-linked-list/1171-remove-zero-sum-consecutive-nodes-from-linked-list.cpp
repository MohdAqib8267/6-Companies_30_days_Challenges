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
   ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp=head;
        unordered_map<int,ListNode*>mp;
       ListNode* dummy = new ListNode(-1);
       dummy->next=head;
       mp[0]=dummy;
        int sum=0;
        while(temp!=NULL){
            sum=sum+temp->val;
            if(mp.find(sum)!=mp.end()){
                int p=sum;
                ListNode* n = mp[sum];
                ListNode* node = n->next;
                while(node != temp){
                    p=p+node->val;
                    mp.erase(p);
                    node=node->next;
                }
                n->next=temp->next;
            }
            else{
                mp[sum]=temp;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};