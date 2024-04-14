class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool>mp;
       int ans=INT_MIN;
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            mp[nums[i]]=true;
        }
        
        for(int i=0;i<n;i++){
            int cnt=0;
            int element = nums[i];
            if(mp[element-1]==true){//agar false hua to mtlb ki wo sequence ka sabse chota element h
                continue;
            }
            while(mp[element]==true){
                cnt++;
                element++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};