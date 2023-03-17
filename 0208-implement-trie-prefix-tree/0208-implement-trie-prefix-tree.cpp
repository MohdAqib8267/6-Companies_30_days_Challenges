class Trie {
public:
    Trie() {
        
    }
    unordered_set<string>s;
    void insert(string word) {
        s.insert(word);
        
    }
    
    bool search(string word) {
        if(s.find(word)!=s.end()){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int sz=prefix.size();
        for(auto it:s){
            if(it.substr(0,sz) == prefix){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */