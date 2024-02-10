class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int j=0;
        for(auto i:magazine){
            if(i == ransomNote[j] && j<ransomNote.size()) j++;
        }
        return (j>=ransomNote.size());
    }
};