class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int res=0;
        int l=0;
        int r=0;
        int maxCount=0;
        while(r<n){
            mp[s[r]]++;
            maxCount=max(maxCount,mp[s[r]]);
            int len=r-l+1;
            if(len-maxCount<=k){
                res=max(res,len);
            }else{
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return res;
    }
};