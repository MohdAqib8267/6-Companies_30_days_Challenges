class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int st=0;
        int en=n-1;
        while(st<=en){
            int mid=(st+en)/2;
            if((mid%2==0 and nums[mid]==nums[mid+1]) or (mid%2 ==1 and nums[mid]==nums[mid-1])){
                st=mid+1;
            }
         
            else{
                en=mid-1;
            }
        }
        return nums[st];
    }
};