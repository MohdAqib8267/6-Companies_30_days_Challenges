class Solution {
public:
    bool check(vector<int>& nums, int k, int mid){
        int cntPairs=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            while(j<nums.size() and nums[j]-nums[i] <= mid) j++;
            
            j--;
            cntPairs += (j-i);
        }
        return cntPairs>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // think like we have to find kth smallest element in a grid
        // but we will not create a grid of difference, just assume
        int l=0, r=nums[n-1]-nums[0]; // (l,r) as pointers on grid
        while(l<=r){
            int mid = (l+(r-l)/2);
            if(check(nums,k,mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};