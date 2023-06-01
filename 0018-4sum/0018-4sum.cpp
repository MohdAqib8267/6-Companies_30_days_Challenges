class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        set<vector<int>>s;
        int n=nums.size();
        long long target1=target;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long long lo=j+1;
                long long hi=n-1;
                vector<int>ans;
                long long sum=0;
                while(lo<hi){
                     sum=(long long) ((long long)nums[i]+ (long long)nums[j]+ (long long )nums[lo]+ (long long)nums[hi]);
                    if(sum == target1){
                        ans = {nums[i], nums[j], nums[lo], nums[hi]};
                        sort(ans.begin(),ans.end());
                        s.insert(ans);
                        lo++;
                        hi--;
                    }
                    else if(sum<target1){
                        lo++;
                    }
                    else{
                        hi--;
                    }
                }
            }
        }
         for (auto x : s)
            res.push_back(x);
        return res;
    }
};