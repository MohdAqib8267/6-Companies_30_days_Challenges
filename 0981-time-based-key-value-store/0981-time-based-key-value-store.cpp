class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        int lo=0;
        int hi=mp[key].size()-1;
        string ans;
       
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
           
            if(mp[key][mid].second <= timestamp){
                ans=mp[key][mid].first;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */