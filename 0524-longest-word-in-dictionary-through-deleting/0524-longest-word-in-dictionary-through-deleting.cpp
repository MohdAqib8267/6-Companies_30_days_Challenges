class Solution {
public:
    bool valid(string &word,string &s){
        int i=0,j=0;
        while(i<s.size() && j<word.size()){
            if(s[i]==word[j]){
                j++;
            }
            i++;
        }
        return j>=word.size(); 
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        int n=s.size();
        
        string ans;
        for(int i=0;i<dictionary.size();i++){
            string word=dictionary[i];
            
            if(valid(word,s)){
                if(ans.size()<word.size()){
                    ans=word;
                }
                else if(ans.size() == word.size() && word<ans){
                    ans=word;
                }
            }
        }
        return ans;
    }
};