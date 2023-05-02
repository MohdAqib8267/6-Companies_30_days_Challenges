class Solution {
public:
    int arraySign(vector<int>& nums) {
       long long int prod=1;
        int j=0;
        int zero=1;
        for(int i=0;i<nums.size();i++){
           if(nums[i]<0){
               j++;
           }
           if(nums[i]==0){
               zero=0;
           }
           else{
               continue;
           }
        }
        if(zero==0){
            return 0;
        }
        else if(j%2 == 0){
            return 1;
        }
        else{
            return -1;
        }
        
        

    }
};