class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>pq(nums.begin(),nums.end());
        while(!pq.empty() and k!=1){
            pq.pop();
            k--;
        }
        return pq.top();
        
    }
};