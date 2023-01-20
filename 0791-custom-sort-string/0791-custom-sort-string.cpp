class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        string ans;
        for(int i=0;i<order.size();i++){
            if(mp.find(order[i])!=mp.end()){
                int temp=mp[order[i]];
                mp[order[i]]=0;
                while(temp--){
                    ans+=order[i];
                }
            }
        }
        string res2;
        for(auto it:mp){
            if(it.second!=0){
                int temp=it.second;
                while(temp--){
                     res2=res2+it.first;
                }
               
            }
        }
        sort(res2.begin(),res2.end());
        return ans+res2;
        
    }
};