class Solution {
public:
    int solve(int i,vector<int>& nums,int n, vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int sum=nums[i];
        int idx=i+1;
        //add into same element in sum 
        while(idx<n and nums[idx]==nums[i]){
            sum+=nums[idx];
            idx++;
        }
        //delete nums[i]+1 elements, we have been sort the element that's why dont need to delete nums[i]-1 elements
        while(idx<n and nums[idx]-nums[i]==1){
            idx++;
        }
        //include
        int include = sum+solve(idx,nums,n,dp);
        int exclude = solve(i+1,nums,n,dp);
        return dp[i] = max(include,exclude);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        // vector<int>dp(n+1,-1);
        // return solve(0,nums,n,dp);
        
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