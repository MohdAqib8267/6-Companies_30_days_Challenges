class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid){
       if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
           return 0;
       }
        int temp=grid[i][j];
        grid[i][j]=0;
        int a=solve(i-1,j,grid);
        int b=solve(i,j-1,grid);
        int c=solve(i+1,j,grid);
        int d=solve(i,j+1,grid);
        int ans=temp+max({a,b,c,d});
        grid[i][j]=temp;
        return ans;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    mx=max(mx,solve(i,j,grid));
                    cout<<mx<<endl;
                    
                }
            }
        }
        return mx==INT_MIN? 0 :mx;
    }
};