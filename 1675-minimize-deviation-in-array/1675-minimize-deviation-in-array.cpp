class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        //maxheap
        priority_queue<int,vector<int>>pq;
        //keep track min element
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]%2 == 1){
                nums[i]=2*nums[i];
            }
            pq.push(nums[i]);
            mini = min(mini,nums[i]);
        }
        int ans=INT_MAX;
        while(pq.top()%2==0){
            int t=pq.top();
            pq.pop();
            ans = min(ans,t-mini);
            pq.push(t/2);
            mini=min(mini,t/2);
        }
        ans=min(ans,pq.top()-mini);
        return ans;
    }
};