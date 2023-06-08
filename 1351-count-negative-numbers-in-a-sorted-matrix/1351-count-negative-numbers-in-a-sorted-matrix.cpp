class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            if(grid[i][0]<0){
                //all rows elements will be zero
                ans=ans+n;
            }
            else if(grid[i][n-1]>=0){
                //last element of row is positive then no negative element in row
                continue;
            }
            else{
                //binary search
                int l=0, r=n-1;
                while(l<r){
                    int mid=(l+r)/2;
                    if(grid[i][mid]>=0){
                        l=mid+1;
                    }
                    else{
                        r=mid;
                    }
                }
                ans=ans+(n-r);
            }
        }
        return ans;
    }
};