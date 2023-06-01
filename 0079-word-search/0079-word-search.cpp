class Solution {
public:
    bool solve(int i,int j,int m,int n,vector<vector<char>>& board,string word,vector<vector<bool>>& vis,int ind){
        if(ind==word.size()){
            return true;
        }
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j]){
            return false;
        }
        if(board[i][j]==word[ind]){
             vis[i][j]=true;
        bool left=solve(i,j-1,m,n,board,word,vis,ind+1);
        bool up=solve(i-1,j,m,n,board,word,vis,ind+1);
        bool right=solve(i,j+1,m,n,board,word,vis,ind+1);
        bool down=solve(i+1,j,m,n,board,word,vis,ind+1);
            if(left or right or up or down){
                return true;
            } vis[i][j]=false;
        return false;
        }
       return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,m,n,board,word,vis,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};