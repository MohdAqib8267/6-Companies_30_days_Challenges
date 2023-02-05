class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>mp;
        
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;
        }
        int i=0;
        int j=0;
        int cnt=mp.size();
        while(j<s.size()){

           if(mp.find(s[j])!=mp.end()){
               mp[s[j]]--;
               if(mp[s[j]]==0){
                   cnt--;
               }
           }
            if(j-i+1<p.size()){
                j++;
            }
            else if(j-i+1==p.size()){
                if(cnt==0){
                    ans.push_back(i);
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        cnt++;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};