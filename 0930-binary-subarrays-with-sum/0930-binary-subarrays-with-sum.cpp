class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            if(sum==goal){
                cnt++;
            }
            if(mp.find(sum-goal)!=mp.end()){
                cnt=cnt+mp[sum-goal];
            }
            mp[sum]++;
        }
        return cnt;
    }
};