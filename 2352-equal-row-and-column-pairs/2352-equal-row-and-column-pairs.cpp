class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<int>>rows,cols;
        
        //calculate rows
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
           rows.push_back(temp);
        }
        //calculate cols
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
           cols.push_back(temp);
        }
        
        map<vector<int> , int>mp;
        for(auto it:rows){
            mp[it]++;
        }
        for(auto it:cols){
            cnt=cnt+mp[it];
        }
        return cnt;
    }
};