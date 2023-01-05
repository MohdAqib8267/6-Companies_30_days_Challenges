class Solution {
public:
    void solve(int ind,int k,int target,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
         if(temp.size()==k and target==0){
            
                ans.push_back(temp);
                return;
            
        }
        if(ind==nums.size()){
            return ;
        }
        //pick
        temp.push_back(nums[ind]);
        solve( ind+1, k, target-nums[ind],nums, temp, ans);
        //not pick
        temp.pop_back();
        solve( ind+1, k, target,nums, temp, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        //according to 1st condition
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,k,n,nums,temp,ans);
        return ans;
        
    }
};