class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int i=0,j=0;
        int mx=INT_MIN;
        int res=INT_MIN;
        while(j<n){
            mp[s[j]]++;
            mx=max(mx,mp[s[j]]);
            int len=j-i+1;
            if(len-mx <= k){
                res=max(res,len);
            }
            else{
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return res;
    }
};