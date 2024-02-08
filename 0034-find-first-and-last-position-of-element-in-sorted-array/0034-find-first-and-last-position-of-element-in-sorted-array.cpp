class Solution {
public:
    int first(int i,int n,vector<int>& nums,int target){
        if(i==n){
            return -1;
        }
        if(nums[i]==target){
            return i;
        }
        return first(i+1,n,nums,target);
    }
    int last(int i,int n,vector<int>&nums,int target){
        if(i==n){
            return -1;
        }
        int res=last(i+1,n,nums,target);
        if(res!=-1){
            return res;
        }
        if(nums[i]==target){
            return i;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int fo=first(0,n,nums,target);
        int lo=last(0,n,nums,target);
        return {fo,lo};
    }
};