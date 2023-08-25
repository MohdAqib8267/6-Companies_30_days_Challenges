class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m=accounts.size();
        int n=accounts[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                
                sum=sum+accounts[i][j];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};