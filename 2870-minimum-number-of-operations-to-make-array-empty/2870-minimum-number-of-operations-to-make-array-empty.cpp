class Solution {
public:
    int minOperations(vector<int>& nums) {
         unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans=0;
        for(auto it:mp){
            if(it.second<2){
                return -1;
            }else if(it.second==2 || it.second==3)ans++;
            else if(it.second>3){
                int c=0;
                int r=0;
                c=it.second/3;
                r=it.second%3;
                ans+=c;
                if(r!=0)ans++;
            }
        }

     return ans;
    }
};