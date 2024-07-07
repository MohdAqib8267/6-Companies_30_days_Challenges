class Solution {
public:
    int findVal(string &str,unordered_map<char,int>&mp){
        int i=0;
        int cost=0;
        while(i<str.size()){
            if(mp.find(str[i])!=mp.end()){
                cost=cost+mp[str[i]];
            }
            else{
                cost=cost+((str[i]-'a')+1);
            }
        }
        return cost;
    }
    int solve(int i,string s,unordered_map<char,int>&mp){
        if(i>=s.size()){
            return 0;
        }
        int maxi=0;
        for(int j=i;j<s.size();j++){
            string str=s.substr(i,j);
            int val=findVal(str,mp);
            maxi=max(maxi,val+solve(j+1,s,mp));
        }
        return maxi;
    }
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