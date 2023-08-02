class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int en=n-1;
        while(st<en){
            int mid=(st+en)/2;
            if(nums[mid]<nums[en]){
                en=mid;
            }
            else if(nums[mid]>nums[en]){
                st=mid+1;
            }
        }
        return nums[st];
    }
};