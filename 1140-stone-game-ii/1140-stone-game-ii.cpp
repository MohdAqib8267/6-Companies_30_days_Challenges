class Solution {
public:
    int dp[101][202];
    int solve(int i,vector<int>& piles,int M){
        if(i>=piles.size()){
            return 0;
        }
        if(dp[i][M]!=-1){
            return dp[i][M];
        }
        int tot=0;
        int ans=INT_MIN;
        for(int j=0;j<2*M;j++){
            if(i+j<piles.size()){
                tot+=piles[i+j];
            }
            ans=max(ans,tot-solve(i+j+1,piles,max(M,j+1)));
        }
        return dp[i][M]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<piles.size();i++){
            sum+=piles[i];
        }
        int diff = solve(0,piles,1);
        //diff hai (a-b); // a -- alice, b--bob 
        //if we add ((a+b) + (a-b))/2=a(alice)
        return (sum+diff)/2;
    }
    
};