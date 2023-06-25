class Solution {
public:
    int mod=1e9+7;
    int solve(vector<int>& locations,int start,int finish,int fuel,vector<vector<int>>&dp){
        int cnt=0;
        if(fuel<0)return 0;
        if(start==finish){
            cnt++;
        }
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        //try to go through every index
        for(int i=0;i<locations.size();i++){
           if(i!=start){
               cnt=cnt+solve(locations,i,finish,fuel-abs(locations[i]-locations[start]),dp);
               cnt=cnt%mod;
           }
        }
        return dp[start][fuel]=cnt%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>>dp(locations.size()+1,vector<int>(fuel+1,-1));
        return solve(locations,start,finish,fuel,dp);
    }
};