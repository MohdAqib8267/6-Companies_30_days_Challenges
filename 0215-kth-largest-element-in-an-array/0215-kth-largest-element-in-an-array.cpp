class Solution {
public:
    int partition(vector<int>& nums,int l,int r){
        int i=l-1;
        int pivot=nums[r]; //pivot ke left me pivot se chote abd right me bdey ho
        for(int j=l;j<=r-1;j++){
            if(nums[j]<=pivot){
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[r]);
        return i+1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        k=n-k; //kth smallest element
        while(lo<hi){
            int pi=partition(nums,lo,hi);
            if(pi<k){
                lo=pi+1;
            }
            else if(pi>k){
                hi=pi-1;
            }
            else{
                break;
            }
        }
        return nums[k];
    }
};