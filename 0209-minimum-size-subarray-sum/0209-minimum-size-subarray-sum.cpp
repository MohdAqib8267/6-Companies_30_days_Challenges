class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int j=0,i=0;
        int ans=INT_MAX;
        while(j<n){
            sum=sum+nums[j];
            if(sum<target){
                j++;
            }
            else if(sum>=target){
                while(sum>=target)
                {
                    ans=min(ans,j-i+1);
                    sum-=nums[i];
                    i++;
                    
                }
                j++;
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};