class Solution {
public:
    bool solve(string s1,string s2){
        if(s1.size()==1){
            return s1==s2;
        }
        if(s1==s2){
            return true;
        }
        //if string length is n, we have n-1 partition points
        int n=s1.size();
        for(int l=1;l<s1.size();l++){
             bool swap=solve(s1.substr(0,l),s2.substr(n-l,l)) && solve(s1.substr(l,n-l),s2.substr(0,n-l));
            bool notswap=solve(s1.substr(0,l),s2.substr(0,l)) && solve(s1.substr(l,n-l),s2.substr(l,n-l));
            if(swap || notswap){
                return true;
                break;
            }
        }
        return false;
    }
   
    
    //Memoization
        bool solveMemo(string s1,string s2,unordered_map<string,bool>& mp){
        if(s1.size()==1){
            return s1==s2;
        }
        if(s1==s2){
            return true;
        }
        string key = s1+s2;
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
        //if string length is n, we have n-1 partition points
        int n=s1.size();
        for(int l=1;l<s1.size();l++){
             bool swap=solveMemo(s1.substr(0,l),s2.substr(n-l,l),mp) && solveMemo(s1.substr(l,n-l),s2.substr(0,n-l),mp);
            bool notswap=solveMemo(s1.substr(0,l),s2.substr(0,l),mp) && solveMemo(s1.substr(l,n-l),s2.substr(l,n-l),mp);
             bool res= swap || notswap;
            mp[key]=res;
            if(res){
                return true;
                break;
            }
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        // return solve(s1,s2);
        
        unordered_map<string,bool>mp;
        return solveMemo(s1,s2,mp);
    }
};