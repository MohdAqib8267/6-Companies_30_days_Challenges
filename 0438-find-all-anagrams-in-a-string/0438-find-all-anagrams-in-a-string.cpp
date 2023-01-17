class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //Giving TLE
      // int n=s.size();
      //   int m=p.size();
      //   string p2=p;
      //   sort(p2.begin(),p2.end());
      //   string str=s.substr(0,m);
      //   sort(str.begin(),str.end());
      //   vector<int>ans;
      //   if(str==p2){
      //       ans.push_back(0);
      //   }
      //   for(int i=1;i<=n-m;i++){
      //       string temp=s.substr(i,m);
      //       sort(temp.begin(),temp.end());
      //       if(temp==p2){
      //           ans.push_back(i);
      //       }
      //   }
      //   return ans;
        
        int n=s.size(), m=p.size();
        unordered_map<char,int>mp;
        vector<int>ans;
        for(int i=0;i<m;i++){
            mp[p[i]]++;
        }
        int i=0,j=0;
        int count=mp.size();
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
                
            }
            if(j-i+1<m){
                j++;
            }
            else if(j-i+1 == m){
                if(count==0){
                    ans.push_back(i);
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};