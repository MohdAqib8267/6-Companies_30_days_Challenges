class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int i=0;
        int j=0;
        int ans=INT_MIN;
        int n=nums.size();
        int count=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]==1){
                count++;
            }
            while(count>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    count--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};