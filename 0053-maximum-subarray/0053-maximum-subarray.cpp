class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        // int sum=0;
        // int maxi=INT_MIN;
        // for(int i=0;i<n;i++){
        //     sum=sum+nums[i];
        //     maxi=max(maxi,sum);
        //     if(sum<0){
        //         sum=0;
        //     }
        // }
        // return maxi;
        
        vector<int>dp(n+1,INT_MIN);
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+nums[i-1];
            dp[i]=max(dp[i-1],sum);
            if(sum<0){
                sum=0;
            }
        }
        return dp[n];
    }
};