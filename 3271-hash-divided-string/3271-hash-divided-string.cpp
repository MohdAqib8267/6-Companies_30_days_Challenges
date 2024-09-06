class Solution {
public:
    string stringHash(string s, int k) {
        int totalSubstr = s.size()/k;
        int i=0;
        string res;
        while(i<s.size()){
            int sum=0;
            string str = s.substr(i,k);
            for(auto c:str){
                sum+=(c-'a');
            }
            res.push_back(sum%26+'a');
            i+=k;
        }
        return res;
    }
};