class Solution {
public:
    int solve(int i,int n,vector<int>& nums,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int sum=nums[i];
        int idx=i+1;
        while(idx<n and nums[i]==nums[idx]){
            sum+=nums[idx];
            idx++;
        }
        while(idx<n and nums[idx]-nums[i]==1){
            idx++;
        }
        int inc=sum+solve(idx,n,nums,dp);
        int exc=solve(i+1,n,nums,dp);
        return dp[i] = max(inc,exc);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // vector<int>dp(n+1,-1);
        // return solve(0,nums.size(),nums,dp);
        
        //bcz we have can multiple same element
        //Tabulation
        //bcz we have can multiple same element
        unordered_map<int,int>mp; //store freq of every element
        int maxel=INT_MIN; //find maximum element that to calculate where can earn
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxel=max(nums[i],maxel);
        }
        vector<int>dp(maxel+1,0);
        dp[1]=mp[1];
        for(int i=2;i<=maxel;i++){
            if(mp.find(i)!=mp.end()){
                //if i==4 then we will delete 3 can consider below 3
                dp[i]=max(i*mp[i]+dp[i-2],dp[i-1]);
            }
            else{
                //not take
                dp[i]=dp[i-1];
            }
        }
        return dp[maxel];
    }
};