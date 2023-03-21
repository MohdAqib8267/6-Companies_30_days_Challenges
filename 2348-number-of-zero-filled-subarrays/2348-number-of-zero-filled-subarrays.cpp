class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                long long cnt=0;
                while(i<n and nums[i]==0){
                    cnt++;
                    i++;
                }
                ans=ans+(cnt*(cnt+1))/2;
            }
        }
        return ans;
    }
};