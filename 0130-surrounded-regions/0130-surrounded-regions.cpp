class Solution {
public:
    void DFS(int i,int j,vector<vector<char>>& board){
        if(board[i][j]!='O') return;
        if(board[i][j]=='O'){
            board[i][j]='*';
        }
        if(i-1>=0){
            DFS(i-1,j,board);
        }
        if(j-1>=0){
            DFS(i,j-1,board);
        }
        if(i+1<board.size()){
            DFS(i+1,j,board);
        }
        if(j+1<board[0].size()){
            DFS(i,j+1,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if( board[i][j]=='O' ){
                    DFS(i,j,board);
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='*'){
                     board[i][j]='O';
                }
            }
        }
        return;
    }
};