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
    int getVal(vector<int>v){
       int n=v.size();
        int i=n-1;
        int ans=0;
        while(i>=0){
            ans=ans+pow(2,(n-1)-i)*v[i];
            i--;
        }
        return ans;
        
    }
    int getDecimalValue(ListNode* head) {
        vector<int>v;
        ListNode* temp=head;
        while(temp!=NULL){
           v.push_back(temp->val);
            temp=temp->next;
        }
        
        return getVal(v);
    }
};