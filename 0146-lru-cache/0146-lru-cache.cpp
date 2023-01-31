class LRUCache {
public: 
        int size;
        list<pair<int,int>>myList;
        unordered_map<int,list<pair<int,int>>::iterator>myMap;
    LRUCache(int capacity) {
       size=capacity;
    }
    
    int get(int key) {
        if(myMap.find(key)==myMap.end()){
            return -1;
        }
        myList.splice(myList.begin(),myList,myMap[key]);
        return myMap[key]->second;
        
    }
    
    void put(int key, int value) {
        if(myMap.find(key)!=myMap.end()){
            //if key is present then update
            //it's used, so push in front of list and update map value
            myMap[key]->second=value;
            myList.splice(myList.begin(),myList,myMap[key]);
            return;
        }
        if(myList.size()==size){
            //remove recently least used which will be last pair of myList
            pair<int,int>temp=myList.back();
            myList.pop_back();
            myMap.erase(temp.first);
        }
        myList.push_front({key,value});
        myMap[key]=myList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */