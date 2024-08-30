class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        unordered_map<char,int>mp;
        int ans=0;
        int n=s.size();
        int maxFreqElement=0;
        while(j<n){
            mp[s[j]]++;
            maxFreqElement=max(maxFreqElement,mp[s[j]]);
            if(j-i+1-maxFreqElement > k){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};