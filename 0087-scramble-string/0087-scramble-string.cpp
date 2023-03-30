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
        for(int i=1;i<s1.size();i++){
            if((solve(s1.substr(0,i),s2.substr(0,i)) and solve(s1.substr(i),s2.substr(i))) or
               (solve(s1.substr(0,i),s2.substr(n-i)) and solve(s1.substr(i),s2.substr(0,n-i)))){
                return true;
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
        for(int i=1;i<s1.size();i++){
            bool no_swap=solveMemo(s1.substr(0,i),s2.substr(0,i),mp) and solveMemo(s1.substr(i),s2.substr(i),mp);
            bool swap=solveMemo(s1.substr(0,i),s2.substr(n-i),mp) and solveMemo(s1.substr(i),s2.substr(0,n-i),mp);
             bool res= swap || no_swap;
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