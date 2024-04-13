class Solution {
public:
    void swap(vector<int>& nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void reverse(vector<int> & nums,int start){
        int i=start;
        int j=nums.size()-1;
        while(i<=j){
            swap(nums,i,j);
            i++;
            j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        //find first decresing element at the end of array
        int i=nums.size()-2;
        while(i>=0 and nums[i]>=nums[i+1]){
            i--;
        }
        //find just greater element with index[i]
        if(i>=0){
        int j=nums.size()-1;
        while(nums[i]>=nums[j]){
            j--;
        }
        //swap i and j
        swap(nums,i,j);
        }
        //reverse array with start i+1 index
        reverse(nums,i+1);
        return ;
    }
};