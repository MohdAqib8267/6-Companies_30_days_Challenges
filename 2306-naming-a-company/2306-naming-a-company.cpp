class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string,bool>mp;
        for(int i=0;i<ideas.size();i++){
            mp[ideas[i]]=true;
        }
        vector<vector<long long>>dict(26,vector<long long>(26,0));
        for(int i=0;i<ideas.size();i++){
            string word = ideas[i].substr(1,ideas[i].size()-1); 
            int ch1 = ideas[i][0]-'a';
            for(int j=0;j<26;j++){
                char ch2 = ('a'+j);
                string temp = ch2+word;
                if(mp.count(temp) == 0){
                    dict[ch1][j] += 1;
                }
            }
        }
        long long count=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j) continue;
                if(dict[i][j]>0){
                    count += dict[i][j]*dict[j][i];
                }
            }
        }
        return count;
    }
};