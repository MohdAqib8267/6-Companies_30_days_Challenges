class Solution {
public:
    bool isPossible(vector<int>& nums) {
         int n=nums.size();
        unordered_map<int,int>count;
        unordered_map<int,int>end; //store end of both subseq
        
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        
        for(int i=0;i<n;i++){
              // if nums[i] is already included(no elements remaining)
            if(count[nums[i]]==0){
                continue;
            }
            //decrement freq
            count[nums[i]]--;
            
            //if nums[i] make part of exsisting subseq
            //to uska end zrur end map me store hoga
            if(end[nums[i]-1]>0){
                //change end element of subseq
                end[nums[i]-1]--;
                end[nums[i]]++;
            }
            //else check can we form new subseq started with nums[i]
            else if(count[nums[i]+1]>0 and count[nums[i]+2]>0){
                //decrement freq of including elememnts
                count[nums[i]+1]--;
                count[nums[i]+2]--;
                //store endimg element of this subseq
                end[nums[i]+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};