class Solution {
public:
    void solve(string s,int open,int close,vector<string>& ans,int n){
        if(open==n and close==n){
            ans.push_back(s);
            return;
        }
        if(open>n or close>n){
            return;
        }
        if(open>close){
            solve(s+')',open,close+1,ans,n);
        }
        
            solve(s+'(',open+1,close,ans,n);
        
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>ans;
        int open=0, close=0;
        solve(s,open,close,ans,n);
        return ans;
    }
};