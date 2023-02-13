class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
          unordered_map<int,int>mp;
        int sum=0;
        int rem=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            rem=sum%k;

            if(rem==0 and i>=1){ //bcs ho skta hai 0th index wala hi pura devide ho jaye but hume km se km do element chahye hai
            return true;

            }

            if(mp.find(rem) != mp.end()){
                //its mean hum remove kr rhey hai jitne element mp[rem] tk ki index per pdey hai
                if(i-mp[rem]>1){
                    //check ki ek hi element to nhi bacha subarray me
                    return true;
                }
            }
            else{
                 mp[rem]=i; //index first time wali hi rhey
            }
           
        }
        return false;
    }
};