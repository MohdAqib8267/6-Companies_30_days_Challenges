class Solution {
public:

    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        //base case 
        if(grid[i][j]==-1&&j==0){
            return -1;
        }
        if(grid[i][j]==1&&j==(grid[0].size()-1)){
            return -1;
        }
        //"v" condition base cases
        if(grid[i][j]==1&&grid[i][j+1]==-1){
            return -1;
        }
        if(grid[i][j]==-1&&grid[i][j-1]==1){
            return -1;
        }
        //if ball has reached last row
        if(i==grid.size()-1){
            if(grid[i][j]==1){
                return j+1;
            }
            return j-1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //two possibilities
        if(grid[i][j]==1){
            return dp[i][j]=f(i+1,j+1,grid,dp);
        }
        return dp[i][j]=f(i+1,j-1,grid,dp);
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m+1,-1));
        //calling recursion for every cell of 0th row
        for(int k=0;k<grid[0].size();k++){
            int x=f(0,k,grid,dp);
            ans.push_back(x);
        }
        return ans;
    }
};
