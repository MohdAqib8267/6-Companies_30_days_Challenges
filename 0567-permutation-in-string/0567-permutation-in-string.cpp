class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,bool>mp;
        for(auto it:s1){
            mp[it]=true;
        }
        int n1=s1.size();
        int n2=s2.size();
        sort(s1.begin(),s1.end());
        for(int i=0;i<n2;i++){
            string str=s2.substr(i,n1);
            sort(str.begin(),str.end());
            if(s1==str){
                return true;
            }
        }
        return false;
    }
};