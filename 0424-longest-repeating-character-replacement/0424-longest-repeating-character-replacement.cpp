class Solution {
public:
    int characterReplacement(string s, int k) {
        //sliding window
        int n=s.size();
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int res=0;
        int maxCount=0;
        while(r<n){
            mp[s[r]]++;
            //now check maximum freq of char(insted of scan whole map using maxCount variable that keep count maximum frequency character)
            maxCount=max(maxCount,mp[s[r]]); //give maxCount element in current window
            //now find current window length and check condition
            int currWindowLen = r-l+1;
            if(currWindowLen-maxCount <= k){
                res=max(res,currWindowLen);
            }
            else{
                //substring condition ko meet nhi krti to shrink the current window
                mp[s[l]]--;
                l++;
        
            }
            r++;
        }
        return res;
    }
};