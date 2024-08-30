class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        int i=0,j=0;
        vector<int>ans;
        while(j<n){
            while(!dq.empty() && nums[j]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ans.push_back(dq.front());
                if(!dq.empty() and nums[i]==dq.front()){
                    dq.pop_front();
                }
                j++;
            i++;
            }
            
        }
        return ans;
    }
};