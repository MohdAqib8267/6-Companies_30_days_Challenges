class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    list<pair<int,int>>li;
    int size;
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        li.splice(li.begin(),li,mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->second=value;
            li.splice(li.begin(),li,mp[key]);
            return;
        }
        if(li.size()==size){
             pair<int,int>temp = li.back();
            li.pop_back();
            mp.erase(temp.first);
        }
        li.push_front({key,value});
        mp[key]=li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */