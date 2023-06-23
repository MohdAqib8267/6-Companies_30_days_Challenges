class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2001,1));
        int mx=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = (nums[i]-nums[j])+500;
                dp[i][diff] = (2,1+dp[j][diff]);
                mx=max(mx,dp[i][diff]);
            }
        }
        return mx;
    }
};