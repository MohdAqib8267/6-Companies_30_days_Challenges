class Solution {
    public boolean solve(int i,int j,int len,String word,char[][] board,int n,int m,boolean[][] vis){
        if(len>=word.length()){
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==true){
            return false;
        }
        if(word.charAt(len)==board[i][j]){
            vis[i][j]=true;
             boolean left = solve(i,j-1,len+1,word,board,n,m,vis);
             boolean up = solve(i-1,j,len+1,word,board,n,m,vis);
             boolean right = solve(i,j+1,len+1,word,board,n,m,vis);
             boolean down = solve(i+1,j,len+1,word,board,n,m,vis);
            if(left || up || right || down){
                return true;
            }
        }
        vis[i][j]=false;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        int n=board.length;
        int m=board[0].length;
        boolean[][] vis = new boolean[n][m];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                vis[i][j]=false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word.charAt(0)){
                    if(solve(i,j,0,word,board,n,m,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
}