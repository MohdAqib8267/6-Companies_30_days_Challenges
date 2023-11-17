class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>arr;
        for(int i=0;i<n/2;i++){
            arr.push_back(nums[i]);
            arr.push_back(nums[n-i-1]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i=i+2){
            ans=max(ans,arr[i]+arr[i+1]);
        }
        return ans;
    }
};