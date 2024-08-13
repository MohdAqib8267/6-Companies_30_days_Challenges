class Solution {
public:
//     void solve(vector<int>& candidates,int target,set<vector<int>>&s,vector<int>&temp,int i){
//         if(target==0){
          
//             s.insert(temp);
//             return;
//         }
//         if(target<0 || i>=candidates.size()){
//             return;
//         }
//         temp.push_back(candidates[i]);
//         solve(candidates,target-candidates[i],s,temp,i+1);
//         temp.pop_back();
//         solve(candidates,target,s,temp,i+1);
//     }
    
    void solve2(vector<int>& candidates, int target,vector<int>&temp,vector<vector<int>>&ans,int i){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        
        for(int index=i;index<candidates.size();index++){
            if(index>i && candidates[index]==candidates[index-1]){
                continue;
            }
            temp.push_back(candidates[index]);
            solve2(candidates,target-candidates[index],temp,ans,index+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // TLE
        // vector<vector<int>>ans;
        // set<vector<int>>s;
        // vector<int>temp;
        // sort(candidates.begin(),candidates.end());
        // solve(candidates,target,s,temp,0);
        // for(auto it:s){
        //     ans.push_back(it);
        // }
        // return ans;
        
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve2(candidates,target,temp,ans,0);
        return ans;
    }
};