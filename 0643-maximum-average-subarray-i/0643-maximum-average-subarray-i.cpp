class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0 , j=k;
        int sum = 0;
        for(int a=i ; a<k ;a++){
            sum += nums[a];
        }   
        int max_sum = sum;
        while(j<nums.size()){
            sum -=nums[i++];
            sum +=nums[j++];
            max_sum = max(max_sum,sum);
        }
        double max_avg = max_sum/(double)k;
        return max_avg;
    }
};