class Solution {
public:
    //[1,4,9]
    int solve(int i,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(i>=arr.size() or sum<0){
            return 10000;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(sum==0){
            return 0;
        }
        //include
        int inc=1+solve(i,sum-arr[i],arr,dp);
        int exc=solve(i+1,sum,arr,dp);
        return dp[i][sum]=min(inc,exc);
    }
    int numSquares(int n) {
        vector<int>arr;
        for(int i=1;i*i<=n;i++){
            arr.push_back(i*i);
        }
        vector<vector<int>>dp(arr.size()+1,vector<int>(n+1,-1));
        return solve(0,n,arr,dp);
        
    }
};