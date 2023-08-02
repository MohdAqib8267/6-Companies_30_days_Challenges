class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<string,vector<string>>mp;
        string str=s;
        sort(str.begin(),str.end());
        mp[str].push_back(s);
        
        string str2=t;
        sort(str2.begin(),str2.end());
        mp[str2].push_back(t);
        if(mp.size()==1){
            return true;
        }
        return false;
    }
};