class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>mp;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            mp[nums[i]]=true;
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            if(mp[curr-1]==true){//agar false hua to mtlb ki wo sequence ka sabse chota element h
                continue;
            }
            int cnt=0;
            while(mp[curr]==true){
                cnt++;
                curr++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};