class Solution {
public:
    bool isValid(string &s,int ind,int len){
        if(ind+len>s.size()){
            return false;
        }
        string str=s.substr(ind,len);
        if(str.size()>1 and str[0]=='0'){
            return false;
        }
        if(stol(str)>255){
            return false;
        }
        return true;
    }
       void recur(string &s , int indx , int used , vector<string> &res , string curr){
        if (indx == s.size() && used == 4){
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        if (indx >= s.size() || used >= 4){
            return;
        }
        if (isValid(s , indx , 1)){
            recur(s , indx + 1 , used + 1 , res , curr + s.substr(indx,1) + ".");
        }
        if (isValid(s , indx , 2)){
            recur(s , indx + 2 , used + 1 , res , curr + s.substr(indx,2) + ".");
        }
        if (isValid(s , indx , 3)){
            recur(s , indx + 3 , used + 1 , res , curr + s.substr(indx,3) + ".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string curr="";
         if (s.size() > 12) return {};
        int dots=0;
        int i=0;
        vector<string>ans;
        recur(s,i,dots,ans,curr);
        return ans;
        
    }
};