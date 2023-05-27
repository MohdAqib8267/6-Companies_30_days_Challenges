class Solution {
public:
    int solve(int i,vector<int>& stoneValue, int n,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take1=stoneValue[i]-solve(i+1,stoneValue,n,dp);
        int take2=INT_MIN;
        if(i+1<n){
            take2=stoneValue[i]+stoneValue[i+1]-solve(i+2,stoneValue,n,dp);
        }
        int take3=INT_MIN;
        if(i+2<n){
            take3=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(i+3,stoneValue,n,dp);
            
        }
        return dp[i]=max({take1,take2,take3});
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n+1,-1);
        int aliceVal = solve(0,stoneValue,n,dp);
        cout<<aliceVal;
        if(aliceVal>0){
            return "Alice";
        }
        else if(aliceVal==0){
            return "Tie";
        }
        return "Bob";
    }
};