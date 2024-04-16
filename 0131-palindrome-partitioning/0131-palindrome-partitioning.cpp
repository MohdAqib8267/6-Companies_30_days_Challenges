class Solution {
public:
    bool isPalindrom(string str){
        int m=str.size();
        int i=0;
        int j=m-1;
        while(i<=j){
            if(str[i] != str[j]) return false;
            i++; j--;
        }
        return true;
    }
    void solve(int i,int n,string s, vector<vector<string>>&ans,vector<string>temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        string str="";
        for(int j=i;j<n;j++){
            str=str+s[j];
            if(isPalindrom(str)){
                temp.push_back(str);
                solve(j+1,n,s,ans,temp);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>ans;
        vector<string>temp;
        string str="";
        solve(0,n,s,ans,temp);
        return ans;
    }
};