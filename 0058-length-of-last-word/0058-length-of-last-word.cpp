class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
       
        vector<string>vec;
        while(ss >> word){
            
            vec.push_back(word);
        }
        int n=vec.size();
        string last=vec[n-1];
        return last.size();
    }
};