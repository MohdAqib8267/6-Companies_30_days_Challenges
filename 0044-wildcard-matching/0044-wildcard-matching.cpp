class Solution {
public:
    bool solve(string &s, string &p,int i,int j,vector<vector<int>>&dp){
        if(i==0 and j==0){
            return true;
        }
        if(i>0 and j==0){
            return false;
        }
        if(i==0 and j>0){
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //match
        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            return dp[i][j]=solve(s,p,i-1,j-1,dp);
        }
        else if(p[j-1]=='*'){
            return dp[i][j]=(solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp));
        }
        else{
            return false;
        }
        
    }
    bool solveTab(string &s, string &p){
         int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        //1st base case
        dp[0][0]=true;
        //2nd base case
        //all rows and 1st col
        //set false--> it is already false, bcz dp initialize with 0
        
        //3rd base case
        //1st row and all columns
        for(int j=1;j<=p.size();j++){
            bool flag=true;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }
        
        //match
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                     dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else{
                  dp[i][j]= false;
                }
            }
        }
        return dp[n][m];
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        //solve memoization (n-->0 && m-->0)
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solve(s,p,n,m,dp);
        
        //solve using tabulation(0-->n && 0-->m)
        return solveTab(s, p);
    }
};