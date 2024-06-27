class Solution {
public:
    void solve(int i,vector<int>& candidates, int target,vector<int>temp,set<vector<int>>&s){
         if(target==0){
             sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        if(i>=candidates.size() || target<0){
            return;
        }
       
        temp.push_back(candidates[i]);
        solve(i,candidates,target-candidates[i],temp,s);
        temp.pop_back();
        solve(i+1,candidates,target,temp,s);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>temp;
        solve(0,candidates,target,temp,s);
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};