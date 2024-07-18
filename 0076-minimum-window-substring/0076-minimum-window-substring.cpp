class Solution {
public:
    string minWindow(string s, string t) {
        int ns=s.size(), nt=t.size();
        if(nt>ns){
            return "";
        }
        unordered_map<char,int>mp;
        for(auto it:t){
            mp[it]++;
        }
        int cnt=0;
        unordered_map<char,int>mps;
        int i=0,j=0;
        int st=-1;
        int len=INT_MAX;
        while(j<ns){
            if(mp.find(s[j])!=mp.end()){
                mps[s[j]]++;
                if(mp[s[j]]==mps[s[j]]){
                    cnt++;
                }
            }
            
            while(cnt>=mp.size()){
                if(j-i+1 < len){
                    len=j-i+1;
                    st=i;
                }
                if(mp.find(s[i])!=mp.end()){
                    mps[s[i]]--;
                    if(mp[s[i]]>mps[s[i]]){
                        cnt--;
                    }
                }
                i++;
            }
            j++;
        }
        return len==INT_MAX?"":s.substr(st,len);
    }
};