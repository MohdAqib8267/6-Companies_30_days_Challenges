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
    struct cmp{
        bool operator()(ListNode* l1, ListNode* l2){
            return l1->val>l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(auto list:lists){
            if(list) {
                pq.push(list);
            }
        }
       ListNode* dummy = new ListNode(-1); // dummy node to get the head of merged lists
        ListNode* curr = dummy;
        
        while(!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            curr->next = temp;
            curr = curr->next;
            if(temp->next) {
                pq.push(temp->next);
            }
        }
        
        return dummy->next;
    }
};