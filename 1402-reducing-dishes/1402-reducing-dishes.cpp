class Solution {
public:
    int solve(int i,vector<int>& sat,int cnt,vector<vector<int>>& dp){
        if(i>=sat.size()){
            return 0;
        }
        if(dp[i][cnt]!=-1){
            return dp[i][cnt];
        }
        //take and not take
        int take = (sat[i]*cnt)+solve(i+1,sat,cnt+1,dp);
        int not_take = solve(i+1,sat,cnt,dp);
         
        return dp[i][cnt]=max(take,not_take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
          int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
      
        sort(satisfaction.begin(),satisfaction.end());
        return solve(0,satisfaction,1,dp);
        
    }
};