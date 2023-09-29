class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        //Greedy Approach
        int n=pairs.size();
        // sort(pairs.begin(),pairs.end(),cmp);
        // int i=0;int j=1;
        // int cnt=1;
        // while(j<n){
        //     if(pairs[i][1]<pairs[j][0]){
        //         cnt++;
        //         i=j;
        //     }
        //     j++;
        // }
        // return cnt;
        
        
        //DP
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return dp[n-1];
    }
};