class Solution {
public:
    int solve(int i,int j,int k,vector<int>& cardPoints, vector<vector<vector<int>>>&dp){
        if(i>=cardPoints.size() or j<0 or k==0){
            return 0;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
       
        int left = cardPoints[i]+solve(i+1,j,k-1,cardPoints,dp);
        int right = cardPoints[j]+solve(i,j-1,k-1,cardPoints,dp);
        dp[i][j][k] = max(left,right);
        return dp[i][j][k];
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        //TLE
//      vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
//         return solve(0,n-1,k,cardPoints,dp);
        
        int  sum=0;
        //calculate sum of first k numbers
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        //now take card from end and replace first card with their position
        int i=k-1;
        int j=n-1;
        int best_comb=sum;
        for(i,j;i>=0;i--,j--){
            sum = sum - cardPoints[i] + cardPoints[j];
            best_comb = max(best_comb,sum);
        }
        return best_comb;
        
    }
};