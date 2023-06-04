class Solution {
public:
    void solve(int i,int n,int k,vector<int>& temp,vector<vector<int>>&ans){
         if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(i>n){
            return;
        }
       
        temp.push_back(i);
        solve(i+1,n,k,temp,ans);
        temp.pop_back();
        solve(i+1,n,k,temp,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,n,k,temp,ans);
        return ans;
    }
};