class Solution {
public:
    void solve(int idx,int n,string &s,string digits,string mapping[10],vector<string>& ans){
        if(idx>=n){
            ans.push_back(s);
            return;
        }
        int code = digits[idx]-'0';
        string val=mapping[code];
        for(int i=0;i<val.size();i++){
            s.push_back(val[i]);
            solve(idx+1,n,s,digits,mapping,ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string s="";
        if(digits==""){
            return ans;
        }
        solve(0,n,s,digits,mapping,ans);
        return ans;
       
    }
};