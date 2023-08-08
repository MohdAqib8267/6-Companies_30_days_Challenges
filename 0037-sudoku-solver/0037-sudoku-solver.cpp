class Solution {
public:
    bool isSafe(int row,int col,char val,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            //check row
            if(board[row][i]==val){
                return false;
            }
            //check col
            if(board[i][col]==val){
                return false;
            }
            //check grid
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int val=1;val<=9;val++){
                        if(isSafe(i,j,val+'0',board)){
                            board[i][j]=val+'0';
                            bool nextPossibleSol=solve(board);
                            if(nextPossibleSol){
                                return true;
                            }else{
                                //backtrack
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};