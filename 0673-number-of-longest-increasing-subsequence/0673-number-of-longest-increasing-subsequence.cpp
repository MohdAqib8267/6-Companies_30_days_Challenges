class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
                int n = arr.size();
    vector<int> dp(n , 1) ,cnt(n ,1);
    int maxi = 0;
	//creating a dp array of n with  1 in all arr
    for(int i = 0 ; i< n ; i++) {
        
        for(int prev = 0 ; prev < i ; prev++) {
            //condition check
            if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev];
            }
            //       4 == 4
            else if(arr[prev] < arr[i] && 1 + dp[prev] ==  dp[i]){
                cnt[i] += cnt[prev];
            }
             
        }
        maxi = max(maxi , dp[i]);   
    }
    int lennums = 0;
    for(int i = 0 ; i< n ; i++) {
        if(dp[i] == maxi) {
            lennums += cnt[i]; 
        }
    }
    return lennums;

    }
};