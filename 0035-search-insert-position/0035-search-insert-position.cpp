class Solution {
public://ye bhi theek sol hai
//     public int searchInsert(int[] nums, int target) {
// int c = -1;
// int i =0;

//     while(i < nums.length && nums[i]<target){
//         if(nums[i] == target){
//             return i;
//         }
//         i++;
//     }
//     if(c == -1){
//         c = i;
//     }
//     return c;
// }
    //ye mera hai...
    int searchInsert(vector<int>& nums, int target) {
       int n=nums.size();
        int st=0;
        int en=n-1;
        int ans=-1;
        while(st<=en){
            int mid=(st+en)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid]<target){
                st=mid+1;
            }
            else{
                en=mid-1;
            }
        }
        if(ans!=-1){
            return ans;
        }
        else{
            for(int i=0;i<n;i++){
                if(nums[i]>target){
                    return i;
                
                }
            }
        }
        return n;
    }
};