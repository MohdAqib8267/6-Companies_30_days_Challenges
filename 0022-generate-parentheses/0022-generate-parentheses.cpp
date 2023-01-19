class Solution {
public:
    void solve(string s,int open,int close,int n,vector<string>&ans){
        if(open==n and close==n){
            ans.push_back(s);
            return;
        }
        if(open>n or close>n){
            return;
        }
        if(open>close){
            solve(s+")",open,close+1,n,ans);
        }
        
            solve(s+"(",open+1,close,n,ans);
        
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        int open=0;
        int close=0;
        vector<string>ans;
        solve(s,open,close,n,ans);
        return ans;
    }
};