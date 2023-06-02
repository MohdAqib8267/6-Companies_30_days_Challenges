class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>copyBoard=board;
        int dx[]={-1,-1,0,1,1,1,0,-1};
         int dy[]={0,-1,-1,-1,0,1,1,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int liveCnt=0;
                for(int k=0;k<8;k++){
                    if(i+dx[k]>=0 and i+dx[k]<m and j+dy[k]>=0 and j+dy[k]<n and copyBoard[i+dx[k]][j+dy[k]]==1){
                        liveCnt++;
                    }
                }
                if(copyBoard[i][j]==1 and (liveCnt==2 or liveCnt==3)){
                    board[i][j]=1;
                }
                else if(copyBoard[i][j]==0 and liveCnt==3){
                    board[i][j]=1;
                }
                else{
                    board[i][j]=0;
                }
            }
        }
        return;
    }
};