class Solution {
public:
    bool solve(vector<vector<char>>& board,int i,int j,string word,int l,int m,int n,vector<vector<bool>>& vis){
        if(l>=word.size()){
            return true;
        }
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j]){
            return false;
        }
       if(board[i][j]==word[l]){
           vis[i][j]=true;
           bool up=solve(board,i-1,j,word,l+1,m,n,vis);
            bool left=solve(board,i,j-1,word,l+1,m,n,vis);
            bool down=solve(board,i+1,j,word,l+1,m,n,vis);
            bool right=solve(board,i,j+1,word,l+1,m,n,vis);
            if(up or left or down or right){
                return true;
            }
       }
        vis[i][j]=false;
      return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(board,i,j,word,0,m,n,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};