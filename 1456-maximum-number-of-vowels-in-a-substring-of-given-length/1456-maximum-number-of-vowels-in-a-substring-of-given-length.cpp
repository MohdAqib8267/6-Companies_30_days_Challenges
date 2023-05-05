class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int mx=0;
        int cnt=0;
        while(i<n){
            if(i-j+1<=k){
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    mp[s[i]]++;
                    cnt++;
                }
                i++;
                continue;
            }
            mx=max(mx,cnt);
             if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                 mp[s[i]]++;
                 cnt++;
             }
            if(mp.find(s[j])!=mp.end()){
                
                cnt--;
                mp[s[j]]--;
            }
            i++;
            j++;
            
        }
        mx=max(cnt,mx);
        return mx;
    }
};