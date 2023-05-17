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
   int sum = 0;
    void fun(ListNode*& a, ListNode* b){
        if(!b) return;
        fun(a,b->next);
        sum = max(sum, a->val + b->val);
        a = a->next;
    }
    int pairSum(ListNode* head) {
        ListNode *a = head;
        fun(a, head);
        return sum;        
    }
};