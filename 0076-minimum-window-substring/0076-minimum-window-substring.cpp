class Solution {
public:
    string minWindow(string s, string t) {
       int n=s.size();
        int m=t.size();
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        int len=INT_MAX;
        int st=-1;
        //count freq of every character of t in freq1 map
        for(int i=0;i<m;i++){
            freq1[t[i]]++;
        }
        
        int i=0;int j=0;
        int count=0;
        while(i<n){
            if(freq1.find(s[i])!=freq1.end()){
               if(freq2[s[i]]<freq1[s[i]]){
                    count++;
                }
                freq2[s[i]]++;
            }
            while(count==t.size()){
                   if(len>i-j+1){
                        len=i-j+1;
                        st=j;
                    }
                
                    if(freq1.find(s[j])!=freq1.end()){
                        freq2[s[j]]--;
                        if(freq2[s[j]]<freq1[s[j]]){
                            count--;
                        }
                    }
                    j++;
                }
            
            i++;
        }
        if(st==-1){
            return "";
        }
        return s.substr(st,len);
    }
};