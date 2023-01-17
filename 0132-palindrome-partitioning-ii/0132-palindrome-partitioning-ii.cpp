class Solution {
public:
    //CORRECT BUT ITS GIVING TLE-------->
    //    bool isPalindrome(string str){
    //     int i=0;
    //     int j=str.size()-1;
    //     while(i<=j){
    //         if(str[i]!=str[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // void solve(int i,string &s,int n,vector<string>&temp,int &ans){
    //     if(i>=n){
    //         if(ans>temp.size()){
    //             ans=temp.size();
    //         }
    //         return;
    //     }
    //     string str="";
    //     for(int j=i;j<n;j++){
    //         str=str+s[j];
    //         if(isPalindrome(str)){
    //             temp.push_back(str);
    //             solve(j+1,s,n,temp,ans);
    //             temp.pop_back();
    //         }
    //     }
    // }
    // int minCut(string s) {
    //     int ans=INT_MAX;
    //     int n = s.size();
    //     vector<string>temp;
    //      solve(0,s,n,temp,ans);
    //     return ans-1;
    // }
   int solve(string &s,int ind,vector<int> &dp){
		if(ind == s.size()) return 0;

		if(dp[ind] != -1) return dp[ind];

		int ans=INT_MAX;
		for(int i=ind;i<s.size();i++){
			if(isPalindrome(s,ind,i)){
				int temp=1+solve(s,i+1,dp);
				ans = min(ans,temp);
			}
		}
		return dp[ind]=ans;
	}

	bool isPalindrome(string &s,int start,int end){
		while(start <= end){if(s[start++] != s[end--]) return false;}
		return true;
	}
	int minCut(string s) {
		int n = size(s);
		if(n==1) return 0;
		vector<int>dp(n,-1);
		return solve(s,0,dp)-1;
	}
};