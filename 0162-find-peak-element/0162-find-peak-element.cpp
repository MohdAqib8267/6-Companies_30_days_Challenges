class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
             int mid = lo + (hi - lo) / 2;
            if((mid==0 || nums[mid-1]<nums[mid]) and (mid==n-1 || nums[mid]>nums[mid+1])){
                return mid;
            }
            else if(nums[mid]<nums[mid+1]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return -1;
    }
};