class Solution {
public:
    int atmost(vector<int>& nums, int k){
        //use sliding window
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans=ans+(j-i+1);
            j++;
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