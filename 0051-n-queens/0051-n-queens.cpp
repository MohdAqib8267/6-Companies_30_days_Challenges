class Solution {
public:
   void addSol(vector<vector<string>>&ans,vector<vector<int>>&board,int n){
    vector<string> temp;
    for(int i=0;i<n;i++){
    string str="";
        for(int j=0;j<n;j++){
            if(board[i][j]==1){
                str.push_back('Q');
            }
            else{
                str.push_back('.');
            }
        }
        temp.push_back(str);
    }
    ans.push_back(temp);
}
    bool isSafe(int row,int col,vector<vector<int>>& board,int n){
        //check in row(we add queeen ----> in left to right direction)
        int x=row; int y=col;
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        // we check only in left up and left down daigonal bcz we add queen in board left to right
         x=row; y=col;
        while(x>=0 and y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        
          x=row;  y=col;
        while(x<n and y>=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(int col, vector<vector<int>>& board,vector<vector<string>>& ans,int n){
        if(col==n){
            addSol(ans,board,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                //put queen in box
                board[row][col]=1;
                solve(col+1,board,ans,n);
                //backtrack
                board[row][col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<string>>ans;
        solve(0,board,ans,n);
        return ans;
    }
};