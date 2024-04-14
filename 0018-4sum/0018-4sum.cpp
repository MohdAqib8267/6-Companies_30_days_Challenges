class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
       vector<vector<int>>ans;
        //[-2,-1,0,0,1,2]
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int l=j+1, h=n-1;
                while(l<h){
                      long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[l]+(long long)nums[h];
                if(sum == target){
                    st.insert({nums[i],nums[j],nums[l],nums[h]});
                    l++;
                    h--;
                }
                else if(sum<target){
                    l++;
                }
                else{
                    h--;
                }
                }
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};