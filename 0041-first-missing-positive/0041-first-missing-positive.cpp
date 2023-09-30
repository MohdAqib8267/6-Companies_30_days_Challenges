class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //O(nlogn)
        // sort(nums.begin(),nums.end());
        // int count=1;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]>0 and nums[i]==count){
        //         count++;
        //     }
        // }
        // return count;
        
        //O(n)
        int n=nums.size();
        //we want like this
        //index-->element
        //0-->1, 1-->2, 2-->3, 3-->4
        
        for(int i=0;i<n;i++){
            int element=nums[i];
            if(element>=1 and element<=n){
                int chair=element-1; //yani is index per element nums[i] hona chahye
                if(nums[chair] != nums[i]){
                    swap(nums[chair],nums[i]);
                    i--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i+1 != nums[i]){
                return i+1;
            }
        }
        return n+1;
    }
};