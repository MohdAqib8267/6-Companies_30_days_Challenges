class Solution {
public:
    void solve(int i,int target,int k,vector<int>& temp,vector<vector<int>>&ans){
        if(target==0 and temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(i>9 or target<0){
            return;
        }
        temp.push_back(i);
        solve(i+1,target-i,k,temp,ans);
        temp.pop_back();
        solve(i+1,target,k,temp,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        int target=n;
        solve(1,target,k,temp,ans);
        return ans;
    }
};