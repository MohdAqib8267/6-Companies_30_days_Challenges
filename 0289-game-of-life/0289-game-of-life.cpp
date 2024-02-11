class Solution {
public:
    vector<int>solve(int i,int j,vector<vector<int>>&copy,int m,int n){
       int dx[8]={-1,-1,0,1,1,1,0,-1};
        int dy[8]={0,-1,-1,-1,0,1,1,1};
        int cntZero=0,cntOne=0;
        for(int k=0;k<8;k++){
            if(i+dx[k]>=0 and i+dx[k]<m and j+dy[k]>=0 and j+dy[k]<n){
                 if( copy[i+dx[k]][j+dy[k]]==0){
                    cntZero++;
                    }else{
                        cntOne++;
                    }
            }
           
        }
        return {cntZero,cntOne};
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>copy=board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<int>cntZO = solve(i,j,copy,m,n);
                cout<<cntZO[0]<<" "<<cntZO[1]<<endl;
                if(copy[i][j]==0){
                    //die cell
                    if(cntZO[1] == 3){
                        board[i][j]=1;
                    }
                }else{
                    //live cell
                    if(cntZO[1]==2 || cntZO[1]==3){
                        continue;
                    }else{
                        board[i][j]=0;
                    }
                }
            }
        }
        return;
    }
};