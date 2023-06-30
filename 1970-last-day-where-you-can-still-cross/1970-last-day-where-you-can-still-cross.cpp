class Solution {
public:
   vector<vector<int>> nthDayBoard(vector<vector<int>>& cells, int n, int row, int col) {
        vector<vector<int>> board(row, vector<int>(col, 0));
        for (int i = 0; i < n; i++) {
            board[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        return board;
    }
    bool dfs(int i,int j,int m,int n,vector<vector<int>>&grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==1){
            return false;
        }
        if(i==m-1){
           
            return true;
        }
        grid[i][j]=1;
        bool a=dfs(i+1,j,m,n,grid);
        bool b=dfs(i,j-1,m,n,grid);
        bool c=dfs(i-1,j,m,n,grid);
        bool d = dfs(i,j+1,m,n,grid);
        return a || b || c || d;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        //agar hum ek ek din per jaa kr check krenge ki kiske baad nhi jaa payenge to hume puri cell me jana pdeyga and grid me to time com o(N2)
        
    //so hum yha din nikalne ke liye binary search use kr lenge and uper se neechey jane ke liye dfs ya bfs
        int ans=-1;
        int lo=0, hi=cells.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            //ab mid wale din se ohle tak k sab day fill kr do
            vector<vector<int>>grid=nthDayBoard(cells,mid,row,col);
            
            //now try to move from top to bottom
            bool flag=false;
           for(int c = 0 ; c < col ; c++){
                if(grid[0][c] == 0){
                    flag = dfs(0, c, row, col,grid);
                }
                if(flag) break;
            }
            if(flag){
                lo = mid+1;
                ans = mid;
            }else{
                hi = mid-1;
            }
        }
        return ans;
    }
};