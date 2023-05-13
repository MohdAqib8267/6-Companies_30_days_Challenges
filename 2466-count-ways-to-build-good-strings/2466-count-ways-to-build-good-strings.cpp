class Solution {

    private:
    int mod=(int)1e9+7;
private:
int find(int low,int high,int zero,int one,int cnt,vector<int> &dp){
    if(cnt>high)
    return 0;
    if(dp[cnt]!=-1)
    return dp[cnt];
    int pickOne=find(low,high,zero,one,cnt+one,dp);
    int pickZero=find(low,high,zero,one,cnt+zero,dp);
    if(cnt>=low && cnt<=high)
    pickZero++;
    return dp[cnt]=(pickZero+pickOne)%mod;
}

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int cnt=0;
        vector<int> dp(high+1,-1);
        return find(low,high,zero,one,cnt,dp);
    }
};