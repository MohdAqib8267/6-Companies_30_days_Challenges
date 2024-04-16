class Solution {
public:
    bool isSafe(int row,int col,vector<vector<char>>& board,char val){
       
        for(int i=0;i<9;i++){
            // //check in row
            if(board[row][i] == val){
                return false;
            }
            //check col
            if(board[i][col] == val){
                return false;
            }
            
        }
        //check in grid
        int row_st=3*(row/3);
        int row_en=3*(row/3)+3;
        int col_st=3*(col/3);
        int col_en=3*(col/3)+3;
        for(int i=row_st;i<row_en;i++){
            for(int j=col_st;j<col_en;j++){
                if(board[i][j]==val){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int val=1;val<=9;val++){
                        if(isSafe(i,j,board,val+'0')){
                            board[i][j]=val+'0';
                            bool nextPossibleSol = solve(board);
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