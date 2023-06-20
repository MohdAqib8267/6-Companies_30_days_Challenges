class Solution {
public:
    bool checkSubstring(unordered_map<string,int>wordsCount,string s,int wordLen){
        unordered_map<string,int>wordSeen; // for multiple same words like "good","good"
        for(int j=0;j<s.size();j=j+wordLen){
            string temp=s.substr(j,wordLen);
            if(wordsCount.find(temp)!=wordsCount.end()){
                wordSeen[temp]++;
                if(wordSeen[temp]>wordsCount[temp]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        unordered_map<string,int>wordsCount;
        for(auto it:words){
            wordsCount[it]++;
        }
        int sLen=s.size();
        int wordLen=words[0].size();
        //bcz all words are same length to jo concatenate krne per string bnegi uski length hogi (words[0].size)*(words.size)
        int wordsWindow = wordLen*words.size();
        int i=0;
        while(i<=(sLen-wordsWindow)){
           if(checkSubstring(wordsCount,s.substr(i,wordsWindow),wordLen)){
               res.push_back(i);
           }
            i++;
        }
        return res;
    }
};