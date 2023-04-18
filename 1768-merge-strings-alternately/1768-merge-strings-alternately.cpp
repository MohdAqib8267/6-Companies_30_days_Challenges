class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=0, j=0;
        string ans;
        while(i<n and j<m){
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }
        while(i<n){
            ans.push_back(word1[i++]);
        }
        while(j<m){
            ans.push_back(word2[j++]);
        }
        return ans;
    }
};