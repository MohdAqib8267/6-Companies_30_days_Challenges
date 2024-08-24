class Solution {
public:
    void solve(string s,int open,int close,vector<string>&ans,int n){
        if(open==n and close==n){
            ans.push_back(s);
            return;
        }
        if(open>n || close>n){
            return;
        }
        if(open==close){
            solve(s+"(",open+1,close,ans,n);
        }
        else{
            solve(s+"(",open+1,close,ans,n);
            solve(s+")",open,close+1,ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve("",0,0,ans,n);
        return ans;
    }
};