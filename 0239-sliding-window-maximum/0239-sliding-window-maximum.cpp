class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        int n=nums.size();
        int i=0;
        int j=0;
        vector<int>ans;
        deque<int>dq;
        while(j<n){
            while(!dq.empty() and nums[j]>dq.back()){
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
                i++;
                j++;
            }
          
        }
        return ans;
    }
};