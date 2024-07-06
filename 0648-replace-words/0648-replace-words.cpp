class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string>sen;
        stringstream ss(sentence);
        string word;
        while(getline(ss,word,' ')){
            sen.push_back(word);
        }
        string ans;
        unordered_map<string,int>mp;
        for(int i=0;i<dictionary.size();i++){
            mp[dictionary[i]]=i;
        }
        for(int i=0;i<sen.size();i++){
            string word=sen[i];
            int j=0;
             string sbs;
            bool find=false;
            while(j<word.size()){
               sbs+=word[j];
                if(mp.find(sbs)!=mp.end()){
                    find=true;
                    word=sbs;
                }
               j++; 
            }
           
                ans=ans+word+" ";
            
        }
        if(!ans.empty() and ans[ans.size()-1]==' '){
            ans.pop_back();
        }
        return ans;
    }
};