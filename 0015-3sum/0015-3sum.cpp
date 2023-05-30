class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
  int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        set<vector<int>>s;
       for(int i=0;i<n;i++)
        {
            int sum = 0;
            int lo = i + 1, hi = n - 1;
            vector<int> ans;
            while (lo < hi)
            {
                sum = nums[i] + nums[lo] + nums[hi];
                if (sum == 0)
                {
                    ans = {nums[i], nums[lo], nums[hi]};
                    sort(ans.begin(),ans.end());
                    s.insert(ans);
                    lo++;
                    hi--;
                }
                else if (sum < 0)
                    lo++;
                else
                    hi--;
            }
        }
        for (auto x : s)
            res.push_back(x);
        return res;
    }
};