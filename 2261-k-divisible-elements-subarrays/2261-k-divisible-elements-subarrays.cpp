class Solution {
public:
   int countDistinct(vector<int>& nums, int k, int p) {
        int l = 0, count = 0;
        int n = nums.size();
       set<vector<int>> res;

        for (int r = 0; r < n; ++r) {
            if (nums[r] % p == 0) {
                ++count;
            }
            
            while (l <= r && count > k) {
                if (nums[l] % p == 0) {
                    --count;
                }
                ++l;
            }
            
            for (int i = r - l; i >= 0; --i) {
                vector<int> subarray(nums.begin() + (r - i), nums.begin() + (r + 1));
                if (res.find(subarray) == res.end()) {
                    res.insert(subarray);
                } else {
                    break;
                }
            }
        }

        return res.size();
    }
};