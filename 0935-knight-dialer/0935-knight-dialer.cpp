class Solution {
public:
    long mod=1e9+7;
    long dp[5001][4][3];  // [n][row][col]
     long solve(int n,int row,int col)
    {
        if(row<0 || col<0 ||row>=4 || col>=3 || (row==3 && col!=1)) return 0;
        if(n==1) return 1;// as 10 numbers when n=1
       if(dp[n][row][col]!=-1){
           return dp[n][row][col];
       }
        long take = solve(n-1,row-2,col-1)%mod +
        solve(n-1,row-2,col+1)%mod + solve(n-1,row-1,col-2)%mod + solve(n-1,row+1,col-2)%mod + 
        solve(n-1,row+1,col+2)%mod + solve(n-1,row-1,col+2)%mod + solve(n-1,row+2,col-1)%mod + 
        solve(n-1,row+2,col+1)%mod; //checking all the knight possibilities
        return dp[n][row][col]=take;
    }
    int knightDialer(int n) {
         long s=0;
        
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                s = (s+solve(n,i,j))%mod;//for each and every index of phone dialer as                                              4*3 grid
            }
        }
    
        return (int)s;
        
    }
};