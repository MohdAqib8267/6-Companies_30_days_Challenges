class Solution {
public:
    bool isValid(string &s,unordered_map<string,int>&mp,int i,int count){
        if(i>=s.size()){
            return count>1;
        }
        bool check=false;
  
        string curr;
        while(i<s.size()){
            curr+=s[i];
            if(mp.find(curr)!=mp.end()){
                if(isValid(s,mp,i+1,count+1)){
                    check=true;
                }
            }
            i++;
        }
        return check;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        
        for(int i=0;i<n;i++){
            string s=words[i];
            if(isValid(s,mp,0,0)){
                ans.push_back(s);
            }
          
        }
        return ans;
    }
};