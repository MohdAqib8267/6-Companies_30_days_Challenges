class Solution {
public:
    bool solve(int i,int j,int l,int m,int n,string &word,vector<vector<char>>&board,vector<vector<int>>&vis){
        if(l>=word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j]){
            return false;
        }
        if(board[i][j]==word[l]){
            vis[i][j]=true;
            bool left=solve(i,j-1,l+1,m,n,word,board,vis);
            bool up = solve(i-1,j,l+1,m,n,word,board,vis);
            bool right = solve(i,j+1,l+1,m,n,word,board,vis);
            bool down =solve(i+1,j,l+1,m, n,word,board,vis);
            if(left || up || right || down){
                return true;
            }
        }
        vis[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,0,m,n,word,board,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};