class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(),paragraph.end(), paragraph.begin(),::tolower);
        unordered_map<string,int>mp;
    
        int n=paragraph.size();
        string s="";
        for(int i=0;i<n;i++){
            
            if(isalpha(paragraph[i])){
                s+=paragraph[i];
            }
            else{
                if(!s.empty()){
                    mp[s]++;
                    s="";
                }
            }
            
        }
           if(!s.empty())
        {
            mp[s]++;
            s="";

        }
        for(int i=0;i<banned.size();i++){
            if(mp.find(banned[i])!=mp.end()){
                mp[banned[i]]=0;
            }
        }
        int mxCnt=0;
        string ans;
        for(auto it:mp){
            if(it.second>mxCnt){
                ans=it.first;
                mxCnt=it.second;
            }
        }
        return ans;
    }
};