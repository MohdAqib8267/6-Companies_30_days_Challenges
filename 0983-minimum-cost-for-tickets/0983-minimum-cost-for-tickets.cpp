class Solution {
public:
    int solve(vector<int>& days,vector<int>& costs,int index,vector<int>& dp){
        if(index>=days.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        //1 day ticket
        int option1 = costs[0]+solve(days,costs,index+1,dp);
        
        //7 day ticket
        int i;
        for( i=index; i<days.size() && days[i]<days[index]+7;i++ );
        
        int option2 = costs[1]+solve(days,costs,i,dp);
        
        //30 day ticket
        for(i=index; i<days.size() && days[i]<days[index]+30;i++);
        
        int option3 = costs[2]+solve(days,costs,i,dp);
        
        return dp[index]=min({option1,option2,option3});
        
    }
    
    //Tabulation (bottom-up)
    int solve(vector<int>& days,vector<int>& costs){
       vector<int>dp(days.size()+1,INT_MAX);
        dp[days.size()]=0;
        for(int k=days.size()-1;k>=0;k--){
              //1 day ticket
            int option1 = costs[0]+dp[k+1];
        
            //7 day ticket
            int i;
            for( i=k; i<days.size() && days[i]<days[k]+7;i++ );
        
            int option2 = costs[1]+dp[i];
        
            //30 day ticket
            for(i=k; i<days.size() && days[i]<days[k]+30;i++);
        
            int option3 = costs[2]+dp[i];
        
            dp[k]=min({option1,option2,option3});
        }
        
        return dp[0];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        // return solve(days,costs,0,dp);
        //tabu
        return solve(days,costs);
    }
};