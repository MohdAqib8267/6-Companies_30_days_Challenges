class Solution {
public:
    
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,long long>mp;
        for(int i=0;i<chars.size();i++){
            mp[chars[i]]=vals[i];
        }
        
        //kadane algo
        int sum=0;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                sum=sum+mp[s[i]];
            }
            else{
                sum=sum+(s[i]-'a'+1);
            }
            maxi=max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};