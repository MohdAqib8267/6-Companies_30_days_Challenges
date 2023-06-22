class Solution {
public:
    int atmost(vector<int>& nums, int k){
        //use sliding window
        int n=nums.size();
        int l=0,r=0;
        int ans=0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans=ans+(r-l+1);
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        //1.find 1 to upto k different integer subarray
        //2.then find 1 to upto k-1 different integer subarray
        //minus 1-2
        // after subtract only left k different subarray
        //ex:- [1],[1,2],[2,3] (1 to k) k==2
        // [1],[2],[3] up to k-1
        //subtract=> [1,2],[2,3] remaining
        //formula
        //atmost(k)-atmost(k-1)==extactly(k)
        if(k==1){
            return atmost(nums,k);
        }
        return atmost(nums,k)-atmost(nums,k-1);
    }
};