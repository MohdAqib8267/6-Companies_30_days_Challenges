class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0 ;
    bool maxfound = false , minfound = false;
    long long minstart = 0 , maxstart = 0 , start = 0 ; 
    for( int i = 0 ; i < nums.size() ; ++i )
    {
        if( nums[i] <minK || nums[i] > maxK)
        {
            // Restart 
            maxfound = false;
            minfound = false ;
            start = i + 1 ;
        }
        if( nums[i] == minK )
        {
            minfound = true;
            minstart = i;
        }
        if( nums[i] == maxK )
        {
            maxfound = true;
            maxstart = i ;
        }
        if( maxfound && minfound )
        {
            res += (min(maxstart,minstart)-start+1 ) ; 
        }
    }
    return res;
    }
};