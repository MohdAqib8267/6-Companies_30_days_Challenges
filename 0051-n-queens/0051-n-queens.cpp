class Solution {
public:
    bool isSafe(int i,int j,vector<vector<int>>&grid,int n){
        int x=i;
        int y=j;
        //row left
        while(y>=0){
            if(grid[x][y]==1){
                return false;
            }
            y--;
        }
        //row right--> (not required)
        
        //up-left diagonal
        x=i, y=j;
        while(x>=0 and y>=0){
            if(grid[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        //down left diagonal
        x=i, y=j;
        while(x<n and y>=0){
            if(grid[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        //col down
        x=i,y=j;
        while(x<n){
            if(grid[x][y]==1){
                return false;
            }
            x++;
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
    void solve(int col,vector<vector<int>>&grid,vector<vector<string>>&ans,int n){
        if(col==n){
            addans(grid,ans,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,grid,n)){
                grid[row][col]=1;
                solve(col+1,grid,ans,n);
                grid[row][col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>grid(n,vector<int>(n,0));
        vector<vector<string>>ans;
        solve(0,grid,ans,n);
        return ans;
    }
};