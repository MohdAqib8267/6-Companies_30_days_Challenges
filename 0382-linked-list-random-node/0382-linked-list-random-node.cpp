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
    int cnt=0;
    ListNode* h;
    vector<int>arr;
    Solution(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            arr.push_back(temp->val);
            temp=temp->next;
        }
        h=head;
    }
    
    int getRandom() {
        int r=rand();
        return arr[r%cnt];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */