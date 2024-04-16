class Solution {
public:
    void solve(int i,vector<int>& candidates,int target, vector<int>temp, set<vector<int>>&st){
        if(target==0){
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        if(target<0 || i>=candidates.size()){
            return;
        }
        temp.push_back(candidates[i]);
        solve(i,candidates,target-candidates[i],temp,st);
        temp.pop_back();
        solve(i+1,candidates,target,temp,st);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        set<vector<int>>st;
        solve(0,candidates,target,temp,st);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};