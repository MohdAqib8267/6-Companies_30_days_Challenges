class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            
           int mid = lo + (hi - lo) / 2; // Use this formula to avoid overflow
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            } else if (mid == 0 || nums[mid]<nums[mid+1]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
};