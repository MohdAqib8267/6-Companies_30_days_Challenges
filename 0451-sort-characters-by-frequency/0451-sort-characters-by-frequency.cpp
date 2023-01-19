class Solution {
public:
   static bool cmp(pair<int,int>&a, pair<int,int>&b){
            return a.second>b.second;
        }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
       string out="";
        for(auto it:v){
            int tmp = it.second;
            while(tmp--){
                out+=it.first;
            }
        }
        return out;
    }
};