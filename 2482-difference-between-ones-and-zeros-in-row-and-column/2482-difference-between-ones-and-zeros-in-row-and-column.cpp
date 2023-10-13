class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>diff(m,vector<int>(n,0));
        unordered_map<int,pair<int,int>>mp_r;
        unordered_map<int,pair<int,int>>mp_c;
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum=sum+grid[i][j];
            }
            mp_r[i]={sum,n-sum};
        }
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<m;i++){
                sum=sum+grid[i][j];
            }
            mp_c[j]={sum,m-sum};
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j]=mp_r[i].first+mp_c[j].first-mp_r[i].second-mp_c[j].second;
            }
        }
        return diff;
    }
};