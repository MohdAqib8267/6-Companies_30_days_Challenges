class Solution {
public:
   bool isPalindrome(string temp){
        int m=temp.size();
        for(int i=0;i<m;i++){
            if(temp[i]!=temp[m-i-1]){
                return false;
            }
        }
        return true;
    }
    void solve(int i,string s,int n,vector<string>& temp,vector<vector<string>>& ans){
        if(i>=n){
            ans.push_back(temp);
           
            return;
        }
        string str="";
        for(int j=i;j<n;j++){
            str=str+s[j];
            if(isPalindrome(str)){
                temp.push_back(str);
                solve(j+1,s,n,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        int n=s.size();
        solve(0,s,n,temp,ans);
        return ans;
    }
};