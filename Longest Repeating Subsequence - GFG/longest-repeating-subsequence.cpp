//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int solve(int i,int j,string &str,vector<vector<int>>&dp){
	    if(i>=str.size() || j>=str.size()){
	        return 0;
	    }
	    if(dp[i][j]!=-1){
	        return dp[i][j];
	    }
	    if(str[i]==str[j] and i!=j){
	        return dp[i][j]=1+solve(i+1,j+1,str,dp);
	    }
	    return dp[i][j]= max(solve(i+1,j,str,dp),solve(i,j+1,str,dp));
	}
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.size();
		    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
		    return solve(0,0,str,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends