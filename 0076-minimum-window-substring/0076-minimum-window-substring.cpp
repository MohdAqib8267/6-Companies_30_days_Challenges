class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        for(auto ch:t){
            freq2[ch]++;
        }
        int st=-1;
        int i=0,j=0;
        int cnt=0;
        int ans=INT_MAX;
        while(j<m){
            if(freq2.find(s[j])!=freq2.end()){
                if(freq1[s[j]]<freq2[s[j]]){
                     cnt++;
                }
                freq1[s[j]]++;
            }
            while(t.size()==cnt){
                
                if(j-i+1<ans){
                    ans=j-i+1;
                    st=i;
                }
                if(freq2.find(s[i])!=freq2.end()){
                     freq1[s[i]]--;
                    if(freq1[s[i]]<freq2[s[i]]){
                        cnt--;
                    }
                   
                }
                i++;
            }
            j++;
        }
        if(st!=-1){
            return s.substr(st,ans);
        }else
        return "";
    }
};