class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        int wordSize=beginWord.size();
        if(beginWord==endWord) return 0;
        if(s.find(endWord)==s.end()) return 0;
        int len=0;
        while(!q.empty()){
            len++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string top=q.front();
                q.pop();
                for(int j=0;j<wordSize;j++){
                    char org=top[j];
                    for(char ch='a';ch<='z';ch++){
                        top[j]=ch;
                        if(top==endWord){
                            return len+1;
                        }
                        if(s.find(top)==s.end()){
                            continue;
                        }
                        q.push(top);
                        s.erase(top);
                    }
                    top[j]=org;
                }
            }
        }
        return 0;
    }
};