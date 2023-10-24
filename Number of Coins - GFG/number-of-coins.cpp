//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int i,int coins[],int n,int v,vector<vector<int>>&dp){
	    if(i==n || v<0){
	        return 1e9;
	    }
	  
	     if(v==0){
	        return 0;
	    }
	    if(dp[i][v]!=-1) return dp[i][v];
	    

	    int inc=1+solve(i,coins,n,v-coins[i],dp);
	    int exc=solve(i+1,coins,n,v,dp);
	    return dp[i][v]=min(inc,exc);
	    
	}
	int solveTab(int coins[],int n,int v){
	     vector<int>dp(v+1,INT_MAX);
	     dp[0]=0;
	     for(int i=1;i<=v;i++){
	         for(int j=0;j<n;j++){
	             if(i>=coins[j] and dp[i-coins[j]]!=INT_MAX){
	                 dp[i]=min(dp[i],1+dp[i-coins[j]]);
	             }
	         }
	     }
	     return dp[v] != INT_MAX ? dp[v] : -1;
	    
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	   // int ans = solve(0,coins,M,V,dp);
	   // return ans==1e9?-1:ans;
	   return solveTab(coins,M,V);
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends