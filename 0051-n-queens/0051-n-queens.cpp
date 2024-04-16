class Solution {
public:
    bool isSafe(int row,int col,vector<vector<int>>&grid,int n){
        int x=row, y=col;
        //check in row
        while(y>=0){
            if(grid[x][y]==1){
                return false;
            }
            y--;
        }
        //check in col --> not required
        
        //check in up-left diagonal
         x=row, y=col;
        while(x>=0 && y>=0){
            if(grid[x][y]==1){
                return false;
            }
            x--; y--;
        }
        
        //check in down-left diagonal
         x=row, y=col;
        while(x<n && y>=0){
            if(grid[x][y]==1){
                return false;
            }
            x++; y--;
        }
        return true;
    }
    void addans(vector<vector<int>>&grid,vector<vector<string>>&ans,int n){
       vector<string>temp;
        for(int i=0;i<n;i++){
             string res;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    res.push_back('Q');
                }
                else{
                     res.push_back('.');
                }
               
            }
            temp.push_back(res);
        }
        ans.push_back(temp);
    }
    void solve(int col,int n,vector<vector<int>>&grid,vector<vector<string>>&ans){
        if(col>=n){
            addans(grid,ans,n);
            return;
        }
        for(int row=0;row<n;row++){
           if(isSafe(row,col,grid,n)){
               grid[row][col]=1;
               solve(col+1,n,grid,ans);  
               grid[row][col]=0;
           } 
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<int>>grid(n,vector<int>(n,0));
        solve(0,n,grid,ans);
        return ans;
    }
};