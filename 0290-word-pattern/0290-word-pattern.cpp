class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,set<char>>mp1;
        unordered_map<char,set<string>>mp2;
        int p=pattern.size();
        int n=s.size();
        vector<string>v;
       
        string str="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                v.push_back(str);
                str="";
            }
            else
            str=str+s[i];  
        }
        v.push_back(str);
         for(int i=0;i<v.size();i++){
           cout<<v[i]<<endl;
       }
        if(v.size()!=p){
            return false;
        }
        for(int i=0;i<p;i++){
            mp1[v[i]].insert(pattern[i]);
            mp2[pattern[i]].insert(v[i]);
        }
      
        for(auto it:mp1){
            if(it.second.size()>1){
                return false;
            }
        }
        for(auto it:mp2){
            if(it.second.size()>1){
                return false;
            }
        }
        return true;
    }
};